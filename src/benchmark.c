#include "./benchmark.h"
#include "./array_in_c/array.h"
#include "./utils/comparators.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// TRYING TO CREATE FUNCTION TO GENERATE ARRS OF ITEMS TO TEST, BUT WILL WORK THIS LATER
// void foo(size_t *buf, size_t count) {
//     for(int i = 0; i < count; ++i)
//         buf[i] = i;
// }

double Array_Insert_At_Head_Benchmark(size_t number_of_items_to_insert){
    Array* array = NULL;
    Init_Array(sizeof(int), &array);

    // size_t arr_of_items_to_insert[*number_of_items_to_insert] = {0};
    // foo(arr_of_items_to_insert, number_of_items_to_insert);

    // create array of things to insert that are random ints
    size_t arr_of_items_to_insert[number_of_items_to_insert];
    for(int i = 0; i < number_of_items_to_insert; i++){
        arr_of_items_to_insert[i] = rand();
    }

    // start clock
    clock_t t = clock(); 

    // insert each thing into the array at the head
    for(int i = 0; i < number_of_items_to_insert; i++){
        Insert_At_Head(array, &arr_of_items_to_insert[i]);
    }

    // get time elapsed 
    t = clock() - t;
    double time = ((double)t) / CLOCKS_PER_SEC;
    printf("TIME: %f\n", time);
    return time;
}

double Array_Insert_At_Tail_Benchmark(size_t number_of_items_to_insert){
    Array* array = NULL;
    Init_Array(sizeof(int), &array);

    size_t arr_of_items_to_insert[number_of_items_to_insert];
    for(int i = 0; i < number_of_items_to_insert; i++){
        arr_of_items_to_insert[i] = rand();
    }

    // start clock
    clock_t t = clock(); 

    // insert each thing into the array at the tail
    for(int i = 0; i < number_of_items_to_insert; i++){
        Insert_At_Tail(array, &arr_of_items_to_insert[i]);
    }

    // get time elapsed 
    t = clock() - t;
    double time = ((double)t) / CLOCKS_PER_SEC;
    printf("TIME: %f\n", time);
    return time;
}

double Array_Search_Benchmark(size_t number_of_items_to_insert){
    Array* array = NULL;
    Init_Array(sizeof(int), &array);

    size_t arr_of_items_to_insert[number_of_items_to_insert];
    for(int i = 0; i < number_of_items_to_insert; i++){
        arr_of_items_to_insert[i] = rand();
    }

    // insert each thing into the array at the tail
    for(int i = 0; i < number_of_items_to_insert; i++){
        Insert_At_Tail(array, &arr_of_items_to_insert[i]);
    }

    // create query to search for
    int query = rand();

    // create a search result store
    void* search_result_store = NULL;

    // start clock
    clock_t t = clock(); 

    Array_Search(array, &query, PIntComparator, &search_result_store);
        // Array_Search(array, &test0, PIntComparator, &search_result_store);

    // get time elapsed 
    t = clock() - t;
    double time = ((double)t) / CLOCKS_PER_SEC;
    printf("TIME: %f\n", time);
    return time;
}

double Array_Max_Benchmark(size_t number_of_items_to_insert){
    Array* array = NULL;
    Init_Array(sizeof(int), &array);

    size_t arr_of_items_to_insert[number_of_items_to_insert];
    for(int i = 0; i < number_of_items_to_insert; i++){
        arr_of_items_to_insert[i] = rand();
    }

    // insert each thing into the array at the tail
    for(int i = 0; i < number_of_items_to_insert; i++){
        Insert_At_Tail(array, &arr_of_items_to_insert[i]);
    }

    // create a max result store
    void* max_result_store = NULL;

    // start clock
    clock_t t = clock(); 

    Array_Max(array, PIntComparator, &max_result_store);

    // get time elapsed 
    t = clock() - t;
    double time = ((double)t) / CLOCKS_PER_SEC;
    printf("TIME: %f\n", time);
    return time;
}