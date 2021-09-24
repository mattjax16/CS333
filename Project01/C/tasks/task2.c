/**
* task2.c
*
* This is a c program for project 1 Q2
*
* Matt Bass
* 08/31/2021 
*/

#include <stdio.h>
#include <stdlib.h>
        
/* A function to declare a variable of each basic type
 */ 
int main (int arg, char *argv[]) {
					
    // Integer types
    char c1;
    unsigned char c2;
    short int integer1;
    int integer2;
    long int integer3;

    // Float types
    float  f1;
    double f2;
    
    
    //Now I am going to assigning the value of 16 to each data type
    c1 = 16;
    c2 = 32;
    integer1 = 170;
    integer2 = 170;
    integer3 = 170;
    
    
    
    // Declaring the Pointer 
    unsigned char *ptr;

    int i; //declaring an int for the loop

    //Going through the unisgned char ptr
    ptr = (unsigned char *)&ptr;//assigning the memory address of c1 to the pointer
    for(i=0;; i++){
        printf("Ptr, Byte %d: %02X\n", i, ptr[i]);
    }

    
					
    return 0;
}