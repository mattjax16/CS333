/**
* html_stripper: a program that strips 
* an html file of all tags and comments.
*
*
* flex -o encode.yy.c encode.yy
* gcc -o encode encode.yy.c -ll
*/

    int comment_count = 0;

Ptag \<\p>

Tag \<[^<>]+>



%%

&gt; {printf(">");}

[  ]

[ \n]

[ \t]  

{Ptag} {printf("\n\n");}

{Tag}



 





%%
	 
int main( int argc, char *argv[] ) {
		
    if (argc > 1)
        yyin = fopen( argv[1], "r" ); //where yylex reads its input

    yylex(); // a function of flex that read input till it is exhausted
    
    printf("\nThere are %d html comments in the file.\n", comment_count);
    
}