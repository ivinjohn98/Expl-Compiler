%{
	#include <stdio.h>
	#include <stdlib.h>
	#include "exprtree.h"
	#include "exprtree.c"
	FILE *yyin;
	int yylex(void);
	int x;
%}

%union{
	struct tnode *no;
}
%type <no> Expr NUM Program Slist Stmt Output Input AsgStmt ID IfStmt WhileStmt IDaddress IDadrs

%token START ASSIGN READ WRITE ID NUM PLUS MINUS MUL DIV END MOD IF THEN ELSE ENDIF WHILE DO ENDWHILE REPEAT UNTIL BREAK CONTINUE
%token LT GT NE EQ GE LE STR INT DECL ENDDECL NOT
%left OR
%left AND
%left PLUS MINUS
%left MUL DIV MOD
%right NOT
%nonassoc LT GT NE EQ GE LE

%%

codeStart : Declarations Program	
				{exit(0);}
	;
Declarations : DECL DeclList ENDDECL
				{
					/*struct Gsymbol *temp=NULL;
					temp = Ghead;
					while(temp!=NULL)
					{
						printf("name: %s\n",temp->name);
						printf("type: %d\n",temp->type);
						printf("size: %d\n",temp->size);
						printf("binding: %d\n",temp->binding);
						temp=temp->next;
					}*/
				}
	| DECL ENDDECL
	;
DeclList : DeclList Decl ';'
	| Decl ';'
	;
Decl 	: Type VarList
	;
Type 	: INT			{typeID = INTTYPE;}
	| STR			{typeID = STRTYPE;}
	;
VarList : VarList ',' Gid
	| Gid
	;
Gid	: ID '[' NUM ']'	{GInstall($1->varname,typeID,1,$3->intval,0);}
	| ID '[' NUM ']' '[' NUM ']' 
				{GInstall($1->varname,typeID,$3->intval,$6->intval,0);}
	| ID			{GInstall($1->varname,typeID,1,1,0);}
	| MUL ID		{GInstall($2->varname,typeID,1,1,1);}
	;
Program : START Slist END	{
					$$ = $2;
					fprintf(target_file,"MOV SP, %d\n",bindno);
					x = codeGen($2);
					fprintf(target_file,"INT 10\n");
				}
	| START END		{$$ = NULL;}
	;
Slist	: Slist Stmt ';'	{$$ = createTree(0,NULL, 0,NULL,NODE_BODY,$1,NULL,$2);}
	| Stmt ';'		{$$ = $1;}
	;
Stmt 	: Input | Output | AsgStmt | IfStmt | WhileStmt	
				{$$ = $1;}
	| BREAK			{$$ = createTree(0,NULL, 0,NULL,NODE_BREAK,NULL,NULL,NULL);}
	| CONTINUE		{$$ = createTree(0,NULL, 0,NULL,NODE_CONTINUE,NULL,NULL,NULL);}
	;
IfStmt 	: IF '(' Expr ')' THEN Slist ELSE Slist ENDIF 
				{$$=createTree(0,NULL, BOOLTYPE,NULL,NODE_IF_THEN_ELSE,$3,$6,$8);}
	| IF '(' Expr ')' THEN Slist ENDIF
				{$$=createTree(0,NULL, BOOLTYPE,NULL,NODE_IF_THEN_ELSE,$3,$6,NULL);}
	;

WhileStmt : WHILE '(' Expr ')' DO Slist ENDWHILE
				{$$=createTree(0,NULL, BOOLTYPE,NULL,NODE_WHILE_DO,$3,NULL,$6);}
	| DO Slist WHILE '(' Expr ')'
				{$$=createTree(0,NULL, BOOLTYPE,NULL,NODE_DO_WHILE,$2,NULL,$5);}
	| REPEAT Slist UNTIL '(' Expr ')'
				{$$=createTree(0,NULL, BOOLTYPE,NULL,NODE_REP_UNTIL,$2,NULL,$5);}
	;
Output	: WRITE '(' Expr ')'	{$$ = createTree(0,NULL, 0,NULL,NODE_WRITE,NULL,$3,NULL);}
	;
Input	: READ '(' IDaddress ')'{$$ = createTree(0,NULL, 0,NULL,NODE_READ,NULL,$3,NULL);}
	;
AsgStmt : IDaddress ASSIGN Expr	{$$ = createTree(0,NULL, 0,NULL,NODE_ASSIGN,$1,NULL,$3);}
	;
IDaddress : IDadrs		{$$ = $1;}
	| IDadrs '[' Expr ']'	{$$ = createTree(0,NULL, $1->type,$1->varname,NODE_ARRAY_ADDRESS,$1,NULL,$3);}
	| IDadrs '[' Expr ']' '[' Expr ']'
				{$$ = createTree(0,NULL, $1->type,$1->varname,NODE_MATRIX_ADDRESS,$1,$3,$6);}
	;
IDadrs	: ID			{$$ = createTree(0,NULL, $1->type,$1->varname,NODE_ID_ADDRESS,NULL,NULL,NULL);}
	| MUL ID		{$$ = createTree(0,NULL, $2->type,$2->varname,NODE_ID,NULL,NULL,NULL);}
	;
Expr 	: Expr PLUS Expr 	{$$ = createTree(0,NULL, INTTYPE,NULL,NODE_PLUS,$1,NULL,$3);}
	| Expr MINUS Expr 	{$$ = createTree(0,NULL, INTTYPE,NULL,NODE_MINUS,$1,NULL,$3);}
	| Expr MUL Expr 	{$$ = createTree(0,NULL, INTTYPE,NULL,NODE_MUL,$1,NULL,$3);}
	| Expr DIV Expr 	{$$ = createTree(0,NULL, INTTYPE,NULL,NODE_DIV,$1,NULL,$3);}
	| Expr MOD Expr 	{$$ = createTree(0,NULL, INTTYPE,NULL,NODE_MOD,$1,NULL,$3);}
	| Expr AND Expr		{$$ = createTree(0,NULL, BOOLTYPE,NULL,NODE_AND,$1,NULL,$3);}
	| Expr OR Expr		{$$ = createTree(0,NULL, BOOLTYPE,NULL,NODE_OR,$1,NULL,$3);}
	| Expr EQ Expr 		{$$ = createTree(0,NULL, BOOLTYPE,NULL,NODE_EQ,$1,NULL,$3);}
	| Expr NE Expr 		{$$ = createTree(0,NULL, BOOLTYPE,NULL,NODE_NE,$1,NULL,$3);}
	| Expr LE Expr	 	{$$ = createTree(0,NULL, BOOLTYPE,NULL,NODE_LE,$1,NULL,$3);}
	| Expr GE Expr 		{$$ = createTree(0,NULL, BOOLTYPE,NULL,NODE_GE,$1,NULL,$3);}
	| Expr LT Expr 		{$$ = createTree(0,NULL, BOOLTYPE,NULL,NODE_LT,$1,NULL,$3);}
	| Expr GT Expr  	{$$ = createTree(0,NULL, BOOLTYPE,NULL,NODE_GT,$1,NULL,$3);}
	| NOT Expr		{$$ = createTree(0,NULL, BOOLTYPE,NULL,NODE_NOT,NULL,$2,NULL);}
	| '(' Expr ')' 		{$$ = $2;}
	| NUM			{$$ = $1;}
	| ID			{$$ = $1;}
	| ID '[' Expr ']'	{$$ = createTree(0,NULL, $1->type,$1->varname,NODE_ARRAY,$1,NULL,$3);}
	| ID '[' Expr ']' '[' Expr ']'
				{$$ = createTree(0,NULL, $1->type,$1->varname,NODE_MATRIX,$1,$3,$6);}
	| MUL ID		{$$ = createTree(0,NULL, $2->type,$2->varname,NODE_ID_VALPTR,NULL,NULL,NULL);}
	| '&' ID		{$$ = createTree(0,NULL, $2->type,$2->varname,NODE_ID_ADDRESS,NULL,NULL,NULL);} 
	;
%%

yyerror(char const *s)
{
	printf("yyerror %s",s);
}

int main(int argc, char **argv)
{
	yyin = fopen(argv[1],"r");
	target_file=fopen("exprtree.xsm","w");
	fprintf(target_file,"0\n2056\n0\n0\n0\n0\n0\n0\nBRKP\n");
	yyparse();
	return 0;
}
