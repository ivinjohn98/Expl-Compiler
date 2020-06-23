#define NODE_ID 0
#define NODE_NUM 1

#define NODE_LT 10
#define NODE_GT 11
#define NODE_LE 12
#define NODE_GE 13
#define NODE_NE 14
#define NODE_EQ 15

#define NODE_ASSIGN 16
#define NODE_PLUS 21
#define NODE_MINUS 22
#define NODE_MUL 23
#define NODE_DIV 24
#define NODE_MOD 25
#define NODE_AND 26
#define NODE_OR 27
#define NODE_NOT 28
#define NODE_NEG 29

#define NODE_CONTINUE 38
#define NODE_BREAK 39

#define NODE_BODY 40
#define NODE_WRITE 41
#define NODE_READ 42
#define NODE_IF_THEN_ELSE 43
#define NODE_WHILE_DO 44
#define NODE_DO_WHILE 45
#define NODE_REP_UNTIL 46

#define inttype 1
#define booltype 0

typedef struct tnode
{
	int val;	// value of a number for NUM nodes.
	int type;	//type of variable
	char varname;	//name of a variable for ID nodes  
	int nodetype;  // information about non-leaf nodes - read/write/connector/+/* etc.  
	struct tnode *left, *mid ,*right;	//left and right branches
}tnode;

typedef struct looptable
{
	int co;
	int br;
	struct looptable *left;
	struct looptable *right;
}looptable;

static struct looptable *loophead=NULL,*looptail=NULL;
static int reg = -1,lab = -1;
int var[26];
FILE *target_file;

/*Create a node tnode*/
struct tnode* createTree(int val, int type, char varname, int nodetype, struct tnode *l, struct tnode *m, struct tnode *r);

int codeGen(struct tnode *t);
int getReg(void);
void freeReg(void);
int getResultReg(struct tnode *t);
