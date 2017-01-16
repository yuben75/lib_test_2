#ifndef COMM_MSG_RX_H
#define COMM_MSG_RX_H

#include "Comm_Msg_Type.h"
#include "Comm_Msg_RxData.h"


typedef struct tagComm_Msg_Rx{
    int (*open_with_para)(void *_pthis, TComm_Msg_RxData *_pRxData);
    int (*clos)(void *_pthis);
    int (*get_fd)(void *_pthis);
    int (*create_ipc)(void *_pthis, int _key, int _fg); //default fg=0666
    int m_fd;
    TComm_Msg_RxData *m_pRxData;
}TComm_Msg_Rx;

#ifdef __cplusplus
extern "C" {
#endif

void TComm_Msg_Rx_Init(void *_pthis);
void TComm_Msg_Rx_Exit(void *_pthis);

#ifdef __cplusplus
}
#endif

#endif //COMM_MSG_RX_H

