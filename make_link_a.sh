#!/bin/bash
rm ./libtest.a
./make_a.sh
gcc -static main.c -L. -ltest -o test_a
#c++ add -lstdc++
#gcc main.c -L. -ltest -o test_so -lstdc++
