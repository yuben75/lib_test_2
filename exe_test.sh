#!/bin/bash

ldd test_so

LD_LIBRARY_PATH=$LD_LIBRARY_PATH:./
export LD_LIBRARY_PATH


echo "shared(.so) execute...."
./test_so

echo "static(.a) execute...."
./test_a
