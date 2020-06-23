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
			yylval.no = createTree(intval,NULL,TLookup("integer"),NULL,NODE_NUM,NULL,NULL,NULL);
			return NUM;
		}
["][" "a-zA-Z0-9]+["] 	{
			strval = strdup(yytext); 
			yylval.no = createTree(0,strval,TLookup("string"),NULL,NODE_STR,NULL,NULL,NULL);
			return NUM;
		}
"main"		{return MAIN;}
"return"	{return RETURN;}
"repeat"	{return REPEAT;}
"str"		{return STR;}
"int"		{return INT;}
"decl"		{return DECL;}
"enddecl"	{return ENDDECL;}
"type"		{return TYPE;}
"endtype"	{return ENDTYPE;}
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
"initialize"	{return INIT;}
"alloc"		{return ALLOC;}
"free"		{return FREE;}
"null"		{return NIL;}
[a-zA-Z]([a-zA-Z0-9_]*)	{
			strval = strdup(yytext);
			yylval.no = createTree(0,NULL,NULL, strval,NODE_ID,NULL,NULL,NULL);
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
