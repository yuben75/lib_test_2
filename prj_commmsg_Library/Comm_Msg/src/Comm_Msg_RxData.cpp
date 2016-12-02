#include "Comm_Msg_RxData.h"


CComm_Msg_RxData::CComm_Msg_RxData(void)
{
    m_buff = NULL;
}
CComm_Msg_RxData::~CComm_Msg_RxData(void)
{
    delete [] m_buff;
    m_buff = NULL;
}

int CComm_Msg_RxData::allocate_buffer(int buff_size)
{
    m_buff_size = buff_size;
    m_buff = new char[m_buff_size]();
    return (m_buff)? 0:-1;
}

char *CComm_Msg_RxData::getBuffer(void)
{
    return m_buff;
}

int CComm_Msg_RxData::getBufferSize(void)
{
    return m_buff_size;
}
long int CComm_Msg_RxData::getCmdCode(void)
{
    long int *pCmdCode;

    pCmdCode = (long int *)m_buff;
    return *pCmdCode;
}
