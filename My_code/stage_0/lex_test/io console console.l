%{
	#include<stdio.h>
	char *file1;
	int count;
%}

%%

[0-9]+ 	{printf("number");}
.	{}

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
	count = 0;
  	yylex();
	char *file1="console";
  	return 1;
}
