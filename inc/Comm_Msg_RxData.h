#ifndef COMM_MSG_RXDATA_H
#define COMM_MSG_RXDATA_H

#include "Comm_Msg_Type.h"

typedef struct tagComm_Msg_RxData{
    int (*open)(void *_pthis);
    int (*clos)(void *_pthis);
    int (*allocate_buffer)(void *_pthis, int _buff_size);
    char *(*getBuffer)(void *_pthis);
	int (*getBufferSize)(void *_pthis);
    long int (*getCmdCode)(void *_pthis);
    int m_buff_size;
    char *m_buff;
}TComm_Msg_RxData;

#ifdef __cplusplus
extern "C" {
#endif

void TComm_Msg_RxData_Init(void *_pthis);
void TComm_Msg_RxData_Exit(void *_pthis);

#ifdef __cplusplus
}
#endif

#endif //COMM_MSG_RXDATA_H

