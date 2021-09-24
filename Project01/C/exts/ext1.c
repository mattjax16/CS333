/**
* ext1.c
*
* This is a c program for project 1 fo be able to input values into the struct from 
* the 
*
* Matt Bass
* 08/31/2021 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
        
/* A script to make a struct with an odd number of bits
and then have to long of a string so that it overwrites the null byte

The string for this struct willbe takin in by an argument when running the
script
 */ 


/*
making the struct
*/

struct EXT1Struct
{
    /* data */
    char name[17];
    short  age;
    float gpa;
    short name_overflow;

};


int main (int arg, char *argv[]) {
    
    //checking that an argument has been provided
    if(arg < 2){
        printf("Error there needs to be a string passed in the argument for the struct! \n");
        exit(1);
    };

    //initilizing the extension struct
    struct EXT1Struct EXT1Struct1;
    
    //Assigning specifications of the struct
    strcpy(EXT1Struct1.name , argv[1]);//16 chars to make it just safe
    EXT1Struct1.age = 19;
    EXT1Struct1.name_overflow = 0;
    EXT1Struct1.gpa = 3.58;
     


    int i; //declaring an int for the loop
    unsigned char *ptr;// Declaring the Pointer 
    
    //Going through the struct
    ptr = (unsigned char *)&EXT1Struct1;//assigning the memory address of c1 to the pointer
    
    //printinf the size of the struct
    printf("This size of the Struct is %lu\n", sizeof(EXT1Struct1));

    for(i=0;i<sizeof(EXT1Struct1); i++){
        printf("EXT1Struct, Byte %d: %02X\n", i, ptr[i]);
        if(i == 19 && ptr[i] == 00){
            printf("\nSafe!!!\n");
        }
        else if(i == 19 && ptr[i] != 00){
            printf("\nHacked!!!\n");
        }
    }
				
    return 0;
}