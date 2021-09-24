/**
* ext4.c
*
* This is a c program for project 1 fo be able to create a segmentation faullt
*
* Matt Bass
* 09/01/2021 
*/

#include <stdio.h>
#include <stdlib.h>


int main () {
    
    int *x = NULL;  // x is a null pointer
    int y = *x;     // CRASH: dereference x, trying to read it 
    // seg fault

    return 0;
}