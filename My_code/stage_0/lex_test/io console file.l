%{
	#include<stdio.h>
	char *file1;
	int count;
%}

%%

[0-9]+ 	{printf("number");}
.	{printf("Not a number");}

%%

int yywrap()
{
  	FILE *newfile_pointer;
  	char *file2="input_file_2.l";
  	newfile_pointer = fopen("input_file_2.l","r");
  	if(count==1)
  	{  
  		yyin = newfile_pointer;
		count=0;
    		return 0;
  	}
  	else
  		return 1;
}

int main()
{
	count=1;
  	yylex();
	char *file1="console";
  	return 1;
}
