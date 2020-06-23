#define NODE_ID 0
#define NODE_NUM 1
#define NODE_STR 2
#define NODE_ARRAY 3
#define NODE_MATRIX 4
#define NODE_ID_ADDRESS 5
#define NODE_ARRAY_ADDRESS 6
#define NODE_MATRIX_ADDRESS 7
#define NODE_ID_VALPTR 8
#define NODE_PTR 9
#define NODE_FIELD_ADDRESS 10

#define NODE_LT 14
#define NODE_GT 15
#define NODE_LE 16
#define NODE_GE 17
#define NODE_NE 18
#define NODE_EQ 19

#define NODE_ASSIGN 20
#define NODE_PLUS 21
#define NODE_MINUS 22
#define NODE_MUL 23
#define NODE_DIV 24
#define NODE_MOD 25
#define NODE_AND 26
#define NODE_OR 27
#define NODE_NOT 28
#define NODE_NEG 29

#define NODE_FIELD 30
#define NODE_ALLOC 31
#define NODE_FREE 32
#define NODE_INIT 33
#define NODE_NIL 34
#define NODE_NEW 35
#define NODE_DELETE 36

#define NODE_CONTINUE 38
#define NODE_BREAK 39

#define NODE_BODY 40
#define NODE_WRITE 41
#define NODE_READ 42
#define NODE_IF_THEN_ELSE 43
#define NODE_WHILE_DO 44
#define NODE_DO_WHILE 45
#define NODE_REP_UNTIL 46
#define NODE_FUN 47
#define NODE_RET 48

#define NODE_CLASS_FUN 50
#define NODE_FIELD_SELF 51
#define NODE_FIELD_SELF_ADDRESS 52
#define NODE_CLASS_ASSIGN 53
#define NODE_CLASS_ASSIGN_NIL 54

typedef struct tnode
{
	int intval;
	char *strval;
	struct Typetable *type; //pointer to the Typetable entry of variable type/return type of the function
	struct Classtable *Ctype;
	char* name;	//name of a variable for ID nodes  
	int nodetype;	// information about non-leaf nodes - read/write/connector/+/* etc.
	struct tnode *ArgList; 
	struct Gsymbol *Gentry;	//pointer to GST entry for global variables and functions
	struct tnode *left, *mid ,*right;	//left and right branches
	struct Lsymbol *Lentry;
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
	char *name; //name of the variable or function
	struct Typetable *type; //pointer to the Typetable entry of variable type/return type of the function
	struct Classtable *Ctype; //THIS FIELD IS REQUIRED ONLY FOR OEXPL
	int size1, size2; //size of an array
	int binding; //static binding of global variables
	int nodetype;
	struct Paramstruct *ParamList;//pointer to the head of the formal parameter list
	int flabel; //a label for identifying the starting address of a function's code
	struct Gsymbol *next; //points to the next Global Symbol Table entry
}Gsymbol; 

typedef struct Lsymbol
{
	char *name;	//name of the variable
	struct Typetable *type; //pointer to the Typetable entry of variable type/return type of the function
	int binding;	//local binding of the variable
	int nodetype;
	struct Lsymbol *next;	//points to the next Local Symbol Table entry
}Lsymbol; 

typedef struct Paramstruct
{
	char* name;
	struct Typetable *type; //pointer to the Typetable entry of variable type/return type of the function
	int binding;
	int nodetype;
	struct Paramstruct *next;
}Paramstruct;

struct Typetable
{
	char *name;                 //type name
	int size;                   //size of the type
	struct Fieldlist *fields;   //pointer to the head of fields list
	struct Typetable *next;     // pointer to the next type table entry
};

struct Classtable
{
 	char *name;                           //name of the class
	struct Fieldlist *Memberfield;        //pointer to Fieldlist 
	struct Memberfunclist *Vfuncptr;      //pointer to Memberfunclist
	struct Classtable *Parentptr;         //pointer to the parent's class table
	int Class_index;                      //position of the class in the virtual function table
	int Fieldcount;                       //count of fields
  	int Methodcount;                      //count of methods
	struct Classtable *next;              //pointer to next class table entry
};

struct Fieldlist
{
	char *name;			//name of the field
	int fieldIndex;			//position of the field
	struct Typetable *type;		//pointer to typetable 
	struct Classtable *Ctype;	//pointer to the class containing the field
	struct Fieldlist *next;		//pointer to next fieldlist entry
};

struct Memberfunclist 
{
 	char *name;                      //name of the member function in the class
	struct Typetable *type;          //pointer to typetable
	struct Paramstruct *paramlist;   //pointer to the head of the formal parameter list
	int Funcposition;                //position of the function in the class table
 	int Flabel;                      //A label for identifying the starting address of the function's code in the memory
	struct Memberfunclist *next;     //pointer to next Memberfunclist entry
};

static struct Paramstruct *Phead=NULL,*Ptail=NULL;
static struct looptable *loophead=NULL,*looptail=NULL;
static struct Gsymbol *Ghead=NULL,*Gtail=NULL;
static struct Lsymbol *Lhead=NULL,*Ltail=NULL;
static struct Typetable *Thead=NULL,*Ttail=NULL,*TypeID=NULL;
static struct Fieldlist *Fhead=NULL,*Ftail=NULL;
static struct Classtable *Chead=NULL,*Ctail=NULL,*Cptr=NULL,*CTypeID=NULL;
static struct Memberfunclist *Mhead=NULL,*Mtail=NULL;
static int reg = -1,usedreg=-1,lab = -1,Flab = -1,bindno = 4095,lbindno = 0,pbindno = 0,ClassI = -1,fieldindex = -1,Memposition = -1;
FILE *target_file,*input_file;

/*Create a node tnode*/
struct tnode* createTree(int intval,char *strval,struct Typetable *type, char* name, int nodetype, struct tnode *l, struct tnode *m, struct tnode *r);
void GInstall(int nodetype,char *name, struct Typetable *type,struct Classtable *Ctype, int size1,int size2,struct Paramstruct *ParamList);
void PInstall(int nodetype,char *name,struct Typetable *type);
void LInstall(int nodetype,char *name,struct Typetable *type);
struct Gsymbol* GLookup(char * name);
struct Lsymbol* LLookup(char *name);
struct Paramstruct* PLookup(char *name);
void TypeTableCreate();
struct Typetable* TLookup(char *name);
void TInstall(char *name,int size,struct Fieldlist *fields);
void FInstall(struct Typetable *type, char *name);
struct Fieldlist* FLookup(struct Typetable *type, char *name);
int GetSize (struct Typetable *type);
struct Classtable* CInstall(char *name,char *parent_class_name);
struct Classtable* CLookup(char *name);
void Class_FInstall(struct Classtable *cptr, char *typename, char *name);
struct Fieldlist* Class_Flookup(struct Classtable* Ctype,char* name);
void Class_MInstall(struct Classtable *cptr, char *name, struct Typetable *type, struct Paramstruct *Paramlist);
struct Memberfunclist* Class_Mlookup(struct Classtable* Ctype,char* name);

void IDCheck(struct tnode *t);
void addloop(int co,int br);
void removeloop();
int codeGen(struct tnode *t);
void pushReg();
void popReg();
int getReg(void);
void freeReg(void);
int getLabel();
int getFun();
