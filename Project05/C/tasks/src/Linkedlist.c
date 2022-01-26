//
// Created by Matthew Bass on 11/17/21.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Linkedlist.h"


//creates a new LinkedList struct, initializes it, and returns it
LinkedList* ll_create(){
    LinkedList* ll = (LinkedList*)malloc(sizeof(LinkedList));
    ll->head = NULL;
    return ll;
}

//adds a node to the front of the list, storing the given data in the node.
void ll_push(LinkedList *l, void *data){
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = l->head;
    l->head = temp;
}

//removes the node at the front of the list and returns the associated data.
void *ll_pop(LinkedList *l){

//    see if the linked list is empty
    if (l->head == NULL) {
        return NULL;
    }

//   else make a temp pointer for data and node
    else {
        void* data = l->head->data;
        Node* temp = l->head->next;
        l->head = temp;
        return data;
    }
}

//adds a node to the end of the list, storing the given data in the node.
void ll_append(LinkedList *l, void *data){
    Node* curr = l->head;
    Node* temp = (Node*)malloc(sizeof(Node));
    
    // if the list is empty
    if(l->head == NULL) {
        temp->data = data;
        temp->next = NULL;
        l->head = temp;
    
    //if the list is not empty
    } else {
        while (curr -> next != NULL) {
            curr = curr -> next;
        }
        temp->data = data;
        temp->next = curr->next;
        curr->next = temp;
    }
}

//removes the first node in the list whose data matches target given the comparison function.
// The function returns the pointer to the data.
void* ll_remove(LinkedList *l, void *target, int (*compfunc)(void *, void *)){
    Node* temp = l -> head;
    if(!temp) {
        return NULL;
    }
    int (*fun_ptr)(void*,void*) = compfunc;

    while (temp->next != NULL) {
        if (compfunc(target, temp->next->data)==0) {
            Node* curr = (Node*)malloc(sizeof(Node));
            curr->data = temp->next->data;
            temp->next = temp->next->next;

            return curr->data;
        }
        temp = temp -> next;
    }
    return NULL;
}

//returns the size of the list.

int ll_size(LinkedList *l){
    int size = 0;
    Node* temp = l->head;
    while (temp->next != NULL) {
        size += 1;
        temp = temp->next;
    }
    size += 1;
    return size;
}

//removes all of the nodes from the list, freeing the associated data using the given function.
void ll_clear(LinkedList *l, void (*freefunc)(void *)){
    void (*fun_ptr)(void*) = freefunc;
    Node* temp = l->head;
    Node* next;
    while (temp != NULL) {
        next = temp->next;
        fun_ptr(temp);
        temp = next;
    }
    l->head = NULL;
}

//traverses the list and applies the given function to the data at each node.
void ll_map(LinkedList *l, void (*mapfunc)(void *)){
    Node* temp = l->head;
    void (*fun_ptr)(void*) = mapfunc;
    while (temp != NULL) {
        void* data = temp -> data;
        fun_ptr(data);
        temp = temp->next;
    }
}
