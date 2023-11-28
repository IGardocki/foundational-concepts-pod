#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// may want to refactor to do something like this
typedef struct {
  size_t arr_size;
  size_t item_size;
  void* array;
} Array;

// this will be the length of the array
int arr_size = 0;

int *generate_random_numbers(int number_of_items){
    int * random_numbers = malloc(sizeof(int) * number_of_items);
    srand(0);
    for (int i = 0; i < number_of_items; i++) {
        random_numbers[i] = rand();
    }
    return random_numbers;
}

int *init_array(int item) {
    // init empty arr
    // define item size for elements
    // implement comparator func to dictate order of elements
    
    int *array;
    int num_elements = 1;
    array = malloc(sizeof(item) * num_elements);
    // printf("%p\n", array);
    array[0] = item;
    arr_size++;
    // printf("%d\n", arr_size);
    // memcpy(array, item, sizeof(item));
    // printf("size of arr: %lu", sizeof(array));
    // printf("size of arr[0]: %lu\n", sizeof(array[2]));
    if(!array){
        printf("Allocating %d bytes failed\n", (int)sizeof(int) * num_elements);
        // return -1;
    }
    // printf("%d\n", array[0]);
    return array;
    // free(array); // 
    // return 0;
}

void insert_at_head(int* array, int item){
    for(int i = arr_size; i >= 0; i--) {
        array[i + 1] = array[i];
    }
    array[0] = item;
    arr_size++;
    printf("%d inserted at head!\n", item);
// insert elements at beginning of arr
// ensure arr expands to accommodate new entries
}

void insert_at_tail(int* array, int item) {
    array[arr_size] = item;
    arr_size++;
    printf("%d inserted at tail!\n", item);
}

int search(int* array, int item) {
    for(int i = 0; i<arr_size; i++){
        if(array[i] == item){
            return item;
        }
    }
    return -1;
    // create search to locate elements
    // use comparator to id position of element
}

void enumeration() {
    // apply provided function to each element sequentially
}

int max(int* array){
    // find max element as id'ed by comparator
    int max = array[0];
    for(int i = 0; i<arr_size; i++){
        if(array[i] > max){
            max = array[i];
        }
    }
    return max;
    printf("max: %d", max);
}

int rank(int* array, int item) {
    int rank = 0;
    // establish rank of element based off of how many elements are smaller than it
    // find num of elements smaller than item
    for(int i = 0; i < arr_size; i++){
        if(array[i] > item){
            rank++;
        }
    }
    return rank;
}

int main() {
    int * rand = generate_random_numbers(2);
    clock_t start = clock();
    int* array = init_array(5);
    insert_at_tail(array, 6);
    insert_at_tail(array, 7);
    insert_at_head(array, 9);
    printf("Array contains: \n");
    for(int i = 0; i < arr_size; i++){
        printf("%d\n", array[i]);
    }
    int search_result = search(array, 0);
    printf("Search result: %d\n", search_result);
    int max_result = max(array);
    printf("Max Result: %d\n", max_result);
    int rank_result = rank(array, 9);
    printf("Rank Result: %d\n", rank_result);
    free(array);
    clock_t end = clock();
    double execution_time = ((double)(end - start))/CLOCKS_PER_SEC;
    free(rand);
    printf("EXECUTION TIME: %f SECONDS\n", execution_time);
    return 0;
}