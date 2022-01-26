/**
 * Matt Bass
 * CS333
 * Taylor
 * Project 8
 * part one
 * task one part 2
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <sys/times.h>
#include <pthread.h>

// thread info struct
typedef struct {
    int *start;
    int len;

} ThreadInfo;

// comparator function for integers
int intcomp(const void *a, const void *b) {
    const int *numA = (const int *)a;
    const int *numB = (const int *)b;

    return (*numA > *numB) - (*numA < *numB); 
}

// display the array
void display(int array[], const void *a) {
    const int *size = (const int *)a;
    for (int i = 0; i < size; i++) {
        printf("%i, ", array[i]);
    }
}

// worker function
void *thread_sort(void *thread_info) {
    ThreadInfo *ti = (ThreadInfo *)thread_info;
    qsort(ti->start, ti->len, 4, intcomp);
}


//function to create an array with random numbers of its same size
int* make_rand_int_arr(int arrSize){
    int *rand_array = (int*)malloc(arrSize*4);
//    srand(0);
    for (int i = 0; i < arrSize; i++) {
        rand_array[i] =(int)(rand()%(arrSize - 0 + 1));
    }
    return rand_array;
}

int main(int argc, char *argv[]) {


    // SETTING CONSTANTS FOR EXPERIMENT
    const long int MAX_ARR_SIZE = 1000000;
    const long int MAX_NUM_THREADS = 50;
    const long int RUNS_PER_SIZE = 1000;
    const long int SIZE_MULT_AMT = 10;



    //may return 0 when not able to detect
//	const auto processor_count = std::thread::hardware_concurrency();


    ///create the CSV file
    //get the current time for the csv file name
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    //make the csv file name
    char csv_file_name[1000000/2];
    sprintf(csv_file_name,"c_t1_stats_%d-%02d-%02d_%02d:%02d:%02d.csv",
            tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday,
            tm.tm_hour, tm.tm_min, tm.tm_sec);
    //get the save dir path
    char save_dir_path[1000000] = "/Users/matthewbass/Documents/School_Colby/Colby/CS333/Project08/Data/" ;
    strcat(save_dir_path,csv_file_name);


    FILE* csv_fp;
    csv_fp = fopen(save_dir_path,"w");







    //printing out the first row for the headers of the csv file
    //set up row for the header
    char headers_row[1000000];

    for (long int numThreads = 1; numThreads <= MAX_NUM_THREADS; numThreads++){
        if(numThreads == 1){
            sprintf(headers_row,"Size, avg time %ld threads(s),", numThreads);
        }
        else{
            char head_str[1000];
            sprintf(head_str,"avg time %ld threads(s),",numThreads);
            strcat(headers_row,head_str);
        }

    }
    strcat(headers_row,"\n");
    fprintf(csv_fp,"%s",headers_row);

    //loop through to the max arr size
    for(long int arrSize = 10; arrSize <= MAX_ARR_SIZE; arrSize = arrSize*SIZE_MULT_AMT){


        //set up row for the size
        char size_row[100000];
        sprintf(size_row,"%ld,", arrSize);

        //loop through the number of threads
        for(long int numThreads = 1; numThreads <= MAX_NUM_THREADS; numThreads++){

            double avg_time = 0;


            //loop through the number of runs per size
            for(long int run_num = 1; run_num <= RUNS_PER_SIZE; run_num++) {


                int *rand_array = make_rand_int_arr(arrSize);

                // display unsorted array
                //printf("Before sorting: \n");
                //display(rand_array, arrSize);

                ThreadInfo ti[numThreads];
                pthread_t thread[numThreads];

                // set array info fields for the different threads
                for (int i = 0; i < numThreads; i++) {
                    int idx = i*arrSize/numThreads;
                    ti[i].start = &rand_array[idx];
                    ti[i].len = arrSize/numThreads;
                }
                    clock_t tStart, tEnd;
                    double totalTime;




                    // start clock
                    tStart = clock();

                    // create threads
                    for (int i = 0; i < numThreads; i++) {
                        pthread_create(&thread[i], NULL, thread_sort, &ti[i]);
                    }

                    // join threads
                    for (int i = 0; i < numThreads; i++) {
                        pthread_join(thread[i], NULL);
                    }

                    // complete sorting
                    qsort(&rand_array[0], arrSize, 4, intcomp);

                    // stop clock
                    tEnd = clock();



                    // calculate total time
                    //totalTime = ((double)(tEnd - tStart))/((double)(CLOCKS_PER_SEC));
                    totalTime = (double)(tEnd - tStart);

                    //add to the average time
                    avg_time += totalTime;
                    //free the rand array
                    free(rand_array);
                }
                //add the average time to the size row
                avg_time = avg_time/RUNS_PER_SIZE;
                char avg_time_str[1000];
                sprintf(avg_time_str,"%f,",avg_time);
                strcat(size_row,avg_time_str);

                printf("%s\n",size_row);
            }

            //output the row
        strcat(size_row,"\n");
        fprintf(csv_fp,"%s",size_row);
        }

    //close the file
    fclose(csv_fp);
    return 0;
}