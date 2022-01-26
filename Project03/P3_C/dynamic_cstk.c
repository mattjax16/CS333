//
// Created by Matthew Bass on 10/18/21.
//


#include "dynamic_cstk.h"
#include <stdlib.h>



D_Stack *d_stk_create(int cstk_size){
    D_Stack *stk = (D_Stack*)malloc(sizeof(D_Stack));
    stk->stack = (int*)malloc( cstk_size * sizeof(int));
    stk->capacity = cstk_size;
    stk->top = -1;

    return stk;
}

void d_stk_destroy (D_Stack* stk){
    free(stk->stack);
    free(stk);
    return;
}


void d_stk_expand(D_Stack* stk){
//    Doubles the size of the stack

    printf("Expanding the stack from %d to %d\n",stk->capacity,stk->capacity *2);
    stk->capacity = stk->capacity * 2;

    int* new_stack =  (int*)malloc((stk->capacity)*sizeof(int));

    for(int i = 0; i <= stk->top; i++){
        new_stack[i] = stk->stack[i];
    }

    free(stk->stack);

    stk->stack = new_stack;
    return;
}

// Function to see if the stack is full
// ie top == CSTK_MAX - 1
int d_stk_is_full(D_Stack* stk){
//    printf("Stack is full at capacity 50");
    return stk->top == stk->capacity - 1;
}


// Function to see if the stack is empty
// ie stack's top == - 1
int d_stk_is_empty(D_Stack* stk){
    return stk->top == -1;
}


void d_stk_push(D_Stack* stk, int val){

    // if the stack is full expand it
    if (d_stk_is_full(stk))
        d_stk_expand(stk);

//    increment stack top by 1
    stk->top = stk->top + 1;

    stk->stack[stk->top] = val;
}

int d_stk_pop(D_Stack* stk){
//    if the stack is empyty return the minimum value
//     for an integer
    if (d_stk_is_empty(stk))
        return -2147483648 ;

    //   decrement stack top by 1
    stk->top = stk->top - 1;

    // returning the valye of the top plus one because
    // I decremented the top pointer before returning the
    // the value that was at the postion in the stack
    return stk->stack[stk->top+1];
}

void d_stk_display(D_Stack* stk, int reverse_stk){

    if(reverse_stk != 1){
        for(int i = 0; i <= stk->top; i++){
            printf("%d ",stk->stack[i]);
        }
        printf("\n");
    }
    else{
        for(int i = stk->top; i > -1;i--){
            printf("%d ",stk->stack[i]);
        }
        printf("\n");
    }

}

// Function to return the top from stack without removing it
int d_stk_peek(D_Stack* stk){
    if (d_stk_is_empty(stk))
        return -214748364;
    return stk->stack[stk->top];
}

