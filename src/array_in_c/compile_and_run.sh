#!/bin/bash
cc -o array array.c 
./array

cc -o array_test -lcunit array_test.c
./array_test