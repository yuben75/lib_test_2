#!/bin/bash
rm ./libtest.a
./make_a.sh
gcc -static main.c -L. -ltest -o test_a
