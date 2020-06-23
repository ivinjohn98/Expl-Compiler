struct tnode* makeLeafNode(char* n)
{
	struct tnode *temp;
	temp = (struct tnode*)malloc(sizeof(struct tnode));
	temp->op = NULL;
	temp->str = n;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

struct tnode* makeOperatorNode(char c,struct tnode *l,struct tnode *r)
{
	struct tnode *temp;
	temp = (struct tnode*)malloc(sizeof(struct tnode));
	temp->op = malloc(sizeof(char));
	*(temp->op) = c;
	temp->left = l;
	temp->right = r;
	return temp;
}

void prefix_fun(struct tnode *t)
{	
	if((t->op)== NULL)
	{
		printf("%s ",t->str);
	}
	else
	{
		printf("%c ",*(t->op));
		prefix_fun(t->left);
		prefix_fun(t->right);
	}
}
