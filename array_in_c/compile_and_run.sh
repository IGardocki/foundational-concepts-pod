#!/bin/bash
cc -o array array.c 
./array

# TODO: Figure out how to properly run tests
cc -o array_test -lcunit array_test.c
./array_test