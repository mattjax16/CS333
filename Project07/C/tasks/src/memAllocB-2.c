/**
 * Matt Bass
 * CS333
 * Project 7
 * memory management in C
 * task b
 */

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


//defining a lenth for max string
#define MAXCHAR 100000

int main(int argc, char *argv[]) {



    //get the number of sizes the user wants to use
    unsigned long long int size_bound ;
    printf("\nHow many different size memory tests would you like to have? ");
    scanf("%llu",&size_bound);
    printf("You chose a max size of %llu bytes!\n", size_bound);



    //get the number of interations the user wants to use
    unsigned long long int num_iters;
    printf("\nHow many different iterations of each memory test would you like to have? ");
    scanf("%llu",&num_iters);
    printf("You chose %ld iterations!\n\n", num_iters);


    //get the number of interations per average the user wants to use
    unsigned long long int iter_per_block;
    printf("\nHow many iterations per block would you like to have? ");
    scanf("%llu",&iter_per_block);
    if(iter_per_block<=0 || iter_per_block > num_iters){
        printf("\nError iterations per block must be greater than 0 and less than %llu! Currently it is %llu!\n"
                ,num_iters,iter_per_block);
        exit(0);
    }
    else if(num_iters%iter_per_block != 0){
        printf("\nError iterations per block (%llu) must be divisor of num_iters(%llu) \n"
                ,iter_per_block,num_iters);
        exit(0);
    }
    printf("You chose %llu iterations per block!\n\n", iter_per_block);



    ///create the CSV file
    //get the current time for the csv file name
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    //make the csv file name
    char csv_file_name[MAXCHAR/2];
    sprintf(csv_file_name,"memAl_B_2_statsC_%d-%02d-%02d_%02d:%02d:%02d.csv",
            tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday,
            tm.tm_hour, tm.tm_min, tm.tm_sec);
    //get the save dir path
    char save_dir_path[MAXCHAR] = "/Users/matthewbass/Documents/School_Colby/Colby/CS333/Project07/Data/" ;



    strcat(save_dir_path,csv_file_name);

    /// why is this not printing
    //    printf("filepath : %s", save_dir_path);

    FILE* csv_fp;
    csv_fp = fopen(save_dir_path,"w");





    /// set up the headers for csv header
    char headers[MAXCHAR] = "Size (bytes),";
    for(int i = 1; i <=  (num_iters/iter_per_block); i++){
        char itercount[MAXCHAR];
        sprintf(itercount,"round %d (%llu iters) avg time,",i,i*iter_per_block);
        strcat(headers,itercount);
    }
    strcat(headers,"\n");
    //add headers to the csv
    fprintf(csv_fp,"%s",headers);




    //set vars
    double start, end;
    double avg_elapsed_time;



    //test every command line size input
    for ( unsigned long long int size = 0; size < size_bound; size= size+1024*2) {



        //set up row for the size
        char size_row[MAXCHAR];
        sprintf(size_row,"%llu,", size);

//        printf("\nNow testing allocating memory of size %i:\n", size);
        start = clock();
        for (int j = 1; j < num_iters; j++) {
            char *mem = (char*)malloc(size);
            free(mem);
            if (j%iter_per_block == 0) {
                end = clock();
                avg_elapsed_time = ((double)((end-start)/(float)iter_per_block));

                ///get the avg time
                char avg_time[100];
                sprintf(avg_time,"%f,",avg_elapsed_time);
                strcat(size_row, avg_time);
                start = clock();
            }
        }
        ///finish writing the row and add it to csv
        strcat(size_row, "\n");
        fprintf(csv_fp,size_row);
        printf("\nRunning Tests: %f %% done ",((double)size/(double)size_bound)*100);
    }


    ///close the file
    fclose(csv_fp);
    return 0;
}