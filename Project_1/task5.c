/**
* task5.c
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
and then have to long of a string so that it overwrites the null byte
 */ 


/*
making the struct
*/

struct Q5Struct
{
    /* data */
    char name[17];
    short  age;
    float gpa;
    short name_overflow;

};


int main (int arg, char *argv[]) {
    
    
    struct Q5Struct Q5Struct1;
    
    //Assigning specifications of the struct
    strcpy(Q5Struct1.name , "Joe Moore Adam 2");//16 chars to make it just safe
    Q5Struct1.age = 19;
    Q5Struct1.name_overflow = 0;
    Q5Struct1.gpa = 3.58;
     


    int i; //declaring an int for the loop
    unsigned char *ptr;// Declaring the Pointer 
    
    //Going through the struct
    ptr = (unsigned char *)&Q5Struct1;//assigning the memory address of c1 to the pointer
    
    //printinf the size of the struct
    printf("This size of the Struct is %lu\n", sizeof(Q5Struct1));

    for(i=0;i<sizeof(Q5Struct1); i++){
        printf("Q5Struct1, Byte %d: %02X\n", i, ptr[i]);
        if(i == 19 && ptr[i] == 00){
            printf("\nSafe!!!\n");
        }
        else if(i == 19 && ptr[i] != 00){
            printf("\nHacked!!!\n");
        }
    }


    //now a hacked one (one that is to long and 
    // overwrites the strings null splace)
    struct Q5Struct Q5Struct2;
    
    //Assigning specifications of the struct
    strcpy(Q5Struct2.name , "Joe Moore Adam 2d");//17 characters but reall 18 to over sized
    Q5Struct2.age = 19;
    Q5Struct2.gpa = 3.58;
    Q5Struct2.name_overflow = 0;
     
    // running this code crashed before I even go through the bytes cant do the second part
    // //printing to see if the name_overflow was overwrittern
    // printf("name_overflow val: %u\n",Q5Struct2.name_overflow);
    
    //Going through the struct
    ptr = (unsigned char *)&Q5Struct2;//assigning the memory address of c1 to the pointer
    
    //printinf the size of the struct
    printf("This size of the Struct is %lu\n", sizeof(Q5Struct2));

    for(i=0;i<sizeof(Q5Struct2); i++){
        printf("Q4Struct2, Byte %d: %02X\n", i, ptr[i]);
        if(i == 24 && ptr[i] == 00){
            printf("\nSafe!!!\n");
        }
        else if(i == 24 && ptr[i] != 00){
            printf("\nHacked!!!\n");
        }
    }

				
    return 0;
}