#!/bin/bash

DIR_TOP=$(cd `dirname $0` ; pwd)
echo ${DIR_TOP}
cd /sitara/ti-sdk-am335x-evm/linux-devkit/
. ./environment-setup
cd ${DIR_TOP}


#######################################################################################
# app_Comm_Msg.pro to Makefile
#######################################################################################
#qmake -project
#mv Comm_Msg.pro app_Comm_Msg.pro  
#modify to app pro. TEMPLATE = app
if [ $1 = "app" ]; then
	echo "app Makefile."
	qmake -o Makefile app_Comm_Msg.pro
	time make
fi
#######################################################################################
# libso_Comm_Msg.pro to Makefile
#######################################################################################
#qmake -project
#mv Comm_Msg.pro libso_Comm_Msg.pro  
#modify to shared library pro. TEMPLATE = lib
if [ $1 = "so" ]; then
	echo "shared library Makefile."
	qmake -o Makefile libso_Comm_Msg.pro
	time make
fi
#######################################################################################
# liba_Comm_Msg.pro to Makefile
#######################################################################################
#qmake -project
#mv Comm_Msg.pro liba_Comm_Msg.pro  
#modify to statuc library pro. TEMPLATE = lib CONFIG += staticlib
if [ $1 = "a" ]; then
	echo "static library Makefile."
	qmake -o Makefile liba_Comm_Msg.pro
	time make
fi



