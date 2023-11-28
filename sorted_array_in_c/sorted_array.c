#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// this will be the length of the array
int arr_size = 0;

int* init_array(int item) {
    int *array;
    int num_elements = 1;
    array = malloc(sizeof(item) * num_elements);
    array[0] = item;
    arr_size++;
    if(!array){
        printf("Allocating %d bytes failed\n", (int)sizeof(int) * num_elements);
    }
    return array;
}

void ordered_insertion(int* array, int item){
    // if there is no greater item, will put the item at the end
    int index_of_greater_item = arr_size; 
    for (int i = 0; i < arr_size; i++){
        if(array[i] > item){
            // determines the index of the first item that is greater than the item
            index_of_greater_item = i;
            break;
        }
    }

    // starting with the last element, sets each element greater than the item to one 
    // index above
    for(int i = arr_size - 1; i >= index_of_greater_item; i--){
        array[i + 1] = array[i];
    }

    // inserts the new item into the index where the first element greater than it 
    // used to be
    array[index_of_greater_item] = item;
    arr_size++;
}

int binary_search(int* array, int query, int low, int high) {
  if (high >= low) {
    int mid = low + (high - low) / 2;

    // If found at middle, return index of item
    if (array[mid] == query)
      return mid;

    // Search the left half
    if (array[mid] > query)
      return binary_search(array, query, low, mid - 1);

    // Search the right half
    return binary_search(array, query, mid + 1, high);
  }
  return -1;
}

int min_retrieval(int* array){
    // locate min in arr
    return array[0];
}

int max_retrieval(int* array){
    // locate max in arr
    return array[arr_size-1];
}

int predecessor(int* array, int query){
    // get element directly before item 
    // find element
    int queryIndex = binary_search(array, query, 0, arr_size-1);
    if(queryIndex == -1 || queryIndex == 0){
        // handle if an item is not found or if item if the first in an array
        return -1;
    }
    // return element before the chosen element
    return array[queryIndex - 1];
}

int successor(int* array, int query){
    // get element directly after item 
    // find element 
    int queryIndex = binary_search(array, query, 0, arr_size-1);
    if(queryIndex == -1 || queryIndex == arr_size-1){
        // handle if an item is not found or if item if the last in an array
        return -1;
    }
    // return element after the chosen element
    return array[queryIndex + 1];
}

int select(int* array, int index){
    // get item at specific index
    if(index >= arr_size || index < 0){
        // handle if index given is out of range of array
        return -1;
    }
    return array[index];
}

int rank(int* array, int query){
    // determine how many elements in array are less than the given item
    // the index of an element will be how many elements are less than it
    // need to figure out how to handle duplicates here
    int queryIndex = binary_search(array, query, 0, arr_size-1);
    return queryIndex;
}


int main() {
    int* array = init_array(5);
    ordered_insertion(array, 6);
    ordered_insertion(array, 7);
    ordered_insertion(array, 4);
    ordered_insertion(array, 90);
    ordered_insertion(array, 0);
    ordered_insertion(array, 11);
    for(int i = 0; i < arr_size; i++){
        printf("%d\n", array[i]);
    }
    int binary_search_result = binary_search(array, 4, 0, arr_size-1);
    printf("Binary Search Result: %d\n", binary_search_result);
    int min_retrieval_result = min_retrieval(array);
    printf("Min Retrieval Result: %d\n", min_retrieval_result);
    int max_retrieval_result = max_retrieval(array);
    printf("Max Retrieval Result: %d\n", max_retrieval_result);
    int predecessor_result = predecessor(array, 0);
    printf("Predecessor Result: %d\n", predecessor_result);
    int successor_result = successor(array, 0);
    printf("Successor Result: %d\n", successor_result);
    int select_result = select(array, 5);
    printf("Select Result: %d\n", select_result);
    int rank_result = rank(array, 90);
    printf("Rank Result: %d\n", rank_result);
    return 0;
}