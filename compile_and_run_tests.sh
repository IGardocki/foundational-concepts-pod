#!/bin/bash
cc -o testRunner testRunner.c ./array_in_c/array_test.c ./array_in_c/array.c ./utils/comparators.c ./sorted_array_in_c/sorted_array.c ./sorted_array_in_c/sorted_array_tests.c -lcunit
./testRunner
