%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	int yylex(void);
	char *concatenate(char *a,char *b,char *c);
%}

%union{
	char *str;
}

%token ID PLUS MINUS MUL DIV END
%left PLUS MINUS
%left '*' '/'
%type <str> ID expr program

%%

program : expr END		{printf("%s \n",$1); exit(1);}
	;
expr : expr PLUS expr 		{$$=concatenate("+",$1,$3);}
	| expr MINUS expr	{$$=concatenate("-",$1,$3);}
	| expr '*' expr 	{$$=concatenate("*",$1,$3);}
	| expr '/' expr 	{$$=concatenate("/",$1,$3);}
	| '(' expr ')'		{$$=$2;}
	| ID 			{$$=$1;}
	;

%%

yyerror(char const *s){
	printf("yyerror %s",s);
}

char *concatenate(char *a,char *b,char *c) {
    int alen = strlen(a);
    int blen = strlen(b);
    int clen = strlen(c);
    char *res = malloc(alen + blen + clen + 1);
    if (res) {
        memcpy(res, a, alen);
        memcpy(res + alen, b, blen);
        memcpy(res + alen + blen, c, clen + 1);
    }
    return res;
}

int main(void){
	yyparse();
	return 0;
}
