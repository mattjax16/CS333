//
// Created by Matthew Bass on 8/31/21.
// These are the functions in the notes
// A Brief Into To C
//

/**
 * File: File Name followed by a short description of the program
 * Author: Your Name
 * Date: MM/DD/YYYY
 */
#include <stdio.h>
#include <stdlib.h>
/* A short description of the function, if necessary
 */
int example_1 (int args, char *argv[]) {

    int courseNum = 333;

    printf("Welcome to CS %d! \n", courseNum);

// Integer types
    char c1;
    unsigned char c2;
    short int integer1;
    int integer2;
    long int integer3;

// Float types
    float f1;
    double f2;

// Pointer types
    unsigned char *ptr;
    ptr = (unsigned char *)&c1; // the symbol & means "address of"
    printf("The pointer points to an address with %u in it.\n", *ptr);

// malloc: initialize pointers with memory
    ptr = (unsigned char *) malloc(sizeof(unsigned char));
    // free: return memory
    free(ptr);

    ptr = (unsigned char *) malloc(sizeof(*ptr));
    free(ptr);

    return 0;
}



/**
 * Array in C
 * array.c
 */
int example_2 () {
    int i;
    int a[5];

    for (i = 0; i < 5; i++) {
        a[i] = i * 10;
    }

    for (i = 0; i < 5; i++) {
        printf("%d ", a[i]);
    }

    printf("\n");

    int *b;
    b = malloc(5 * sizeof(int));

    for (i = 0; i < 5; i++) {
        *(b+i) = i * 100;
    }

    for (i = 0; i < 5; i++) {
        printf("%d ", *(b+i));
    }
    free(b);

    return 0;
}


/**
 * Print the whole string including the end character
 * str.c
 */
int example_3 (int argc, char *argv[]) {
    char string[] = "Hello world!";

    int i = sizeof(string)/sizeof(char);
    printf("size of the string: %d\n", i);

    for (int j = 0; j < i; j++) {
        printf("%d ", string[j]);
    }
    printf(“\n");
    return 0;
}