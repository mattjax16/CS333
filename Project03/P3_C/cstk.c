//
// Created by Matthew Bass on 10/18/21.
//

#include <stdlib.h>
#include "cstk.h"

//global var used for base test code not actual
// max of stack that is set in creation of the stack
int CSTK_MAX = 50;

Stack *stk_create(int cstk_size){
    Stack *stk = (Stack*)malloc(sizeof(Stack));
    stk->stack = (int*)malloc( cstk_size * sizeof(int));
    stk->capacity = cstk_size;
    stk->top = -1;

    return stk;
}

void stk_destroy (Stack* stk){
    free(stk->stack);
    free(stk);
    return;
}


// Function to see if the stack is full
// ie top == CSTK_MAX - 1
int stk_is_full(Stack* stk){
//    printf("Stack is full at capacity 50");
    return stk->top == stk->capacity - 1;
}


// Function to see if the stack is empty
// ie stack's top == - 1
int stk_is_empty(Stack* stk){
    return stk->top == -1;
}


void stk_push(Stack* stk, int val){

    if (stk_is_full(stk))
        return;

//    increment stack top by 1
    stk->top = stk->top + 1;

    stk->stack[stk->top] = val;
}

int stk_pop(Stack* stk){
//    if the stack is empyty return the minimum value
//     for an integer
    if (stk_is_empty(stk))
        return -2147483648 ;

    //   decrement stack top by 1
    stk->top = stk->top - 1;

    // returning the valye of the top plus one because
    // I decremented the top pointer before returning the
    // the value that was at the postion in the stack
    return stk->stack[stk->top+1];
}

void stk_display(Stack* stk, int reverse_stk){

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


//// Test main function
//int main()
//{
//    struct Stack* stk_test= stk_create(10);
//
//
//    printf("Stack is empty returns %d (for true) when empty\n", stk_is_empty(stk_test));
//    printf("Stack is full returns %d (for flase) when not full\n", stk_is_full(stk_test));
//
//    stk_destroy(stk_test);
//
//    return 0;
//}