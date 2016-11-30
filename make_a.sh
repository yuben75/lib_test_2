#!/bin/bash
gcc -c test_a.c test_b.c test_c.c -L. -ltest
ar rcs libtest.a test_a.o test_b.o test_c.o
