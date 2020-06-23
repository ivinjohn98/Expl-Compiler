#define NODE_ID 0
#define NODE_NUM 1
#define NODE_STR 2
#define NODE_ARRAY 3
#define NODE_MATRIX 4
#define NODE_ID_ADDRESS 5
#define NODE_ARRAY_ADDRESS 6
#define NODE_MATRIX_ADDRESS 7
#define NODE_ID_VALPTR 8

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

#define BOOLTYPE 0
#define INTTYPE 1
#define STRTYPE 2
#define PTRTYPE 3

typedef struct tnode
{
	int intval;
	char *strval;
	int type;	//type of variable
	char* varname;	//name of a variable for ID nodes  
	int nodetype;  // information about non-leaf nodes - read/write/connector/+/* etc.  
	struct Gsymbol *Gentry;	//pointer to GST entry for global variables and functions
	struct tnode *left, *mid ,*right;	//left and right branches
}tnode;

typedef struct looptable
{
	int co;
	int br;
	struct looptable *left;
	struct looptable *right;
}looptable;

typedef struct Gsymbol
{
	char *name;	// name of the variable
	int type;	// type of the variable
	int size1;	// size1 of the type of the variable
	int size2;	// size1 of the type of the variable
	int binding;	// stores the static memory address allocated to the variable
	int ptr;	// type of the variable pointer
	struct Gsymbol *next;
}Gsymbol;

static struct looptable *loophead=NULL,*looptail=NULL;
static struct Gsymbol *Ghead=NULL,*Gtail=NULL;
static int reg = -1,lab = -1,bindno = 4095,count=0;
int var[26],typeID;
FILE *target_file,*input_file;

/*Create a node tnode*/
struct tnode* createTree(int intval,char *strval,int type, char* varname, int nodetype, struct tnode *l, struct tnode *m, struct tnode *r);
// Returns a pointer to the symbol table entry for the variable, returns NULL otherwise.
struct Gsymbol *Lookup(char * name);
// Creates a symbol table entry.
void GInstall(char *name, int type, int size1,int size2,int ptr);

int codeGen(struct tnode *t);
int getReg(void);
void freeReg(void);
int getResultReg(struct tnode *t);
