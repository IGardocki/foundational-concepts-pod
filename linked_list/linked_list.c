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
    linked_list->head = NULL;
    linked_list->tail = NULL;
    linked_list->number_of_items=0;
    *result = linked_list;
    return kSuccess;
}

// assumes items to insert are doubles. Will need to update this later
ResultCode LinkedList_Insertion(LinkedList* linked_list, double item_to_insert, int position_to_insert_at){
    // if(linked_list->head == NULL){
    //     linked_list-> head = item;
    //     linked_list->tail =item;
    //     return kSuccess;
    // }
    // // linked_list->head->previous = item;
    // // left off here...need to finish out insertion
    // return kSuccess;
    Node *newNode = calloc(sizeof(Node),1);
    newNode->data = (double)item_to_insert;
    newNode->next = NULL;

    // if there are no items in list yet, sets head and tail to the new node, increments number of items
    if(linked_list->number_of_items == 0){
        linked_list->head = newNode;
        linked_list->tail = newNode;
        linked_list->number_of_items +=1;
    } 
    // if inserting at head...
    else if (position_to_insert_at == 0){
        // sets the new nodes next to head
        newNode->next = linked_list->head;
        // sets the lls head to the new node
        linked_list->head = newNode;
        linked_list->number_of_items +=1;
    }
    // if inserting at tail...
    else if (position_to_insert_at == linked_list->number_of_items) {
        // sets the next of the tail to the new node
        linked_list->tail->next = newNode;
        // sets the tail to point to the new node
        linked_list->tail = newNode;
        linked_list->number_of_items +=1;
    }
    // inserting in the middle
    else if (position_to_insert_at > 0 && position_to_insert_at < linked_list->number_of_items) {
        Node* node_to_insert_after = linked_list->head;

        // finding node before the node you want to add
        for (int i = 0; i < position_to_insert_at - 1; i++){
            node_to_insert_after = node_to_insert_after->next;
        }
        // sets newNodes next to the next of the node you wanted to insert after
        newNode->next = node_to_insert_after->next;
        // set the node to insert afters next to newNode
        node_to_insert_after->next = newNode;
        linked_list->number_of_items +=1;
    }

    return kSuccess;
}

//  - Search: Implement both a generic and predicate-based search. 
void LinkedList_Search(LinkedList* linked_list, double item_to_search_for){
    for(int i = 0; i < linked_list->number_of_items; i++){
        printf("hi");
        linked_list
    }

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

void PrintLinkedList(LinkedList* linked_list){
    printf("START PRINTOUT\n");
    Node *currentNode = linked_list->head;

    while(currentNode != NULL){
        printf("-> %lf\n", currentNode->data);
        currentNode = currentNode->next;
    }
    printf("END PRINTOUT\n");
}

int main (){
    LinkedList* linked_list = NULL;
    LinkedList_Init(&linked_list);
    LinkedList_Insertion(linked_list, 12, 1);
    LinkedList_Insertion(linked_list, 1, 0);
    LinkedList_Insertion(linked_list, 3, 1);
    PrintLinkedList(linked_list);
    LinkedList_Search(linked_list, 12);
    // printf("Hello World\n");
    free(linked_list);
}