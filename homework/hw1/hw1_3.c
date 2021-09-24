/**
* hw1_3.c
*
* This is a c program for hw 1 q3 meant to demonstrate 
that addition in C with floating point numbers is not associative (in
the mathematical sense). The following two statements should print
different numbers.
*
* Matt Bass
* 09/16/2021
*/

#include <stdio.h>
#include <stdlib.h>


/* A function to find the largest int a float can hold
 */
float find_largest_flt(){
    float a;

    a = 0.0;

    for(;;){
        a = a + 1;
        if(a + 1 ==a){
            return a;
        }
    }
}


int main () {
					

    float  a,b,c,r1,r2,r3;

    a = find_largest_flt() * -1;
    b = find_largest_flt();
    c = 1.0;

    r1 = (a + b) + c ;
    r2 = a + (b + c);
    r3 = a + b + c;




    printf( "The largest integer a float can hold is %0.16f\n", find_largest_flt());
    printf( "(a + b) + c = %0.16f\n", r1);
    printf( "a + (b + c) = %0.16f\n", r2);
    printf( "a + b + c = %0.16f\n", r3);

    return 0;
}