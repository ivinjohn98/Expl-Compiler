%{
 
#include <stdlib.h>
#include <stdio.h>
 
int floating;
int integers;

%}
 

%%

[0-9][0-9]*		++integers;
[0-9]+"."[0-9]+		++floating;
.			;

%%
 
int yywrap()
{
  return 1;
}
 
int main()
{
	integers=floating=0;
	yylex();
	printf("number of :\nfloat -%d\nintegers -%d\n",floating,integers);
	return 0;
}
