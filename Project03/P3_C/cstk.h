//
// Created by Matthew Bass on 10/18/21.
//

#ifndef CSTK_H
#define CSTK_H

#include <stdio.h>

extern int CSTK_MAX;

typedef struct stack {
    int* stack;
    int capacity;
    int top;
} Stack;


Stack *stk_create(int);

void stk_destroy (Stack*);

void stk_push(Stack*, int);

int stk_pop(Stack*);

void stk_display(Stack*, int);

// Function to see if the stack is full
// ie top == CSTK_MAX - 1
int stk_is_full(Stack*);


// Function to see if the stack is empty
// ie stack's top == - 1
int stk_is_empty(Stack*);

#endif //CSTK_H
