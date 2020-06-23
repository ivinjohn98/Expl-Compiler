%{

	#include <stdio.h>
	#include <stdlib.h>
	#include <ctype.h>

%}

%token DIGIT
%left '+'
%left '*'

%%

start : stmt '\n'		{printf("\n");exit(1);}
	;

stmt : 'i' 'f' '(' DIGIT '=' DIGIT ')' 't' 'h' 'e' 'n' stmt 'e' 'l' 's' 'e' stmt		{printf("if(%d=%d) ",$4,$6);}
	| expr
	;
expr :  expr '+' expr		{printf("+ ");}
	| expr '*' expr		{printf("* ");}
	| '(' expr ')'
	| DIGIT			{printf("%d ",$1);}
	;

%%

yyerror(){
	printf("Error");
}

yylex(){
	int c;
	c = getchar();
	if(isdigit(c)){
		yylval = c - '0';
		return DIGIT;
	}
	return c;
}

main(){
	yyparse();
	return 1;
}
