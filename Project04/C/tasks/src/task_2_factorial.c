/**
* different ways to calc a factorial
 *
 * Matt Bass
 * 11/03/2021
 */

#include <stdio.h>
#include <stdlib.h>

int factorial_for(int n){

    int fact = 1;
    for (int i = 1; i <= n; ++i) {
        fact *= i;
    }
    return fact;
}

int factorial_rec(int n){

    if (n == 0)
        return 1;
    return n * factorial_rec(n - 1);
}


int factorial_while(int n){

    int fact = 1;
    int i = 1;
    while (i <= n) {
        fact *= i;
        ++i;
    }
    return fact;
}

int main (int argc, char **argv) {

    
    //checking that an argument has been provided
    if(argc < 2){
        printf("\nError there needs to be a integer passed in the argument for the factorial! \n");
        exit(1);
    };

    int n = atoi(argv[1]);

    // check that int passed >= 0
    if(n < 0){
        printf("Error the intrger needs to  be >= for the factorial! \n Currently it is: %d \n",n);
        exit(1);
    };

    int (*calc)(const int);
    calc = factorial_rec;


    int fact = calc(n);

    printf("Factorial of %d is %d \n\n", n, fact);

    return 0;

//    breaks at factorial 13 because it really is 6227020800 and the max number and int can hold is
// 2,147,483,647 but it is showing 1932053504 for a factorial of 13
}