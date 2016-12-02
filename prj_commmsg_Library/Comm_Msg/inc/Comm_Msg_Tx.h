#ifndef COMM_MSG_TX_H
#define COMM_MSG_TX_H

#include "Comm_Msg_Type.h"

class CComm_Msg_Tx{

public:
	CComm_Msg_Tx(void);
	~CComm_Msg_Tx(void);
    int Open(int key, int fg=0666);
    int getFd(void) const;
private:
    int m_fd;

};



#endif //COMM_MSG_TX_H

