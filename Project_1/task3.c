/**
* task3.c
*
* This is a c program for project 1 Q3
*
* Matt Bass
* 08/31/2021 
*/

#include <stdio.h>
#include <stdlib.h>
        
/* A function to program that repeatedly allocates a small 
amount of memory in a loop that goes on for a long time. 
Just use a single variable to point to the memory

Meant to be seeing the memory grow until I free the memory in the code

 */ 
int main (int arg, char *argv[]) {
    

    int i; //declaring an int for the loop

    //declaring heap int pointer
    int *b;
    
    //making a memory leak without the free statement
    for(i=0;i < 90000000; i++){
        b = (int *)malloc(sizeof(int));
        printf("Byte %d\n", i);
        free(b);//Use this line of code to free the memory 
        //      From the heap to prevent a memory leak 
    }

				
    return 0;
}