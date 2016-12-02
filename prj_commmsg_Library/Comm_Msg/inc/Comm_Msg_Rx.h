#ifndef COMM_MSG_RX_H
#define COMM_MSG_RX_H

#include "Comm_Msg_Type.h"
#include "Comm_Msg_RxData.h"

class CComm_Msg_Rx{

public:
	CComm_Msg_Rx(CComm_Msg_RxData *pRxData);
	~CComm_Msg_Rx(void);
    int Open(int key, int fg=0666);
    int getFd(void) const;

private:
    int m_fd;
    CComm_Msg_RxData *m_pRxData;

};



#endif //COMM_MSG_RX_H

