//
// Created by Matthew Bass on 11/17/21.
//

#ifndef PROJECT05_LINKEDLIST_H
#define PROJECT05_LINKEDLIST_H

#include <stdio.h>


typedef struct node {

    void* data;
    struct node* next;
    struct node* prev;
}Node;



typedef struct linkedlist {

    Node* head;
}LinkedList;


//creates a new LinkedList struct, initializes it, and returns it
LinkedList* ll_create();

//adds a node to the front of the list, storing the given data in the node.
void ll_push(LinkedList *l, void *data);

//removes the node at the front of the list and returns the associated data.
void* ll_pop(LinkedList *l);

//adds a node to the end of the list, storing the given data in the node.
void ll_append(LinkedList *l, void *data);

//removes the first node in the list whose data matches target given the comparison function.
// The function returns the pointer to the data.
void* ll_remove(LinkedList *l, void *target, int (*compfunc)(void *, void *));

//returns the size of the list.
int ll_size(LinkedList *l);

//removes all of the nodes from the list, freeing the associated data using the given function.
void ll_clear(LinkedList *l, void (*freefunc)(void *));

//traverses the list and applies the given function to the data at each node.
void ll_map(LinkedList *l, void (*mapfunc)(void *));

#endif //PROJECT05_LINKEDLIST_H
