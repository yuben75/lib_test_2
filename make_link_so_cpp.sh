#!/bin/bash
rm ./libtest.so
./make_so.sh
#gcc main.c -L. -ltest -o test_so

#c++ add -lstdc++
gcc main.cpp -L. -ltest -o test_so_cpp -lstdc++

