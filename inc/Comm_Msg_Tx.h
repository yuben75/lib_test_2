#ifndef COMM_MSG_TX_H
#define COMM_MSG_TX_H

#include "Comm_Msg_Type.h"




typedef struct tagComm_Msg_Tx{
    int (*open)(void *_pthis);
    int (*clos)(void *_pthis);
    int (*get_fd)(void *_pthis);
    int (*create_ipc)(void *_pthis, int _key, int _fg); //default fg=0666
    int m_fd;
}TComm_Msg_Tx;

#ifdef __cplusplus
extern "C" {
#endif

void TComm_Msg_Tx_Init(void *_pthis);
void TComm_Msg_Tx_Exit(void *_pthis);

#ifdef __cplusplus
}
#endif

#endif //COMM_MSG_TX_H

