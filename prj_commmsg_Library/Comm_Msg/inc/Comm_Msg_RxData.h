#ifndef COMM_MSG_RXDATA_H
#define COMM_MSG_RXDATA_H

#include "Comm_Msg_Type.h"




class CComm_Msg_RxData{

public:
	CComm_Msg_RxData(void);
	~CComm_Msg_RxData(void);
    int allocate_buffer(int buff_size);
	virtual char *getBuffer(void);
	virtual int getBufferSize(void);
    virtual long int getCmdCode(void);

private:
    int m_buff_size;
    char *m_buff;

};



#endif //COMM_MSG_RXDATA_H

