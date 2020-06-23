%{
	#include <stdio.h>
	#include "y.tab.h"
	#include <stdlib.h>
	#include "exprtree.h"
	int number;
	char str;
	
	#define NODE_ID 0
	#define NODE_NUM 1
%}

%%

"begin"		{return PSTART;}
"end"		{return END;}
"read"		{return READ;}
"write"		{return WRITE;}
[a-z]		{
			str = *yytext;
			yylval.no = createTree(0, 0, str,NODE_ID,NULL,NULL);
			return ID;
		}
[0-9]+ 		{
			number = atoi(yytext); 
			yylval.no = createTree(number, 0,'0',NODE_NUM,NULL,NULL);
			return NUM;
		}
"="		{return ASSIGN;}
"+" 		{return PLUS;}
"-" 		{return MINUS;}
"*" 		{return MUL;}
"/"		{return DIV;}
"%"		{return MOD;}
"<"		{return LT;}
">"		{return GT;}
"<="		{return LE;}
">="		{return GE;}
"!="		{return NE;}
"=="		{return EQ;}
[\n \t] 	{}
[{}()]		{return *yytext;}
[&.,;\"] 	{return *yytext;}
.		{
			yyerror("unknown character\n");
			exit(1);
		}
%%

int yywrap(void) 
{
	return 1;
}
