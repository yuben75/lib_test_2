#!/bin/bash
rm ./libtest.so
./make_so.sh
gcc main.c -L. -ltest -o test_so

