#include "./benchmark.h"

double test(int foo){
    return foo * 10;
}

double Array_Insert_At_Head_Benchmark(size_t number_of_items_to_insert){


    
    t = clock();
    Insert_At_Head(Array* arr, void* item)
    t = clock() - t;
    double time = ((double)t) / CLOCKS_PER_SEC;
    return time;
}