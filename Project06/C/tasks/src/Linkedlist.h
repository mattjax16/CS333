//
// Created by Matthew Bass on 1/02/22.
//

#ifndef PROJECT06_LINKEDLIST_H
#define PROJECT06_LINKEDLIST_H

#include <stdio.h>


typedef struct node {

    void* data;
    struct node* next;
    struct node* prev;
}Node;



typedef struct linkedlist {

    Node* head;
    int size;
}LinkedList;


//creates a new LinkedList struct, initializes it, and returns it
LinkedList* ll_create();

//adds a node to the front of the list, storing the given data in the node.
void ll_push(LinkedList *l, void *data);

//removes the node at the front of the list and returns the associated data.
void* ll_pop(LinkedList *l);

//adds a node to the end of the list, storing the given data in the node.
void ll_append(LinkedList *l, void *data);

//adds a node to the postion of the list specified, 
//storing the given data in the node.
void ll_insert(LinkedList *l, void* data, int index);
    

//removes the first node in the list whose data matches target given the comparison function.
// The function returns the pointer to the data.
void* ll_remove(LinkedList *l, void *target, int (*compfunc)(void *, void *));


/* checks to see if the list already contains a node with value field equal to target */
int ll_contains(LinkedList *l, void* target, int (*compfunc)(void*, void*));

//updates a node (index) currently in the linked list.
void ll_update(LinkedList *l, void *data, int index);

//returns the size of the list.
int ll_size(LinkedList *l);

//removes all of the nodes from the list, freeing the associated data using the given function.
void ll_clear(LinkedList *l, void (*freefunc)(void *));

//traverses the list and applies the given function to the data at each node.
void ll_map(LinkedList *l, void (*mapfunc)(void *));






// function that compares two strings and returns 0 if they are equal 
// < 0 if the first string is of lower value than the second
// > 0 if the other way around 
// refer to https://www.cplusplus.com/reference/cstring/strcmp/
int compStr(void *a, void *b);


// function that compares two integers and returns 0 if they are equal
// -1 if the first int is of lower value than the second
// 1 if the other way around
int compInt(void *i, void *j);

// function that prints an integer
void printInt(void *i);

// function that prints a char
void printChar(void *i);

// function that prints a str
void printStr(void *i);


///
///More List Manipulation Functions
///

/* splits the linkedlist into a linked list of lists
 * Creates a new linked list */
LinkedList* ll_Split(LinkedList *l);



///
///Sorting Functions
///

/* sorts the linkedlist based on  the compFunc */
void ll_mergeSort(LinkedList *l, int (*compfunc)(void*, void*));


#endif //PROJECT06_LINKEDLIST_H
