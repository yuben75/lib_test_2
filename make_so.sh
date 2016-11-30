#!/bin/bash
gcc test_a.c test_b.c test_c.c -fPIC -shared -o libtest.so
