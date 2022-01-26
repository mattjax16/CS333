/**
 * Matt Bass
 * CS333
 * Taylor
 * Project 8
 * part one
 * task two
 */

#include <stdio.h>
#include <stdlib.h>
#include "ppmIO.h"
#include <time.h>
#include <pthread.h>
#include <string.h>

// thread info struct
typedef struct {
    Pixel *src;
    int start;
    int len;

} ThreadInfo;

// worker function
void *thread_apply(void *thread_info) {
    ThreadInfo *ti = (ThreadInfo *)thread_info;
    int origin = ti->start;
    int extent = ti->len;
    // loop over thread's section
    for (int i = origin; i < (origin + extent); i++) {
		ti->src[i].r = ti->src[i].r > 128 ? (220+ti->src[i].r)/2 : (30+ti->src[i].r)/2;
		ti->src[i].g = ti->src[i].g > 128 ? (220+ti->src[i].g)/2 : (30+ti->src[i].g)/2;
		ti->src[i].b = ti->src[i].b > 128 ? (220+ti->src[i].b)/2 : (30+ti->src[i].b)/2;
	}
}

int main(int argc, char *argv[]) {
    Pixel *src;
	int rows, cols, colors;
    clock_t tStart, tEnd;
    double totalTime;


    char* entered_file_name = malloc(sizeof(char));
    char file_name_char;
    int file_name_len;

    //prompt for user to enter file name
    printf("Enter the Absolute file path of the img you want to distort: ");

    //keep going while a character is successfully being scanned
    while(scanf("%c", &file_name_char)==1)
    {
        //if there is a line break stop the looping
        if(file_name_char== '\n')
            break;

        // update the file name len
        file_name_len = strlen(entered_file_name);

        //reallocate the space for the file name
        entered_file_name= realloc(entered_file_name,
                                   file_name_len+1);

        //update the file name string
        *(entered_file_name+file_name_len) = file_name_char;

        //adding null space at end of file_name_string
        *(entered_file_name+file_name_len+1) = '\0';
        //or  can be done by memset
        //memset(*(entered_file_name+file_name_len+1),1,'\0');
    }

    // read the image
    src = ppm_read( &rows, &cols, &colors, entered_file_name );

    // alert if failed
	if( !src ) {
		printf("Unable to read file %s\n", entered_file_name);
		exit(-1);
	}


    
    



    int numThreads;
    printf("\nPlease Enter the number of threads you want: ");
    scanf("%d", &numThreads);

    char color_file_name[10000];
    char color_file_help[100];
    strcpy(color_file_name, entered_file_name);
    sprintf(color_file_help,"_%d_colorized.ppm",numThreads);
    strcat(color_file_name, color_file_help);

    int N = rows*cols;
    ThreadInfo ti[numThreads];
    pthread_t thread[numThreads];

    // set thread info fields
    for (int i = 0; i < numThreads; i++) {
        ti[i].src = src;
        ti[i].start = i*N/numThreads;
        ti[i].len = N/numThreads;
    }

    // start clock
    tStart = clock();

    // create threads
    for (int i = 0; i < numThreads; i++) {
        pthread_create(&thread[i], NULL, thread_apply, &ti[i]);
    }

    // join threads
    for (int i = 0; i < numThreads; i++) {
        pthread_join(thread[i], NULL);
    }

    // stop clock
    tEnd = clock();

    // calculate total time
    totalTime = ((double)(tEnd - tStart))/((double)(CLOCKS_PER_SEC));

    // print results
    printf("\nIt took %f seconds to colorize the image with %i threads.\n", totalTime, numThreads);

    // write image to file
    ppm_write( src, rows, cols, colors,  color_file_name);

    free(entered_file_name);
    free(src);

    return 0;
}