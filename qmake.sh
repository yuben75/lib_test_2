#!/bin/bash


echo "====qmake.sh============================================="

if [ $1 = "-h" ]; then
    echo "qmake.sh -project (Just once)"
    echo "qmake.sh -d -app" 
    echo "qmake.sh -d -libshared"
    echo "qmake.sh -d -libstatic"
    echo "qmake.sh -r -app"
    echo "qmake.sh -r -libshared"
    echo "qmake.sh -r -libstatic"
    exit 0
fi 

DIR_TOP=$(cd `dirname $0` ; pwd)
BASENAME=$(basename  $DIR_TOP)
PRO_NAME=$BASENAME.pro
QPRO_NAME="Q"$PRO_NAME

echo "DIR_TOP="${DIR_TOP}
echo "BASENAME="${BASENAME}
echo "PRO_NAME="${PRO_NAME}
echo "QPRO_NAME="${QPRO_NAME}

#######################################################################################
# qmake -project
#######################################################################################
if [ $1 = "-p" ]; then
    qmake -project
    cp QTemplate.pro $QPRO_NAME
    exit 0
fi 

#######################################################################################
# &1 = debug or release
# &2 = -app or -libshared or -libstatic
#######################################################################################
if [ $1 = "-d" ]; then
    echo "debug build.."
    unset QMAKESPEC  
    echo "QMAKESPEC=" $QMAKESPEC
    DEFS=x86$2
elif [ $1 = "-r" ]; then
    echo "relrese build.."   
    cd /sitara/ti-sdk-am335x-evm/linux-devkit/
    . ./environment-setup
    unset QMAKESPEC  
    echo "QMAKESPEC=" $QMAKESPEC
    DEFS=arm$2
else
    echo "error build.."
    exit -1
fi 
cd ${DIR_TOP}

#######################################################################################
# generate Makefile and make
#######################################################################################
qmake QDEFS=$DEFS QTARGET_NAME=$BASENAME -o Makefile $QPRO_NAME
time make
exit 0




