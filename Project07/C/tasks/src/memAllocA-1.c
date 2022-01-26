/**
 * Matt Bass
 * CS333
 * Project 7
 * memory management in C
 * task a-1
 */

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "class_timing.h"



int main(int argc, char *argv[]) {

    //get the number of sizes the user wants to use
    int num_dif_sizes;
    printf("\nHow many different size memory tests would you like to have? ");
    scanf("%d",&num_dif_sizes);
    printf("You chose %d different sizes!\n", num_dif_sizes);

    //get the sizes from the user
    unsigned long long int* sizes = (unsigned long long int*) malloc(num_dif_sizes*sizeof(unsigned long long int));

    for(int i=0; i<num_dif_sizes; i++){

        printf("\n How many bytes would you like for size %d?  ", i+1);
        scanf("%llu",&sizes[i]);
    }


    //get the number of iterations the user wants to use
    unsigned long long int num_iters;
    printf("\nHow many different interations of each memory test would you like to have? ");
    scanf("%llu",&num_iters);
    printf("You chose %ld iterations!\n\n", num_iters);



    // initialize vars
    double start, end, start2, end2;
    double total_time,total_time2;

    // test every size input
    for (int i = 0; i < num_dif_sizes; i++) {

        unsigned long long int size = sizes[i];

        start = clock();
//        start2= get_time_nsec();
        for (int j = 0; j < num_iters; j++) {
            char *mem = (char*)malloc(size);
            free(mem);
        }
//        end2= get_time_nsec();
        end = clock();

        total_time = ((double)(end-start));
        total_time2 = ((double)(end2-start2));

        double avg = ((double)(total_time/((float)num_iters)));
//        double avg2 = ((double)(total_time2/((float)num_iters)));

//        printf("average time to allocate memory size %i: %f , %f\n", size, avg,avg2);
        printf("average time to allocate memory size %i: %f\n", size, avg);
    }
    return 0;
}