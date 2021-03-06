%{
	#include <stdio.h>
	#include <stdlib.h>
	#include "ex_3.h"
	#include "ex_3.c"
	int yylex(void);
	int x;
%}

%union{
	struct tnode *no;
}
%type <no> expr NUM program END

%token NUM PLUS MINUS MUL DIV END
%left PLUS MINUS
%left MUL DIV

%%

program	: expr END 		{
					$$ = $2;
					x=codeGen($1);
					exit(1);
				}
	;

expr 	: PLUS expr expr 	{$$ = makeOperatorNode('+',$2,$3);}
	| MINUS expr expr 	{$$ = makeOperatorNode('-',$2,$3);}
	| MUL expr expr 	{$$ = makeOperatorNode('*',$2,$3);}
	| DIV expr expr 	{$$ = makeOperatorNode('/',$2,$3);}
	| '(' expr ')' 		{$$ = $2;}
	| NUM 			{$$ = $1;}
	;

%%

yyerror(char const *s)
{
	printf("yyerror %s",s);
}

	
int main(void) 
{
	target_file=fopen("exprtree.xsm","w");
	fprintf(target_file,"0\n2056\n0\n0\n0\n0\n0\n0\nBRKP\n");
	yyparse();
	return 0;
}
