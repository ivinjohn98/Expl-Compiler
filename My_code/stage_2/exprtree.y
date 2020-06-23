%{
	#include <stdio.h>
	#include <stdlib.h>
	#include "exprtree.h"
	#include "exprtree.c"
	int yylex(void);
	int x;

%}

%union{
	struct tnode *no;
}
%type <no> expr NUM Program END Slist Stmt Output Input AsgStmt ID

%token PSTART ASSIGN READ WRITE ID NUM PLUS MINUS MUL DIV END MOD
%token LT GT NE EQ GE LE
%left PLUS MINUS
%left MUL DIV

%%

Program : PSTART Slist END 	{
					$$ = $3;
					x = codeGen($2);
					fprintf(target_file,"INT 10\n");
					printf("\nEvaluation:\n");
					printf("\n return value:%d\n",evaluate($2));
					exit(0);
				}
	| PSTART END		{	exit(0);}
	;
Slist	: Slist Stmt ';'	{$$ = createTree(0, 0,'0',NODE_BODY,$1,$2);}
	| Stmt ';'		{$$ = $1;}
	;
Stmt 	: Input			{$$ = $1;}
	| Output		{$$ = $1;}
	| AsgStmt		{$$ = $1;}
	;
Output	: WRITE '(' expr ')'	{$$ = createTree(0, 0,'0',NODE_WRITE,NULL,$3);}
	;
Input	: READ '(' expr ')'	{$$ = createTree(0, 0,'0',NODE_READ,NULL,$3);}
	;
AsgStmt : ID ASSIGN expr	{$$ = createTree(0, 0,'0',NODE_ASSIGN,$1,$3);}
	;
expr 	: expr PLUS expr 	{$$ = createTree(0, 0,'0',NODE_PLUS,$1,$3);}
	| expr MINUS expr 	{$$ = createTree(0, 0,'0',NODE_MINUS,$1,$3);}
	| expr MUL expr 	{$$ = createTree(0, 0,'0',NODE_MUL,$1,$3);}
	| expr DIV expr 	{$$ = createTree(0, 0,'0',NODE_DIV,$1,$3);}
	| '(' expr ')' 		{$$ = $2;}
	| NUM 			{$$ = $1;}
	| ID			{$$ = $1;}
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
	fprintf(target_file,"MOV SP, 4121\n");
	yyparse();
	return 0;
}
