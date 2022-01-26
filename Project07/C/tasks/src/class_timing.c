//
// Created by Matthew Bass on 1/11/22.
//
// This is code for a timing function provided in class cs333
//

#include <sys/time.h> // for get_time_second
#include <time.h>
#include "class_timing.h"

//Returns the time in seconds (double)
double get_time_sec(){
    struct timeval t;
    struct timezone tzp;
    gettimeofday(&t,&tzp);
    return t.tv_sec + t.tv_usec*1e-6;
}

//Returns the time in seconds (double)
double get_time_nsec(){
    struct timespec t;
    clock_gettime(CLOCK_MONOTONIC, &t);
    return t.tv_nsec;
}