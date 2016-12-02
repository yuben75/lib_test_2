#!/bin/bash


gcc main.cpp -I../inc -L../lib_shared/Debug -lComm_Msg -o test_lib_shared -lstdc++

