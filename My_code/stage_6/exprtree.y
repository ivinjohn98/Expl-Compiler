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
%type <no> Expr NUM Slist Stmt Output Body Input AsgStmt ID IfStmt WhileStmt IDaddress ArgList Field

%token MAIN START ASSIGN READ WRITE ID NUM PLUS MINUS MUL DIV END MOD IF THEN ELSE ENDIF WHILE DO ENDWHILE REPEAT UNTIL BREAK CONTINUE
%token LT GT NE EQ GE LE STR INT DECL ENDDECL NOT RETURN INIT NIL ALLOC FREE TYPE ENDTYPE
%left AND OR
%left PLUS MINUS
%left MUL DIV MOD
%right NOT
%nonassoc LT GT NE EQ GE LE

%%

Program	: TypeDefBlock GdeclBlock FdefBlock MainBlock
	| TypeDefBlock GdeclBlock MainBlock 
	;
TypeDefBlock : TYPE TypeDefList ENDTYPE
	|
	;
TypeDefList : TypeDefList TypeDef
	| TypeDef
	;
TypeDef : ID '{' FieldDeclList '}'
				{
					TInstall($1->name,0,Fhead);
					Fhead = Ftail = NULL;
				}
	;
FieldDeclList : FieldDeclList FieldDecl
	| FieldDecl
	;
FieldDecl : TypeName ID ';'	{FInstall(TypeID, $2->name);}
	;
TypeName : INT			{TypeID = TLookup("integer");}
	| STR			{TypeID = TLookup("string");}
	| ID			{
					TypeID = TLookup($1->name);
					if(TypeID == NULL)
						TypeID = TLookup("type");
				}
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
	|
	;
GdeclList : GdeclList GDecl 
	| GDecl
	;
GDecl	: Type GidList ';'
	;
Type 	: INT			{TypeID = TLookup("integer");}
	| STR			{TypeID = TLookup("string");}
	| ID			{TypeID = TLookup($1->name);}
	;
GidList : GidList ',' Gid
	| Gid
	;
Gid	: ID			{GInstall(NODE_ID,$1->name,TypeID,1,1,NULL);}
	| ID '[' NUM ']'	{GInstall(NODE_ARRAY,$1->name,TypeID,1,$3->intval,NULL);}
	| ID '[' NUM ']' '[' NUM ']'
				{GInstall(NODE_MATRIX,$1->name,TypeID,$3->intval,$6->intval,NULL);}
	| ID '(' ParamList ')'	{
					GInstall(NODE_FUN,$1->name,TypeID,0,0,Phead);
					Phead = Ptail = NULL;
					pbindno = 0;
				}
	| MUL ID		{GInstall(NODE_PTR,$2->name,TypeID,1,1,NULL);}
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
			Gtemp = GLookup($2->name);
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
Param 	: Type ID	{PInstall(NODE_ID,$2->name,TypeID);}
	| Type MUL ID	{PInstall(NODE_PTR,$3->name,TypeID);}
	;
LdeclBlock : DECL LDecList ENDDECL 
	| DECL ENDDECL
	|
	;
LDecList : LDecList LDecl 
	| LDecl	
	;
LDecl	: Type IdList ';'
	;
IdList	: IdList ',' Lid
	| Lid
	;
Lid	: ID		{LInstall(NODE_ID,$1->name,TypeID);}
	| MUL ID	{LInstall(NODE_PTR,$2->name,TypeID);}
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
Slist	: Slist Stmt ';'	{$$ = createTree(0,NULL, TLookup("void"),NULL,NODE_BODY,$1,NULL,$2);}
	| Stmt ';'		{$$ = $1;}
	;
Stmt 	: Input | Output | AsgStmt | IfStmt | WhileStmt
				{$$ = $1;}
	| BREAK			{$$ = createTree(0,NULL, TLookup("void"),NULL,NODE_BREAK,NULL,NULL,NULL);}
	| CONTINUE		{$$ = createTree(0,NULL, TLookup("void"),NULL,NODE_CONTINUE,NULL,NULL,NULL);}
	| RETURN Expr		{$$ = createTree(0,NULL, TLookup("void"),NULL,NODE_RET,NULL,$2,NULL);}
	| FREE '(' IDaddress ')' 
				{
					if(!($3->nodetype == NODE_ID_ADDRESS || $3->nodetype == NODE_FIELD_ADDRESS))
					{
						printf("ERROR:FREE argument invalid\n");
						exit(1);
					}
					$$ = createTree(0,NULL, TLookup("void"),NULL,NODE_FREE,NULL,$3,NULL);
				}
	;
IfStmt 	: IF '(' Expr ')' THEN Slist ELSE Slist ENDIF 
				{$$=createTree(0,NULL, TLookup("boolean"),NULL,NODE_IF_THEN_ELSE,$3,$6,$8);}
	| IF '(' Expr ')' THEN Slist ENDIF
				{$$=createTree(0,NULL, TLookup("boolean"),NULL,NODE_IF_THEN_ELSE,$3,$6,NULL);}
	;
WhileStmt : WHILE '(' Expr ')' DO Slist ENDWHILE
				{$$=createTree(0,NULL, TLookup("boolean"),NULL,NODE_WHILE_DO,$3,NULL,$6);}
	| DO Slist WHILE '(' Expr ')'
				{$$=createTree(0,NULL, TLookup("boolean"),NULL,NODE_DO_WHILE,$2,NULL,$5);}
	| REPEAT Slist UNTIL '(' Expr ')'
				{$$=createTree(0,NULL, TLookup("boolean"),NULL,NODE_REP_UNTIL,$2,NULL,$5);}
	;
Output	: WRITE '(' Expr ')'	{$$ = createTree(0,NULL, TLookup("void"),NULL,NODE_WRITE,NULL,$3,NULL);}
	;
Input	: READ '(' IDaddress ')'{$$ = createTree(0,NULL, TLookup("void"),NULL,NODE_READ,NULL,$3,NULL);}
	;
AsgStmt : IDaddress ASSIGN Expr	{$$ = createTree(0,NULL, TLookup("void"),NULL,NODE_ASSIGN,$1,NULL,$3);}
	;
IDaddress : ID			{
					IDCheck($1);
					$$ = createTree(0,NULL, $1->type,$1->name,NODE_ID_ADDRESS,NULL,NULL,NULL);
				}
	| Field '.' ID		{
					struct Fieldlist *Ftemp = FLookup($1->type,$3->name);
					if(Ftemp == NULL)
					{
						printf("ERROR:Unknown identifier in FIELD: %s\n",$3->name);
					}
					$$ = createTree(0,NULL,$3->type,NULL,NODE_FIELD_ADDRESS,$1,NULL,$3);
				}
	| ID '.' ID 		{
					struct Fieldlist *Ftemp = FLookup($1->type,$3->name);
					if(Ftemp == NULL)
					{
						printf("ERROR:Unknown identifier in FIELD: %s\n",$3->name);
					}
					$$ = createTree(0,NULL,$3->type,NULL,NODE_FIELD_ADDRESS,$1,NULL,$3);
				}
	| MUL ID		{
					IDCheck($2);
					$$ = createTree(0,NULL, $2->type,$2->name,NODE_ID,NULL,NULL,NULL);
				}
	| ID '[' Expr ']'	{
					IDCheck($1);
					$1->nodetype = NODE_ID_ADDRESS;
					$$ = createTree(0,NULL, $1->type,$1->name,NODE_ARRAY_ADDRESS,$1,$3,NULL);
				}
	| ID '[' Expr ']' '[' Expr ']'
				{
					IDCheck($1);
					$1->nodetype = NODE_ID_ADDRESS;
					$$ = createTree(0,NULL, $1->type,$1->name,NODE_MATRIX_ADDRESS,$1,$3,$6);
				}
	;
Expr 	: Expr PLUS Expr 	{
					TypeCheck($1->type,$3->type,NODE_PLUS);
					$$ = createTree(0,NULL, TLookup("integer"),NULL,NODE_PLUS,$1,NULL,$3);
				}
	| Expr MINUS Expr 	{
					TypeCheck($1->type,$3->type,NODE_MINUS);
					$$ = createTree(0,NULL, TLookup("integer"),NULL,NODE_MINUS,$1,NULL,$3);
				}
	| Expr MUL Expr 	{
					TypeCheck($1->type,$3->type,NODE_MUL);
					$$ = createTree(0,NULL, TLookup("integer"),NULL,NODE_MUL,$1,NULL,$3);
				}
	| Expr DIV Expr 	{
					TypeCheck($1->type,$3->type,NODE_DIV);
					$$ = createTree(0,NULL, TLookup("integer"),NULL,NODE_DIV,$1,NULL,$3);
				}
	| Expr MOD Expr 	{
					TypeCheck($1->type,$3->type,NODE_MOD);
					$$ = createTree(0,NULL, TLookup("integer"),NULL,NODE_MOD,$1,NULL,$3);
				}
	| Expr AND Expr		{
					TypeCheck($1->type,$3->type,NODE_AND);
					$$ = createTree(0,NULL, TLookup("boolean"),NULL,NODE_AND,$1,NULL,$3);
				}
	| Expr OR Expr		{
					TypeCheck($1->type,$3->type,NODE_OR);
					$$ = createTree(0,NULL, TLookup("boolean"),NULL,NODE_OR,$1,NULL,$3);
				}
	| Expr EQ Expr 		{
					TypeCheck($1->type,$3->type,NODE_EQ);
					$$ = createTree(0,NULL, TLookup("boolean"),NULL,NODE_EQ,$1,NULL,$3);
				}
	| Expr NE Expr 		{
					TypeCheck($1->type,$3->type,NODE_NE);
					$$ = createTree(0,NULL, TLookup("boolean"),NULL,NODE_NE,$1,NULL,$3);
				}
	| Expr LE Expr	 	{
					TypeCheck($1->type,$3->type,NODE_LE);
					$$ = createTree(0,NULL, TLookup("boolean"),NULL,NODE_LE,$1,NULL,$3);
				}
	| Expr GE Expr 		{
					TypeCheck($1->type,$3->type,NODE_GE);
					$$ = createTree(0,NULL, TLookup("boolean"),NULL,NODE_GE,$1,NULL,$3);
				}
	| Expr LT Expr 		{
					TypeCheck($1->type,$3->type,NODE_LT);
					$$ = createTree(0,NULL, TLookup("boolean"),NULL,NODE_LT,$1,NULL,$3);
				}
	| Expr GT Expr  	{
					TypeCheck($1->type,$3->type,NODE_GT);
					$$ = createTree(0,NULL, TLookup("boolean"),NULL,NODE_GT,$1,NULL,$3);
				}
	| NOT Expr		{$$ = createTree(0,NULL, TLookup("boolean"),NULL,NODE_NOT,NULL,$2,NULL);}
	| NIL			{$$ = createTree(0,NULL, TLookup("null"),NULL,NODE_NIL,NULL,NULL,NULL);}
	| '(' Expr ')' 		{$$ = $2;}
	| NUM			{$$ = $1;}
	| ID			{
					IDCheck($1);
					$$ = $1;
				}
	| ID '[' Expr ']'	{
					IDCheck($1);
					$$ = createTree(0,NULL, $1->type,$1->name,NODE_ARRAY,$1,$3,NULL);
				}
	| ID '[' Expr ']' '[' Expr ']'
				{
					IDCheck($1);
					$$ = createTree(0,NULL, $1->type,$1->name,NODE_MATRIX,$1,$3,$6);
				}
	| MUL ID		{
					IDCheck($2);
					$$ = createTree(0,NULL, $2->type,$2->name,NODE_ID_VALPTR,NULL,NULL,NULL);
				}
	| '&' ID		{
					IDCheck($2);
					$$ = createTree(0,NULL, $2->type,$2->name,NODE_ID_ADDRESS,NULL,NULL,NULL);
				}
	| ALLOC '(' ')'		{$$ = createTree(0,NULL, TLookup("null"),NULL,NODE_ALLOC,NULL,NULL,NULL);}
	| INIT '(' ')'		{$$ = createTree(0,NULL, TLookup("integer"),NULL,NODE_INIT,NULL,NULL,NULL);}
	| ID '(' ArgList ')'
		{
			struct Gsymbol *gtemp,*gtemp1;
			struct Paramstruct *ptemp;
			struct tnode *atemp;
			gtemp = GLookup($1->name);
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
			$$ = createTree(0,NULL, gtemp->type,$1->name,NODE_FUN,NULL,$3,NULL);
		}
	| Field			{$$ = $1;}
	;
ArgList : ArgList ',' Expr 	{
					struct tnode *temp = $1;
					while(temp->ArgList!=NULL)
						temp = temp->ArgList;
					temp->ArgList = $3;
					$$ = $1;
				}
	| Expr			{$$ = $1;}
	|			{$$ = NULL;}
	;
Field	: Field '.' ID 		{
					struct Fieldlist *Ftemp = FLookup($1->type,$3->name);
					if(Ftemp == NULL)
					{
						printf("ERROR:Unknown identifier in FIELD: %s\n",$3->name);
						exit(1);
					}
					$$ = createTree(0,NULL,Ftemp->type,NULL,NODE_FIELD,$1,NULL,$3);
				}
	| ID '.' ID 		{
					struct Fieldlist *Ftemp = FLookup($1->type,$3->name);
					if(Ftemp == NULL)
					{
						printf("ERROR:Unknown identifier in FIELD: %s\n",$3->name);
						exit(1);
					}
					$$ = createTree(0,NULL,Ftemp->type,NULL,NODE_FIELD,$1,NULL,$3);
				}
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
	TypeTableCreate();
	yyparse();
	return 0;
}
