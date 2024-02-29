#pragma once
#include "../utils/utils.h"


// creates a pseudo class in C
typedef struct {
  size_t n; // number of items in array
  size_t item_size; // size of item. So we can have an arr of ints, or chars, or floats, etc etc
  void* array; // an opaque pointer (meaning it could point to any type) to the array
} Array;

typedef int (*item_comparator)(const void* x, const void* y);

typedef void (*arr_enumerator)(const void* x);

// typedef int (*enumerator)(const void* x);

// takes in the size of the item so we could init an array of any type, and a pointer to a pointer to an array
ResultCode Init_Array(size_t item_size, Array**);
ResultCode Insert_At_Head(Array* arr, void* item);
ResultCode Insert_At_Tail(Array* arr, void* item);
ResultCode Array_Search(Array* arr, void* query, item_comparator comparator, void** result);
ResultCode Array_Max(Array* arr, item_comparator comparator, void** max_result);
ResultCode Array_Enumeration(Array* arr, arr_enumerator enumerator);
ResultCode Array_Rank(Array* arr, item_comparator comparator, void* item, int** rank_result);

