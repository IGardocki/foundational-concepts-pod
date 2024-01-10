#!/bin/bash
cc -o testRunner testRunner.c ./array_in_c/array_test.c ./array_in_c/array.c -lcunit
./testRunner
