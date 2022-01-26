/**
* A Clite Parser
*/


Integer [0-9]+

Float [0-9]+.[0-9]+

Keyword if|else|while|for|int|float

Identifier [a-zA-z]+[a-zA-z0-9]*

Assignment =

Comparison ==|\<|>|\<=|>=

Operator	\+|\-|\*|\/

Open-bracket [ \{]

Close-bracket [ \}]

Open-paren [ (]

Close-paren [ )]

Comment ["//"].+

%%

{Comment}

[ \n]


{Keyword} printf("Keyword-%s\n", yytext);

{Identifier} printf("Identifier-%s\n", yytext);

{Float} printf("Float-%.1f\n", atof(yytext)); // question how many decimals to print

{Integer} printf("Integer-%d\n", atoi(yytext));

{Comparison} printf("Comparison-%s\n", yytext);

{Operator} printf("Operator-%s\n", yytext);

{Assignment} printf("Assignment\n");

{Open-bracket} printf("Open-bracket\n");

{Close-bracket} printf("Close-bracket\n");

{Open-paren} printf("Open-paren\n");

{Close-paren} printf("Close-paren\n");

.

%%
	 
int main( int argc, char *argv[] ) {
		
    if (argc > 1)
        yyin = fopen( argv[1], "r" ); //where yylex reads its input

    yylex(); // a function of flex that read input till it is exhausted
    
    
}