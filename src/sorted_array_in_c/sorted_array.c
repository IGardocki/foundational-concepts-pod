// CODE I WROTE AFTER WRITING ARRAY IN C
#include "../array_in_c/array.h"
#include "sorted_array.h"
#include "../utils/utils.h"
#include "../utils/comparators.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// takes in item size and a pointer to a pointer to an Array struct
ResultCode Init_Sorted_Array(size_t item_size, Array** result) {
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
ResultCode Create_First_Sorted_Arr_Item(Array* arr, void* item){
        if(arr == NULL || item == NULL) return kNullGuard;
        // if the array has no items in it, clears and allocates memory for one
        // item of the size of items in the array
        arr-> array = calloc(1, arr->item_size); 
        // copies memory using arr->array as the destination
        // the item as the source to copy, and arr->item_size as the size of memory to copy
        memcpy(arr->array, item, arr->item_size);
        arr->n += 1;
        printf("CREATED ARR\n");
        return kSuccess;
}

// for use in determining rankings
// ResultCode Array_Rank(Array* arr, item_comparator comparator, void* item, int** rank_result) {
//     int rank = 0;
//     printf("array size = %zu\n", arr->n);
//     for(int i = 0; i < arr->n; i++){
//         void* current = arr->array + i * arr->item_size;
//         // determines number of items in array that are larger than the item
//         printf("i= %d, current: %d\n", i, *(int*)current);
//         printf("result= %d\n",comparator(item, current));
//         if(comparator(item, current) < 0){
//             rank++;
//             printf("COMP HIT! RANK: ");
//         }
//     }
//     printf("RANK: %d\n", rank);
//     *rank_result = &rank;
//     return kSuccess;
// }

ResultCode Sorted_Array_Ordered_Insertion(Array* arr, item_comparator comparator, void* item) {
    if(arr == NULL || item == NULL) return kNullGuard;

    if(arr -> n == 0) {
        return Create_First_Sorted_Arr_Item(arr, item);
    } 

    int index_to_insert_at = -1;
 
    for(int i = 0; i < arr->n; i++){
        void* current = arr->array + (i * arr->item_size);
        if(comparator(item, current) < 0){
            index_to_insert_at = i;
            break;
        }
    }

    if(index_to_insert_at == -1){
        index_to_insert_at = arr->n;
    }

    arr->array = realloc(arr->array, (arr->n + 1) * arr->item_size);
    char* start_address = (char*)arr->array + (arr->item_size * index_to_insert_at);
    memmove(start_address + arr->item_size, start_address, (arr->n - index_to_insert_at) * arr->item_size);
    memcpy(start_address, item, arr->item_size);
    arr->n +=1;
    return kSuccess;
}

void print_sorted_array(Array* arr){
    printf("PRINTING ARRAY:\n");
    printf("n: %zu\n", arr->n);
    for(int i = 0; i < arr->n; i++){
        printf("%d: %d\n", i, ((int*)arr->array)[i]);
    }
}

// ResultCode Sorted_Array_Min_Retrieval(Array* arr, void** min_result){
//     if(arr == NULL || min_result == NULL) return kNullGuard;
//     // locate min in arr
//     *min_result = arr->array[0];
//     return kSuccess;
// }

ResultCode Sorted_Array_Min_Retrieval(Array* arr, void** min_result){
    if(arr == NULL || min_result == NULL) return kNullGuard;
    *min_result = arr->array;
    return kSuccess;
}

ResultCode Sorted_Array_Max_Retrieval(Array* arr, void** max_result){
    if(arr == NULL || max_result == NULL) return kNullGuard;
    *max_result = arr->array + arr->item_size * (arr->n-1);
    return kSuccess;
}

// int main(){
//     Array* array = NULL; // calls a pointer to an Array struct array and sets it to NULL
//     Init_Sorted_Array(sizeof(int), &array); // passes in int size, and the reference to the array

//     int test0 = 850;
//     int test1 = 851;
//     int test2 = 888;
//     int test3 = 123;

//     // printf("TEST: %i\n", PIntComparator(&test1, &test0));
//     Ordered_Insertion(array, PIntComparator, &test3); // passes the array pointer and a reference to test into the function
//     print_sorted_array(array);
//     Ordered_Insertion(array, PIntComparator, &test1);
//     print_sorted_array(array);
//     Ordered_Insertion(array, PIntComparator, &test2);
//     print_sorted_array(array);
//     Ordered_Insertion(array, PIntComparator, &test0);

//     print_sorted_array(array);
// //     Ordered_Insertion(array, PIntComparator, &test0);
//     test0 = 138;
//     print_sorted_array(array);
// //     // Test_Ordered_Insertion(array, PIntComparator, &test2);
// //     printf("Hello World\n");
//     free(array);
// }


// ORIGINAL CODE I WROTE

// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// // this will be the length of the array
// int n = 0;

// int* init_array(int item) {
//     int *array;
//     int num_elements = 1;
//     array = malloc(sizeof(item) * num_elements);
//     array[0] = item;
//     n++;
//     if(!array){
//         printf("Allocating %d bytes failed\n", (int)sizeof(int) * num_elements);
//     }
//     return array;
// }

// void ordered_insertion(int* array, int item){
//     // if there is no greater item, will put the item at the end
//     int index_of_greater_item = n; 
//     for (int i = 0; i < n; i++){
//         if(array[i] > item){
//             // determines the index of the first item that is greater than the item
//             index_of_greater_item = i;
//             break;
//         }
//     }

//     // starting with the last element, sets each element greater than the item to one 
//     // index above
//     for(int i = n - 1; i >= index_of_greater_item; i--){
//         array[i + 1] = array[i];
//     }

//     // inserts the new item into the index where the first element greater than it 
//     // used to be
//     array[index_of_greater_item] = item;
//     n++;
// }

// int binary_search(int* array, int query, int low, int high) {
//   if (high >= low) {
//     int mid = low + (high - low) / 2;

//     // If found at middle, return index of item
//     if (array[mid] == query)
//       return mid;

//     // Search the left half
//     if (array[mid] > query)
//       return binary_search(array, query, low, mid - 1);

//     // Search the right half
//     return binary_search(array, query, mid + 1, high);
//   }
//   return -1;
// }

// int min_retrieval(int* array){
//     // locate min in arr
//     return array[0];
// }

// int max_retrieval(int* array){
//     // locate max in arr
//     return array[n-1];
// }

// int predecessor(int* array, int query){
//     // get element directly before item 
//     // find element
//     int queryIndex = binary_search(array, query, 0, n-1);
//     if(queryIndex == -1 || queryIndex == 0){
//         // handle if an item is not found or if item if the first in an array
//         return -1;
//     }
//     // return element before the chosen element
//     return array[queryIndex - 1];
// }

// int successor(int* array, int query){
//     // get element directly after item 
//     // find element 
//     int queryIndex = binary_search(array, query, 0, n-1);
//     if(queryIndex == -1 || queryIndex == n-1){
//         // handle if an item is not found or if item if the last in an array
//         return -1;
//     }
//     // return element after the chosen element
//     return array[queryIndex + 1];
// }

// int select(int* array, int index){
//     // get item at specific index
//     if(index >= n || index < 0){
//         // handle if index given is out of range of array
//         return -1;
//     }
//     return array[index];
// }

// int rank(int* array, int query){
//     // determine how many elements in array are less than the given item
//     // the index of an element will be how many elements are less than it
//     // need to figure out how to handle duplicates here
//     int queryIndex = binary_search(array, query, 0, n-1);
//     return queryIndex;
// }


// int main() {
//     int* array = init_array(5);
//     ordered_insertion(array, 6);
//     ordered_insertion(array, 7);
//     ordered_insertion(array, 4);
//     ordered_insertion(array, 90);
//     ordered_insertion(array, 0);
//     ordered_insertion(array, 11);
//     for(int i = 0; i < n; i++){
//         printf("%d\n", array[i]);
//     }
//     int binary_search_result = binary_search(array, 4, 0, n-1);
//     printf("Binary Search Result: %d\n", binary_search_result);
//     int min_retrieval_result = min_retrieval(array);
//     printf("Min Retrieval Result: %d\n", min_retrieval_result);
//     int max_retrieval_result = max_retrieval(array);
//     printf("Max Retrieval Result: %d\n", max_retrieval_result);
//     int predecessor_result = predecessor(array, 0);
//     printf("Predecessor Result: %d\n", predecessor_result);
//     int successor_result = successor(array, 0);
//     printf("Successor Result: %d\n", successor_result);
//     int select_result = select(array, 5);
//     printf("Select Result: %d\n", select_result);
//     int rank_result = rank(array, 90);
//     printf("Rank Result: %d\n", rank_result);
//     return 0;
// }