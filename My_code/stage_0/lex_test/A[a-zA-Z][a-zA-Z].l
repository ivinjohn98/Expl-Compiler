%{
 
#include <stdlib.h>
#include <stdio.h>
char s[100][4];
int i;

%}

pattern [A][a-zA-Z][a-zA-Z]

%%
{pattern}(" "|\n)	{
				s[i][0]=yytext[0];
				s[i][1]=yytext[1];
				s[i][2]=yytext[2];
				++i;
			}
.			;
%%

int yywrap()
{
  return 1;
}

int main()
{
	i=0;
	int j;
	yylex();
	printf("List of [A][a-zA-Z][a-zA-Z] words:\n");
	for(j=0;j<=i;j++)
		printf("%c%c%c\n",s[j][0],s[j][1],s[j][2]);
	return 0;
}
