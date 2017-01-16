#include "Comm_Msg_RxData.h"

#define MODULE_NAME "TComm_Msg_RxData"
static int open(void *_pthis)
{
    TComm_Msg_RxData *pthis = (TComm_Msg_RxData *)_pthis;

    pthis->m_buff_size = 0;
    pthis->m_buff = NULL;
    return 0;
}
static int clos(void *_pthis)
{
    TComm_Msg_RxData *pthis = (TComm_Msg_RxData *)_pthis;

    if (pthis->m_buff){
        free(pthis->m_buff);
        pthis->m_buff = NULL;
        pthis->m_buff_size = 0;
    }

    return 0;
}

static int allocate_buffer(void *_pthis, int _buff_size)
{
    TComm_Msg_RxData *pthis = (TComm_Msg_RxData *)_pthis;

    pthis->m_buff_size = _buff_size;
    pthis->m_buff = malloc(pthis->m_buff_size);

    return (pthis->m_buff)? 0:-1;
}
static char *getBuffer(void *_pthis)
{
    TComm_Msg_RxData *pthis = (TComm_Msg_RxData *)_pthis;

    return pthis->m_buff;
}
static int getBufferSize(void *_pthis)
{
    TComm_Msg_RxData *pthis = (TComm_Msg_RxData *)_pthis;

    return pthis->m_buff_size;
}
static long int getCmdCode(void *_pthis)
{
    TComm_Msg_RxData *pthis = (TComm_Msg_RxData *)_pthis;
    long int *pCmdCode;

    pCmdCode = (long int *)pthis->m_buff;

    return *pCmdCode;
}



//=============================================================================//
//  init and exit module
//=============================================================================//
void TComm_Msg_RxData_Init(void *_pthis)
{
    TComm_Msg_RxData *pthis = (TComm_Msg_RxData *)_pthis;

    pthis->open = open;
    pthis->clos = clos;
    pthis->allocate_buffer = allocate_buffer;
    pthis->getBuffer = getBuffer;
    pthis->getBufferSize = getBufferSize;
    pthis->getCmdCode = getCmdCode;
}
void TComm_Msg_RxData_Exit(void *_pthis)
{

}


