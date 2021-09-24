/**
* task1.c
*
* This is a c program for project 1 meant to demonstrate memory allocation 
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
    
    
    //Now I am going to assigning values to each data type
    c1 = 15;
    c2 = 16;
    integer1 = 256;
    integer2 = 268435458;
    integer3 = 4503599627370649;
    f1 = 16;
    f2 = -16;
    
    
    // Declaring the Pointer 
    unsigned char *ptr;

    int i; //declaring an int for the loop

    //Going through c1
    ptr = (unsigned char *)&c1;//assigning the memory address of c1 to the pointer
    for(i=0;i<sizeof(char); i++){
        printf("Char, Byte  %d: %02X\n", i, ptr[i]);
    }

    //Going through c2
    ptr = (unsigned char *)&c2;
    for(i=0;i<sizeof(unsigned char); i++){
        printf("Unsigned Char, Byte  %d: %02X\n", i, ptr[i]);
    }

    //Going through integer1
    ptr = (unsigned char *)&integer1;
    for(i=0;i<sizeof(short int); i++){
        printf("Short Int, Byte  %d: %02X\n", i, ptr[i]);
    }

    //Going through integer2
    ptr = (unsigned char *)&integer2;
    for(i=0;i<sizeof(int); i++){
        printf("Int, Byte  %d: %02X\n", i, ptr[i]);
    }

    //Going through integer3
    ptr = (unsigned char *)&integer3;
    for(i=0;i<sizeof(long int); i++){
        printf("Long Int, Byte  %d: %02X\n", i, ptr[i]);
    }

    //Going through f1
    ptr = (unsigned char *)&f1;
    for(i=0;i<sizeof(float); i++){
        printf("Float, Byte %d: %02X\n", i, ptr[i]);
    }

    //Going through f2
    ptr = (unsigned char *)&f2;
    for(i=0;i<sizeof(double); i++){
        printf("Double, Byte  %d: %02X\n", i, ptr[i]);
    }
					
    return 0;
}