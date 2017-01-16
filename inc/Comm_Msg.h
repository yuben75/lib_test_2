#ifndef COMM_MSG_H
#define COMM_MSG_H

#include "Comm_Msg_User.h"

#include "Comm_Msg_Type.h"
#include "Comm_Msg_RxData.h"
#include "Comm_Msg_Rx.h"
#include "Comm_Msg_Tx.h"

typedef struct tagComm_Msg{
    int (*open)(void *_pthis);
    int (*clos)(void *_pthis);
    int (*create_ipc)(void *_pthis, int RxKey, int TxKey, int buffSize);
    int (*snd)(void *_pthis, char *p, int len);
    int (*rcv)(void *_pthis);
    int (*snd_to_sub_process)(void *_pthis);

    TComm_Msg_RxData *m_pRxData;
    int m_buff_size;
    TComm_Msg_Rx *m_pRx;
    TComm_Msg_Tx *m_pTx;
}TComm_Msg;

#ifdef __cplusplus
extern "C" {
#endif

void TComm_Msg_Init(void *_pthis);
void TComm_Msg_Exit(void *_pthis);

#ifdef __cplusplus
}
#endif



#endif //COMM_MSG_H


