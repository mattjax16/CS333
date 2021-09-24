/**
* ext2.c
*
* This is a c program for project 1 fo be able to fiind a floatng point number
* that I can add 1 to and get back the same number
*
* Matt Bass
* 09/01/2021 
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
    
    float a,b,result1; //declaring floats

    a=find_largest_flt(); //setting a to the largest float so when 1 
                        // is added the value won;t chante
    
    b = 1;

    result1 = a + b;

    
    printf( "The largest integer a float can hold is %0.1f\n", a);
    printf( "%0.1f + %0.1f = %0.1f\n", a , b, result1 );
    
				
    return 0;
}