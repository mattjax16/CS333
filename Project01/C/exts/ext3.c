/**
* ext3.c
*
* This is a c program for project 1 fo be able to create a bus error
*
* Matt Bass
* 09/01/2021 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
        




int main () {
    
    char *test = "Bus Error";
    test[0] = 'b'; // This will create the bus error
    return 0;

}