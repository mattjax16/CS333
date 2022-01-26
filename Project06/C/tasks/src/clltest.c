/*
	Bruce Maxwell
	Fall 2012
	CS 333

	Linked list test function
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Linkedlist.h"





// function that squares an integer
void squareInt(void *i) {
	int *a = (int *)i;

	*a = *a * *a;
}


// test function for the various linked list functions
int main(int argc, char *argv[]) {
	LinkedList* l;
	int* a;
	int* target, index;
	int i;

	// create a list
	l = ll_create();

	// push data on the list
	for(i=0;i<20;i+=2) {
		a = malloc(sizeof(int));
		*a = i;

		ll_push(l, a);
	}

	// printing the list and testing map
	printf("After initialization\n");
	ll_map(l, printInt);

	ll_map(l, squareInt);

	printf("\nAfter squaring\n");
	ll_map(l, printInt);

	// testing removing data
	target = malloc(sizeof(int));

	*target = 16;
	a = ll_remove(l, target, compInt);
	if(a != NULL)
		printf("\nremoved: %d\n", *a);
	else
		printf("\nNo instance of %d\n", *target);

	
	
	*target = 983;
	
	a = ll_remove(l, target, compInt);
	if(a != NULL)
		printf("\nremoved: %d\n", *a);
	else
		printf("\nNo instance of %d\n", *target);

	printf("\nAfter removals\n");
	ll_map(l, printInt);

	// testing appending data
	ll_append(l, target);

	
	printf("\nAfter append\n");
	ll_map(l, printInt);

    // testing removing data
    target = malloc(sizeof(int));

	// testing insert data
	*target = 1111;

//    index = malloc(sizeof(int));

    //with index that doest work
//    *index = 20;
    index = 20;
	ll_insert(l, target, index);

    printf("\nAfter insert fail\n");
    ll_map(l, printInt);

    //with index that does work
//    *index = 3;
    index = 3;
    ll_insert(l, target,index);

	printf("\nAfter insert success\n");
	ll_map(l, printInt);

    // testing update data
    target = malloc(sizeof(int));
    *target = 322;
    index = 132;

    ll_update(l, target,index);

    index = 4;
    ll_update(l, target,index);

    printf("\nAfter update\n");
    ll_map(l, printInt);


	// test clearing
	ll_clear(l, free);


    printf("\nAfter clear\n");
	ll_map(l, printInt);

	// rebuild and test append and pop
	for(i=0;i<5;i++) {
		a = malloc(sizeof(int));
		*a = i;
		ll_append(l, a);
	}

	printf("\nAfter appending\n");
	ll_map(l, printInt);

	a = ll_pop(l);
	printf("\npopped: %d\n", *a);
	free(a);

	a = ll_pop(l);
	printf("popped: %d\n", *a);
	free(a);

	printf("\nAfter popping\n");
	ll_map(l, printInt);

	printf("\nList size: %d\n", ll_size(l) );





//    making test list with chrs
//    clear the list
    ll_clear(l, free);

    a = malloc(sizeof(char));
    *a = 'a';
    ll_append(l, a);

    a= malloc(sizeof(char));
    *a = 'b';
    ll_append(l, a);

    a= malloc(sizeof(char));
    *a = 'c';
    ll_append(l, a);

    ll_map(l, printChar);

	free(a);

  
//    making test list with strings
   //clear the list
   ll_clear(l, free);
  
    a = malloc(sizeof(char)*4);
    strcpy(a,"How");
    ll_append(l, a);

    a = malloc(sizeof(char)*4);
    strcpy(a,"are");
    ll_append(l, a);

    a = malloc(sizeof(char)*4);
    strcpy(a,"you");;
    ll_append(l, a);
   
   a = malloc(sizeof(char)*6);
    strcpy(a,"doing");
    printf("%s",a);
   ll_append(l, a);

    a = malloc(sizeof(char)*6);
    strcpy(a,"?");
    ll_append(l, a);

   printf("\nList size with Strings: %d\n", ll_size(l) );
   ll_map(l, printStr);

   free(a);
//   free(index);
//   free(target);
   return(0);
}