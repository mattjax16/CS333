/**
 * Matt Bass
 * CS333
 * Signal Handling Part 1
 * Project 6
 */

#include<stdio.h> 
#include<stdlib.h>
#include<signal.h>

// handles a user created ctrl-C interruption
void handle_sigint(int sig) {
    printf("Interrupted! Caught signal: %d\n", sig); 
    exit(0);
}

//enters an infinite loop
int main() {
    signal(SIGINT, handle_sigint);
    while(1) {
        printf("\nlooping infinitely :)\n");
        wait(1);
    }
    return 0;
}