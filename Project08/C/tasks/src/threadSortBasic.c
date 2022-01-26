/**
 * Matt Bass
 * CS333
 * Taylor
 * Project 8
 * part one
 * task one
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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

int main(int argc, char *argv[]) {


    // getting the desired size of the array
    int arrSize;
    printf("\nPlease Enter the amount of numbers you want in the array: ");
    scanf("%d", &arrSize);


    int numThreads;
    printf("\nPlease Enter the number of threads you want: ");
    scanf("%d", &numThreads);

    //may return 0 when not able to detect
//	const auto processor_count = std::thread::hardware_concurrency();

    int *my_array = (int*)malloc(arrSize*4);
    srand(0);
    for (int i = 0; i < arrSize; i++) {
        my_array[i] = (rand()%(100 - 0 + 1)) + 0;
    }

    // display unsorted array
    printf("Before sorting: \n");
    display(my_array, arrSize);

    clock_t tStart, tEnd;
    double totalTime;
    int N = arrSize;


    ThreadInfo ti[numThreads];
    pthread_t thread[numThreads];

    // set array info fields for the different threads
    for (int i = 0; i < numThreads; i++) {
        int idx = i*N/numThreads;
        ti[i].start = &my_array[idx];
        ti[i].len = N/numThreads;
    }

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
    qsort(&my_array[0], arrSize, 4, intcomp);

    // stop clock
    tEnd = clock();

    // print sorted aray
    printf("\nAfter sorting: \n");
    display(my_array, arrSize);

    // calculate total time
    totalTime = ((double)(tEnd - tStart))/((double)(CLOCKS_PER_SEC));

    // print results
    printf("\nIt took %f seconds to sort the array of size: %i with %i threads.\n", totalTime, arrSize, numThreads);

    free(my_array);

    return 0;
}