#!/usr/bin/python3

import ctypes
from enum import IntEnum
import time
from random import randint

lib = ctypes.CDLL('./algo.so')

# need to figure out how to use ctypes with current c code 

number_of_items = [10 ** 2, 10 ** 3, 10 ** 4, 10 ** 5]

class CtypesEnum(IntEnum):
    """A ctypes-compatible IntEnum superclass."""
    @classmethod
    def from_param(cls, obj):
        return int(obj)

lib.test.argtypes = [ctypes.c_int]
lib.test.restype = ctypes.c_double
print(lib.test(5))
# generate rancom arr with certain number of items to test ops with 


# loop over each operation
# todo: Start time before each function

# stop after each


# eventually will gen charts