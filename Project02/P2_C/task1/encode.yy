/**
* Encode:  reads in a text file and
* takes any character in a-z 
* or A-Z and shifts it 13 spaces forward 
* in the alphabet, with wraparound from z 
* back to a. 
*
*
* flex -o encode.yy.c encode.yy
* gcc -o encode encode.yy.c -ll
*/

LowLet [a-z]

CapLet [A-Z]


%%
	 
{LowLet}   printf("%c", (yytext[0] - 'a' + 13) % 26 + 'a');

{CapLet}   printf("%c", (yytext[0] - 'A' + 13) % 26 + 'A');
	 
%%
	 
int main( int argc, char *argv[] ) {
		
    if (argc > 1)
        yyin = fopen( argv[1], "r" ); //where yylex reads its input

    yylex(); // a function of flex that read input till it is exhausted
}