/**
* ext5.c
*
* This is a c program for project 1 fo be able to create a run time error by creating a trace trap
*
* Matt Bass
* 09/01/2021 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
    
    char name[12] = "Matt";
    char greeting[] = "hello";
    strcpy(greeting, "greetings, "); 
    printf("%s%s\n", greeting, name);
    return 0;
}   