%{

#include <stdlib.h>
#include <stdio.h>
 
int lines;
int words;
int ch;

%}
 

%%
[a-zA-Z0-9]		++ch;
" "			++words;
\n			++lines;
.			;
%%
 
int yywrap()
{
  return 1;
}
 
int main()
{
	lines=ch=words=0;
	yylex();
	printf("\nlines -%d\nwords -%d\nch -%d\n",lines,lines+words,ch);
	return 0;
}
