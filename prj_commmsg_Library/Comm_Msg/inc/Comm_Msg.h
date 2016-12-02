#ifndef COMM_MSG_H
#define COMM_MSG_H

#include "Comm_Msg_Type.h"
#include "Comm_Msg_RxData.h"
#include "Comm_Msg_Rx.h"
#include "Comm_Msg_Tx.h"

//check scpi tagPROGDATA type
struct tagPROGDATA{
	unsigned char	byDataType;
	unsigned char	byBuffer[32];
};


class CComm_Msg{

public:
	CComm_Msg(void);
	~CComm_Msg(void);
	int create(int RxKey, int TxKey, int buffSize=8);
    virtual int snd(char *p, int len);
    virtual int rcv(void);
    virtual int snd_ScpiCmd(long int cmdCode, int cnt, tagPROGDATA progData[]);

    CComm_Msg_RxData *m_pRxData;
private:
    int m_buffSize;
    CComm_Msg_Rx *m_pRx;
    CComm_Msg_Tx *m_pTx;

};

#ifdef PLC_SPEC
    #define KEY_RX_PLC      0x2000
    #define KEY_TX_PLC      0x2001
#else
    #define KEY_RX_80618PLC 0x2001
    #define KEY_TX_80618PLC 0x2000
#endif


#ifdef GB_SPEC
    #define KEY_RX_GB      0x3000
    #define KEY_TX_GB      0x3001
#else
    #define KEY_RX_80618GB 0x3001
    #define KEY_TX_80618GB 0x3000
#endif

#ifdef CHADEMO_SPEC
    #define KEY_RX_CHADEMO      0x4000
    #define KEY_TX_CHADEMO      0x4001
#else
    #define KEY_RX_80618CHADEMO 0x4001
    #define KEY_TX_80618CHADEMO 0x4000
#endif





#endif //COMM_MSG_H

