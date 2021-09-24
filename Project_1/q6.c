/**
* task4.c
*
* This is a c program for project 1 Q4 but this one actualy is an odd number of bytes
* since only 3 chars
*
* Matt Bass
* 08/31/2021 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
        
/* A script to make a struct with an odd number of bits
 */ 


/*
making the struct
*/

struct Q6Struct
{
    /* data */
    char a;
    char b;
    char c;

};


int main (int arg, char *argv[]) {
    
    
    struct Q6Struct Q6Struct1;
    
    Q6Struct1.a = 'a';
    Q6Struct1.b = 'b';
    Q6Struct1.c = 'c';
    
     


    int i; //declaring an int for the loop
    unsigned char *ptr;// Declaring the Pointer 
    
    //Going through the struct
    ptr = (unsigned char *)&Q6Struct1;//assigning the memory address of c1 to the pointer
    
    //printinf the size of the struct
    printf("This size of the Struct is %lu\n", sizeof(Q6Struct1));

    for(i=0;i<sizeof(Q6Struct1); i++){
        printf("Q6Struct1, Byte %d: %02X\n", i, ptr[i]);
    }

				
    return 0;
}
