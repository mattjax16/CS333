/**
* Encorow_char_vow count: reads in a text file 
* and tells you not only the 
* number of rows and characters, but also how many of 
* each vowel [a, e, i, o, u] are in the file.
*
*
* flex -o encode.yy.c encode.yy
* gcc -o encode encode.yy.c -ll
*/

    int char_count = 0;
    int a_count = 0;
    int e_count = 0;
    int i_count = 0;
    int o_count = 0;
    int u_count = 0;
    int line_count = 0;

%%



a|A {a_count++;
    char_count++;}

e|E {e_count++;
    char_count++;}

i|I {i_count++;
    char_count++;}

o|O {o_count++;
    char_count++;}

u|U {a_count++;
    char_count++;}

[a-zA-Z] char_count++;

[ \n] line_count++;


%%
	 
int main( int argc, char *argv[] ) {
		
    if (argc > 1)
        yyin = fopen( argv[1], "r" ); //where yylex reads its input

    yylex(); // a function of flex that read input till it is exhausted
    
    
    
    // Printing out all the counts
    printf("\nThere are %d a's in the file.\n", a_count);
    printf("\nThere are %d e's in the file.\n", e_count);
    printf("\nThere are %d i's in the file.\n", i_count);
    printf("\nThere are %d o's in the file.\n", o_count);
    printf("\nThere are %d u's in the file.\n", u_count);
    printf("\nThere are %d chars in the file.\n", char_count);
    printf("\nThere are %d rows in the file.\n", line_count);
}