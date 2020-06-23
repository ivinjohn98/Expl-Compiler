%{

	#include <stdio.h>
	#include <stdlib.h>
	#include <ctype.h>

%}

%token DIGIT CHAR
%%

start : stmt '\n'		{printf("Valid identifier\n");exit(1);}
	;

stmt : CHAR id
	;

id : CHAR id | DIGIT id | CHAR | DIGIT
	;

%%

yyerror(){
	printf("Error");
}

yylex(){
	int c;
	c = getchar();
	if(isdigit(c))
	{
		return DIGIT;
	}
	if(isalpha(c))
	{
		return CHAR;
	}
	return c;
}

main(){
	yyparse();
	return 1;
}
