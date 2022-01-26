//
// Created by Matthew Bass on 1/02/22.
//

#ifndef PROJECT06_WORDCOUNTER_H
#define PROJECT06_WORDCOUNTER_H

#include <stdio.h>
#include "Linkedlist.h"
#include <ctype.h>




/*
 * Functions for word count struct
 */

typedef struct wordCountData {

    char* word;
    int count;
    
}wordCountData;

//creates a new wordCount struct, initializes it with a count of 0
// and returns it
wordCountData* wc_data_create(char* new_word);

//compare functions for word count data word value
// returns based off of compStr
int compWCdataWord(void* a,void* b);

//compare functions for word count data word value
// returns based off of compInt
int compWCdataCount(void* a,void* b);


/*
 * Functions for wordCounter
 */
typedef struct wordCounter {

    LinkedList* word_count_list;
    char* file_name;
    int unique_words;
    int total_words;

}wordCounter;


//creates a new wordCounter struct, initializes it, and returns it
wordCounter* wc_create();

//updates the file name for the wordCounter
int updateWCfile(wordCounter* wc, char* new_file_name);

//function to add a word to the word counter
void addWord(wordCounter* wc, char *word);


//function to add a word to proper spot the word counter
// the higher the count the more of the start of the list it is
void addWordInPos(wordCounter* wc, wordCountData *wcd);


// function that prints a word count data
void printWCD(void *i);

/*
 * Functions to run word counter
 */


//Function to print out the top so many words in the word counter
void printTopWords(wordCounter* wc, int top_ammount);


//function to run the wordCounter with user input
void userRunWC(wordCounter* wc);




//main function to run the wordCounter with user input
void runWC(wordCounter* wc);









#endif //PROJECT06_WORDCOUNTER_H
