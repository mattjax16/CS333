//
//    Matthew Bass
//	Winter 2021
//	CS 333
//
//	WordCounter test function
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Linkedlist.h"
#include "WordCounter.h"


// test function for the various WordCounter functions
int main(int argc, char *argv[]) {


    //initilizing a word counter
    wordCounter* wc = wc_create();

    //testing user run wordCounter
    userRunWC(wc);

    return 0;
 }