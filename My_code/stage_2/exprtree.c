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

struct tnode* createTree(int val, int type, char varname, int nodetype, struct tnode *l, struct tnode *r)
{
	struct tnode *temp;
	temp = (struct tnode*)malloc(sizeof(struct tnode));
	temp->nodetype = nodetype;
	switch(nodetype)
	{
		case NODE_ID:
			temp->varname = varname;
			temp->left = NULL;
			temp->right = NULL;
		case NODE_NUM:
			temp->val = val;
			temp->left = NULL;
			temp->right = NULL;
			break;
		case NODE_PLUS:
		case NODE_MINUS:
		case NODE_DIV:
		case NODE_MUL:
		case NODE_MOD:
		case NODE_ASSIGN:
		case NODE_BODY:
			temp->left = l;
			temp->right = r;
			break;
		case NODE_READ:
		case NODE_WRITE:
			temp->left =NULL;
			temp->right =r;
			break;
	}
	return temp;
}

int codeGen(struct tnode *t)
{
	int x, y, z,w;
	if(t == NULL)
		return -1;
	switch(t->nodetype)
	{
		case NODE_ID:
		{
			return (t->varname)-'a'+4096;
		}
			break;
		case NODE_ASSIGN:
		{
			if(t->right->nodetype == NODE_ID)
			{
				y = getReg();
				z = codeGen(t->right);
				fprintf(target_file,"MOV R%d, [%d]\n",y,z);
			}
			else
			{
				y = codeGen(t->right);
			}
			x = (t->left->varname)-'a'+4096;
			fprintf(target_file,"MOV [%d], R%d\n",x,y);
			freeReg();
			return -1;
		}
			break;
		case NODE_NUM:
		{	x = getReg();
			fprintf(target_file,"MOV R%d, %d\n",x,t->val);
			return x;
		}
			break;
		case NODE_PLUS:
		{			
			if(t->left->nodetype == NODE_ID)
			{
				x = getReg();
				z = codeGen(t->left);
				fprintf(target_file,"MOV R%d, [%d]\n",x,z);
			}
			else
			{
				x = codeGen(t->left);
			}
			if(t->right->nodetype == NODE_ID)
			{
				y = getReg();
				z = codeGen(t->right);
				fprintf(target_file,"MOV R%d, [%d]\n",y,z);
			}
			else
			{
				y = codeGen(t->right);
			}
			fprintf(target_file,"ADD R%d, R%d\n",x,y);
			freeReg();
			return x;
		}
			break;
		case NODE_MINUS:
		{
			if(t->left->nodetype == NODE_ID)
			{
				x = getReg();
				z = codeGen(t->left);
				fprintf(target_file,"MOV R%d, [%d]\n",x,z);
			}
			else
			{
				x = codeGen(t->left);
			}
			if(t->right->nodetype == NODE_ID)
			{
				y = getReg();
				z = codeGen(t->right);
				fprintf(target_file,"MOV R%d, [%d]\n",y,z);
			}
			else
			{
				y = codeGen(t->right);
			}
			fprintf(target_file,"SUB R%d, R%d\n",x,y);
			freeReg();
			return x;
		}
			break;
		case NODE_DIV:
		{
			if(t->left->nodetype == NODE_ID)
			{
				x = getReg();
				z = codeGen(t->left);
				fprintf(target_file,"MOV R%d, [%d]\n",x,z);
			}
			else
			{
				x = codeGen(t->left);
			}
			if(t->right->nodetype == NODE_ID)
			{
				y = getReg();
				z = codeGen(t->right);
				fprintf(target_file,"MOV R%d, [%d]\n",y,z);
			}
			else
			{
				y = codeGen(t->right);
			}
			x = codeGen(t->left);
			y = codeGen(t->right);
			fprintf(target_file,"DIV R%d, R%d\n",x,y);
			freeReg();
			return x;
		}
			break;
		case NODE_MUL:
		{
			if(t->left->nodetype == NODE_ID)
			{
				x = getReg();
				z = codeGen(t->left);
				fprintf(target_file,"MOV R%d, [%d]\n",x,z);
			}
			else
			{
				x = codeGen(t->left);
			}
			if(t->right->nodetype == NODE_ID)
			{
				y = getReg();
				z = codeGen(t->right);
				fprintf(target_file,"MOV R%d, [%d]\n",y,z);
			}
			else
			{
				y = codeGen(t->right);
			}
			fprintf(target_file,"MUL R%d, R%d\n",x,y);
			freeReg();
			return x;
		}
			break;
		case NODE_MOD:
		{
			if(t->left->nodetype == NODE_ID)
			{
				x = getReg();
				z = codeGen(t->left);
				fprintf(target_file,"MOV R%d, [%d]\n",x,z);
			}
			else
			{
				x = codeGen(t->left);
			}
			if(t->right->nodetype == NODE_ID)
			{
				y = getReg();
				z = codeGen(t->right);
				fprintf(target_file,"MOV R%d, [%d]\n",y,z);
			}
			else
			{
				y = codeGen(t->right);
			}
			fprintf(target_file,"MOD R%d, R%d\n",x,y);
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
				x = codeGen(t->right);
				fprintf(target_file,"MOV R%d, R%d\n",z,x);
			}
			fprintf(target_file,"PUSH R%d\n",z);
			fprintf(target_file,"PUSH R%d\n",z);
			fprintf(target_file,"PUSH R%d\n",z);
			fprintf(target_file,"CALL 0\n");
			fprintf(target_file,"POP R%d\n",z);
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
	}
}
