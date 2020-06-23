%{
	#include<stdio.h>
	int count;
%}

%%

"//"(.)*	{printf("%s",yytext);}
"/*"(.)*"*/"	{printf("%s",yytext);}
.		{}

%%

int yywrap()
{
	return 1;
}

int main()
{  	
	yyin=fopen("input_file.l","r");
	yylex();
	return 1;
}
