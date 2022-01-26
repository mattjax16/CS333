/**
 * incrementb.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#define NUM_THREADS 10

/* create thread argument struct for thr_func() */
typedef struct _thread_data_t {
    int tid;
} thread_data_t;
/* shared data between threads */
int shared_x;

void *thr_func(void *arg) {
    thread_data_t *data = (thread_data_t *)arg;
    printf("hello from thr_func, thread id: %d\n", data->tid);
    sleep(1);
    shared_x++;
    printf("x = %d\n", shared_x);
    pthread_exit(NULL);
}
int main(int argc, char **argv) {
    pthread_t thr[NUM_THREADS];
    int i, rc;
    /* create a thread_data_t argument array */
    thread_data_t thr_data[NUM_THREADS];
    /* initialize shared data */
    shared_x = 0;
    /* create threads */
    for (i = 0; i < NUM_THREADS; ++i) {
        thr_data[i].tid = i;
        if ((rc = pthread_create(&thr[i], NULL, thr_func, &thr_data[i]))) {
            fprintf(stderr, "error: pthread_create, rc: %d\n", rc);
            return EXIT_FAILURE;
        }
    }
    /* block until all threads complete */
    for (i = 0; i < NUM_THREADS; ++i) {
        pthread_join(thr[i], NULL);
    }
    return EXIT_SUCCESS;
}