struct tnode* makeLeafNode(int n){
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->op = NULL;
    temp->val = n;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct tnode* makeOperatorNode(char c,struct tnode *l,struct tnode *r){
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->op = malloc(sizeof(char));
    *(temp->op) = c;
    temp->left = l;
    temp->right = r;
    return temp;
}

void print_prefix(struct tnode *t)
{   
	if(t->op == NULL)
	{
        printf("%d ",t->val);
    }
    else
	{
		switch(*(t->op))
		{
            case '+' : printf("+ ");
                       break;
            case '-' : printf("- ");
                       break;
            case '*' : printf("* ");
                       break;
            case '/' : printf("/ ");
                       break;
        }
		print_prefix(t->left);
		print_prefix(t->right);
    }
}
