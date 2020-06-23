typedef struct tnode
{
	int val; //value of for the expression tree
	char *op; //indicates the opertor branch
	struct tnode *left,*right; //left and right branches
}tnode;
	
static int reg=-1;
FILE *target_file;

/*Make a leaf tnode and set the value of val field*/
struct tnode* makeLeafNode(int n);

/*Make a tnode with opertor, left and right branches set*/
struct tnode* makeOperatorNode(char c,struct tnode *l,struct tnode *r);

int codeGen(struct tnode *t);

int getReg(void);
void freeReg(void);
