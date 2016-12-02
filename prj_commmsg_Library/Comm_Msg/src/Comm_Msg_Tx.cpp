#include "Comm_Msg_Tx.h"


CComm_Msg_Tx::CComm_Msg_Tx(void)
{
    m_fd = -1;
}

CComm_Msg_Tx::~CComm_Msg_Tx(void)
{


}

int CComm_Msg_Tx::Open(int key, int fg)
{
    m_fd = msgget((key_t)key, fg | IPC_CREAT);

    return m_fd;
}

int CComm_Msg_Tx::getFd(void) const
{

    return m_fd;
}
