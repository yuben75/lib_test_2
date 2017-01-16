#ifndef COMM_MSG_USER_H
#define COMM_MSG_USER_H

//====================================//
//==UESR Define
//====================================//
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


#endif //COMM_MSG_USER_H

