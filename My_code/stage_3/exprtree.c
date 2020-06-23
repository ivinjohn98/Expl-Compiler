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

int getlooplabelcontinue()
{
	return looptail->co;
}

int getlooplabelbreak()
{
	return looptail->br;
}


void removeloop()
{
	struct looptable *temp;
	temp = looptail;
	if(temp->right == NULL)
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

int getResultReg(struct tnode *t)
{
	int x,z;	
	if(t->nodetype == NODE_ID)
	{
		x = getReg();
		z = codeGen(t);
		fprintf(target_file,"MOV R%d, [%d]\n",x,z);
	}
	else
	{
		x = codeGen(t);
	}
	return x;
}

struct tnode* createTree(int val, int type, char varname, int nodetype, struct tnode *l, struct tnode *m, struct tnode *r)
{
	struct tnode *temp;
	temp = (struct tnode*)malloc(sizeof(struct tnode));
	temp->nodetype = nodetype;
	temp->type = type;
	temp->val = val;
	temp->varname = varname;
	temp->mid = m;
	temp->left = l;
	temp->right = r;
	switch(nodetype)
	{
		case NODE_ID:
			break;
		case NODE_NUM:
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
			if ((l->type != inttype) || (r->type != inttype))
			{
				error("type mismatch");
				exit(1);
			}
			break;
		case NODE_IF_THEN_ELSE:
		case NODE_WHILE_DO:
			if (l->type != booltype)
			{
				error("type mismatch");
				exit(1);
			}
			break;
		case NODE_DO_WHILE:
		case NODE_REP_UNTIL:
			if (r->type != booltype)
			{
				error("type mismatch");
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
		case NODE_ID:
		{
			return (t->varname)-'a'+4096;
		}
			break;
		case NODE_NUM:
		{
			x = getReg();
			fprintf(target_file,"MOV R%d, %d\n",x,t->val);
			return x;
		}
			break;
		case NODE_ASSIGN:
		{
			y = getResultReg(t->right);
			x = (t->left->varname)-'a'+4096;
			fprintf(target_file,"MOV [%d], R%d\n",x,y);
			freeReg();
			return -1;
		}
			break;
		case NODE_PLUS:
		{			
			x = getResultReg(t->left);
			y = getResultReg(t->right);
			fprintf(target_file,"ADD R%d, R%d\n",x,y);
			freeReg();
			return x;
		}
			break;
		case NODE_MINUS:
		{
			x = getResultReg(t->left);
			y = getResultReg(t->right);
			fprintf(target_file,"SUB R%d, R%d\n",x,y);
			freeReg();
			return x;
		}
			break;
		case NODE_DIV:
		{
			x = getResultReg(t->left);
			y = getResultReg(t->right);
			fprintf(target_file,"DIV R%d, R%d\n",x,y);
			freeReg();
			return x;
		}
			break;
		case NODE_MUL:
		{
			x = getResultReg(t->left);
			y = getResultReg(t->right);
			fprintf(target_file,"MUL R%d, R%d\n",x,y);
			freeReg();
			return x;
		}
			break;
		case NODE_MOD:
		{
			x = getResultReg(t->left);
			y = getResultReg(t->right);
			fprintf(target_file,"MOD R%d, R%d\n",x,y);
			freeReg();
			return x;
		}
			break;
		case NODE_EQ:
		{
			x = getResultReg(t->left);
			y = getResultReg(t->right);
			fprintf(target_file,"EQ R%d, R%d\n",x,y);
			freeReg();
			return x;
		}
			break;
		case NODE_NE:
		{
			x = getResultReg(t->left);
			y = getResultReg(t->right);
			fprintf(target_file,"NE R%d, R%d\n",x,y);
			freeReg();
			return x;
		}
			break;
		case NODE_LE:
		{
			x = getResultReg(t->left);
			y = getResultReg(t->right);
			fprintf(target_file,"LE R%d, R%d\n",x,y);
			freeReg();
			return x;
		}
			break;
		case NODE_GE:
		{
			x = getResultReg(t->left);
			y = getResultReg(t->right);
			fprintf(target_file,"GE R%d, R%d\n",x,y);
			freeReg();
			return x;
		}
			break;
		case NODE_LT:
		{
			x = getResultReg(t->left);
			y = getResultReg(t->right);
			fprintf(target_file,"LT R%d, R%d\n",x,y);
			freeReg();
			return x;
		}
			break;
		case NODE_GT:
		{
			x = getResultReg(t->left);
			y = getResultReg(t->right);
			fprintf(target_file,"GT R%d, R%d\n",x,y);
			freeReg();
			return x;
		}
			break;
		case NODE_BODY:
		{
			x = codeGen(t->left);
			y = codeGen(t->right);
			return -1;
		}
			break;
		case NODE_READ:
		{	x = getReg();
			y = getReg();
			z = getReg();
			fprintf(target_file,"MOV R%d, \"Read\"\n",z);
			fprintf(target_file,"PUSH R%d\n",z);
			fprintf(target_file,"MOV R%d, -1\n",z);
			fprintf(target_file,"PUSH R%d\n",z);
			fprintf(target_file,"MOV R%d, %d\n",z,(t->right->varname)-'a'+4096);
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
		}
			break;
		case NODE_WRITE:
		{	
			x = getReg();
			y = getReg();
			z = getReg();
			fprintf(target_file,"MOV R%d, \"Write\"\n",z);
			fprintf(target_file,"PUSH R%d\n",z);
			fprintf(target_file,"MOV R%d, -2\n",z);
			fprintf(target_file,"PUSH R%d\n",z);
			if(t->right->nodetype == NODE_ID)
			{
				w = codeGen(t->right);
				fprintf(target_file,"MOV R%d, [%d]\n",z,w);
			}
			else
			{
				w = codeGen(t->right);
				fprintf(target_file,"MOV R%d, R%d\n",z,w);
			}
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
		}
			break;
		case NODE_IF_THEN_ELSE:
		{
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
			}
			return -1;
		}
			break;
		case NODE_WHILE_DO:
		{
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
			return -1;
		}
			break;
		case NODE_REP_UNTIL:
		case NODE_DO_WHILE:
		{
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
			return -1;
		}
			break;
		case NODE_BREAK:
		{
			fprintf(target_file,"JMP L%d:\n",getlooplabelbreak());
			return -1;
		}
		case NODE_CONTINUE:
		{
			fprintf(target_file,"JMP L%d:\n",getlooplabelcontinue());
			return -1;
		}
			break;
	}
}

int evaluate(struct tnode *t)
{
	int x, y, z;
	if(t == NULL)
		return -1;
	switch(t->nodetype)
	{
		case NODE_BODY:
			x = evaluate(t->left);
			return evaluate(t->right);
		case NODE_ID:
			return (t->varname -'a');
			break;
		case NODE_ASSIGN:
		{	
			var[(t->left->varname)-'a'] = evaluate(t->right);
			return 1;
		}
			break;
		case NODE_NUM:
			return t->val;
			break;
		case NODE_PLUS:
		{
			if(t->left->nodetype == NODE_ID)
				x = var[(t->left->varname)-'a'];
			else
				x = evaluate(t->left);
			if(t->right->nodetype == NODE_ID)
				y = var[(t->right->varname)-'a'];
			else
				y = evaluate(t->right);
			return x + y;
		}
			break;
		case NODE_MINUS:
		{
			if(t->left->nodetype == NODE_ID)
				x = var[(t->left->varname)-'a'];
			else
				x = evaluate(t->left);
			if(t->right->nodetype == NODE_ID)
				y = var[(t->right->varname)-'a'];
			else
				y = evaluate(t->right);
			return x - y;
		}
			break;
		case NODE_DIV:
		{
			if(t->left->nodetype == NODE_ID)
				x = var[(t->left->varname)-'a'];
			else
				x = evaluate(t->left);
			if(t->right->nodetype == NODE_ID)
				y = var[(t->right->varname)-'a'];
			else
				y = evaluate(t->right);
			return x / y;
		}
			break;
		case NODE_MUL:
		{
			if(t->left->nodetype == NODE_ID)
				x = var[(t->left->varname)-'a'];
			else
				x = evaluate(t->left);
			if(t->right->nodetype == NODE_ID)
				y = var[(t->right->varname)-'a'];
			else
				y = evaluate(t->right);
			return x * y;
		}
			break;
		case NODE_MOD:
		{
			if(t->left->nodetype == NODE_ID)
				x = var[(t->left->varname)-'a'];
			else
				x = evaluate(t->left);
			if(t->right->nodetype == NODE_ID)
				y = var[(t->right->varname)-'a'];
			else
				y = evaluate(t->right);
			return x % y;
		}
			break;
		case NODE_READ:
			scanf("%d",&x);
			var[(t->right->varname)-'a'] = x;
			return 1;
			break;
		case NODE_WRITE:
			if(t->right->nodetype == NODE_ID)
				x = var[(t->right->varname)-'a'];
			else
				x = evaluate(t->right);
			printf("%d",x);
			return 1;
			break;
		case NODE_IF_THEN_ELSE:
		{
			if(evaluate(t->left))
				return evaluate(t->mid);
			else
				return evaluate(t->right);
		}
			break;
		case NODE_WHILE_DO:
		case NODE_REP_UNTIL:
		case NODE_DO_WHILE:
			return -1;
			break;
	}
}
