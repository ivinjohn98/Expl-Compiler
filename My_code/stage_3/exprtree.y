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
%type <no> Expr NUM Program Slist Stmt Output Input AsgStmt ID IfStmt WhileStmt

%token PSTART ASSIGN READ WRITE ID NUM PLUS MINUS MUL DIV END MOD IF THEN ELSE ENDIF WHILE DO ENDWHILE REPEAT UNTIL BREAK CONTINUE
%token LT GT NE EQ GE LE
%left LT GT NE EQ GE LE
%left PLUS MINUS
%left MUL DIV

%%

Program : PSTART Slist END 	{
					$$ = $2;
					x = codeGen($2);
					fprintf(target_file,"INT 10\n");
					printf("\nEvaluation:\n");
					printf("\n return value:%d\n",evaluate($2));
					exit(0);
				}
	| PSTART END		{	exit(0);}
	;
Slist	: Slist Stmt ';'	{$$ = createTree(0, 0,'0',NODE_BODY,$1,NULL,$2);}
	| Stmt ';'		{$$ = $1;}
	;
Stmt 	: Input | Output | AsgStmt | IfStmt | WhileStmt	
				{$$ = $1;}
	| BREAK			{$$ = createTree(0, 0,'0',NODE_BREAK,NULL,NULL,NULL);}
	| CONTINUE		{$$ = createTree(0, 0,'0',NODE_CONTINUE,NULL,NULL,NULL);}
	;
IfStmt 	: IF '(' Expr ')' THEN Slist ELSE Slist ENDIF 
				{$$=createTree(0, booltype,'0',NODE_IF_THEN_ELSE,$3,$6,$8);}
	| IF '(' Expr ')' THEN Slist ENDIF
				{$$=createTree(0, booltype,'0',NODE_IF_THEN_ELSE,$3,$6,NULL);}
	;

WhileStmt : WHILE '(' Expr ')' DO Slist ENDWHILE
				{$$=createTree(0, booltype,'0',NODE_WHILE_DO,$3,NULL,$6);}
	| DO Slist WHILE '(' Expr ')'
				{$$=createTree(0, booltype,'0',NODE_DO_WHILE,$2,NULL,$5);}
	| REPEAT Slist UNTIL '(' Expr ')'
				{$$=createTree(0, booltype,'0',NODE_REP_UNTIL,$2,NULL,$5);}
	;
Output	: WRITE '(' Expr ')'	{$$ = createTree(0, 0,'0',NODE_WRITE,NULL,NULL,$3);}
	;
Input	: READ '(' ID ')'	{$$ = createTree(0, 0,'0',NODE_READ,NULL,NULL,$3);}
	;
AsgStmt : ID ASSIGN Expr	{$$ = createTree(0, inttype,'0',NODE_ASSIGN,$1,NULL,$3);}
	;
Expr 	: Expr PLUS Expr 	{$$ = createTree(0, inttype,'0',NODE_PLUS,$1,NULL,$3);}
	| Expr MINUS Expr 	{$$ = createTree(0, inttype,'0',NODE_MINUS,$1,NULL,$3);}
	| Expr MUL Expr 	{$$ = createTree(0, inttype,'0',NODE_MUL,$1,NULL,$3);}
	| Expr DIV Expr 	{$$ = createTree(0, inttype,'0',NODE_DIV,$1,NULL,$3);}
	| Expr EQ Expr 		{$$ = createTree(0, booltype,'0',NODE_EQ,$1,NULL,$3);}
	| Expr NE Expr 		{$$ = createTree(0, booltype,'0',NODE_NE,$1,NULL,$3);}
	| Expr LE Expr	 	{$$ = createTree(0, booltype,'0',NODE_LE,$1,NULL,$3);}
	| Expr GE Expr 		{$$ = createTree(0, booltype,'0',NODE_GE,$1,NULL,$3);}
	| Expr LT Expr 		{$$ = createTree(0, booltype,'0',NODE_LT,$1,NULL,$3);}
	| Expr GT Expr  	{$$ = createTree(0, booltype,'0',NODE_GT,$1,NULL,$3);}
	| '(' Expr ')' 		{$$ = $2;}
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
