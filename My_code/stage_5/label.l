%{
	#include <stdio.h>
	#include <stdlib.h>
	FILE *target_file;
	int pass,tem,nl;
	char *str0,*str1;
	struct label_table
	{
		char *str;
		int loc;
		struct label_table *next;
	}*head,*tail;
	void add_label(char *str,int loc);
	int get_loc(char *str);
%}

%%
"CALL MAIN:"	{
			if(pass)
				fprintf(target_file, "CALL %d",get_loc(yytext+5));
		}
"CALL "[A-Z][0-9]+":"		{
			if(pass)
				fprintf(target_file, "CALL %d",get_loc(yytext+5));
		}
"JMP "[A-Z][0-9]+":"		{
			if(pass)
				fprintf(target_file, "JMP %d", get_loc(yytext+4));
		}
"JZ R"([0-9]+)", "([A-Z][0-9]+)":"	{
			if(pass)
			{
				
				if(isdigit(yytext[5]))
					fprintf(target_file, "JZ R%c%c, %d",yytext[4],yytext[5],get_loc(yytext+8));
				else
					fprintf(target_file, "JZ R%c, %d",yytext[4],get_loc(yytext+7));
			}
		}
"JNZ R"([0-9]+)", "[A-Z][0-9]+":"	{
			if(pass)
			{
				if(isdigit(yytext[6]))
					fprintf(target_file, "JNZ R%c%c, %d",yytext[5],yytext[6],get_loc(yytext+9));
				else
					fprintf(target_file, "JNZ R%c, %d",yytext[5],get_loc(yytext+8));
			}
		}
[A-Z][0-9]+":"	{
			if(!pass)
			{
				str0 = strdup(yytext);
				nl = nl-2;
				add_label(str0,nl);
			}
		}
"MAIN:"		{
			if(!pass)
			{
				str0 = strdup(yytext);
				nl = nl-2;
				add_label(str0,nl);
			}
		}
[\n]		{
			if(pass)
				fprintf(target_file,"\n");
			else
				nl = nl+2;
		}
.		{
			if(pass)
				fprintf(target_file, "%s", yytext);
		}
%%

int yywrap(void) 
{
	if(!pass)
	{
		pass = 1;
		yyin = fopen("exprtree.xsm","r");
		return 0;
	}
	return 1;
}

void add_label(char *str,int loc)
{
	struct label_table* temp;
	temp = (struct label_table*)malloc(sizeof(struct label_table));
	temp->str = str;
	temp->loc = loc;
	temp->next = NULL;
	if(head == NULL)
	{
		head = temp;
		tail = temp;
	}
	else
	{
		tail->next = temp;
		tail = temp;
	}
}

int get_loc(char *str)
{
	struct label_table *temp;
	temp = head;
	while(temp!=NULL)
	{
		if(!strcmp(temp->str, str))
			return temp->loc;
		temp = temp->next;
	}
	return -1;
}

int main()
{
	head = NULL;
	tail = NULL;
	pass = 0;
	nl = 2048-6;
	target_file = fopen("code.xsm","w");
	yyin = fopen("exprtree.xsm","r");
	yylex();
	return 1;
}
