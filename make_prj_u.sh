#!/bin/bash

DIR_TOP=$(cd `dirname $0` ; pwd)
MAKE_PATH=${DIR_TOP}/prj_Makefile_C

echo ${DIR_TOP}

cd /sitara/ti-sdk-am335x-evm/linux-devkit/
. ./environment-setup

cd ${MAKE_PATH}
#time qmake -project
#time qmake -o Makefile Comm_Msg.pro
time make release

