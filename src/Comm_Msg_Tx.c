#include "Comm_Msg_Tx.h"

#define MODULE_NAME "TComm_Msg_Tx"
static int open(void *_pthis)
{
    TComm_Msg_Tx *pthis = (TComm_Msg_Tx *)_pthis;

    pthis->m_fd = -1;

    return 0;
}
static int clos(void *_pthis)
{
    TComm_Msg_Tx *pthis = (TComm_Msg_Tx *)_pthis;

    if (pthis->m_fd >= 0){
        if ( msgctl(pthis->m_fd, IPC_RMID, 0) < 0 ){
            fprintf(stderr, "[%s:%s]msgctl(IPC_RMID) failed.\n", MODULE_NAME, __func__);
            return 1;
        }
        pthis->m_fd = -1;
    }
    return 0;
}

static int create_ipc(void *_pthis, int _key, int _fg)
{
    TComm_Msg_Tx *pthis = (TComm_Msg_Tx *)_pthis;

    pthis->m_fd = msgget((key_t)_key, _fg | IPC_CREAT);

    return pthis->m_fd;
}

static int get_fd(void *_pthis)
{
    TComm_Msg_Tx *pthis = (TComm_Msg_Tx *)_pthis;

    return pthis->m_fd;
}


//=============================================================================//
//  init and exit module
//=============================================================================//
void TComm_Msg_Tx_Init(void *_pthis)
{
    TComm_Msg_Tx *pthis = (TComm_Msg_Tx *)_pthis;

    pthis->open = open;
    pthis->clos = clos;
    pthis->create_ipc = create_ipc;
    pthis->get_fd = get_fd;
}
void TComm_Msg_Tx_Exit(void *_pthis)
{


}
