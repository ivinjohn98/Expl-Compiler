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

void print_postfix(struct tnode *t)
{
    if(t->op == NULL){
        printf("%d ",t->val);
    }
    else
	{
		print_postfix(t->left);
		print_postfix(t->right);
        switch(*(t->op)){
            case '+' : printf("+ ");
                       break;
            case '-' : printf("- ");
                       break;
            case '*' : printf("* ");
                       break;
            case '/' : printf("/ ");
                       break;
        }
    }
}
