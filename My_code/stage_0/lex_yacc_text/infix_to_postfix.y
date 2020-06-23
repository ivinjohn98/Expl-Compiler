%{
	#include <stdio.h>
	#include <stdlib.h>
	int yylex(void);
	
%}

%token ID PLUS MINUS MUL DIV END
%left PLUS MINUS
%left '*' '/'
%%

program : expr END		{printf("\n"); exit(1);}
	;
	
expr : expr PLUS expr 		{printf("+");}
	| expr MINUS expr 	{printf("-");}
	| expr '*' expr 	{printf("*");}
	| expr '/' expr 	{printf("/");}
	| '(' expr ')'		
	| ID 			{printf("%c",$1);}
	;
	
%%

yyerror(char const *s){
	printf("yyerror %s",s);
}


int main(void){
	yyparse();
	return 0;
}
