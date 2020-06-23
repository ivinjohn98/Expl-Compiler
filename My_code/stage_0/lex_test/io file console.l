%{
	#include<stdio.h>
	int count;
%}

%%

[0-9]+ 	{printf("number");}
.	{printf("Not a number");}

%%

int yywrap()
{
	if(count==0)
	{
		count =1;
		yyin=stdin;
		return 0;
	}
	else
		return 1;
}

int main()
{
	count=0;  
	yyin=fopen("input_file.l","r");
	yylex();
	return 1;
}
