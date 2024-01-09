// Your mission this week is to create a Structured Linked List, a fundamental data structure that epitomizes dynamic and efficient data handling. 
// This task is not just about coding a list; it’s about understanding the intricate dance of interconnected nodes. 
// Assignment Specification: 
// Implement a Structured Linked List that supports any arbitrary data type.
//  Your list should support the following operations: 
//  - Initialization: Construct a list from an array of elements with an optional custom comparator. 
//  - Insertion: Add items to the list, maintaining its structure. 
//  - Search: Implement both a generic and predicate-based search. 
//  - Max: Determine the maximum value. 
//  - Predecessor: Determine the predecessor of a given value. 
//  - Rank: Calculate the number of elements less than a given value. 
//  - Delete: Remove an item, ensuring the list remains cohesive. 
//  - Enumerate: Traverse the list, applying an action to each element. 
//  Pay close attention to the handling of edge cases and null values.

#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
#include "../utils/utils.h"

// Creates a linked list
ResultCode LinkedList_Init(LinkedList** result){
    LinkedList* linked_list = calloc(sizeof(LinkedList), 1);
    *result = linked_list;
    return kSuccess;
}

ResultCode LinkedList_Insertion(LinkedList* linked_list, LLItem* item){
    if(linked_list->head == NULL){
        linked_list-> head = item;
        linked_list->tail =item;
        return kSuccess;
    }
    linked_list->head->previous = item;
    // left off here...need to finish out insertion
    return kSuccess;
}

//  - Search: Implement both a generic and predicate-based search. 
void LinkedList_Search(){

}

//  - Max: Determine the maximum value. 
void LinkedList_Max(){

}

//  - Predecessor: Determine the predecessor of a given value. 
void LinkedList_Predecessor(){

}

//  - Rank: Calculate the number of elements less than a given value.
void LinkedList_Rank(){}

//  - Delete: Remove an item, ensuring the list remains cohesive. 
void LinkedList_Delete(){}

//  - Enumerate: Traverse the list, applying an action to each element. 
void LinkedList_Enumerate(){}

int main (){
    LinkedList* linked_list = NULL;
    LinkedList_Init(&linked_list);
    printf("Hello World\n");
    free(linked_list);
}