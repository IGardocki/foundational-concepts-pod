#!/usr/bin/python3

import ctypes
from enum import IntEnum
import time
# from random import randint

lib = ctypes.CDLL('./algo.so')

number_of_items = [10 ** 2, 10 ** 3, 10 ** 4, 10 ** 5]

class CtypesEnum(IntEnum):
    """A ctypes-compatible IntEnum superclass."""
    @classmethod
    def from_param(cls, obj):
        return int(obj)


lib.Array_Insert_At_Head_Benchmark.argtypes = [ctypes.c_size_t]
lib.Array_Insert_At_Head_Benchmark.restype = ctypes.c_double

lib.Array_Insert_At_Tail_Benchmark.argtypes = [ctypes.c_size_t]
lib.Array_Insert_At_Tail_Benchmark.restype = ctypes.c_double

lib.Array_Search_Benchmark.argtypes = [ctypes.c_size_t]
lib.Array_Search_Benchmark.restype = ctypes.c_double

lib.Array_Max_Benchmark.argtypes = [ctypes.c_size_t]
lib.Array_Max_Benchmark.restype = ctypes.c_double

lib.Array_Enumeration_Benchmark.argtypes = [ctypes.c_size_t]
lib.Array_Enumeration_Benchmark.restype = ctypes.c_double

lib.Array_Rank_Benchmark.argtypes = [ctypes.c_size_t]
lib.Array_Rank_Benchmark.restype = ctypes.c_double

for num in number_of_items:
    print(f'Array_Insert_At_Head_Benchmark time {num}: {lib.Array_Insert_At_Head_Benchmark(num)}\n')
    print(f'Array_Insert_At_Tail_Benchmark time {num}: {lib.Array_Insert_At_Tail_Benchmark(num)}\n')
    print(f'Array_Search_Benchmark time {num}: {lib.Array_Search_Benchmark(num)}\n')
    print(f'Array_Max_Benchmark time {num}: {lib.Array_Max_Benchmark(num)}\n')
    print(f'Array_Enumeration_Benchmark time {num}: {lib.Array_Enumeration_Benchmark(num)}\n')
    print(f'Array_Rank_Benchmark time {num}: {lib.Array_Rank_Benchmark(num)}\n')


# eventually will gen charts