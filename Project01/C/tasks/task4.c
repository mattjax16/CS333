/**
* task4.c
*
* This is a c program for project 1 Q3
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

struct Q4Struct
{
    /* data */
    short age;
    float gpa;
    char name[17];
    short name_overflow;

};


int main (int arg, char *argv[]) {
    
    
    struct Q4Struct Q4Struct1;
    
    //Assigning specifications of the struct
    strcpy(Q4Struct1.name , "Joe Moore");
    Q4Struct1.age = 19;
    Q4Struct1.gpa = 3.58;
    Q4Struct1.name_overflow = 1;

    
     


    int i; //declaring an int for the loop
    unsigned char *ptr;// Declaring the Pointer 
    
    //Going through the struct
    ptr = (unsigned char *)&Q4Struct1;//assigning the memory address of c1 to the pointer
    
    //printinf the size of the struct
    printf("This size of the Struct is %lu\n", sizeof(Q4Struct1));

    for(i=0;i<sizeof(Q4Struct1); i++){
        printf("Q4Struct1, Byte %d: %02X\n", i, ptr[i]);
    }

				
    return 0;
}