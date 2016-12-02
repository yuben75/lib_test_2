#include <iostream>
#include "Comm_Msg.h"

using namespace std;

int main()
{

    cout << "80618 Hello world!" << endl;
    CComm_Msg Msg;




    if (Msg.create(KEY_RX_80618PLC, KEY_TX_80618PLC, 1024) < 0){
        cout << "Msg.create Failed!" << endl;
        return -1;
    }

    if ( Msg.snd((char *)"1234567", sizeof("1234567")) ){
        cout << "Msg.snd Failed!" << endl;
        return -1;
    }
    if (Msg.snd((char *)"ABCDEFG", sizeof("ABCDEFG"))){
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


    cout << "80618 End" << endl;
    return 0;
}
