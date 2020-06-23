/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "exprtree.y" /* yacc.c:339  */

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "exprtree.h"
	#include "exprtree.c"
	FILE *yyin;
	int yylex();
	void yyerror(const char *s);
	int x;

#line 78 "exprtree.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    MAIN = 258,
    START = 259,
    ASSIGN = 260,
    READ = 261,
    WRITE = 262,
    ID = 263,
    NUM = 264,
    PLUS = 265,
    MINUS = 266,
    MUL = 267,
    DIV = 268,
    END = 269,
    MOD = 270,
    IF = 271,
    THEN = 272,
    ELSE = 273,
    ENDIF = 274,
    WHILE = 275,
    DO = 276,
    ENDWHILE = 277,
    REPEAT = 278,
    UNTIL = 279,
    BREAK = 280,
    CONTINUE = 281,
    LT = 282,
    GT = 283,
    NE = 284,
    EQ = 285,
    GE = 286,
    LE = 287,
    STR = 288,
    INT = 289,
    DECL = 290,
    ENDDECL = 291,
    NOT = 292,
    RETURN = 293,
    INIT = 294,
    NIL = 295,
    ALLOC = 296,
    FREE = 297,
    TYPE = 298,
    ENDTYPE = 299,
    CLASS = 300,
    ENDCLASS = 301,
    EXTENDS = 302,
    NEW = 303,
    DELETE = 304,
    SELF = 305,
    AND = 306,
    OR = 307
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 13 "exprtree.y" /* yacc.c:355  */

	struct tnode *no;

#line 172 "exprtree.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 189 "exprtree.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   731

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  63
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  46
/* YYNRULES -- Number of rules.  */
#define YYNRULES  128
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  287

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   307

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    61,     2,
      56,    57,     2,     2,    58,     2,    62,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    55,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    59,     2,    60,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    53,     2,    54,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    28,    28,    29,    30,    32,    33,    35,    36,    38,
      44,    45,    47,    49,    50,    51,    57,    85,    86,    88,
     126,   127,   132,   133,   135,   142,   143,   145,   158,   159,
     161,   161,   190,   192,   193,   195,   197,   198,   199,   209,
     210,   212,   218,   219,   221,   226,   228,   229,   231,   307,
     308,   309,   311,   312,   314,   315,   316,   318,   319,   321,
     323,   324,   326,   327,   329,   354,   355,   357,   358,   360,
     360,   360,   360,   360,   362,   363,   364,   365,   374,   379,
     381,   384,   386,   388,   391,   393,   395,   423,   451,   456,
     463,   467,   472,   479,   483,   487,   491,   495,   499,   503,
     507,   511,   515,   519,   523,   527,   531,   532,   533,   534,
     535,   539,   543,   548,   552,   557,   558,   559,   592,   593,
     595,   602,   603,   605,   619,   634,   656,   678,   705
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "MAIN", "START", "ASSIGN", "READ",
  "WRITE", "ID", "NUM", "PLUS", "MINUS", "MUL", "DIV", "END", "MOD", "IF",
  "THEN", "ELSE", "ENDIF", "WHILE", "DO", "ENDWHILE", "REPEAT", "UNTIL",
  "BREAK", "CONTINUE", "LT", "GT", "NE", "EQ", "GE", "LE", "STR", "INT",
  "DECL", "ENDDECL", "NOT", "RETURN", "INIT", "NIL", "ALLOC", "FREE",
  "TYPE", "ENDTYPE", "CLASS", "ENDCLASS", "EXTENDS", "NEW", "DELETE",
  "SELF", "AND", "OR", "'{'", "'}'", "';'", "'('", "')'", "','", "'['",
  "']'", "'&'", "'.'", "$accept", "Program", "TypeDefBlock", "TypeDefList",
  "TypeDef", "FieldDeclList", "FieldDecl", "TypeName", "ClassDefBlock",
  "ClassDefList", "Classdef", "Cname", "Fieldlists", "Fld", "MethodDecl",
  "MDecl", "MethodDefns", "GdeclBlock", "GdeclList", "GDecl", "Type",
  "GidList", "Gid", "FdefBlock", "Fdef", "ParamList", "Param",
  "LdeclBlock", "LDecList", "LDecl", "IdList", "Lid", "MainBlock", "Body",
  "Slist", "Stmt", "IfStmt", "WhileStmt", "Output", "Input", "AsgStmt",
  "IDaddress", "Expr", "ArgList", "Field", "FieldFunction", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   123,   125,    59,    40,    41,    44,    91,
      93,    38,    46
};
# endif

#define YYPACT_NINF -132

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-132)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-1)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -29,    11,    31,    76,    -6,     0,  -132,  -132,    68,    53,
      34,   100,   168,  -132,  -132,  -132,  -132,  -132,  -132,    89,
    -132,    24,    28,     3,  -132,    40,   197,    74,   104,   100,
    -132,  -132,  -132,  -132,  -132,     8,  -132,   106,  -132,  -132,
       4,   118,    37,  -132,   120,  -132,  -132,   112,   100,    85,
      95,  -132,  -132,  -132,  -132,    90,   197,   157,  -132,  -132,
      24,  -132,  -132,  -132,   143,   197,  -132,    66,   128,  -132,
     137,  -132,   197,   167,   130,  -132,   202,  -132,   197,   170,
    -132,   110,  -132,   224,   204,   189,  -132,  -132,   237,   197,
    -132,   241,   140,   207,   250,   204,   205,    19,  -132,   219,
    -132,   197,  -132,   105,   363,  -132,   421,   235,   250,  -132,
    -132,  -132,   141,  -132,   276,    69,  -132,  -132,  -132,   234,
     243,    78,   300,  -132,   253,   260,   616,   616,  -132,  -132,
      -2,   261,   262,   269,   460,   277,  -132,  -132,  -132,  -132,
    -132,   328,   280,  -132,   297,   304,  -132,  -132,   105,     5,
      -2,    -2,   344,  -132,    -2,    -2,   655,   499,   -44,  -132,
     352,    -2,   305,  -132,   312,   307,    -2,   362,   679,   310,
    -132,     5,     5,   365,  -132,   319,  -132,    59,   367,  -132,
    -132,  -132,   322,   240,   152,  -132,   249,   283,   320,   324,
      -2,    -2,   373,  -132,   127,   325,   327,   377,   292,  -132,
      -2,    -2,    -2,    -2,    -2,    -2,    -2,    -2,    -2,    -2,
      -2,    -2,    -2,   383,   336,   338,  -132,  -132,   348,   679,
    -132,  -132,  -132,   347,   392,   389,    -2,    -2,   679,   187,
     162,   355,  -132,  -132,   356,  -132,   501,   501,   127,   127,
     127,   298,   298,   298,   298,   298,   298,   688,   688,   357,
    -132,  -132,   406,    -2,   616,   616,   326,   335,  -132,    -2,
     358,    -2,    -2,    -2,   359,   196,   382,   538,   389,  -132,
     679,    -2,   216,   225,   230,  -132,  -132,   616,  -132,  -132,
     206,  -132,  -132,  -132,   577,  -132,  -132
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       6,     0,     0,    32,     0,     0,     8,     1,     0,     0,
      32,     0,     0,     5,     7,    38,    37,    36,    30,     0,
      34,     0,    20,     0,    18,     0,     0,    36,     0,     0,
      47,     4,    15,    14,    13,     0,    11,     0,    31,    33,
      41,     0,     0,    40,     0,    16,    17,     0,     0,     0,
       0,    46,     3,     9,    10,     0,    51,     0,    45,    35,
       0,    21,    23,     2,     0,    51,    12,     0,     0,    50,
       0,    39,     0,     0,     0,    52,     0,    44,     0,    42,
      22,     0,    26,     0,    56,     0,    53,    49,     0,     0,
      25,     0,     0,     0,     0,    56,     0,     0,    29,     0,
      24,    51,    55,     0,     0,    58,     0,     0,     0,    43,
      19,    28,     0,    62,     0,     0,    61,    54,    57,     0,
       0,    88,     0,    66,     0,     0,     0,     0,    74,    75,
       0,     0,     0,     0,     0,     0,    72,    73,    70,    69,
      71,     0,    89,    64,     0,     0,    63,    59,     0,     0,
       0,     0,     0,    90,     0,     0,     0,     0,   110,   109,
       0,     0,     0,   107,     0,     0,     0,     0,    76,   118,
     119,     0,     0,     0,    65,     0,    68,     0,     0,    48,
      27,    60,     0,     0,     0,   124,     0,     0,     0,     0,
     122,     0,     0,   113,   106,     0,     0,     0,     0,   114,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   125,    67,     0,    86,
     123,    85,    84,    91,     0,     0,     0,     0,   121,     0,
       0,   124,   116,   115,   125,   108,    93,    94,    95,    96,
      97,   104,   105,   101,   100,   103,   102,    98,    99,   123,
      77,    78,     0,     0,     0,     0,     0,     0,   117,     0,
     111,   122,   122,   122,     0,     0,     0,     0,    82,    83,
     120,     0,     0,     0,     0,    87,    92,     0,    80,    81,
       0,   128,   126,   127,     0,   112,    79
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -132,  -132,  -132,  -132,   410,  -132,   384,  -132,  -132,  -132,
     395,  -132,  -132,  -132,  -132,   340,  -132,   412,  -132,   404,
      38,  -132,   366,   399,   -25,   -43,   360,   339,  -132,   332,
    -132,   282,   -24,   331,  -125,  -131,  -132,  -132,  -132,  -132,
    -132,   114,  -121,   -93,  -106,  -132
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     5,     6,    35,    36,    37,    10,    23,
      24,    25,    72,    80,    81,    82,    97,    11,    19,    20,
      28,    42,    43,    29,    30,    68,    69,    94,   104,   105,
     115,   116,    31,   107,   134,   135,   136,   137,   138,   139,
     140,   141,   228,   229,   169,   170
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     142,   156,   157,   175,    51,    52,   158,   159,     4,   168,
     160,    22,   190,   121,     1,   191,    32,   122,   192,     4,
     142,   142,    74,    51,    63,   175,   175,    15,   142,   183,
     184,     7,    40,   186,   187,   161,    41,   162,   163,   164,
     194,    33,    34,   142,    13,   198,    21,    12,   165,    45,
     142,   142,    16,    17,   166,   133,   219,    21,   112,   167,
      56,    22,    53,    57,    98,   142,   142,   158,   159,     8,
     230,   160,   111,   110,    75,    44,    15,    49,    76,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,    59,    47,    67,    60,   161,    15,   162,   163,
     164,    16,    17,    67,    18,   256,   257,   218,    15,   165,
      83,     8,    50,   113,    55,   166,    67,   114,    15,    91,
     167,     9,    16,    17,   147,    38,    58,   148,    61,   266,
     267,   103,   265,    16,    27,   175,   175,   151,   270,    67,
     152,    64,   103,    16,    17,    66,    89,    62,   142,   142,
     280,    65,   284,   175,   205,   206,   207,   208,   209,   210,
     142,   142,   200,   201,   202,   203,    70,   204,   272,   273,
     274,   142,   200,   201,   202,   203,    32,   204,   142,   205,
     206,   207,   208,   209,   210,    77,    78,    85,    78,   205,
     206,   207,   208,   209,   210,   100,   101,    79,   145,    78,
      73,    33,    34,   211,   212,    15,   200,   201,   202,   203,
      86,   204,   223,   211,   212,    15,   200,   201,   202,   203,
      84,   204,   260,   205,   206,   207,   208,   209,   210,    88,
      16,    17,    92,   205,   206,   207,   208,   209,   210,    93,
      16,    17,    95,   102,   258,   259,    96,   211,   212,    99,
     200,   201,   202,   203,   106,   204,   276,   211,   212,   200,
     201,   202,   203,   182,   204,   109,   285,   205,   206,   207,
     208,   209,   210,   281,   259,   101,   205,   206,   207,   208,
     209,   210,   282,   259,   146,   214,   215,   283,   259,   143,
     149,   211,   212,   200,   201,   202,   203,   222,   204,   150,
     211,   212,   200,   201,   202,   203,   224,   204,   153,   154,
     205,   206,   207,   208,   209,   210,   155,   171,   172,   205,
     206,   207,   208,   209,   210,    -1,    -1,    -1,    -1,    -1,
      -1,   173,   176,   177,   211,   212,   200,   201,   202,   203,
     225,   204,   178,   211,   212,   200,   201,   202,   203,   235,
     204,   179,   185,   205,   206,   207,   208,   209,   210,   180,
     193,   195,   205,   206,   207,   208,   209,   210,   196,   197,
     199,    15,   213,   216,   217,   220,   226,   211,   212,   221,
     227,   231,   232,   268,   233,   234,   211,   212,   119,   120,
     121,   249,   269,   250,   122,   251,    16,    17,   124,   117,
     277,   278,   125,   126,   252,   127,   253,   128,   129,   254,
     255,   261,   262,   263,   264,    14,   275,   271,    46,    54,
     130,    90,    26,    39,   131,    48,    71,   119,   120,   121,
     181,   132,   133,   122,   108,   123,   118,   124,    87,   144,
       0,   125,   126,     0,   127,     0,   128,   129,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   130,
       0,     0,     0,   131,     0,     0,   119,   120,   121,     0,
     132,   133,   122,     0,   174,     0,   124,     0,     0,     0,
     125,   126,     0,   127,     0,   128,   129,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   130,     0,
       0,     0,   131,     0,     0,   119,   120,   121,     0,   132,
     133,   122,     0,   202,   203,   124,   204,     0,     0,   125,
     126,     0,   127,   189,   128,   129,     0,     0,   205,   206,
     207,   208,   209,   210,     0,     0,     0,   130,     0,     0,
       0,   131,     0,     0,   119,   120,   121,     0,   132,   133,
     122,     0,     0,     0,   124,     0,     0,     0,   125,   126,
     279,   127,     0,   128,   129,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   130,     0,     0,     0,
     131,     0,     0,   119,   120,   121,     0,   132,   133,   122,
       0,     0,     0,   124,     0,     0,   286,   125,   126,     0,
     127,     0,   128,   129,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   130,     0,     0,     0,   131,
       0,     0,   119,   120,   121,     0,   132,   133,   122,     0,
       0,     0,   124,     0,     0,     0,   125,   126,     0,   127,
       0,   128,   129,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   130,     0,     0,     0,   131,     0,
       0,   119,   120,   121,     0,   132,   133,   122,     0,     0,
       0,   124,     0,     0,     0,   188,   126,     0,   127,     0,
     128,   129,     0,     0,     0,     0,     0,     0,     0,   200,
     201,   202,   203,   130,   204,     0,     0,   131,   200,   201,
     202,   203,     0,   204,   132,   133,   205,   206,   207,   208,
     209,   210,     0,     0,     0,   205,   206,   207,   208,   209,
     210,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     211,   212
};

static const yytype_int16 yycheck[] =
{
     106,   126,   127,   134,    29,    29,     8,     9,     8,   130,
      12,     8,    56,     8,    43,    59,     8,    12,    62,     8,
     126,   127,    65,    48,    48,   156,   157,     8,   134,   150,
     151,     0,     8,   154,   155,    37,    12,    39,    40,    41,
     161,    33,    34,   149,    44,   166,     8,    53,    50,    46,
     156,   157,    33,    34,    56,    50,   177,    19,   101,    61,
      56,     8,    54,    59,    89,   171,   172,     8,     9,    35,
     191,    12,    97,    54,     8,    47,     8,     3,    12,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,    55,    53,    56,    58,    37,     8,    39,    40,
      41,    33,    34,    65,    36,   226,   227,    48,     8,    50,
      72,    35,     8,     8,     8,    56,    78,    12,     8,    81,
      61,    45,    33,    34,    55,    36,     8,    58,     8,   254,
     255,    93,   253,    33,    34,   266,   267,    59,   259,   101,
      62,    56,   104,    33,    34,    55,    36,    35,   254,   255,
     271,    56,   277,   284,    27,    28,    29,    30,    31,    32,
     266,   267,    10,    11,    12,    13,     9,    15,   261,   262,
     263,   277,    10,    11,    12,    13,     8,    15,   284,    27,
      28,    29,    30,    31,    32,    57,    58,    57,    58,    27,
      28,    29,    30,    31,    32,    55,    56,    60,    57,    58,
      57,    33,    34,    51,    52,     8,    10,    11,    12,    13,
       8,    15,    60,    51,    52,     8,    10,    11,    12,    13,
      53,    15,    60,    27,    28,    29,    30,    31,    32,    59,
      33,    34,     8,    27,    28,    29,    30,    31,    32,    35,
      33,    34,    53,    36,    57,    58,     9,    51,    52,     8,
      10,    11,    12,    13,     4,    15,    60,    51,    52,    10,
      11,    12,    13,   149,    15,    60,    60,    27,    28,    29,
      30,    31,    32,    57,    58,    56,    27,    28,    29,    30,
      31,    32,    57,    58,     8,   171,   172,    57,    58,    54,
      56,    51,    52,    10,    11,    12,    13,    57,    15,    56,
      51,    52,    10,    11,    12,    13,    57,    15,     8,    56,
      27,    28,    29,    30,    31,    32,    56,    56,    56,    27,
      28,    29,    30,    31,    32,    27,    28,    29,    30,    31,
      32,    62,    55,     5,    51,    52,    10,    11,    12,    13,
      57,    15,    62,    51,    52,    10,    11,    12,    13,    57,
      15,    54,     8,    27,    28,    29,    30,    31,    32,    55,
       8,    56,    27,    28,    29,    30,    31,    32,    56,    62,
       8,     8,    62,     8,    55,     8,    56,    51,    52,    57,
      56,     8,    57,    57,    57,     8,    51,    52,     6,     7,
       8,     8,    57,    57,    12,    57,    33,    34,    16,    36,
      18,    19,    20,    21,    56,    23,    59,    25,    26,    17,
      21,    56,    56,    56,     8,     5,    57,    59,    23,    35,
      38,    81,    10,    19,    42,    26,    60,     6,     7,     8,
     148,    49,    50,    12,    95,    14,   104,    16,    78,   108,
      -1,    20,    21,    -1,    23,    -1,    25,    26,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      -1,    -1,    -1,    42,    -1,    -1,     6,     7,     8,    -1,
      49,    50,    12,    -1,    14,    -1,    16,    -1,    -1,    -1,
      20,    21,    -1,    23,    -1,    25,    26,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,
      -1,    -1,    42,    -1,    -1,     6,     7,     8,    -1,    49,
      50,    12,    -1,    12,    13,    16,    15,    -1,    -1,    20,
      21,    -1,    23,    24,    25,    26,    -1,    -1,    27,    28,
      29,    30,    31,    32,    -1,    -1,    -1,    38,    -1,    -1,
      -1,    42,    -1,    -1,     6,     7,     8,    -1,    49,    50,
      12,    -1,    -1,    -1,    16,    -1,    -1,    -1,    20,    21,
      22,    23,    -1,    25,    26,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,
      42,    -1,    -1,     6,     7,     8,    -1,    49,    50,    12,
      -1,    -1,    -1,    16,    -1,    -1,    19,    20,    21,    -1,
      23,    -1,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,    42,
      -1,    -1,     6,     7,     8,    -1,    49,    50,    12,    -1,
      -1,    -1,    16,    -1,    -1,    -1,    20,    21,    -1,    23,
      -1,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,    42,    -1,
      -1,     6,     7,     8,    -1,    49,    50,    12,    -1,    -1,
      -1,    16,    -1,    -1,    -1,    20,    21,    -1,    23,    -1,
      25,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    10,
      11,    12,    13,    38,    15,    -1,    -1,    42,    10,    11,
      12,    13,    -1,    15,    49,    50,    27,    28,    29,    30,
      31,    32,    -1,    -1,    -1,    27,    28,    29,    30,    31,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      51,    52
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    43,    64,    65,     8,    66,    67,     0,    35,    45,
      71,    80,    53,    44,    67,     8,    33,    34,    36,    81,
      82,    83,     8,    72,    73,    74,    80,    34,    83,    86,
      87,    95,     8,    33,    34,    68,    69,    70,    36,    82,
       8,    12,    84,    85,    47,    46,    73,    53,    86,     3,
       8,    87,    95,    54,    69,     8,    56,    59,     8,    55,
      58,     8,    35,    95,    56,    56,    55,    83,    88,    89,
       9,    85,    75,    57,    88,     8,    12,    57,    58,    60,
      76,    77,    78,    83,    53,    57,     8,    89,    59,    36,
      78,    83,     8,    35,    90,    53,     9,    79,    87,     8,
      55,    56,    36,    83,    91,    92,     4,    96,    90,    60,
      54,    87,    88,     8,    12,    93,    94,    36,    92,     6,
       7,     8,    12,    14,    16,    20,    21,    23,    25,    26,
      38,    42,    49,    50,    97,    98,    99,   100,   101,   102,
     103,   104,   107,    54,    96,    57,     8,    55,    58,    56,
      56,    59,    62,     8,    56,    56,    97,    97,     8,     9,
      12,    37,    39,    40,    41,    50,    56,    61,   105,   107,
     108,    56,    56,    62,    14,    98,    55,     5,    62,    54,
      55,    94,   104,   105,   105,     8,   105,   105,    20,    24,
      56,    59,    62,     8,   105,    56,    56,    62,   105,     8,
      10,    11,    12,    13,    15,    27,    28,    29,    30,    31,
      32,    51,    52,    62,   104,   104,     8,    55,    48,   105,
       8,    57,    57,    60,    57,    57,    56,    56,   105,   106,
     105,     8,    57,    57,     8,    57,   105,   105,   105,   105,
     105,   105,   105,   105,   105,   105,   105,   105,   105,     8,
      57,    57,    56,    59,    17,    21,   105,   105,    57,    58,
      60,    56,    56,    56,     8,   105,    97,    97,    57,    57,
     105,    59,   106,   106,   106,    57,    60,    18,    19,    22,
     105,    57,    57,    57,    97,    60,    19
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    63,    64,    64,    64,    65,    65,    66,    66,    67,
      68,    68,    69,    70,    70,    70,    71,    72,    72,    73,
      74,    74,    75,    75,    76,    77,    77,    78,    79,    79,
      80,    80,    80,    81,    81,    82,    83,    83,    83,    84,
      84,    85,    85,    85,    85,    85,    86,    86,    87,    88,
      88,    88,    89,    89,    90,    90,    90,    91,    91,    92,
      93,    93,    94,    94,    95,    96,    96,    97,    97,    98,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    99,
      99,   100,   100,   100,   101,   102,   103,   103,   104,   104,
     104,   104,   104,   105,   105,   105,   105,   105,   105,   105,
     105,   105,   105,   105,   105,   105,   105,   105,   105,   105,
     105,   105,   105,   105,   105,   105,   105,   105,   105,   105,
     106,   106,   106,   107,   107,   107,   108,   108,   108
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     4,     3,     3,     0,     2,     1,     4,
       2,     1,     3,     1,     1,     1,     3,     2,     1,     8,
       1,     3,     2,     0,     3,     2,     1,     6,     2,     1,
       2,     3,     0,     2,     1,     3,     1,     1,     1,     3,
       1,     1,     4,     7,     4,     2,     2,     1,     9,     3,
       1,     0,     2,     3,     3,     2,     0,     2,     1,     3,
       3,     1,     1,     2,     8,     3,     2,     3,     2,     1,
       1,     1,     1,     1,     1,     1,     2,     4,     4,     9,
       7,     7,     6,     6,     4,     4,     3,     6,     1,     1,
       2,     4,     7,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     1,     3,     1,
       1,     4,     7,     2,     2,     3,     3,     4,     1,     1,
       3,     1,     0,     3,     3,     3,     6,     6,     6
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 9:
#line 39 "exprtree.y" /* yacc.c:1646  */
    {
					TInstall((yyvsp[-3].no)->name,0,Fhead);
					Fhead = Ftail = NULL;
				}
#line 1555 "exprtree.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 47 "exprtree.y" /* yacc.c:1646  */
    {FInstall(TypeID, (yyvsp[-1].no)->name);}
#line 1561 "exprtree.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 49 "exprtree.y" /* yacc.c:1646  */
    {TypeID = TLookup("integer");}
#line 1567 "exprtree.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 50 "exprtree.y" /* yacc.c:1646  */
    {TypeID = TLookup("string");}
#line 1573 "exprtree.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 51 "exprtree.y" /* yacc.c:1646  */
    {
					TypeID = TLookup((yyvsp[0].no)->name);
					if(TypeID == NULL)
						TypeID = TLookup("type");
				}
#line 1583 "exprtree.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 58 "exprtree.y" /* yacc.c:1646  */
    {
					fprintf(target_file,"MOV SP, %d\n",bindno);
					struct Classtable *Ctemp = Chead;
					struct Memberfunclist *Mtemp;
					int i;
					while(Ctemp != NULL)
					{
						bindno += 8;
						Mtemp = Ctemp->Vfuncptr;
						i=0;
						while(Mtemp!=NULL)
						{
							fprintf(target_file,"MOV R0, F%d\n",Mtemp->Flabel);
							fprintf(target_file,"PUSH R0\n");
							i++;
							Mtemp=Mtemp->next;
						}
						fprintf(target_file, "MOV R0, -1\n");
						while(i<8)
						{
							fprintf(target_file, "PUSH R0\n");
							i++;
						}
						Ctemp=Ctemp->next;
					}
				}
#line 1614 "exprtree.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 89 "exprtree.y" /* yacc.c:1646  */
    {
			Cptr->Class_index = ++ClassI;
			struct Fieldlist *Ftemp = Fhead;
			struct Memberfunclist *Mtemp = Mhead;
			x = 0;
			while(Ftemp != NULL)
			{
				Ftemp->fieldIndex = x++;
				if(Ftemp->type == NULL)
					x++;
				Ftemp = Ftemp->next;
			}
			if(x > 8)
			{
				printf("ERROR:Number of memberfields exceeds 8");
				exit(1);
			}
			Cptr->Fieldcount = x;
			x = 0;
			while(Mtemp != NULL)
			{
				Mtemp->Funcposition = x++;
				Mtemp = Mtemp->next;
			}
			if(x > 8)
			{
				printf("ERROR:Number of memberfunctions exceeds 8");
				exit(1);
			}
			Cptr->Methodcount = x;
			Cptr->Memberfield = Fhead; 
			Cptr->Vfuncptr = Mhead;
			Fhead = Ftail = NULL;
			Mhead = Mtail = NULL;
			Cptr = NULL;
		}
#line 1655 "exprtree.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 126 "exprtree.y" /* yacc.c:1646  */
    {Cptr = CInstall((yyvsp[0].no)->name,NULL);}
#line 1661 "exprtree.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 127 "exprtree.y" /* yacc.c:1646  */
    {
					Cptr = CInstall((yyvsp[-2].no)->name,(yyvsp[0].no)->name);
					Inheritance_parent_copy_child(CLookup((yyvsp[0].no)->name),Cptr);
				}
#line 1670 "exprtree.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 135 "exprtree.y" /* yacc.c:1646  */
    {
					if(TypeID == NULL)
						Class_FInstall(Cptr,CTypeID->name,(yyvsp[-1].no)->name);
					else
						Class_FInstall(Cptr,TypeID->name,(yyvsp[-1].no)->name);
				}
#line 1681 "exprtree.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 146 "exprtree.y" /* yacc.c:1646  */
    {
					struct Typetable *Ttemp = TypeID;
					if(Ttemp != NULL)
						Class_MInstall(Cptr,(yyvsp[-4].no)->name,Ttemp,Phead);
					else
					{
						printf("ERROR:Memberfunction type not found %s",TypeID->name);
						exit(1);
					}
					Phead = Ptail = NULL;
				}
#line 1697 "exprtree.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 162 "exprtree.y" /* yacc.c:1646  */
    {
					fprintf(target_file,"MOV BP, %d\n",bindno+1);
					fprintf(target_file,"PUSH R0\n");
					fprintf(target_file,"CALL MAIN:\n");
					fprintf(target_file,"POP R0\n");
					fprintf(target_file,"INT 10\n");
					/*struct Gsymbol *temp=NULL;
					struct Paramstruct *temp1=NULL;
					temp = Ghead;
					while(temp!=NULL)
					{
						printf("name: %s\n",temp->name);
						printf("type: %d\n",temp->type);
						printf("size: %d\n",temp->size1);
						printf("size: %d\n",temp->size2);
						printf("binding: %d\n",temp->binding);
						if(temp->ParamList!=NULL)
						{
							temp1=temp->ParamList;
							while(temp1!=NULL)
							{
								printf("paramter: %s %d\n",temp1->name,temp1->type);
								temp1 = temp1->next;
							}
						}
						temp=temp->next;
					}*/
				}
#line 1730 "exprtree.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 197 "exprtree.y" /* yacc.c:1646  */
    {TypeID = TLookup("integer");}
#line 1736 "exprtree.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 198 "exprtree.y" /* yacc.c:1646  */
    {TypeID = TLookup("string");}
#line 1742 "exprtree.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 199 "exprtree.y" /* yacc.c:1646  */
    {
					TypeID = TLookup((yyvsp[0].no)->name);
					CTypeID = CLookup((yyvsp[0].no)->name);
					if(TypeID==NULL && CTypeID==NULL)
					{
						printf("Unknown type: %s\n", (yyvsp[0].no)->name);
						exit(1);
					}
				}
#line 1756 "exprtree.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 212 "exprtree.y" /* yacc.c:1646  */
    {
					if(Cptr == NULL)
						GInstall(NODE_ID,(yyvsp[0].no)->name,TypeID,Cptr,1,1,NULL);
					else
						GInstall(NODE_ID,(yyvsp[0].no)->name,TypeID,Cptr,1,2,NULL);
				}
#line 1767 "exprtree.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 218 "exprtree.y" /* yacc.c:1646  */
    {GInstall(NODE_ARRAY,(yyvsp[-3].no)->name,TypeID,NULL,1,(yyvsp[-1].no)->intval,NULL);}
#line 1773 "exprtree.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 220 "exprtree.y" /* yacc.c:1646  */
    {GInstall(NODE_MATRIX,(yyvsp[-6].no)->name,TypeID,NULL,(yyvsp[-4].no)->intval,(yyvsp[-1].no)->intval,NULL);}
#line 1779 "exprtree.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 221 "exprtree.y" /* yacc.c:1646  */
    {
					GInstall(NODE_FUN,(yyvsp[-3].no)->name,TypeID,NULL,0,0,Phead);
					Phead = Ptail = NULL;
					pbindno = 0;
				}
#line 1789 "exprtree.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 226 "exprtree.y" /* yacc.c:1646  */
    {GInstall(NODE_PTR,(yyvsp[0].no)->name,TypeID,NULL,1,1,NULL);}
#line 1795 "exprtree.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 232 "exprtree.y" /* yacc.c:1646  */
    {
			pbindno = 0;
			lbindno = 0;
			struct Gsymbol *Gtemp;
			struct Paramstruct *Ptemp,*Ptemp1;
			struct Lsymbol *Ltemp;
			struct Memberfunclist *Mtemp;
			int Pcount,Lcount;
			if(Cptr != NULL)
			{
				Mtemp = Class_Mlookup(Cptr,(yyvsp[-7].no)->name);
				if(Mtemp == NULL)
				{
					printf("ERROR:Memberfunction not declared\n");
					exit(1);
				}
				Ptemp = Mtemp->paramlist;
				x = Mtemp->Flabel;
			}
			else
			{
				Gtemp = GLookup((yyvsp[-7].no)->name);
				if(Gtemp == NULL)
				{
					printf("ERROR:function not declared\n");
					exit(1);
				}
				Ptemp = Gtemp->ParamList;
				x = Gtemp->flabel;
			}
			//checking match of function defintion with defintion
			Ptemp1 = Phead;
			while((Ptemp1!=NULL) && (Ptemp!=NULL))
			{
				if(!((Ptemp->nodetype == Ptemp1->nodetype) 
					&& (Ptemp->type == Ptemp1->type) 
					&& (!strcmp(Ptemp->name,Ptemp1->name))))
				{
					printf("ERROR:function parameter mismatch with defintion\n");
					exit(1);
				}
				Ptemp = Ptemp->next;
				Ptemp1 = Ptemp1->next;
			}
			if(!((Ptemp1==NULL) && (Ptemp==NULL)))
			{
				printf("ERROR:function parameter mismatch with defintion\n");
				exit(1);
			}
			//checking match of local variable with formal parameters
			Lcount = 0;
			Ltemp = Lhead;
			while(Ltemp!=NULL)
			{
				if(PLookup(Ltemp->name) != NULL)
				{
					printf("ERROR:function parameter matches with local variables\n");
					exit(1);
				}
				Lcount++;
				Ltemp = Ltemp->next;
			}
			fprintf(target_file,"F%d:\n",x);
			fprintf(target_file,"PUSH BP\n");
			fprintf(target_file,"MOV BP, SP\n");
			fprintf(target_file, "ADD SP, %d\n", Lcount);
			x = codeGen((yyvsp[-1].no));
			fprintf(target_file, "SUB SP, %d\n", Lcount);
			fprintf(target_file, "MOV BP, [SP]\n");
			fprintf(target_file, "POP R0\n");
			fprintf(target_file, "RET\n");
			Lhead = Ltail = NULL;
			Phead = Ptail = NULL;
		}
#line 1874 "exprtree.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 311 "exprtree.y" /* yacc.c:1646  */
    {PInstall(NODE_ID,(yyvsp[0].no)->name,TypeID);}
#line 1880 "exprtree.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 312 "exprtree.y" /* yacc.c:1646  */
    {PInstall(NODE_PTR,(yyvsp[0].no)->name,TypeID);}
#line 1886 "exprtree.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 326 "exprtree.y" /* yacc.c:1646  */
    {LInstall(NODE_ID,(yyvsp[0].no)->name,TypeID);}
#line 1892 "exprtree.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 327 "exprtree.y" /* yacc.c:1646  */
    {LInstall(NODE_PTR,(yyvsp[0].no)->name,TypeID);}
#line 1898 "exprtree.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 330 "exprtree.y" /* yacc.c:1646  */
    {
				lbindno = 0;
				struct Gsymbol *Gtemp;
				struct Lsymbol *Ltemp;
				int Lcount;
				Lcount = 0;
				Ltemp = Lhead;
				while(Ltemp!=NULL)
				{
					Lcount++;
					Ltemp=Ltemp->next;
				}
				fprintf(target_file,"MAIN:\n");
				fprintf(target_file,"PUSH BP\n");
				fprintf(target_file,"MOV BP, SP\n");
				fprintf(target_file, "ADD SP, %d\n", Lcount);
				x = codeGen((yyvsp[-1].no));
				fprintf(target_file, "SUB SP, %d\n", Lcount);
				fprintf(target_file, "MOV BP, [SP]\n");
				fprintf(target_file, "POP R0\n");
				fprintf(target_file, "RET\n");
				Lhead = Ltail = NULL;
			}
#line 1926 "exprtree.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 354 "exprtree.y" /* yacc.c:1646  */
    {(yyval.no) = (yyvsp[-1].no);}
#line 1932 "exprtree.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 355 "exprtree.y" /* yacc.c:1646  */
    {(yyval.no) = NULL;}
#line 1938 "exprtree.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 357 "exprtree.y" /* yacc.c:1646  */
    {(yyval.no) = createTree(0,NULL, TLookup("void"),NULL,NODE_BODY,(yyvsp[-2].no),NULL,(yyvsp[-1].no));}
#line 1944 "exprtree.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 358 "exprtree.y" /* yacc.c:1646  */
    {(yyval.no) = (yyvsp[-1].no);}
#line 1950 "exprtree.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 361 "exprtree.y" /* yacc.c:1646  */
    {(yyval.no) = (yyvsp[0].no);}
#line 1956 "exprtree.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 362 "exprtree.y" /* yacc.c:1646  */
    {(yyval.no) = createTree(0,NULL, TLookup("void"),NULL,NODE_BREAK,NULL,NULL,NULL);}
#line 1962 "exprtree.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 363 "exprtree.y" /* yacc.c:1646  */
    {(yyval.no) = createTree(0,NULL, TLookup("void"),NULL,NODE_CONTINUE,NULL,NULL,NULL);}
#line 1968 "exprtree.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 364 "exprtree.y" /* yacc.c:1646  */
    {(yyval.no) = createTree(0,NULL, TLookup("void"),NULL,NODE_RET,NULL,(yyvsp[0].no),NULL);}
#line 1974 "exprtree.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 366 "exprtree.y" /* yacc.c:1646  */
    {
					if(!((yyvsp[-1].no)->nodetype == NODE_ID_ADDRESS || (yyvsp[-1].no)->nodetype == NODE_FIELD_ADDRESS))
					{
						printf("ERROR:FREE argument invalid\n");
						exit(1);
					}
					(yyval.no) = createTree(0,NULL, TLookup("void"),NULL,NODE_FREE,NULL,(yyvsp[-1].no),NULL);
				}
#line 1987 "exprtree.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 375 "exprtree.y" /* yacc.c:1646  */
    {
					(yyval.no) = createTree(0,NULL, TLookup("void"),NULL,NODE_FREE,NULL,(yyvsp[-1].no),NULL);
				}
#line 1995 "exprtree.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 380 "exprtree.y" /* yacc.c:1646  */
    {(yyval.no)=createTree(0,NULL, TLookup("boolean"),NULL,NODE_IF_THEN_ELSE,(yyvsp[-6].no),(yyvsp[-3].no),(yyvsp[-1].no));}
#line 2001 "exprtree.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 382 "exprtree.y" /* yacc.c:1646  */
    {(yyval.no)=createTree(0,NULL, TLookup("boolean"),NULL,NODE_IF_THEN_ELSE,(yyvsp[-4].no),(yyvsp[-1].no),NULL);}
#line 2007 "exprtree.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 385 "exprtree.y" /* yacc.c:1646  */
    {(yyval.no)=createTree(0,NULL, TLookup("boolean"),NULL,NODE_WHILE_DO,(yyvsp[-4].no),NULL,(yyvsp[-1].no));}
#line 2013 "exprtree.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 387 "exprtree.y" /* yacc.c:1646  */
    {(yyval.no)=createTree(0,NULL, TLookup("boolean"),NULL,NODE_DO_WHILE,(yyvsp[-4].no),NULL,(yyvsp[-1].no));}
#line 2019 "exprtree.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 389 "exprtree.y" /* yacc.c:1646  */
    {(yyval.no)=createTree(0,NULL, TLookup("boolean"),NULL,NODE_REP_UNTIL,(yyvsp[-4].no),NULL,(yyvsp[-1].no));}
#line 2025 "exprtree.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 391 "exprtree.y" /* yacc.c:1646  */
    {(yyval.no) = createTree(0,NULL, TLookup("void"),NULL,NODE_WRITE,NULL,(yyvsp[-1].no),NULL);}
#line 2031 "exprtree.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 393 "exprtree.y" /* yacc.c:1646  */
    {(yyval.no) = createTree(0,NULL, TLookup("void"),NULL,NODE_READ,NULL,(yyvsp[-1].no),NULL);}
#line 2037 "exprtree.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 396 "exprtree.y" /* yacc.c:1646  */
    {
				struct Classtable *Ctemp,*Ctemp1;
				if((yyvsp[-2].no)->type == NULL || (yyvsp[0].no)->type == NULL)
				{
					if((yyvsp[-2].no)->type == NULL && (yyvsp[0].no)->type == NULL)
					{
						//Isparent Check?
						Ctemp = (yyvsp[-2].no)->Ctype;
						Ctemp1 = (yyvsp[0].no)->Ctype;
						while(!(Ctemp == Ctemp1 || Ctemp1!=NULL))
							Ctemp1 = Ctemp1->Parentptr;
						if(Ctemp1 == NULL)
						{
							printf("ERROR:Object %s does not support assignment of Object %s\n",Ctemp->name,Ctemp1->name);
							exit(1);
						}
						(yyvsp[0].no)->nodetype = NODE_ID_ADDRESS;
						(yyval.no) = createTree(0,NULL,TLookup("void"),NULL,NODE_CLASS_ASSIGN,(yyvsp[-2].no),NULL,(yyvsp[0].no));
					}
					else
					{
						printf("ERROR:Assignment type mismatch\n");
						exit(1);
					}
				}
				(yyval.no) = createTree(0,NULL, TLookup("void"),NULL,NODE_ASSIGN,(yyvsp[-2].no),NULL,(yyvsp[0].no));
			}
#line 2069 "exprtree.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 424 "exprtree.y" /* yacc.c:1646  */
    {
				struct Classtable *Ctemp,*Ctemp1;
				if(CLookup((yyvsp[-1].no)->name) == NULL)
				{
					printf("ERROR:New fuunction argumment has invalid Classtype\n");
					exit(1);
				}
				if(!((yyvsp[-5].no)->nodetype == NODE_ID_ADDRESS || (yyvsp[-5].no)->nodetype == NODE_FIELD_ADDRESS))
				{
					printf("ERROR:Assignment type mismatch\n");
					exit(1);
				}
				//is parent check?
				Ctemp = (yyvsp[-5].no)->Ctype;
				Ctemp1 = (yyvsp[-1].no)->Ctype;
				while(!(Ctemp == Ctemp1 || Ctemp1!=NULL))
					Ctemp1 = Ctemp1->Parentptr;
				if(Ctemp1 == NULL)
				{
					printf("ERROR:Object assigned to wrong Class variable\n");
					exit(1);
				}
				(yyval.no) = createTree(0,NULL,NULL,(yyvsp[-1].no)->name,NODE_NEW,(yyvsp[-5].no),NULL,
					createTree(0,NULL, TLookup("void"),NULL,NODE_ASSIGN,(yyvsp[-5].no),NULL,
					createTree(0,NULL,TLookup("type"),NULL,NODE_ALLOC,NULL,NULL,NULL)));
			}
#line 2100 "exprtree.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 451 "exprtree.y" /* yacc.c:1646  */
    {
					IDCheck((yyvsp[0].no));
					(yyvsp[0].no)->nodetype = NODE_ID_ADDRESS;
					(yyval.no) = (yyvsp[0].no);
				}
#line 2110 "exprtree.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 456 "exprtree.y" /* yacc.c:1646  */
    {
					if((yyvsp[0].no)->nodetype == NODE_FIELD_SELF)
						(yyvsp[0].no)->nodetype = NODE_FIELD_SELF_ADDRESS;
					else
						(yyvsp[0].no)->nodetype = NODE_FIELD_ADDRESS;
					(yyval.no) = (yyvsp[0].no);
				}
#line 2122 "exprtree.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 463 "exprtree.y" /* yacc.c:1646  */
    {
					IDCheck((yyvsp[0].no));
					(yyval.no) = createTree(0,NULL, (yyvsp[0].no)->type,(yyvsp[0].no)->name,NODE_ID,NULL,NULL,NULL);
				}
#line 2131 "exprtree.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 467 "exprtree.y" /* yacc.c:1646  */
    {
					IDCheck((yyvsp[-3].no));
					(yyvsp[-3].no)->nodetype = NODE_ID_ADDRESS;
					(yyval.no) = createTree(0,NULL, (yyvsp[-3].no)->type,(yyvsp[-3].no)->name,NODE_ARRAY_ADDRESS,(yyvsp[-3].no),(yyvsp[-1].no),NULL);
				}
#line 2141 "exprtree.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 473 "exprtree.y" /* yacc.c:1646  */
    {
					IDCheck((yyvsp[-6].no));
					(yyvsp[-6].no)->nodetype = NODE_ID_ADDRESS;
					(yyval.no) = createTree(0,NULL, (yyvsp[-6].no)->type,(yyvsp[-6].no)->name,NODE_MATRIX_ADDRESS,(yyvsp[-6].no),(yyvsp[-4].no),(yyvsp[-1].no));
				}
#line 2151 "exprtree.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 479 "exprtree.y" /* yacc.c:1646  */
    {
					TypeCheck((yyvsp[-2].no)->type,(yyvsp[0].no)->type,NODE_PLUS);
					(yyval.no) = createTree(0,NULL, TLookup("integer"),NULL,NODE_PLUS,(yyvsp[-2].no),NULL,(yyvsp[0].no));
				}
#line 2160 "exprtree.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 483 "exprtree.y" /* yacc.c:1646  */
    {
					TypeCheck((yyvsp[-2].no)->type,(yyvsp[0].no)->type,NODE_MINUS);
					(yyval.no) = createTree(0,NULL, TLookup("integer"),NULL,NODE_MINUS,(yyvsp[-2].no),NULL,(yyvsp[0].no));
				}
#line 2169 "exprtree.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 487 "exprtree.y" /* yacc.c:1646  */
    {
					TypeCheck((yyvsp[-2].no)->type,(yyvsp[0].no)->type,NODE_MUL);
					(yyval.no) = createTree(0,NULL, TLookup("integer"),NULL,NODE_MUL,(yyvsp[-2].no),NULL,(yyvsp[0].no));
				}
#line 2178 "exprtree.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 491 "exprtree.y" /* yacc.c:1646  */
    {
					TypeCheck((yyvsp[-2].no)->type,(yyvsp[0].no)->type,NODE_DIV);
					(yyval.no) = createTree(0,NULL, TLookup("integer"),NULL,NODE_DIV,(yyvsp[-2].no),NULL,(yyvsp[0].no));
				}
#line 2187 "exprtree.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 495 "exprtree.y" /* yacc.c:1646  */
    {
					TypeCheck((yyvsp[-2].no)->type,(yyvsp[0].no)->type,NODE_MOD);
					(yyval.no) = createTree(0,NULL, TLookup("integer"),NULL,NODE_MOD,(yyvsp[-2].no),NULL,(yyvsp[0].no));
				}
#line 2196 "exprtree.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 499 "exprtree.y" /* yacc.c:1646  */
    {
					TypeCheck((yyvsp[-2].no)->type,(yyvsp[0].no)->type,NODE_AND);
					(yyval.no) = createTree(0,NULL, TLookup("boolean"),NULL,NODE_AND,(yyvsp[-2].no),NULL,(yyvsp[0].no));
				}
#line 2205 "exprtree.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 503 "exprtree.y" /* yacc.c:1646  */
    {
					TypeCheck((yyvsp[-2].no)->type,(yyvsp[0].no)->type,NODE_OR);
					(yyval.no) = createTree(0,NULL, TLookup("boolean"),NULL,NODE_OR,(yyvsp[-2].no),NULL,(yyvsp[0].no));
				}
#line 2214 "exprtree.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 507 "exprtree.y" /* yacc.c:1646  */
    {
					TypeCheck((yyvsp[-2].no)->type,(yyvsp[0].no)->type,NODE_EQ);
					(yyval.no) = createTree(0,NULL, TLookup("boolean"),NULL,NODE_EQ,(yyvsp[-2].no),NULL,(yyvsp[0].no));
				}
#line 2223 "exprtree.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 511 "exprtree.y" /* yacc.c:1646  */
    {
					TypeCheck((yyvsp[-2].no)->type,(yyvsp[0].no)->type,NODE_NE);
					(yyval.no) = createTree(0,NULL, TLookup("boolean"),NULL,NODE_NE,(yyvsp[-2].no),NULL,(yyvsp[0].no));
				}
#line 2232 "exprtree.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 515 "exprtree.y" /* yacc.c:1646  */
    {
					TypeCheck((yyvsp[-2].no)->type,(yyvsp[0].no)->type,NODE_LE);
					(yyval.no) = createTree(0,NULL, TLookup("boolean"),NULL,NODE_LE,(yyvsp[-2].no),NULL,(yyvsp[0].no));
				}
#line 2241 "exprtree.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 519 "exprtree.y" /* yacc.c:1646  */
    {
					TypeCheck((yyvsp[-2].no)->type,(yyvsp[0].no)->type,NODE_GE);
					(yyval.no) = createTree(0,NULL, TLookup("boolean"),NULL,NODE_GE,(yyvsp[-2].no),NULL,(yyvsp[0].no));
				}
#line 2250 "exprtree.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 523 "exprtree.y" /* yacc.c:1646  */
    {
					TypeCheck((yyvsp[-2].no)->type,(yyvsp[0].no)->type,NODE_LT);
					(yyval.no) = createTree(0,NULL, TLookup("boolean"),NULL,NODE_LT,(yyvsp[-2].no),NULL,(yyvsp[0].no));
				}
#line 2259 "exprtree.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 527 "exprtree.y" /* yacc.c:1646  */
    {
					TypeCheck((yyvsp[-2].no)->type,(yyvsp[0].no)->type,NODE_GT);
					(yyval.no) = createTree(0,NULL, TLookup("boolean"),NULL,NODE_GT,(yyvsp[-2].no),NULL,(yyvsp[0].no));
				}
#line 2268 "exprtree.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 531 "exprtree.y" /* yacc.c:1646  */
    {(yyval.no) = createTree(0,NULL, TLookup("boolean"),NULL,NODE_NOT,NULL,(yyvsp[0].no),NULL);}
#line 2274 "exprtree.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 532 "exprtree.y" /* yacc.c:1646  */
    {(yyval.no) = createTree(0,NULL, TLookup("null"),NULL,NODE_NIL,NULL,NULL,NULL);}
#line 2280 "exprtree.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 533 "exprtree.y" /* yacc.c:1646  */
    {(yyval.no) = (yyvsp[-1].no);}
#line 2286 "exprtree.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 534 "exprtree.y" /* yacc.c:1646  */
    {(yyval.no) = (yyvsp[0].no);}
#line 2292 "exprtree.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 535 "exprtree.y" /* yacc.c:1646  */
    {
					IDCheck((yyvsp[0].no));
					(yyval.no) = (yyvsp[0].no);
				}
#line 2301 "exprtree.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 539 "exprtree.y" /* yacc.c:1646  */
    {
					IDCheck((yyvsp[-3].no));
					(yyval.no) = createTree(0,NULL, (yyvsp[-3].no)->type,(yyvsp[-3].no)->name,NODE_ARRAY,(yyvsp[-3].no),(yyvsp[-1].no),NULL);
				}
#line 2310 "exprtree.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 544 "exprtree.y" /* yacc.c:1646  */
    {
					IDCheck((yyvsp[-6].no));
					(yyval.no) = createTree(0,NULL, (yyvsp[-6].no)->type,(yyvsp[-6].no)->name,NODE_MATRIX,(yyvsp[-6].no),(yyvsp[-4].no),(yyvsp[-1].no));
				}
#line 2319 "exprtree.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 548 "exprtree.y" /* yacc.c:1646  */
    {
					IDCheck((yyvsp[0].no));
					(yyval.no) = createTree(0,NULL, (yyvsp[0].no)->type,(yyvsp[0].no)->name,NODE_ID_VALPTR,NULL,NULL,NULL);
				}
#line 2328 "exprtree.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 552 "exprtree.y" /* yacc.c:1646  */
    {
					IDCheck((yyvsp[0].no));
					(yyvsp[0].no)->nodetype = NODE_ID_ADDRESS;
					(yyval.no) = (yyvsp[0].no);
				}
#line 2338 "exprtree.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 557 "exprtree.y" /* yacc.c:1646  */
    {(yyval.no) = createTree(0,NULL, TLookup("type"),NULL,NODE_ALLOC,NULL,NULL,NULL);}
#line 2344 "exprtree.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 558 "exprtree.y" /* yacc.c:1646  */
    {(yyval.no) = createTree(0,NULL, TLookup("integer"),NULL,NODE_INIT,NULL,NULL,NULL);}
#line 2350 "exprtree.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 560 "exprtree.y" /* yacc.c:1646  */
    {
			struct Gsymbol *gtemp,*gtemp1;
			struct Paramstruct *ptemp;
			struct tnode *atemp;
			gtemp = GLookup((yyvsp[-3].no)->name);
			if(gtemp==NULL)
			{
				printf("ERROR:no declared function found\n");
				exit(1);
			}
			else
			{
				ptemp = gtemp->ParamList;
				atemp = (yyvsp[-1].no);
				while((ptemp!=NULL) && (atemp!=NULL))
				{
					if(ptemp->type != atemp->type)
					{
						printf("ERROR:function argument mismatch with defintion\n");
						exit(1);
					}
					ptemp = ptemp->next;
					atemp = atemp->ArgList;
				}
				if(!((atemp==NULL) && (ptemp==NULL)))
				{
					printf("ERROR:function argument mismatch with defintion\n");
					exit(1);
				}
			}
			(yyval.no) = createTree(0,NULL, gtemp->type,(yyvsp[-3].no)->name,NODE_FUN,NULL,(yyvsp[-1].no),NULL);
		}
#line 2387 "exprtree.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 592 "exprtree.y" /* yacc.c:1646  */
    {(yyval.no) = (yyvsp[0].no);}
#line 2393 "exprtree.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 593 "exprtree.y" /* yacc.c:1646  */
    {(yyval.no) = (yyvsp[0].no);}
#line 2399 "exprtree.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 595 "exprtree.y" /* yacc.c:1646  */
    {
					struct tnode *temp = (yyvsp[-2].no);
					while(temp->ArgList!=NULL)
						temp = temp->ArgList;
					temp->ArgList = (yyvsp[0].no);
					(yyval.no) = (yyvsp[-2].no);
				}
#line 2411 "exprtree.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 602 "exprtree.y" /* yacc.c:1646  */
    {(yyval.no) = (yyvsp[0].no);}
#line 2417 "exprtree.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 603 "exprtree.y" /* yacc.c:1646  */
    {(yyval.no) = NULL;}
#line 2423 "exprtree.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 605 "exprtree.y" /* yacc.c:1646  */
    {
					struct Fieldlist *Ftemp;
					if((yyvsp[-2].no)->type == NULL)
						Ftemp = Class_Flookup((yyvsp[-2].no)->Ctype,(yyvsp[0].no)->name);
					else
						Ftemp = FLookup((yyvsp[-2].no)->type,(yyvsp[0].no)->name);
					if(Ftemp == NULL)
					{
						printf("ERROR:Unknown identifier in FIELD: %s\n",(yyvsp[0].no)->name);
						exit(1);
					}
					(yyval.no) = createTree(0,NULL,Ftemp->type,NULL,NODE_FIELD,(yyvsp[-2].no),NULL,(yyvsp[0].no));
					(yyval.no)->Ctype = Ftemp->Ctype;
				}
#line 2442 "exprtree.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 619 "exprtree.y" /* yacc.c:1646  */
    {
					//This will not occur inside a class.
					struct Fieldlist *Ftemp;
					if((yyvsp[-2].no)->type == NULL)
						Ftemp = Class_Flookup((yyvsp[-2].no)->Ctype,(yyvsp[0].no)->name);
					else
						Ftemp = FLookup((yyvsp[-2].no)->type,(yyvsp[0].no)->name);
					if(Ftemp == NULL)
					{
						printf("ERROR:Unknown identifier in FIELD: %s\n",(yyvsp[0].no)->name);
						exit(1);
					}
					(yyval.no) = createTree(0,NULL,Ftemp->type,NULL,NODE_FIELD,(yyvsp[-2].no),NULL,(yyvsp[0].no));
					(yyval.no)->Ctype = Ftemp->Ctype;
				}
#line 2462 "exprtree.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 634 "exprtree.y" /* yacc.c:1646  */
    {
					struct Fieldlist *Ftemp = Fhead;
					if(Cptr == NULL)
					{
						printf("ERROR:SELF should be used only inside class\n");
						exit(1);
					}
					while(Ftemp != NULL)
					{
						if(!strcmp(Ftemp->name, (yyvsp[0].no)->name))
							break;
						Ftemp = Ftemp->next;
					}
					if(Ftemp == NULL)
					{
						printf("ERROR: Unknown MemberField: %s\n", (yyvsp[0].no)->name);
						exit(1);
					}
					(yyval.no) = createTree(0,NULL,Ftemp->type,NULL,NODE_FIELD_SELF,NULL,(yyvsp[0].no),NULL);
					(yyval.no)->Ctype = Ftemp->Ctype;
				}
#line 2488 "exprtree.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 657 "exprtree.y" /* yacc.c:1646  */
    {
					struct Memberfunclist *Mtemp = Mhead;
					if(Cptr == NULL)
					{
						printf("ERROR:SELF should be used only inside class\n");
						exit(1);
					}
					while(Mtemp != NULL)
					{
						if(!strcmp(Mtemp->name, (yyvsp[-3].no)->name))
							break;
						Mtemp = Mtemp->next;
					}
					if(Mtemp == NULL)
					{
						printf("ERROR: Unknown MemberFunction: %s\n", (yyvsp[-3].no)->name);
						exit(1);
					}
					(yyval.no) = createTree(0,NULL,Mtemp->type,NULL,NODE_CLASS_FUN,NULL,(yyvsp[-1].no),(yyvsp[-3].no));
					(yyval.no)->Ctype = Cptr;
				}
#line 2514 "exprtree.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 679 "exprtree.y" /* yacc.c:1646  */
    {
					(yyvsp[-5].no)->nodetype = NODE_FIELD_ADDRESS;
					struct Paramstruct *ptemp;
					struct Memberfunclist *Mtemp;
					struct tnode *atemp;
					Mtemp = Class_Mlookup((yyvsp[-5].no)->Ctype,(yyvsp[-3].no)->name);
					ptemp = Mtemp->paramlist;
					atemp = (yyvsp[-1].no);
					while((ptemp!=NULL) && (atemp!=NULL))
					{
						if(ptemp->type != atemp->type)
						{
							printf("ERROR:Class function argument mismatch with defintion\n");
							exit(1);
						}
						ptemp = ptemp->next;
						atemp = atemp->ArgList;
					}
					if(!((atemp==NULL) && (ptemp==NULL)))
					{
						printf("ERROR:Class function argument mismatch with defintion\n");
						exit(1);
					}
					(yyval.no) = createTree(0,NULL,Mtemp->type,NULL,NODE_CLASS_FUN,(yyvsp[-5].no),(yyvsp[-1].no),(yyvsp[-3].no));
					(yyval.no)->Ctype = (yyvsp[-5].no)->Ctype;
				}
#line 2545 "exprtree.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 706 "exprtree.y" /* yacc.c:1646  */
    {
					(yyvsp[-5].no)->nodetype = NODE_FIELD_ADDRESS;
					struct Paramstruct *ptemp;
					struct Memberfunclist *Mtemp;
					struct tnode *atemp;
					Mtemp = Class_Mlookup((yyvsp[-5].no)->Ctype,(yyvsp[-3].no)->name);
					ptemp = Mtemp->paramlist;
					atemp = (yyvsp[-1].no);
					while((ptemp!=NULL) && (atemp!=NULL))
					{
						if(ptemp->type != atemp->type)
						{
							printf("ERROR:Class function argument mismatch with defintion\n");
							exit(1);
						}
						ptemp = ptemp->next;
						atemp = atemp->ArgList;
					}
					if(!((atemp==NULL) && (ptemp==NULL)))
					{
						printf("ERROR:Class function argument mismatch with defintion\n");
						exit(1);
					}
					(yyval.no) = createTree(0,NULL,Mtemp->type,NULL,NODE_CLASS_FUN,(yyvsp[-5].no),(yyvsp[-1].no),(yyvsp[-3].no));
					(yyval.no)->Ctype = (yyvsp[-5].no)->Ctype;
				}
#line 2576 "exprtree.tab.c" /* yacc.c:1646  */
    break;


#line 2580 "exprtree.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 733 "exprtree.y" /* yacc.c:1906  */


void yyerror(char const *s)
{
	printf("yyerror %s",s);
	exit(1);
}

int main(int argc, char **argv)
{
	yyin = fopen(argv[1],"r");
	target_file=fopen("exprtree.xsm","w");
	fprintf(target_file,"0\n2056\n0\n0\n0\n0\n0\n0\nBRKP\n");
	TypeTableCreate();
	yyparse();
	return 0;
}
