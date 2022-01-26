
#include <stdio.h>
#include <pthread.h>
#define NUM_THREADS 50
typedef struct {
    int id;
} threadInfo;
void *hello_thread(void *threadinfo) {
    threadInfo *ti = (threadInfo *) threadinfo;
    printf("Thread %d saying Hello!\n", ti->id);
    pthread_exit(NULL);
}
int main () {
    int i;
    threadInfo ti[NUM_THREADS];
    pthread_t thread[NUM_THREADS];
    // Set up the parameters for each thread
    for (i = 0; i < NUM_THREADS; i++)
        ti[i].id = i;
    // Get the threads going
    for (i = 0; i < NUM_THREADS; i++)
        pthread_create(&(thread[i]), NULL, hello_thread, &(ti[i]));
    // Join up with them. This will wait until they are done.
    for (i = 0; i < NUM_THREADS; i++)
        pthread_join(thread[i], NULL);
    return 0; }