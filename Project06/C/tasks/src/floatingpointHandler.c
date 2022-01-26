/**
 * Matt Bass
 * CS333
 * Signal Handling Part 2
 * Project 6
 */

#include<stdio.h>
#include<stdlib.h>
#include<signal.h>

int v1 = 24;
int v2 = 0;

//handles a floating point error
void handle_sigfpe(int sig) {
    printf("\nInterrupted! Caught signal: %d", sig);
    v2 = 2;
}

// creates a floating point error by dividing by zero
int main() {
    int a = -1;
    signal(SIGFPE, handle_sigfpe);
    printf("\nv1 = %i ,v2 = %i", v1,v2);
    
    a = v1/v2;
    printf("\na =v1/v2=%i/%i=%i",v1,v2, a);
    int v2 = 2;
    printf("\ndividing by 2 instead");
    a = v1/v2;
    printf("\na = %i\n", a);

    return 0;
}

