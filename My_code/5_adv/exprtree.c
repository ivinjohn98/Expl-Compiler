int getReg()
{
	if(reg>=20){
		printf("Out of registers\n");
		exit(1);
	}
	return ++reg;
}

void freeReg()
{
	if(reg>=0)
		--reg;
	else
	{
		printf("No registers allocated\n");
		exit(1);
	}
}

int getFun()
{
	return ++Flab;
}

int getLabel()
{
	return ++lab;
}

void GInstall(int nodetype,char *name, int type, int size1, int size2,struct Paramstruct *ParamList)
{
	struct Gsymbol *temp;
	temp = GLookup(name);
	if(temp != NULL)
	{
		printf("Error:Multiple declarations");
		exit(1);
	}
	temp = (struct Gsymbol*)malloc(sizeof(struct Gsymbol));
	temp->nodetype = nodetype;
	temp->name = name;
	temp->type = type;
	temp->size1 = size1;
	temp->size2 = size2;
	temp->binding = bindno+1;
	temp->ParamList = ParamList;
	temp->flabel = -1;
	switch(nodetype)
	{
		case NODE_FUN:
			temp->flabel = getFun();
		case NODE_MATRIX:
		case NODE_ARRAY:
		case NODE_ID:
		case NODE_PTR:
			break;
		default:
			printf("Error\n");
			exit(1);
	}
	temp->next = NULL;
	if(Ghead == NULL)
	{
		Ghead = temp;
		Gtail = temp;
	}
	else
	{
		Gtail->next = temp;
		Gtail = temp;
	}
	bindno = bindno + size1*size2;
}

struct Gsymbol* GLookup(char *name)
{
	if(name==NULL)
		return NULL;
	struct Gsymbol *temp=NULL;
	temp = Ghead;
	while(temp!=NULL)
	{
		if(!strcmp(temp->name,name))
			return temp;
		temp=temp->next;
	}
	return NULL;
}

void LInstall(int nodetype,char *name,int type)
{
	struct Lsymbol *temp;
	temp = LLookup(name);
	if(temp != NULL)
	{
		printf("Error:Multiple declarations");
		exit(1);
	}
	temp = (struct Lsymbol*)malloc(sizeof(struct Lsymbol));
	temp->nodetype = nodetype;
	temp->name = name;
	temp->type = type;
	temp->binding = ++lbindno;
	temp->next = NULL;
	if(Lhead == NULL)
	{
		Lhead = temp;
		Ltail = temp;
	}
	else
	{
		Ltail->next = temp;
		Ltail = temp;
	}
}

struct Lsymbol* LLookup(char *name)
{
	if(name==NULL)
		return NULL;
	struct Lsymbol *temp=NULL;
	temp = Lhead;
	while(temp!=NULL)
	{
		if(!strcmp(temp->name,name))
			return temp;
		temp=temp->next;
	}
	return NULL;
}

void PInstall(int nodetype,char *name, int type)
{
	struct Paramstruct *temp;
	temp = PLookup(name);
	if(temp != NULL)
	{
		printf("Error:Multiple declarations");
		exit(1);
	}
	temp = (struct Paramstruct*)malloc(sizeof(struct Paramstruct));
	temp->nodetype = nodetype;
	temp->name = name;
	temp->type = type;
	temp->binding = ++pbindno;
	temp->next = NULL;
	if(Phead == NULL)
	{
		Phead = temp;
		Ptail = temp;
	}
	else
	{
		Ptail->next = temp;
		Ptail = temp;
	}
}

struct Paramstruct* PLookup(char *name)
{
	if(name==NULL)
		return NULL;
	struct Paramstruct *temp=NULL;
	temp = Phead;
	while(temp!=NULL)
	{
		if(!strcmp(temp->name,name))
			return temp;
		temp=temp->next;
	}
	return NULL;
}

void addloop(int co,int br)
{
	struct looptable *temp;
	temp = (struct looptable*)malloc(sizeof(struct looptable));
	temp->co = co;
	temp->br = br;
	temp->left = NULL;
	temp->right = NULL;
	if(loophead == NULL)
	{
		loophead = temp;
		looptail = temp;
	}
	else
	{
		looptail->right = temp;
		temp->left = looptail;
		looptail = temp;
	}
}

void removeloop()
{
	struct looptable *temp;
	temp = looptail;
	if(looptail == loophead)
	{
		looptail = NULL;
		loophead = NULL;
	}
	else
	{
		looptail = looptail->left;
		looptail->right = NULL;
		temp->left = NULL;
	}
	free(temp);
}

void fun_to_reverse_push_arguments(struct tnode *temp)
{
	int x;
	if(temp != NULL)
	{
		fun_to_reverse_push_arguments(temp->ArgList);
		x = codeGen(temp);
		fprintf(target_file,"PUSH R%d\n",x);
		freeReg();
	}
}

struct tnode* createTree(int intval,char *strval, int type, char* varname, int nodetype, struct tnode *l, struct tnode *m, struct tnode *r)
{
	struct tnode *temp;
	temp = (struct tnode*)malloc(sizeof(struct tnode));
	temp->nodetype = nodetype;
	temp->type = type;
	temp->intval = intval;
	temp->strval = strval;
	temp->varname = varname;
	temp->mid = m;
	temp->left = l;
	temp->right = r;
	temp->Gentry = NULL;
	temp->Lentry =  NULL;
	temp->ArgList = NULL;
	switch(nodetype)
	{
		case NODE_NUM:
		case NODE_STR:
			break;
		case NODE_ARRAY:
		case NODE_MATRIX:
		case NODE_ID_VALPTR:
		case NODE_ID:
		case NODE_FUN:
		case NODE_STAR_FUN:
		case NODE_ARRAY_ADDRESS:
		case NODE_MATRIX_ADDRESS:
			temp->Gentry = GLookup(varname);
			break;
		case NODE_PLUS:
		case NODE_MINUS:
		case NODE_DIV:
		case NODE_MUL:
		case NODE_MOD:
		case NODE_LT:
		case NODE_GT:
		case NODE_NE:
		case NODE_EQ:
		case NODE_LE:
		case NODE_GE:
		case NODE_ASSIGN:
			if ((l->type != INTTYPE) || (r->type != INTTYPE))
			{
				printf("Error:type mismatch");
				exit(1);
			}
			break;
		case NODE_IF_THEN_ELSE:
		case NODE_WHILE_DO:
			if (l->type != BOOLTYPE)
			{
				printf("Error:type mismatch");
				exit(1);
			}
			break;
		case NODE_DO_WHILE:
		case NODE_REP_UNTIL:
			if (r->type != BOOLTYPE)
			{
				printf("Error:type mismatch");
				exit(1);
			}
			break;
		case NODE_READ:
		case NODE_WRITE:
		case NODE_BODY:
			break;
	}
	return temp;
}

int codeGen(struct tnode *t)
{
	int x, y, z, w;
	struct Gsymbol *Gtemp;
	struct Lsymbol *Ltemp;
	struct Paramstruct *Ptemp;
	struct tnode *Ntemp;

	struct Gsymbol *temp=NULL;
	struct Paramstruct *temp1;
	if(t == NULL)
		return -1;
	//printf("reg:%d\n",reg);
	//printf("node:%d\n",t->nodetype);
	switch(t->nodetype)
	{
		case NODE_NUM:
			x = getReg();
			fprintf(target_file,"MOV R%d, %d\n",x,t->intval);
			return x;
		case NODE_ID:
		case NODE_ID_ADDRESS:
		case NODE_ID_VALPTR:
			Ltemp=LLookup(t->varname);
			Ptemp=PLookup(t->varname);
			Gtemp=GLookup(t->varname);
			x = getReg();
			if(Ltemp != NULL)
			{
				fprintf(target_file,"MOV R%d, BP\n",x);
				fprintf(target_file,"ADD R%d, %d\n",x,Ltemp->binding);
			}
			else if(Ptemp != NULL)
			{
				fprintf(target_file,"MOV R%d, BP\n",x);
				fprintf(target_file,"SUB R%d, %d\n",x,Ptemp->binding+2);
			}
			else
				fprintf(target_file,"MOV R%d, %d\n",x,Gtemp->binding);
			switch(t->nodetype)
			{
				case NODE_ID:
					fprintf(target_file,"MOV R%d, [R%d]\n",x,x);
					return x;
				case NODE_ID_ADDRESS:
					return x;
				case NODE_ID_VALPTR:
					fprintf(target_file,"MOV R%d, [R%d]\n",x,x);
					fprintf(target_file,"MOV R%d, [R%d]\n",x,x);
					return x;
			}
		case NODE_ARRAY:
			x = codeGen(t->mid);
			fprintf(target_file,"ADD R%d, %d\n",x,t->Gentry->binding);
			fprintf(target_file,"MOV R%d, [R%d]\n",x,x);
			return x;
		case NODE_ARRAY_ADDRESS:
			x = codeGen(t->mid);
			fprintf(target_file,"ADD R%d, %d\n",x,t->Gentry->binding);
			return x;
		case NODE_MATRIX_ADDRESS:
			x = getReg();
			fprintf(target_file,"MOV R%d, %d\n",x,t->Gentry->size2);
			y = codeGen(t->mid);
			fprintf(target_file,"MUL R%d, R%d\n",x,y);
			freeReg();
			y = codeGen(t->right);
			fprintf(target_file,"ADD R%d, R%d\n",x,y);
			freeReg();
			z = t->left->Gentry->binding;
			fprintf(target_file,"ADD R%d, %d\n",x,z);
			return x;
		case NODE_MATRIX:
			x = getReg();
			fprintf(target_file,"MOV R%d, %d\n",x,t->Gentry->size2);
			y = codeGen(t->mid);
			fprintf(target_file,"MUL R%d, R%d\n",x,y);
			freeReg();
			y = codeGen(t->right);
			fprintf(target_file,"ADD R%d, R%d\n",x,y);
			freeReg();
			z = t->left->Gentry->binding;
			fprintf(target_file,"ADD R%d, %d\n",x,z);
			fprintf(target_file,"MOV R%d, [R%d]\n",x,x);
			return x;
		case NODE_STR:
			x = getReg();
			fprintf(target_file,"MOV R%d, %s\n", x, t->strval);
			return x;
		case NODE_FUN:
		case NODE_STAR_FUN:
			y = reg;
			z = getReg();
			freeReg();
			while(reg != -1)
			{
				fprintf(target_file,"PUSH R%d\n",reg);
				freeReg();
			}
			fun_to_reverse_push_arguments(t->mid);
			fprintf(target_file,"PUSH R%d\n",getReg()); //return value
			freeReg();
			fprintf(target_file,"CALL F%d:\n",t->Gentry->flabel);
			fprintf(target_file,"POP R%d\n",z);
			x = getReg();
			Ntemp = t->mid;
			while(Ntemp != NULL)
			{
				fprintf(target_file,"POP R%d\n",x);
				Ntemp = Ntemp->ArgList;
			}
			freeReg();
			while(y!=reg)
			{
				x = getReg();
				fprintf(target_file,"POP R%d\n",x);				
			}
			x = getReg();
			if(t->nodetype == NODE_STAR_FUN)
			{
				fprintf(target_file,"MOV R%d, [R%d]",z,z);
			}
			return z;
		case NODE_RET:
			x = getReg();
			fprintf(target_file,"MOV R%d, BP\n",x);
			fprintf(target_file,"SUB R%d, 2\n",x);
			y = codeGen(t->mid);
			fprintf(target_file,"MOV [R%d], R%d\n",x,y);
			freeReg();
			freeReg();
			return -1;
		case NODE_ASSIGN:
			x = codeGen(t->left);
			y = codeGen(t->right);
			fprintf(target_file,"MOV [R%d], R%d\n",x,y);
			freeReg();
			freeReg();
			return -1;
		case NODE_NOT:
			return -1;
		case NODE_PLUS:		
			x = codeGen(t->left);
			y = codeGen(t->right);
			fprintf(target_file,"ADD R%d, R%d\n",x,y);
			freeReg();
			return x;
		case NODE_MINUS:
			x = codeGen(t->left);
			y = codeGen(t->right);
			fprintf(target_file,"SUB R%d, R%d\n",x,y);
			freeReg();
			return x;
		case NODE_DIV:
			x = codeGen(t->left);
			y = codeGen(t->right);
			fprintf(target_file,"DIV R%d, R%d\n",x,y);
			freeReg();
			return x;
		case NODE_MUL:
			x = codeGen(t->left);
			y = codeGen(t->right);
			fprintf(target_file,"MUL R%d, R%d\n",x,y);
			freeReg();
			return x;
		case NODE_MOD:
			x = codeGen(t->left);
			y = codeGen(t->right);
			fprintf(target_file,"MOD R%d, R%d\n",x,y);
			freeReg();
			return x;
		case NODE_AND:
			x = codeGen(t->left);
			y = codeGen(t->right);
			fprintf(target_file,"MUL R%d, R%d\n",x,y);
			freeReg();
			return x;
		case NODE_OR:
			x = codeGen(t->left);
			y = codeGen(t->right);
			fprintf(target_file,"ADD R%d, R%d\n",x,y);
			fprintf(target_file,"MOV R%d, 1\n",y);
			fprintf(target_file,"GE R%d, R%d\n",x,y);
			freeReg();
			return x;
		case NODE_EQ:
			x = codeGen(t->left);
			y = codeGen(t->right);
			fprintf(target_file,"EQ R%d, R%d\n",x,y);
			freeReg();
			return x;
		case NODE_NE:
			x = codeGen(t->left);
			y = codeGen(t->right);
			fprintf(target_file,"NE R%d, R%d\n",x,y);
			freeReg();
			return x;
		case NODE_LE:
			x = codeGen(t->left);
			y = codeGen(t->right);
			fprintf(target_file,"LE R%d, R%d\n",x,y);
			freeReg();
			return x;
		case NODE_GE:
			x = codeGen(t->left);
			y = codeGen(t->right);
			fprintf(target_file,"GE R%d, R%d\n",x,y);
			freeReg();
			return x;
		case NODE_LT:
			x = codeGen(t->left);
			y = codeGen(t->right);
			fprintf(target_file,"LT R%d, R%d\n",x,y);
			freeReg();
			return x;
		case NODE_GT:
			x = codeGen(t->left);
			y = codeGen(t->right);
			fprintf(target_file,"GT R%d, R%d\n",x,y);
			freeReg();
			return x;
		case NODE_BODY:
			x = codeGen(t->left);
			y = codeGen(t->right);
			return -1;
		case NODE_READ:
			x = getReg();
			y = getReg();
			z = getReg();
			fprintf(target_file,"MOV R%d, \"Read\"\n",z);
			fprintf(target_file,"PUSH R%d\n",z);
			fprintf(target_file,"MOV R%d, -1\n",z);
			fprintf(target_file,"PUSH R%d\n",z);
			w = codeGen(t->mid);
			fprintf(target_file,"MOV R%d, R%d\n",z,w);
			freeReg();
			fprintf(target_file,"PUSH R%d\n",z);
			fprintf(target_file,"PUSH R%d\n",z);
			fprintf(target_file,"PUSH R%d\n",z);
			fprintf(target_file,"CALL 0\n");
			fprintf(target_file,"POP R%d\n",x);
			fprintf(target_file,"POP R%d\n",y);
			fprintf(target_file,"POP R%d\n",y);
			fprintf(target_file,"POP R%d\n",y);
			fprintf(target_file,"POP R%d\n",y);
			freeReg();
			freeReg();
			freeReg();
			return -1;
		case NODE_WRITE:	
			x = getReg();
			y = getReg();
			z = getReg();
			fprintf(target_file,"MOV R%d, \"Write\"\n",z);
			fprintf(target_file,"PUSH R%d\n",z);
			fprintf(target_file,"MOV R%d, -2\n",z);
			fprintf(target_file,"PUSH R%d\n",z);
			w = codeGen(t->mid);
			fprintf(target_file,"MOV R%d, R%d\n",z,w);
			freeReg();
			fprintf(target_file,"PUSH R%d\n",z);
			fprintf(target_file,"PUSH R%d\n",z);
			fprintf(target_file,"PUSH R%d\n",z);
			fprintf(target_file,"CALL 0\n");
			fprintf(target_file,"POP R%d\n",x);
			fprintf(target_file,"POP R%d\n",y);
			fprintf(target_file,"POP R%d\n",y);
			fprintf(target_file,"POP R%d\n",y);
			fprintf(target_file,"POP R%d\n",y);
			freeReg();
			freeReg();
			freeReg();
			return -1;
		case NODE_IF_THEN_ELSE:
			x = codeGen(t->left);
			y = getLabel();
			z = getLabel();
			fprintf(target_file,"JZ R%d, L%d:\n",x,y);
			freeReg();
			x = codeGen(t->mid);
			if(t->right == NULL)
			{
				fprintf(target_file,"L%d:\n",y);
			}
			else
			{
				fprintf(target_file,"JMP L%d:\n",z);
				fprintf(target_file,"L%d:\n",y);
				x = codeGen(t->right);
				fprintf(target_file,"L%d:\n",z);
			}
			return -1;
		case NODE_WHILE_DO:
			z = getLabel();
			y = getLabel();
			addloop(z,y);
			fprintf(target_file,"L%d:\n",z);
			x = codeGen(t->left);
			fprintf(target_file,"JZ R%d, L%d:\n",x,y);
			freeReg();		
			x = codeGen(t->right);
			fprintf(target_file,"JMP L%d:\n",z);
			fprintf(target_file,"L%d:\n",y);
			removeloop();
			return -1;
		case NODE_REP_UNTIL:
		case NODE_DO_WHILE:
			z = getLabel();
			y = getLabel();
			w = getLabel();
			addloop(y,w);
			fprintf(target_file,"L%d:\n",z);
			x = codeGen(t->left);
			fprintf(target_file,"L%d:\n",y);
			x = codeGen(t->right);
			fprintf(target_file,"JNZ R%d, L%d:\n",x,z);
			freeReg();
			fprintf(target_file,"L%d:\n",w);
			removeloop();
			return -1;
		case NODE_BREAK:
			fprintf(target_file,"JMP L%d:\n",looptail->br);
			return -1;
		case NODE_CONTINUE:
			fprintf(target_file,"JMP L%d:\n",looptail->co);
			return -1;
		default:
			printf("Error\n");
			exit(1);
	}
}
