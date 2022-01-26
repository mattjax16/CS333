/**
 * Matt Bass
 * CS333
 * Word Counter
 * Project 6
 */

#include <stdio.h>
#include "../tasks/src/Linkedlist.h"
#include "../tasks/src/Linkedlist.c"
#include <string.h>
#include <ctype.h>

// prints an integer
void printInt(void *i) {
	int a = i;

	printf("count: %d\n", a);
}

// prints a string
void printStr(char *s[50*sizeof(char)]) {
    char *word = (char *)s;
    printf("word: %s\n", word);
}

// compares two strings
int compStr(void *a[50*sizeof(char)], void *b[50*sizeof(char)]) {
    char *strA = (char*)a;
	char *strB = (char*)b;
    int ret = strcmp(strA, strB);

	return ret;
}


int main(int argc, char *argv[]) {
    FILE *fp1, *fp2;
    char value[20];

    // opens file
    fp1 = fopen(argv[1], "r");
    if (fp1 == NULL){return 1;}
    fp2 = fopen(argv[2], "w");

    // create linked list
    LinkedList *l;
    l = ll_create();

    // set temp vars
    char *str = (char*)malloc(30*sizeof(char));
    char c;
    int i = 0;

    //add words to linked list
    while ((c=fgetc(fp1))!=EOF) {
        c = tolower(c);
        if (c != ' ' && c != '\n' && ispunct(c)==0 || c == '-') {
            str[i++] = c;
        } else if (strlen(str) > 0){
            str[i] = '\0';           
            char *word = malloc(sizeof(50*sizeof(char)));
            strcpy(word, str);
            // if the word is already in the list, update the count
            if (ll_contains(l, word, strcmp)) {
                ll_update(l, word, strcmp);
            } else {
                ll_push(l, word);
            }
            memset(str, '\0', sizeof(50*sizeof(char)));
            i = 0;
        }
    }

    printf("%s", "\n");


    // print the words with the top 20 frequencies
    printf("\nTop 20 words in: %s\n", argv[1]);
    for (i=0; i<40; ++i) {
        ll_print_highest(l);
    }

    fclose(fp1);
    fclose(fp2);
    return 0;
}