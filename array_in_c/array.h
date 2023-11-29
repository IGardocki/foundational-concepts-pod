#include "../utils/utils.h"

#pragma once
// creates a pseudo class in C
typedef struct {
  size_t arr_size; // number of items in array
  size_t item_size; // size of item. So we can have an arr of ints, or chars, or floats, etc etc
  void* array; // an opaque pointer (meaning it could point to any type) to the array
} Array;

// takes in the size of the item so we could init an array of any type, and a pointer to a pointer to an array
ResultCode Init_Array(size_t item_size, Array**);
ResultCode Insert_At_Head(Array* arr, void* item);
