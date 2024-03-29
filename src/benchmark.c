#include "./benchmark.h"
#include "./array_in_c/array.h"
#include "./utils/comparators.h"
#include "./sorted_array_in_c/sorted_array.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

double Array_Insert_At_Head_Benchmark(size_t number_of_items_to_insert){
    Array* array = NULL;
    Init_Array(sizeof(int), &array);

    // start clock
    clock_t t = clock(); 

    // insert each thing into the array at the head
    for(int i = 0; i < number_of_items_to_insert; i++){
        size_t number = rand();
        Array_Insert_At_Head(array, &number);
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

    // start clock
    clock_t t = clock(); 

    // insert each thing into the array at the tail
    for(int i = 0; i < number_of_items_to_insert; i++){
        size_t number = rand();
        Array_Insert_At_Tail(array, &number);
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
        Array_Insert_At_Tail(array, &arr_of_items_to_insert[i]);
    }

    // create a search result store
    void* search_result_store = NULL;
    // start clock
    clock_t t = clock(); 
    for(int i = 0; i < number_of_items_to_insert; i++){
        // create query to search for
        int query = rand();
        search_result_store = NULL;
        Array_Search(array, &query, PIntComparator, &search_result_store);
    }

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
        Array_Insert_At_Tail(array, &arr_of_items_to_insert[i]);
    }

    // create a max result store
    void* max_result_store = NULL;

    // start clock
    clock_t t = clock(); 

    for(int i = 0; i < number_of_items_to_insert; i++){
        max_result_store = NULL;
        Array_Max(array, PIntComparator, &max_result_store);
    }
 
    // get time elapsed 
    t = clock() - t;
    double time = ((double)t) / CLOCKS_PER_SEC;
    printf("TIME: %f\n", time);
    return time;
}

    // provide enumerator for below function
    void Sample_Enumerator(const void* x){
        // printf("ENUMERATOR: %i\n", *(int*)x);
        *(int*)x += 1;
    }

double Array_Enumeration_Benchmark(size_t number_of_items_to_insert){
    Array* array = NULL;
    Init_Array(sizeof(int), &array);

    // create arr of items to insert
    size_t arr_of_items_to_insert[number_of_items_to_insert];
    for(int i = 0; i < number_of_items_to_insert; i++){
        arr_of_items_to_insert[i] = rand();
    }

    // insert each thing into the array at the tail
    for(int i = 0; i < number_of_items_to_insert; i++){
        Array_Insert_At_Tail(array, &arr_of_items_to_insert[i]);
    }

    // start clock
    clock_t t = clock(); 

    Array_Enumeration(array, Sample_Enumerator);

    // get time elapsed 
    t = clock() - t;
    double time = ((double)t) / CLOCKS_PER_SEC;
    printf("TIME: %f\n", time);
    return time;
}

double Array_Rank_Benchmark(size_t number_of_items_to_insert){
    Array* array = NULL;
    Init_Array(sizeof(int), &array);

    // create arr of items to insert
    size_t arr_of_items_to_insert[number_of_items_to_insert];
    for(int i = 0; i < number_of_items_to_insert; i++){
        arr_of_items_to_insert[i] = rand();
    }

    // insert each thing into the array at the tail
    for(int i = 0; i < number_of_items_to_insert; i++){
        Array_Insert_At_Tail(array, &arr_of_items_to_insert[i]);
    }

    // create query to get rank for
    int query = rand();

    // create a search result store
    int* rank_result_store = NULL;

    // start clock
    clock_t t = clock(); 

    Array_Rank(array, PIntComparator, &query, &rank_result_store);

    // get time elapsed 
    t = clock() - t;
    double time = ((double)t) / CLOCKS_PER_SEC;
    printf("TIME: %f\n", time);
    return time;
}

double Sorted_Array_Ordered_Insertion_Benchmark(size_t number_of_items_to_insert){
    Array* array = NULL;
    Init_Array(sizeof(int), &array);

    // start clock
    clock_t t = clock(); 

    // ordered insert each thing into the array
    for(int i = 0; i < number_of_items_to_insert; i++){
        size_t number = rand();
        Sorted_Array_Ordered_Insertion(array, PIntComparator, &number);
    }

    // get time elapsed 
    t = clock() - t;
    double time = ((double)t) / CLOCKS_PER_SEC;
    printf("TIME: %f\n", time);
    return time;
}