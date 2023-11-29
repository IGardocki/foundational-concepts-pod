#include "array.h"
#include "../utils/utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// takes in item size and a pointer to a pointer to an Array struct
ResultCode Init_Array(size_t item_size, Array** result) {
    // init empty arr
    // define item size for elements

    // the second arg is a pointer to a pointer to result. If this is null, returns a fail code
    if(result == NULL) return kFailure;

    // sets a pointer to an Array struct, calls it array, then uses calloc to allocate memory
    // The syntax of calloc is: void *calloc(size_t num, size_t size);
    // I was orignally using malloc for this, but calloc allocates multiple memory blocks to a single variable,
    // which is better for arrays.
    Array* array = calloc(sizeof(Array), 1);
    array->item_size = item_size; // the -> syntax is used to access properties of a pseudoclass in c. Similar to array.item_size
    *result = array; // sets the pointer to result to array, which is a pointer to an array struct
    return kSuccess;
}

ResultCode Insert_At_Head(Array* arr, void* item) {
    if(arr -> arr_size == 0) {
        printf("ZERO ARR SIZE\n");
        arr-> array = calloc(1, arr->item_size);
    };

    return kSuccess;
}

// void insert_at_head(int* array, int item){
//     // pass in pointer to arr
//     // use realloc so im not risking overflowing into things I shouldnt be
//     for(int i = arr_size; i >= 0; i--) {
//         array[i + 1] = array[i];
//     }
//     array[0] = item;
//     arr_size++;
//     printf("%d inserted at head!\n", item);
// // insert elements at beginning of arr
// // ensure arr expands to accommodate new entries
// }

// void insert_at_tail(int* array, int item) {
//     array[arr_size] = item;
//     arr_size++;
//     printf("%d inserted at tail!\n", item);
// }

// int search(int* array, int item) {
//     for(int i = 0; i<arr_size; i++){
//         if(array[i] == item){
//             return item;
//         }
//     }
//     return -1;
//     // create search to locate elements
//     // use comparator to id position of element
// }

// void enumeration() {
//     // apply provided function to each element sequentially
// }

// int max(int* array){
//     // find max element as id'ed by comparator
//     int max = array[0];
//     for(int i = 0; i<arr_size; i++){
//         if(array[i] > max){
//             max = array[i];
//         }
//     }
//     return max;
//     printf("max: %d", max);
// }

// int rank(int* array, int item) {
//     int rank = 0;
//     // establish rank of element based off of how many elements are smaller than it
//     // find num of elements smaller than item
//     for(int i = 0; i < arr_size; i++){
//         if(array[i] > item){
//             rank++;
//         }
//     }
//     return rank;
// }

int main() {
    Array* array = NULL; // calls a pointer to an Array struct array and sets it to NULL
    printf("%i\n", Init_Array(sizeof(int), &array)); // passes in int size, and the reference to the array
    int test = 15; //declares an int
    printf("%i\n", Insert_At_Head(array, &test)); // passes the array pointer and a reference to test into the function

    free(array);
    // int * rand = generate_random_numbers(2);
    // clock_t start = clock();
    // int* array = init_array(5);
    // insert_at_tail(array, 6);
    // insert_at_tail(array, 7);
    // insert_at_head(array, 9);
    // printf("Array contains: \n");
    // for(int i = 0; i < arr_size; i++){
    //     printf("%d\n", array[i]);
    // }
    // int search_result = search(array, 0);
    // printf("Search result: %d\n", search_result);
    // int max_result = max(array);
    // printf("Max Result: %d\n", max_result);
    // int rank_result = rank(array, 9);
    // printf("Rank Result: %d\n", rank_result);
    // free(array);
    // clock_t end = clock();
    // double execution_time = ((double)(end - start))/CLOCKS_PER_SEC;
    // free(rand);
    // printf("EXECUTION TIME: %f SECONDS\n", execution_time);
    // return 0;
}