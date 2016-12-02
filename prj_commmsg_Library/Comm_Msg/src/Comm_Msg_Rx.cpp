#include "Comm_Msg_Rx.h"


CComm_Msg_Rx::CComm_Msg_Rx(CComm_Msg_RxData *pRxData)
{
    m_fd = -1;
    m_pRxData = pRxData;
}

CComm_Msg_Rx::~CComm_Msg_Rx(void)
{
    if (m_fd >= 0){
        if ( msgctl(m_fd, IPC_RMID, 0) < 0 ){
            fprintf(stderr, "msgctl(IPC_RMID) failed.\n");
        }
    }

}

int CComm_Msg_Rx::Open(int key, int fg)
{
    m_fd = msgget((key_t)key, fg | IPC_CREAT);

    return m_fd;
}

int CComm_Msg_Rx::getFd(void) const
{

    return m_fd;
}
