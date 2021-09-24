/**
* ext5.c
*
* This is a c program for project 1 fo be able to create a run time error creating a number bigger 
than data type of short creating a wrong result
*
* Matt Bass
* 09/01/2021 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
    
    short int a = 1000;

    short int b = a*a;

    printf("%d * %d = %d \n",a,a,b);
    
    return 0;
}   