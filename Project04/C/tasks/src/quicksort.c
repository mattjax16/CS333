/**
 * Given an array of random integers, sort it in such a way that the even 
 * numbers appear first and the odd numbers appear later. The even numbers 
 * should be sorted in descending order and the odd numbers should be sorted 
 * in ascending order.
 *
 * Ying Li
 * 08/02/2016
 */

#include <stdio.h>
#include <stdlib.h>

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

int main (int argc, char **argv) {
	int ary[] = {10, 11, 1, 8, 9, 0, 13, 4, 2, 7, 6, 3, 5, 12};
	
	int size = sizeof(ary) / sizeof(int);
	
	qsort((void *) ary, size, sizeof(int), comparator_mod);
	
	printf("The sorted array is: ");
	for (int i = 0; i < size; i++) {
		printf("%d ", ary[i]);
	}
	printf("\n");
	
	return 0;
}