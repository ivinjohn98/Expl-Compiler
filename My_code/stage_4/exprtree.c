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
		reg--;
}

int getLabel()
{
	return ++lab;
}

void GInstall(char *name, int type, int size1, int size2,int ptr)
{
	struct Gsymbol *temp;
	temp = Lookup(name);
	if(temp != NULL)
	{
		printf("Error:Multiple declarations");
		exit(1);
	}
	temp = (struct Gsymbol*)malloc(sizeof(struct Gsymbol));
	temp->name = name;
	temp->type = type;
	temp->size1 = size1;
	temp->size2 = size2;
	temp->binding = bindno+1;
	temp->ptr = ptr;
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

struct Gsymbol* Lookup(char *name)
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
	temp->Gentry = Lookup(temp->varname);
	switch(nodetype)
	{
		case NODE_ID:
		{
			temp->Gentry = Lookup(temp->varname);
		}
			break;
		case NODE_NUM:
		case NODE_STR:
		case NODE_ARRAY:
		case NODE_MATRIX:
		case NODE_ID_VALPTR:
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
	if(t == NULL)
		return -1;
	switch(t->nodetype)
	{
		case NODE_NUM:
			x = getReg();
			fprintf(target_file,"MOV R%d, %d\n",x,t->intval);
			return x;
		case NODE_ID:
			x = getReg();
			fprintf(target_file,"MOV R%d, %d\n",x,t->Gentry->binding);
			fprintf(target_file,"MOV R%d, [R%d]\n",x,x);
			return x;
		case NODE_ID_ADDRESS:
			x = getReg();
			fprintf(target_file,"MOV R%d, %d\n",x,t->Gentry->binding);
			return x;
		case NODE_ID_VALPTR:
			x = getReg();
			fprintf(target_file,"MOV R%d, %d\n",x,t->Gentry->binding);
			fprintf(target_file,"MOV R%d, [R%d]\n",x,x);
			fprintf(target_file,"MOV R%d, [R%d]\n",x,x);
			return x;
		case NODE_ARRAY_ADDRESS:
			x = codeGen(t->right);
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
		case NODE_ARRAY:
			x = codeGen(t->right);
			fprintf(target_file,"ADD R%d, %d\n",x,t->Gentry->binding);
			fprintf(target_file,"MOV R%d, [R%d]\n",x,x);
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
			fprintf(target_file, "MOV R%d, %s\n", x, t->strval);
			return x;
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
			fprintf(target_file,"AND R%d, R%d\n",x,y);
			freeReg();
			return x;
		case NODE_OR:
			x = codeGen(t->left);
			y = codeGen(t->right);
			fprintf(target_file,"OR R%d, R%d\n",x,y);
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
			freeReg();
			freeReg();
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
			return x;
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
			return x;
		case NODE_IF_THEN_ELSE:
			x = codeGen(t->left);
			y = getLabel();
			z = getLabel();
			fprintf(target_file,"JZ R%d, L%d:\n",x,y);
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
				freeReg();
			}
			freeReg();
			freeReg();
			return -1;
		case NODE_WHILE_DO:
			z = getLabel();
			y = getLabel();
			addloop(z,y);
			fprintf(target_file,"L%d:\n",z);
			x = codeGen(t->left);
			fprintf(target_file,"JZ R%d, L%d:\n",x,y);		
			x = codeGen(t->right);
			fprintf(target_file,"JMP L%d:\n",z);
			fprintf(target_file,"L%d:\n",y);
			removeloop();
			freeReg();
			freeReg();
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
			fprintf(target_file,"L%d:\n",w);
			removeloop();
			freeReg();
			freeReg();
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
