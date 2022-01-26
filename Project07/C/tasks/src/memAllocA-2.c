/**
 * Matt Bass
 * CS333
 * Project 7
 * memory management in C
 * task a-2
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <time.h>
#include <sys/times.h>
#include "class_timing.h"

//defining a lenth for max string
#define MAXCHAR 100000




int main(int argc, char *argv[]) {


    //malloc to get rid of start up time
    char *rid_prep = (char *) malloc(MAXCHAR);
    free(rid_prep);
    rid_prep = (char *) malloc(MAXCHAR);
    free(rid_prep);
    rid_prep = (char *) malloc(MAXCHAR);
    free(rid_prep);
    rid_prep = (char *) malloc(MAXCHAR);
    free(rid_prep);



    //get the number of sizes the user wants to use
    unsigned long long int size_bound ;
    printf("\nHow many different size memory tests would you like to have? ");
    scanf("%llu",&size_bound);
    printf("You chose a max size of %llu bytes!\n", size_bound);



    //get the number of iterations the user wants to use
    unsigned long long int num_iters;
    printf("\nHow many iterations of each size per memory test would you like to have? ");
    scanf("%llu",&num_iters);
    printf("You chose %llu iterations per memory test!\n\n", num_iters);


    //get the number of iterations the user wants to use
    unsigned long long int num_tests;
    printf("\nHow many iterations of each test would you like to have? ");
    scanf("%llu",&num_tests);
    printf("You chose %llu iterations per memory test!\n\n", num_tests);



    ///create the CSV file
    //get the current time for the csv file name
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    //make the csv file name
    char csv_file_name[MAXCHAR/2];
    sprintf(csv_file_name,"memAl_A-2_statsC_%d-%02d-%02d_%02d:%02d:%02d.csv",
            tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday,
            tm.tm_hour, tm.tm_min, tm.tm_sec);
    //get the save dir path
    char save_dir_path[MAXCHAR] = "/Users/matthewbass/Documents/School_Colby/Colby/CS333/Project07/Data/" ;
    strcat(save_dir_path,csv_file_name);

    /// why is this not printing
    //    printf("filepath : %s", save_dir_path);

    FILE* csv_fp;
    csv_fp = fopen(save_dir_path,"w");

    /// getting the clock speed of the macking
    clock_t clock_speed = sysconf(_SC_CLK_TCK);

    /// set up the headers for csv header
    char headers[MAXCHAR];
    sprintf(headers, "Size (Bytes),");
    for(unsigned long long i = 1; i <= num_tests; i++){
        char runHeader[MAXCHAR];
        sprintf(runHeader,"Round %llu (%llu iter),",i,num_iters);
        strcat(headers,runHeader);
    }
    strcat(headers,"\n");
    //add headers to the csv
    fprintf(csv_fp,"%s",headers);



    // initialize vars
    double start, end;
    double total_time;

    // do every test the appropriate number of times
    for (unsigned long long int size = 1; size <= size_bound; size = size+2048) {

        //set up row for the size
        char size_row[MAXCHAR];
        sprintf(size_row,"%llu,", size);

        for(unsigned long long int i = 0; i < num_tests; i++) {

            start = clock();

            for (int j = 0; j < num_iters; j++) {
                char *mem = (char *) malloc(size);

                free(mem);
            }

            end = clock();

            total_time = ((double) (end - start));


            double avg = ((double) (total_time / ((float) num_iters)));

            ///get the average time
            char avg_time[MAXCHAR/2];
            sprintf(avg_time,"%f,", avg);
            strcat(size_row,avg_time);
        }
        //write the row to the csv
        strcat(size_row,"%\n");
        fprintf(csv_fp,size_row);

        printf("\nRunning Tests: %f %% done ",((double)size/(double)size_bound)*100);
//        printf("\nDone with size %llu",size);
    }

    //close the file
    fclose(csv_fp);
    return 0;
}