%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "exprtree.h"
	#include "exprtree.c"
	FILE *yyin;
	int yylex();
	void yyerror(const char *s);
	int x;
%}

%union{
	struct tnode *no;
}
%type <no> Expr NUM Slist Stmt Output Body Input AsgStmt ID IfStmt WhileStmt IDaddress IDadrs ArgList

%token MAIN START ASSIGN READ WRITE ID NUM PLUS MINUS MUL DIV END MOD IF THEN ELSE ENDIF WHILE DO ENDWHILE REPEAT UNTIL BREAK CONTINUE
%token LT GT NE EQ GE LE STR INT DECL ENDDECL NOT RETURN
%left AND OR
%left PLUS MINUS
%left MUL DIV MOD
%right NOT
%nonassoc LT GT NE EQ GE LE

%%

Program	: GdeclBlock FdefBlock MainBlock 
	| GdeclBlock MainBlock 
	| MainBlock
	;
GdeclBlock : DECL ENDDECL | DECL GdeclList ENDDECL 
				{
					/*struct Gsymbol *temp=NULL;
					struct Paramstruct *temp1=NULL;
					temp = Ghead;
					while(temp!=NULL)
					{
						printf("name: %s\n",temp->name);
						printf("type: %d\n",temp->type);
						printf("size: %d\n",temp->size1);
						printf("size: %d\n",temp->size2);
						printf("binding: %d\n",temp->binding);
						if(temp->ParamList!=NULL)
						{
							temp1=temp->ParamList;
							while(temp1!=NULL)
							{
								printf("paramter: %s %d\n",temp1->name,temp1->type);
								temp1 = temp1->next;
							}
						}
						temp=temp->next;
					}*/
					fprintf(target_file,"MOV SP, %d\n",bindno);
					fprintf(target_file,"MOV BP, %d\n",bindno+1);
					fprintf(target_file,"PUSH R0\n");
					fprintf(target_file,"CALL MAIN:\n");
					fprintf(target_file,"POP R0\n");
					fprintf(target_file,"INT 10\n");
				}
	;
GdeclList : GdeclList GDecl 
	| GDecl
	;
GDecl	: Type GidList ';'
	;
Type 	: INT			{typeID = INTTYPE;}
	| STR			{typeID = STRTYPE;}
	;
GidList : GidList ',' Gid
	| Gid
	;
Gid	: ID			{GInstall(NODE_ID,$1->varname,typeID,1,1,NULL);}
	| ID '[' NUM ']'	{GInstall(NODE_ARRAY,$1->varname,typeID,1,$3->intval,NULL);}
	| ID '[' NUM ']' '[' NUM ']'
				{GInstall(NODE_MATRIX,$1->varname,typeID,$3->intval,$6->intval,NULL);}
	| ID '(' ParamList ')'	{
					GInstall(NODE_FUN,$1->varname,typeID,0,0,Phead);
					Phead = Ptail = NULL;
					pbindno = 0;
				}
	| MUL ID		{GInstall(NODE_PTR,$2->varname,typeID,1,1,NULL);}
	;
FdefBlock : FdefBlock Fdef 
	| Fdef
	;
Fdef 	: Type ID '(' ParamList ')' '{' LdeclBlock Body '}'
		{
			pbindno = 0;
			lbindno = 0;
			struct Gsymbol *Gtemp;
			struct Paramstruct *Ptemp,*Ptemp1;
			struct Lsymbol *Ltemp;
			int Pcount,Lcount;
			Gtemp = GLookup($2->varname);
			if(Gtemp==NULL)
			{
				printf("ERROR:function not declared\n");
				exit(1);
			}
			else
			{
				//checking match of function defintion with global defintion
				Ptemp = Gtemp->ParamList;
				Ptemp1 = Phead;
				while((Ptemp1!=NULL) && (Ptemp!=NULL))
				{
					if(!((Ptemp->nodetype == Ptemp1->nodetype) && (Ptemp->type == Ptemp1->type) && (!strcmp(Ptemp->name,Ptemp1->name))))
					{
						printf("ERROR:function parameter mismatch with defintion\n");
						exit(1);
					}
					Ptemp = Ptemp->next;
					Ptemp1 = Ptemp1->next;
				}
				if(!((Ptemp1==NULL) && (Ptemp==NULL)))
				{
					printf("ERROR:function parameter mismatch with defintion\n");
					exit(1);
				}
				//checking match of local variable with formal parameters
				Ltemp = Lhead;
				while(Ltemp!=NULL)
				{
					if(PLookup(Ltemp->name) != NULL)
					{
						printf("ERROR:function parameter matches with local variables\n");
						exit(1);
					}
					Ltemp = Ltemp->next;
				}
			}
			Lcount = 0;
			Ltemp = Lhead;
			while(Ltemp!=NULL)
			{
				Lcount++;
				Ltemp=Ltemp->next;
			}
			fprintf(target_file,"F%d:\n",Gtemp->flabel);
			fprintf(target_file,"PUSH BP\n");
			fprintf(target_file,"MOV BP, SP\n");
			fprintf(target_file, "ADD SP, %d\n", Lcount);
			x = codeGen($8);
			fprintf(target_file, "SUB SP, %d\n", Lcount);
			fprintf(target_file, "MOV BP, [SP]\n");
			fprintf(target_file, "POP R0\n");
			fprintf(target_file, "RET\n");
			Lhead = Ltail = NULL;
			Phead = Ptail = NULL;
		}
	;
ParamList : ParamList ',' Param 
	| Param
	|
	;
Param 	: Type ID	{PInstall(NODE_ID,$2->varname,typeID);}
	| Type MUL ID	{PInstall(NODE_PTR,$3->varname,typeID);}
	;
LdeclBlock : DECL LDecList ENDDECL 
	| DECL ENDDECL
	;
LDecList : LDecList LDecl 
	| LDecl	
	;
LDecl	: Type IdList ';'
	;
IdList	: IdList ',' Lid
	| Lid
	;
Lid	: ID		{LInstall(NODE_ID,$1->varname,typeID);}
	| MUL ID	{LInstall(NODE_PTR,$2->varname,typeID);}
	;
MainBlock : INT MAIN '(' ')' '{' LdeclBlock Body '}'
		{
			lbindno = 0;
			struct Gsymbol *Gtemp;
			struct Lsymbol *Ltemp;
			int Lcount;
			Lcount = 0;
			Ltemp = Lhead;
			while(Ltemp!=NULL)
			{
				Lcount++;
				Ltemp=Ltemp->next;
			}
			fprintf(target_file,"MAIN:\n");
			fprintf(target_file,"PUSH BP\n");
			fprintf(target_file,"MOV BP, SP\n");
			fprintf(target_file, "ADD SP, %d\n", Lcount);
			x = codeGen($7);
			fprintf(target_file, "SUB SP, %d\n", Lcount);
			fprintf(target_file, "MOV BP, [SP]\n");
			fprintf(target_file, "POP R0\n");
			fprintf(target_file, "RET\n");
			Lhead = Ltail = NULL;
		}
	;
Body 	: START Slist END	{$$ = $2;}
	| START END		{$$ = NULL;}
	;
Slist	: Slist Stmt ';'	{$$ = createTree(0,NULL, 0,NULL,NODE_BODY,$1,NULL,$2);}
	| Stmt ';'		{$$ = $1;}
	;
Stmt 	: Input | Output | AsgStmt | IfStmt | WhileStmt
				{$$ = $1;}
	| BREAK			{$$ = createTree(0,NULL, 0,NULL,NODE_BREAK,NULL,NULL,NULL);}
	| CONTINUE		{$$ = createTree(0,NULL, 0,NULL,NODE_CONTINUE,NULL,NULL,NULL);}
	| RETURN Expr		{$$ = createTree(0,NULL, 0,NULL,NODE_RET,NULL,$2,NULL);}
	;
IfStmt 	: IF '(' Expr ')' THEN Slist ELSE Slist ENDIF 
				{$$=createTree(0,NULL, BOOLTYPE,NULL,NODE_IF_THEN_ELSE,$3,$6,$8);}
	| IF '(' Expr ')' THEN Slist ENDIF
				{$$=createTree(0,NULL, BOOLTYPE,NULL,NODE_IF_THEN_ELSE,$3,$6,NULL);}
	;

WhileStmt : WHILE '(' Expr ')' DO Slist ENDWHILE
				{$$=createTree(0,NULL, BOOLTYPE,NULL,NODE_WHILE_DO,$3,NULL,$6);}
	| DO Slist WHILE '(' Expr ')'
				{$$=createTree(0,NULL, BOOLTYPE,NULL,NODE_DO_WHILE,$2,NULL,$5);}
	| REPEAT Slist UNTIL '(' Expr ')'
				{$$=createTree(0,NULL, BOOLTYPE,NULL,NODE_REP_UNTIL,$2,NULL,$5);}
	;
Output	: WRITE '(' Expr ')'	{$$ = createTree(0,NULL, 0,NULL,NODE_WRITE,NULL,$3,NULL);}
	;
Input	: READ '(' IDaddress ')'{$$ = createTree(0,NULL, 0,NULL,NODE_READ,NULL,$3,NULL);}
	;
AsgStmt : IDaddress ASSIGN Expr	{$$ = createTree(0,NULL, 0,NULL,NODE_ASSIGN,$1,NULL,$3);}
	;
IDaddress : IDadrs		{$$ = $1;}
	| IDadrs '[' Expr ']'	{$$ = createTree(0,NULL, $1->type,$1->varname,NODE_ARRAY_ADDRESS,$1,$3,NULL);}
	| IDadrs '[' Expr ']' '[' Expr ']'
				{$$ = createTree(0,NULL, $1->type,$1->varname,NODE_MATRIX_ADDRESS,$1,$3,$6);}
	;
IDadrs	: ID			{$$ = createTree(0,NULL, $1->type,$1->varname,NODE_ID_ADDRESS,NULL,NULL,NULL);}
	| MUL ID		{$$ = createTree(0,NULL, $2->type,$2->varname,NODE_ID,NULL,NULL,NULL);}
	;
Expr 	: Expr PLUS Expr 	{$$ = createTree(0,NULL, INTTYPE,NULL,NODE_PLUS,$1,NULL,$3);}
	| Expr MINUS Expr 	{$$ = createTree(0,NULL, INTTYPE,NULL,NODE_MINUS,$1,NULL,$3);}
	| Expr MUL Expr 	{$$ = createTree(0,NULL, INTTYPE,NULL,NODE_MUL,$1,NULL,$3);}
	| Expr DIV Expr 	{$$ = createTree(0,NULL, INTTYPE,NULL,NODE_DIV,$1,NULL,$3);}
	| Expr MOD Expr 	{$$ = createTree(0,NULL, INTTYPE,NULL,NODE_MOD,$1,NULL,$3);}
	| Expr AND Expr		{$$ = createTree(0,NULL, BOOLTYPE,NULL,NODE_AND,$1,NULL,$3);}
	| Expr OR Expr		{$$ = createTree(0,NULL, BOOLTYPE,NULL,NODE_OR,$1,NULL,$3);}
	| Expr EQ Expr 		{$$ = createTree(0,NULL, BOOLTYPE,NULL,NODE_EQ,$1,NULL,$3);}
	| Expr NE Expr 		{$$ = createTree(0,NULL, BOOLTYPE,NULL,NODE_NE,$1,NULL,$3);}
	| Expr LE Expr	 	{$$ = createTree(0,NULL, BOOLTYPE,NULL,NODE_LE,$1,NULL,$3);}
	| Expr GE Expr 		{$$ = createTree(0,NULL, BOOLTYPE,NULL,NODE_GE,$1,NULL,$3);}
	| Expr LT Expr 		{$$ = createTree(0,NULL, BOOLTYPE,NULL,NODE_LT,$1,NULL,$3);}
	| Expr GT Expr  	{$$ = createTree(0,NULL, BOOLTYPE,NULL,NODE_GT,$1,NULL,$3);}
	| NOT Expr		{$$ = createTree(0,NULL, BOOLTYPE,NULL,NODE_NOT,NULL,$2,NULL);}
	| '(' Expr ')' 		{$$ = $2;}
	| NUM			{$$ = $1;}
	| ID			{$$ = $1;}
	| ID '[' Expr ']'	{$$ = createTree(0,NULL, $1->type,$1->varname,NODE_ARRAY,$1,$3,NULL);}
	| ID '[' Expr ']' '[' Expr ']'
				{$$ = createTree(0,NULL, $1->type,$1->varname,NODE_MATRIX,$1,$3,$6);}
	| MUL ID		{$$ = createTree(0,NULL, $2->type,$2->varname,NODE_ID_VALPTR,NULL,NULL,NULL);}
	| '&' ID		{$$ = createTree(0,NULL, $2->type,$2->varname,NODE_ID_ADDRESS,NULL,NULL,NULL);}
	| ID '(' ArgList ')'
		{
			struct Gsymbol *gtemp,*gtemp1;
			struct Paramstruct *ptemp;
			struct tnode *atemp;
			gtemp = GLookup($1->varname);
			if(gtemp==NULL)
			{
				printf("ERROR:no declared function found\n");
				exit(1);
			}
			else
			{
				ptemp = gtemp->ParamList;
				atemp = $3;
				while((ptemp!=NULL) && (atemp!=NULL))
				{
					if(ptemp->type != atemp->type)
					{
						printf("ERROR:function argument mismatch with defintion\n");
						exit(1);
					}
					ptemp = ptemp->next;
					atemp = atemp->ArgList;
				}
				if(!((atemp==NULL) && (ptemp==NULL)))
				{
					printf("ERROR:function argument mismatch with defintion\n");
					exit(1);
				}
			}
			$$ = createTree(0,NULL, gtemp->type,$1->varname,NODE_FUN,NULL,$3,NULL);
		}
	;
ArgList : ArgList ',' Expr 	{
					$1->ArgList = $3;
					$$ = $1;
				}
	| Expr			{$$ = $1;}
	|			{$$ = NULL;}
	;

%%

void yyerror(char const *s)
{
	printf("yyerror %s",s);
}

int main(int argc, char **argv)
{
	yyin = fopen(argv[1],"r");
	target_file=fopen("exprtree.xsm","w");
	fprintf(target_file,"0\n2056\n0\n0\n0\n0\n0\n0\nBRKP\n");
	yyparse();
	return 0;
}
