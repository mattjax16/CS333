/**
 * Given an array of random integers, sort it in such a way that the even 
 * numbers appear first and the odd numbers appear later. The even numbers 
 * should be sorted in descending order and the odd numbers should be sorted 
 * in ascending order.
 *
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* the comparator funciton used in qsort */
int comparator_bit_and(const void *p, const void *q) {
    // Get the values at the given addresses
    int left_val = *(const int *)p;
    int right_val = *(const int *)q;

    // both odd, put the greater of two first.
    if ((left_val&1) && (right_val&1))
        return (left_val-right_val);

    // both even, put the smaller of two first
    if ( !(left_val&1) && !(right_val&1) )
        return (right_val-left_val);

    // left_val is even, put right_val first
    if (!(left_val&1))
        return -1;

    // left_val is odd, put left_val first
    return 1;
}



/* the comparator funciton used in qsort */
int comparator_mod(const void *p, const void *q) {
    // Get the values at the given addresses
    int left_val = *(const int *)p;
    int right_val = *(const int *)q;
//    return (left_val - right_val);
    // both odd, put the greater of two first.
    if ((left_val%2 ==1) && (right_val%2 ==1))
        return (left_val-right_val);

    // both even, put the smaller of two first
    if ((left_val%2 ==0) && (right_val%2 ==0) )
        return (right_val-left_val);

    // left_val is even, put right_val first
    if ((left_val%2 == 0))
        return -1;

    // left_val is odd, put left_val first
    return 1;
}

\
int main (int argc, char **argv) {
	

     int (*calc)(const int);
    
    //checking that an argument has been provided
    if(argc < 2){
        printf("\nError there needs to be a integer passed in the argument for the version of comparator! \n");
        printf("\n 0 for mod 2 and 1 for bitwise and \n");
        exit(1);
    };
    char meth[4];
    strcpy(meth,argv[1]);
    
    
    
    int ary_size = 100000;
    int ary0[ary_size];
    int ary1[ary_size];
    int ary2[ary_size];
    int ary3[ary_size];
    int ary4[ary_size];

    int size = sizeof(ary0) / sizeof(int);

    for (int i = 0; i < size; i++) {
        ary0[i] = rand() % 100;
        ary1[i] = rand() % 100;
        ary2[i] = rand() % 100;
        ary3[i] = rand() % 100;
        ary4[i] = rand() % 100;
        
    }
	

	

    if( strcmp(meth, "mod") == 0) {
        printf("\nPreforming Qsort with MOD\n");
        qsort((void *) ary0, size, sizeof(int), comparator_mod);
        qsort((void *) ary1, size, sizeof(int), comparator_mod);
        qsort((void *) ary2, size, sizeof(int), comparator_mod);
        qsort((void *) ary3, size, sizeof(int), comparator_mod);
        qsort((void *) ary4, size, sizeof(int), comparator_mod);
    }
    else if( strcmp(meth,"bit") == 0 )
    {
        printf("\nPreforming Qsort with BIT AND\n");
        qsort((void *) ary0, size, sizeof(int), comparator_bit_and);
        qsort((void *) ary1, size, sizeof(int), comparator_bit_and);
        qsort((void *) ary2, size, sizeof(int), comparator_bit_and);
        qsort((void *) ary3, size, sizeof(int), comparator_bit_and);
        qsort((void *) ary4, size, sizeof(int), comparator_bit_and);
    }
    else{
        printf("\nError method needs to be mod or bit\n");
        exit(1);
    }
	
//	printf("The sorted array is: ");
//	for (int i = 0; i < size; i++) {
//		printf("%d ", ary[i]);
//	}
//	printf("\n");
	
	return 0;
}