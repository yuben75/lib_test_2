#include "client.h"
#include <ctype.h>
#include "crc32.h"


int main()
{
    int server_fifo_fd, client_fifo_fd;
    struct data_to_pass_st my_data;
    int read_res;
    char client_fifo[256];
    char *tmp_char_ptr;
    FILE *read_fp;
    int chars_read;
    
    u_int32_t crc;
    u_char crc_data[16];

    fprintf(stderr, "server named pipe start\n");

    crc = crc32(0xffffffff, crc_data, sizeof(crc_data));

	

    mkfifo(SERVER_FIFO_NAME, 0777);
    fprintf(stderr, "server named pipe start = %s\n", "A_1");
    server_fifo_fd = open(SERVER_FIFO_NAME, O_RDONLY);
    fprintf(stderr, "server named pipe start = %s\n", "A_2");
    if (server_fifo_fd == -1) {
        fprintf(stderr, "Server fifo failure\n");
        exit(EXIT_FAILURE);
    }
	fprintf(stderr, "server named pipe start = %s\n", "A_3");
    sleep(5); /* lets clients queue for demo purposes */

    do {
        read_res = read(server_fifo_fd, &my_data, sizeof(my_data));
        
        if (read_res > 0) {
			//pipe test

			#ifdef x86
			read_fp = popen("ifconfig", "r");
			#endif

			#ifdef __ANDROID__
			read_fp = popen("busybox ifconfig", "r");
			#endif

			if (read_fp != NULL){
				do{
					tmp_char_ptr = my_data.some_data;
					chars_read = fread(tmp_char_ptr, sizeof(char), (BUFFER_SIZE-1), read_fp);
					if (chars_read != (BUFFER_SIZE-1)){
						my_data.some_data[chars_read -1] = '\0';
					} 
					if (chars_read){
						sprintf(client_fifo, CLIENT_FIFO_NAME, my_data.client_pid);
						// Then we send the processed data back, opening the client pipe in write-only, blocking mode.
						// Finally, we shut down the server FIFO by closing the file and then unlinking the FIFO.
						client_fifo_fd = open(client_fifo, O_WRONLY);
						if (client_fifo_fd != -1) {
							write(client_fifo_fd, &my_data, (chars_read));
							close(client_fifo_fd);
						}
						fprintf(stderr, "server named pipe start = %s, %i, %i\n", "B", chars_read, (chars_read + (int)sizeof(pid_t)) );	
					}
				} while (chars_read >0);
			} else {
				// In this next stage, we perform some processing on the data just read from the client.
				// We convert all the characters in some_data to uppercase and combine the CLIENT_FIFO_NAME
				// with the received client_pid.
				tmp_char_ptr = my_data.some_data;
				while (*tmp_char_ptr) {
					*tmp_char_ptr = toupper(*tmp_char_ptr);
					tmp_char_ptr++;
				}
				sprintf(client_fifo, CLIENT_FIFO_NAME, my_data.client_pid);

				// Then we send the processed data back, opening the client pipe in write-only, blocking mode.
				// Finally, we shut down the server FIFO by closing the file and then unlinking the FIFO.
				client_fifo_fd = open(client_fifo, O_WRONLY);
				if (client_fifo_fd != -1) {
					write(client_fifo_fd, &my_data, sizeof(my_data));
					close(client_fifo_fd);
				}				
            }

        }
    } while (read_res > 0);
    close(server_fifo_fd);
    unlink(SERVER_FIFO_NAME);
    fprintf(stderr, "server named pipe end\n");
    exit(EXIT_SUCCESS);
}

