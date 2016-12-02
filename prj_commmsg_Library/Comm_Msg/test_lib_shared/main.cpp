#include <iostream>
#define PLC_SPEC
#include "Comm_Msg.h"
using namespace std;



#if 1
int main()
{
    cout << "Shared library test for c++ style." << endl;

    return 0;
}
#else
int main()
{

    cout << "80618_PLC Hello world!" << endl;
    CComm_Msg Msg;




    if (Msg.create(KEY_RX_PLC, KEY_TX_PLC, 1024) < 0){
        cout << "Msg.create Failed!" << endl;
        return -1;
    }

    if ( Msg.snd((char *)"9876543", sizeof("9876543")) ){
        cout << "Msg.snd Failed!" << endl;
        return -1;
    }
    if (Msg.snd((char *)"abcdefg", sizeof("abcdefg"))){
        cout << "Msg.snd Failed!" << endl;
        return -1;
    }

    if ( Msg.rcv() ){
        cout << "Msg.rcv Failed!" << endl;
        return -1;
    } else {
        printf("CmdCode=%lx\n", Msg.m_pRxData->getCmdCode());
    }

    if ( Msg.rcv() ){
        cout << "Msg.rcv Failed!" << endl;
        return -1;
    } else {
        printf("CmdCode=%lx\n", Msg.m_pRxData->getCmdCode() );
    }


    cout << "80618_PLC End" << endl;
    return 0;
}
#endif
