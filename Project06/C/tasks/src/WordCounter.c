//
// Created by Matthew Bass on 1/6/22.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Linkedlist.h"
#include "WordCounter.H"





/*
 * Functions for word count struct
 */
//creates a new wordCount struct, initializes it with a count of 1
// and returns it
wordCountData* wc_data_create(char* new_word){
    wordCountData* wc_data = (wordCountData*)malloc(sizeof(wordCountData));

    wc_data->word = new_word;
    wc_data->count = 1;
    return wc_data;
}

//compare functions for word count data word value
//returns 0 if they are equal
// < 0 if the first string is of lower value than the second
// > 0 if the other way around
int compWCdataWord(void* a,void* b){
    wordCountData* wcd1 = (wordCountData*)a;
    wordCountData* wcd2 = (wordCountData*)b;

    int ret = strcmp(wcd1->word, wcd2->word);
    return ret;

}

//compare functions for word count data count value
// returns based off of compInt
int compWCdataCount(void* a,void* b){
    wordCountData* wcd1 = (wordCountData*)a;
    wordCountData* wcd2 = (wordCountData*)b;

    if(wcd1->count == wcd2->count){
        return 0;
    }
    else if (wcd1->count < wcd2->count){
        return -1;
    }
    else{
        return 1;
    }
}

// function that prints a word count data
void printWCD(void *i) {
    wordCountData* wcd = (wordCountData*)i;

    printf("\nWord: %s   Count: %d", wcd->word,wcd->count);
}

/*
 * Functions for wordCounter
 */

//creates a new valueCounter struct, initializes it, and returns it
wordCounter* wc_create(){
    wordCounter* wc = (wordCounter*)malloc(sizeof(wordCounter));
    wc->file_name = NULL;
    wc->word_count_list = ll_create();
    wc->unique_words = 0;
    wc->total_words = 0;
    return wc;
}


//updates the file name for the wordCounter
int updateWCfile(wordCounter* wc, char* new_file_name){

    //TODO checking that file name is valid

    wc->file_name = new_file_name;
    return 1;
}


//function to add a word to the word counter
void addWord(wordCounter* wc, char *word){


    //create new wordcount data to be compared
    wordCountData* word_added = wc_data_create(word);

    // seeing if the word is in the list and getting its index
    int pos_of_word = ll_contains(wc->word_count_list,
                                  word_added,compWCdataWord);

    //if the word is already in the word counter increment the count by 1
    if(pos_of_word > -1){

        //remove the wc_data from the counter
//        free(word_added);


        word_added = (wordCountData*) ll_remove(wc->word_count_list,
                                                word_added,compWCdataWord);

        //increment the count by 1
        word_added->count++;

        //add the word back into the list
//        ll_insert(wc->word_count_list,word_added,pos_of_word);



//        addWordInPos(wc->word_count_list,word_added);
        addWordInPos(wc,word_added);
        //increment total words by 1
        wc->total_words++;


    }
    //if the word is not in the word list already add it to the list
    else {


        ll_append(wc->word_count_list, word_added);

        //increment unique words by 1
        wc->unique_words++;

        //increment total words by 1
        wc->total_words++;


    }
}


//function to add a word to proper spot the word counter
// the higher the count the more of the start of the list it is
void addWordInPos(wordCounter* wc, wordCountData *wcd){

    int index = 0;
    Node* curr = wc->word_count_list->head;

    while(compWCdataCount(curr->data,wcd) >= 0){
        curr = curr->next;
        index++;
    }

    ll_insert(wc->word_count_list, wcd, index);
}


/*
 * Functions to run word counter
 */


//Function to print out the top so many words in the word counter
void printTopWords(wordCounter* wc, int top_ammount){

    Node *curr = wc->word_count_list->head;

    for(int i = 0; i<=top_ammount;i++){

        wordCountData *wcd = (wordCountData*)(curr->data);
        printf("\nWord: %s   Count: %d", wcd->word,wcd->count);

        curr=curr->next;
    }
}

//function to run the wordCounter with user input
void userRunWC(wordCounter* wc){

    /* Getting the file name the user wants to Use
     * This code is written so that the file name can be of any length
     * The idea of how to intake a string of any length was found here
     * https://www.quora.com/How-can-I-take-a-string-input-from-user-without-asking-for-size-of-array-in-C
     *
     * This really helped me better understand realloc function in c*/

    char* entered_file_name = malloc(sizeof(char));
    char file_name_char;
    int file_name_len;

    //prompt for user to enter file name
    printf("Enter the Absolute file path of the file whose word count you want: ");

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

    //update the file name
    updateWCfile(wc,entered_file_name);

    /*TODO add debugging    printf("The entered file name is: %s!",wc->file_name);
    * printf("The entered file name is: %s!",wc->file_name);*/

    //running the word counter
    runWC(wc);
}





//main function to run the wordCounter with user input
void runWC(wordCounter* wc){

    //initilizing the variables
    FILE* read_file_ptr;

    //opening file
    read_file_ptr = fopen(wc->file_name, "r");

    // if the file is not found
    if (read_file_ptr == NULL){
        printf("\nERROR the file, %s , can not be found!!\n", wc->file_name);
    }
    else{
        printf("\nSUCCESS the file, %s , has can been found!!\n", wc->file_name);
    }


    //reading in the words now
    char* file_word = malloc(sizeof(char));
    char file_word_char;
    int file_word_len = 0;

    //keep scanning the file while there is a character
    while((file_word_char = fgetc(read_file_ptr))!=(-1)){




        //making the character lower case
        file_word_char = tolower(file_word_char);

        /*checking that the character is a letter if not make
         * it a new word and add it to the word counter */
        if(isalnum(file_word_char) == 0){

            //adding null space at end of file_name_string
            *(file_word+file_word_len+1) = '\0';

            //add the word to the file
            if(file_word_len > 0){
                //add the word to the word counter
                addWord(wc,file_word);
            }

            //reset the file word len and malloc a new piece of memory
            file_word_len = 0;
            file_word = malloc(sizeof(char));
        }

        //else if it is a letter keep adding it to the file_word string
        else{
            // update the file word len
            file_word_len++;

            //reallocate the space for the file word
            file_word= realloc(file_word,file_word_len+1);

            //seeing if realloc failed
            if(file_word == NULL){
                printf("Error realloc for word failed!!");
            }

            //update the file word string
            *(file_word+file_word_len-1) = file_word_char;
        }
    }

    //close the file pointer
    fclose(read_file_ptr);

    //once all the words have been print out the top words the user wants
    //prompt for user to enter file name
    int top_words;
    printf("\nHow many top words would you like printed?\n ");
    scanf("%d",&top_words);
    printTopWords(wc,top_words);

}



