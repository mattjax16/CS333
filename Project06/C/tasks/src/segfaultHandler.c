/**
 * Matt Bass
 * CS333
 * Signal Handling Part 3
 * Project 6
 */

#include<stdio.h>
#include<stdlib.h>
#include<signal.h>

// handles segmentation fault
void handle_sigsegv(int sig) {
    printf("\nInterrupted! Caught segmentation fault: %d\n", sig);
    exit(0);
}

//creates segmentation fault by attempting to illegaly access memory
int main() {
    signal(SIGSEGV, handle_sigsegv);
    *(int*)0 = 0;
    return 0;
}