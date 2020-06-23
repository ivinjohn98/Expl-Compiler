%{
	#include <stdio.h>
	#include "y.tab.h"
	#include <stdlib.h>
	#include "exprtree.h"
	int intval;
	char *strval;
	#define NODE_ID 0
	#define NODE_NUM 1
%}

%%

[0-9]+ 		{
			intval = atoi(yytext);
			yylval.no = createTree(intval,NULL,INTTYPE,NULL,NODE_NUM,NULL,NULL,NULL);
			return NUM;
		}
["][" "a-zA-Z0-9]+["] 	{
			strval = strdup(yytext); 
			yylval.no = createTree(0,strval,STRTYPE,NULL,NODE_STR,NULL,NULL,NULL);
			return NUM;
		}
"repeat"	{return REPEAT;}
"str"		{return STR;}
"int"		{return INT;}
"decl"		{return DECL;}
"enddecl"	{return ENDDECL;}
"until"		{return UNTIL;}
"while"		{return WHILE;}
"break"		{return BREAK;}
"continue"	{return CONTINUE;}
"endwhile"	{return ENDWHILE;}
"do"		{return DO;}
"begin"		{return START;}
"end"		{return END;}
"read"		{return READ;}
"write"		{return WRITE;}
"endif"		{return ENDIF;}
"if"		{return IF;}
"then"		{return THEN;}
"else"		{return ELSE;}
"AND"		{return AND;}
"OR"		{return OR;}
[a-zA-Z]([a-zA-Z0-9_]*)	{
			strval = strdup(yytext);
			if(Lookup(strval) != NULL)
				yylval.no = createTree(0,NULL,Lookup(strval)->type, strval,NODE_ID,NULL,NULL,NULL);
			else
				yylval.no = createTree(0,NULL,0, strval,NODE_ID,NULL,NULL,NULL);
			return ID;
		}
"="		{return ASSIGN;}
"!"		{return NOT;}
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
"["		{return *yytext;}
"]"		{return *yytext;}
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
