//
// Created by Matthew Bass on 10/20/21.
//

#ifndef DYNAMIC_CSTK_H
#define DYNAMIC_CSTK_H

#include <stdio.h>


typedef struct d_stack {
    int* stack;
    int capacity;
    int top;
} D_Stack;


D_Stack *d_stk_create(int);

void d_stk_destroy (D_Stack*);

void d_stk_expand(D_Stack*);

void d_stk_push(D_Stack *stk, int val);

int d_stk_pop(D_Stack*);

void d_stk_display(D_Stack*, int);

// Function to see if the stack is full
// ie top == CSTK_MAX - 1
int d_stk_is_full(D_Stack*);


// Function to see if the stack is empty
// ie stack's top == - 1
int d_stk_is_empty(D_Stack*);

// Function to return the top from stack without removing it
int d_stk_peek(D_Stack*);

#endif //DYNAMIC_CSTK_H
