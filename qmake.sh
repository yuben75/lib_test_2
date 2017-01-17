#!/bin/bash

QPRO_NAME="QComm_Msg.pro"

DIR_TOP=$(cd `dirname $0` ; pwd)
echo ${DIR_TOP}

if [ $1 = "-d" ]; then
    echo "debug build.."
    unset QMAKESPEC  
    echo "QMAKESPEC=" $QMAKESPEC
    QDEFINE=$QMAKESPEC
elif [ $1 = "-r" ]; then
    echo "relrese build.."   
    cd /sitara/ti-sdk-am335x-evm/linux-devkit/
    . ./environment-setup
    unset QMAKESPEC  
    echo "QMAKESPEC=" $QMAKESPEC
    QDEFINE=$QMAKESPEC
else
    echo "error build.."
    exit -1
fi 
cd ${DIR_TOP}

qmake -project
#######################################################################################
# app_Comm_Msg.pro to Makefile
#######################################################################################
#copy Comm_Msg.pro the DEPENDPATH, INCLUDEPATH, HEADERS, SOURCES to QPRO_NAME
if [ $2 = "-app" ]; then
    echo "app Makefile."
    if [ $1 = "-d" ]; then
    	qmake QDEFS=x86_app -o Makefile $QPRO_NAME
    elif [ $1 = "-r" ]; then
 	qmake QDEFS=arm_app -o Makefile $QPRO_NAME
    fi
    time make
fi
#######################################################################################
# libso_Comm_Msg.pro to Makefile
#######################################################################################
#copy Comm_Msg.pro the DEPENDPATH, INCLUDEPATH, HEADERS, SOURCES to QPRO_NAME 
if [ $2 = "-libshared" ]; then
    echo "shared library Makefile."
    if [ $1 = "-d" ]; then
    	qmake QDEFS=x86_sharedlib -o Makefile QPRO_NAME
    elif [ $1 = "-r" ]; then
 	qmake QDEFS=arm_sharedlib -o Makefile QPRO_NAME
    fi
    time make
fi
#######################################################################################
# liba_Comm_Msg.pro to Makefile
#######################################################################################
#copy Comm_Msg.pro the DEPENDPATH, INCLUDEPATH, HEADERS, SOURCES to QPRO_NAME
if [ $2 = "-libstatic" ]; then
    echo "static library Makefile."
    if [ $1 = "-d" ]; then
    	qmake QDEFS=x86_staticlib -o Makefile QPRO_NAME
    elif [ $1 = "-r" ]; then
 	qmake QDEFS=arm_staticlib -o Makefile QPRO_NAME
    fi
    time make
fi



