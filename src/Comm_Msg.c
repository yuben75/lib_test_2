#include "Comm_Msg.h"

#define MODULE_NAME "TComm_Msg"

static int open(void *_pthis)
{
    TComm_Msg *pthis = (TComm_Msg *)_pthis;

    pthis->m_pRxData = NULL;
    pthis->m_buff_size = 0;
    pthis->m_pRx = NULL;
    pthis->m_pTx = NULL;

    return 0;
}
static int clos(void *_pthis)
{
    TComm_Msg *pthis = (TComm_Msg *)_pthis;

    pthis->m_pRxData->clos(pthis->m_pRxData);
    if (pthis->m_pRxData){
        free(pthis->m_pRxData);
        pthis->m_pRxData = NULL;
    }
    pthis->m_pRx->clos(pthis->m_pRx);
    if (pthis->m_pRx){
        free(pthis->m_pRx);
        pthis->m_pRx = NULL;
    }
    pthis->m_pTx->clos(pthis->m_pTx);
    if (pthis->m_pTx){
        free(pthis->m_pTx);
        pthis->m_pTx = NULL;
    }

    return 0;
}
static int create_ipc(void *_pthis, int RxKey, int TxKey, int buff_size)
{
    TComm_Msg *pthis = (TComm_Msg *)_pthis;
    fprintf(stdout, "[%s:%s]\n", MODULE_NAME, __func__);

    //=====================================================
    pthis->m_pRxData = malloc(sizeof(TComm_Msg_RxData));
    if (!pthis->m_pRxData){
        fprintf(stdout, "[%s:%s]-1\n", MODULE_NAME, __func__);
        return -1;
    }
    TComm_Msg_RxData_Init(pthis->m_pRxData);
    if (pthis->m_pRxData->open(pthis->m_pRxData) < 0){
        fprintf(stdout, "[%s:%s]-2\n", MODULE_NAME, __func__);
        return -2;
    }
    if (pthis->m_pRxData->allocate_buffer(pthis->m_pRxData, buff_size) < 0){
        fprintf(stdout, "[%s:%s]-3\n", MODULE_NAME, __func__);
        return -3;
    }
    pthis->m_buff_size = buff_size;
    //=====================================================
    pthis->m_pRx = malloc(sizeof(TComm_Msg_Rx));
    if (!pthis->m_pRx){
        fprintf(stdout, "[%s:%s]-4\n", MODULE_NAME, __func__);
        return -4;
    }
    TComm_Msg_Rx_Init(pthis->m_pRx);
    if (pthis->m_pRx->open_with_para(pthis->m_pRx, pthis->m_pRxData) < 0){
        fprintf(stdout, "[%s:%s]-5\n", MODULE_NAME, __func__);
        return -5;
    }
    if (pthis->m_pRx->create_ipc(pthis->m_pRx, RxKey, 0666) < 0){
        fprintf(stdout, "[%s:%s]-6\n", MODULE_NAME, __func__);
        return -6;
    }
    //=====================================================
    pthis->m_pTx = malloc(sizeof(TComm_Msg_Tx));
    if (!pthis->m_pTx){
        fprintf(stdout, "[%s:%s]-7\n", MODULE_NAME, __func__);
        return -7;
    }
    TComm_Msg_Tx_Init(pthis->m_pTx);
    if (pthis->m_pTx->open(pthis->m_pTx) < 0){
        fprintf(stdout, "[%s:%s]-8\n", MODULE_NAME, __func__);
        return -8;
    }
    if (pthis->m_pTx->create_ipc(pthis->m_pTx, TxKey, 0666) < 0){
        fprintf(stdout, "[%s:%s]-9\n", MODULE_NAME, __func__);
        return -9;
    }

    return 0;

}
static int snd(void *_pthis, char *p, int len)
{
    TComm_Msg *pthis = (TComm_Msg *)_pthis;

    fprintf(stdout, "[%s:%s]\n", MODULE_NAME, __func__);

    len -= sizeof(long int);
    if ( msgsnd(pthis->m_pTx->get_fd(pthis->m_pTx), (void *)p, len, 0) < 0 ){
        return -1;
    }
    return 0;
}
static int rcv(void *_pthis)
{
    TComm_Msg *pthis = (TComm_Msg *)_pthis;

    fprintf(stdout, "[%s:%s] m_pRx->get_fd():%i \n", MODULE_NAME, __func__, pthis->m_pRx->get_fd(pthis->m_pRx));

    if (msgrcv(pthis->m_pRx->get_fd(pthis->m_pRx),
               pthis->m_pRxData->getBuffer(pthis->m_pRxData), pthis->m_pRxData->getBufferSize(pthis->m_pRxData), 0, 0) < 0){

        fprintf(stdout, "[%s:%s] m_pRx->get_fd():%i fail. \n", MODULE_NAME, __func__, pthis->m_pRx->get_fd(pthis->m_pRx));
        return -1;
    }
    fprintf(stdout, "[%s:%s] m_pRx->get_fd():%i ok.\n", MODULE_NAME, __func__, pthis->m_pRx->get_fd(pthis->m_pRx));
    return 0;
}

static int snd_to_sub_process(void *_pthis)
{
    TComm_Msg *pthis = (TComm_Msg *)_pthis;
    char *buff;
    fprintf(stdout, "[%s:%s]\n", MODULE_NAME, __func__);

    buff = malloc(pthis->m_buff_size);

    return 0;
}

//=============================================================================//
//  init and exit module
//=============================================================================//
void TComm_Msg_Init(void *_pthis)
{
    TComm_Msg *pthis = (TComm_Msg *)_pthis;

    pthis->open = open;
    pthis->clos = clos;
    pthis->create_ipc = create_ipc;
    pthis->snd = snd;
    pthis->rcv = rcv;
    pthis->snd_to_sub_process = snd_to_sub_process;
}

void TComm_Msg_Exit(void *_pthis)
{

}






