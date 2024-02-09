#include "array.h"
#include "../utils/utils.h"
#include "../utils/comparators.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


// takes in item size and a pointer to a pointer to an Array struct
ResultCode Init_Array(size_t item_size, Array** result) {
    // init empty arr
    // define item size for elements

    // the second arg is a pointer to a pointer to result. If this is null, returns a fail code
    if(result == NULL) return kNullGuard;

    // sets a pointer to an Array struct, calls it array, then uses calloc to allocate memory
    // The syntax of calloc is: void *calloc(size_t num, size_t size);
    // I was originally using malloc for this, but calloc allocates multiple memory blocks to a single variable,
    // which is better for arrays.
    Array* array = calloc(sizeof(Array), 1);
    array->item_size = item_size; // the -> syntax is used to access properties of a pseudoclass in c. Similar to array.item_size
    *result = array; // sets the pointer to result to array, which is a pointer to an array struct
    return kSuccess;
}

// This check was needed for both inserting at head and tail, so made into its own function
ResultCode Create_First_Arr_Item(Array* arr, void* item){
        if(arr == NULL || item == NULL) return kNullGuard;
        // if the array has no items in it, clears and allocates memory for one
        // item of the size of items in the array
        arr-> array = calloc(1, arr->item_size); 
        // copies memory using arr->array as the destination
        // the item as the source to copy, and arr->item_size as the size of memory to copy
        memcpy(arr->array, item, arr->item_size);
        arr->arr_size += 1;
        return kSuccess;
}

ResultCode Insert_At_Head(Array* arr, void* item) {
    if(arr == NULL || item == NULL) return kNullGuard;

    if(arr -> arr_size == 0) {
        size_t result_code = Create_First_Arr_Item(arr, item);
    } else {
        // realloc resizes the memory block pointed to by the pointer that was allocated before
        // syntax is realloc(void *pointer, size_t size)
        void* temp_arr = realloc(arr->array, (arr->arr_size +1) * arr->item_size);
        // sets the array pointer to the temp_arr
        arr->array = temp_arr;

        // moves the array head over one block
        memmove((char*)arr->array + arr->item_size, arr->array,arr->item_size*arr->arr_size);
        arr->arr_size +=1;
        // inserts the new item where the previous head item was 
        memcpy(arr->array, item, arr->item_size);
    }

    return kSuccess;
}

ResultCode Insert_At_Tail(Array* arr, void* item) {
    if(arr == NULL || item == NULL) return kNullGuard;

    if(arr->arr_size == 0){
       size_t result_code = Create_First_Arr_Item(arr, item);
    }
    else {
        void* temp_arr = realloc(arr->array, (arr->arr_size +1) * arr->item_size);
        arr->array = temp_arr;
        memcpy(arr->array + arr->arr_size * arr->item_size, item, arr->item_size);
        arr->arr_size +=1;
    }
    return kSuccess;
}


ResultCode Array_Search(Array* arr, void* query, item_comparator comparator, void** result){
    if(arr == NULL || query == NULL || comparator == NULL || result == NULL) return kNullGuard;

    for(int i = 0; i < arr->arr_size; i++){
        void* current = arr->array + i * arr->item_size;

        if(comparator(current, query) == 0){
            *result = current;
            return kFound;
        }
    }
    return kNotFound;
}

ResultCode Array_Max(Array* arr, item_comparator comparator, void** max_result){
    if(arr == NULL || comparator == NULL || max_result == NULL) return kNullGuard;
    void* max = arr->array;
    for(int i = 1; i < arr->arr_size; i++){
        void* current = arr->array + i * arr->item_size;
        if(comparator(max, current) < 0){
            max = current;
        }
    }
    *max_result = max;
    return kSuccess;
}

    // apply provided function to each element sequentially
ResultCode Array_Enumeration(Array* arr, arr_enumerator enumerator) {
    if(arr == NULL || enumerator == NULL) return kNullGuard;

    for(int i = 0; i < arr->arr_size; i++){
        void* current = arr->array + i * arr->item_size;
        enumerator(current);
    }
    return kSuccess;
}

ResultCode Array_Rank(Array* arr, item_comparator comparator, void* item, int** rank_result) {
    int rank = 0;
    for(int i = 0; i < arr->arr_size; i++){
        void* current = arr->array + i * arr->item_size;
        // determines number of items in array that are larger than the item
        if(comparator(item, current) < 0){
            rank++;
        }
    }
    printf("RANK: %d\n", rank);
    *rank_result = &rank;
    return kSuccess;
}

// int PIntComparator(const void* x, const void* y) { return *(int*)x - *(int*)y; };

// int PCharComparator(const void* x, const void* y) {
//     return *(char*)x - *(char*)y;
// }

// a simple enumerator that just prints each thing in the arr
// void Enumerator(const void* x){
//     printf("ENUMERATOR: %i\n", *(int*)x);
// }

// int main() {
//     Array* array = NULL; // calls a pointer to an Array struct array and sets it to NULL
//     Init_Array(sizeof(int), &array); // passes in int size, and the reference to the array
//     int test0 = 15; //declares an int
//     int test1 = 20;
 
//     void* max_result_store = NULL;
//     Insert_At_Head(array, &test0); // passes the array pointer and a reference to test into the function
//     Insert_At_Tail(array, &test1);

//     void* search_result_store = NULL;
//     Array_Search(array, &test0, PIntComparator, &search_result_store);

//     Array_Max(array, PIntComparator, &max_result_store);
//     Array_Enumeration(array, Enumerator);

//     int test_for_rank = 10;
//     int* rank_result_store = NULL;
//     Array_Rank(array, PIntComparator, &test_for_rank, &rank_result_store);
//     free(array);

//     Array* char_array = NULL;
//     char c = 'c';
//     char a = 'a';
//     char t = 't' ;
//     void* cat_search_res_store = NULL;
//     Init_Array(sizeof(char), &char_array);
//     Insert_At_Head(char_array, &c);
//     Insert_At_Tail(char_array, &a);
//     Insert_At_Tail(char_array, &t);
//     Array_Search(char_array, &c, PCharComparator, &cat_search_res_store);
//     Array_Enumeration(char_array, Enumerator);

//     char test_for_char_rank = 'l';
//     int* char_rank_result_store = NULL;
//     Array_Rank(char_array, PCharComparator, &test_for_char_rank, &char_rank_result_store);
//     free(char_array);
// }