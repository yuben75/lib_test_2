#include "Comm_Msg.h"
#include <iostream>
using namespace std;

CComm_Msg::CComm_Msg(void)
{
    m_pRxData = NULL;
    m_pRx = NULL;
    m_pTx = NULL;
}

CComm_Msg::~CComm_Msg(void)
{
    if (m_pRxData)
        delete m_pRxData;
    if (m_pRx)
        delete m_pRx;
    if (m_pTx)
        delete m_pTx;
}

int CComm_Msg::create(int RxKey, int TxKey, int buffSize)
{
    m_pRxData = new CComm_Msg_RxData();
    m_buffSize = buffSize;
    if (m_pRxData == NULL)
        return -1;
    if (m_pRxData->allocate_buffer(buffSize) < 0)
        return -1;

    m_pRx = new CComm_Msg_Rx(m_pRxData);
    if (m_pRx == NULL)
        return -1;
    if (m_pRx->Open(RxKey) < 0)
        return -1;

    m_pTx = new CComm_Msg_Tx();
    if (m_pTx == NULL)
        return -1;
    if (m_pTx->Open(TxKey) < 0)
        return -1;

    return 0;
}

int CComm_Msg::snd(char *p, int len)
{
    cout << __func__ << "," << m_pTx->getFd() << endl;
    len -= sizeof(long int);
    if ( msgsnd(m_pTx->getFd(), (void *)p, len, 0) < 0 ){
        return -1;
    }
    return 0;
}

int CComm_Msg::rcv(void)
{
    cout << __func__ << "," << m_pRx->getFd() << endl;
    if (msgrcv(m_pRx->getFd(), (void *)m_pRxData->getBuffer(), m_pRxData->getBufferSize(), 0, 0) < 0){

        return -1;
    }
    return 0;
}

int CComm_Msg::snd_ScpiCmd(long int cmdCode, int cnt, tagPROGDATA progData[])
{
    char *buff = new char[m_buffSize]();
    char *p;
    if (buff==NULL)
        return -1;
    p = buff;

    *(long int *)buff = cmdCode;
    buff += sizeof(long int);

    for (int i=0; i<cnt; i++){
        *(short *)buff = progData[i].byDataType;
        buff += sizeof(short);
        buff += sprintf(buff, "%s", progData[i].byBuffer);

    }

    snd(buff, p-buff);
    delete [] buff;
    return 0;
}

