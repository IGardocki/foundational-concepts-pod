#!/bin/bash
cc -o array array.c
./array

# cc -o -lcunit array_test array_test.c
# ./array_test

cc array_test.c -lcunit -o array_test 