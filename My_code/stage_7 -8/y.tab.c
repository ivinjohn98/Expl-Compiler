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

#line 78 "y.tab.c" /* yacc.c:339  */

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

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
/* Tokens.  */
#define MAIN 258
#define START 259
#define ASSIGN 260
#define READ 261
#define WRITE 262
#define ID 263
#define NUM 264
#define PLUS 265
#define MINUS 266
#define MUL 267
#define DIV 268
#define END 269
#define MOD 270
#define IF 271
#define THEN 272
#define ELSE 273
#define ENDIF 274
#define WHILE 275
#define DO 276
#define ENDWHILE 277
#define REPEAT 278
#define UNTIL 279
#define BREAK 280
#define CONTINUE 281
#define LT 282
#define GT 283
#define NE 284
#define EQ 285
#define GE 286
#define LE 287
#define STR 288
#define INT 289
#define DECL 290
#define ENDDECL 291
#define NOT 292
#define RETURN 293
#define INIT 294
#define NIL 295
#define ALLOC 296
#define FREE 297
#define TYPE 298
#define ENDTYPE 299
#define CLASS 300
#define ENDCLASS 301
#define EXTENDS 302
#define NEW 303
#define DELETE 304
#define SELF 305
#define AND 306
#define OR 307

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 13 "exprtree.y" /* yacc.c:355  */

	struct tnode *no;

#line 226 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 243 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   777

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  63
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  46
/* YYNRULES -- Number of rules.  */
#define YYNRULES  128
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  284

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
       0,    28,    28,    29,    31,    32,    34,    35,    37,    44,
      45,    47,    49,    50,    51,    57,    88,    90,    91,    93,
     106,   107,   112,   113,   115,   122,   123,   125,   139,   140,
     142,   142,   172,   174,   175,   177,   179,   180,   181,   191,
     192,   194,   200,   201,   203,   208,   210,   211,   213,   288,
     289,   290,   292,   293,   295,   296,   297,   299,   300,   302,
     304,   305,   307,   308,   310,   335,   336,   338,   339,   341,
     341,   341,   341,   341,   343,   344,   345,   346,   357,   362,
     364,   367,   369,   371,   374,   376,   378,   416,   446,   451,
     458,   462,   467,   474,   478,   482,   486,   490,   494,   498,
     502,   506,   510,   514,   518,   522,   526,   527,   528,   529,
     530,   534,   538,   543,   547,   552,   553,   554,   587,   588,
     590,   597,   598,   600,   614,   628,   650,   672,   702
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

#define YYPACT_NINF -237

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-237)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-1)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -29,     8,    30,    -7,     6,     2,  -237,  -237,   111,    87,
      27,  -237,  -237,    18,    -2,  -237,    77,    50,    42,  -237,
    -237,  -237,     0,  -237,   139,   157,  -237,  -237,   131,  -237,
    -237,  -237,  -237,    61,  -237,     5,   171,   186,    42,  -237,
    -237,  -237,  -237,   135,  -237,  -237,  -237,  -237,   -27,   217,
      22,  -237,   122,   140,  -237,  -237,  -237,    65,    65,   220,
    -237,  -237,     5,   169,    65,  -237,   105,  -237,   223,    13,
      60,  -237,   184,  -237,   189,    67,    65,  -237,   237,    78,
    -237,   238,  -237,    65,   202,   212,   195,     3,  -237,   206,
    -237,    65,  -237,  -237,   254,   136,   260,   212,  -237,  -237,
      85,   205,  -237,   108,   159,  -237,   467,   213,   260,   211,
    -237,  -237,   261,    38,  -237,  -237,  -237,   214,   215,    23,
     264,  -237,   219,   221,   662,   662,  -237,  -237,   123,   225,
     227,   216,   506,   235,  -237,  -237,  -237,  -237,  -237,   263,
     233,  -237,   243,  -237,  -237,  -237,   108,    -5,   123,   123,
     268,  -237,   123,   123,   701,   545,   -47,  -237,   290,   123,
     244,  -237,   251,   252,   123,   291,   725,   253,  -237,    -5,
      -5,   308,  -237,   262,  -237,    31,   310,  -237,  -237,   265,
     274,   170,  -237,   281,   324,   267,   271,   123,   123,   311,
    -237,   182,   272,   273,   312,   331,  -237,   123,   123,   123,
     123,   123,   123,   123,   123,   123,   123,   123,   123,   123,
     313,   283,   288,  -237,  -237,   292,   725,  -237,  -237,  -237,
     269,   307,   326,   123,   123,   725,    92,   176,   293,  -237,
    -237,   294,  -237,   430,   430,   182,   182,   182,   188,   188,
     188,   188,   188,   188,   734,   734,   301,  -237,  -237,   356,
     123,   662,   662,   374,   381,  -237,   123,   306,   123,   123,
     123,   309,   222,   428,   584,   326,  -237,   725,   123,    98,
     119,   166,  -237,  -237,   662,  -237,  -237,   228,  -237,  -237,
    -237,   623,  -237,  -237
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,     0,     0,    16,     0,     0,     7,     1,     0,    32,
       0,     4,     6,    20,     0,    18,     0,     0,     0,    14,
      13,    12,     0,    10,     0,     0,    15,    17,     0,    38,
      37,    36,    30,     0,    34,     0,    36,     0,     0,    47,
       3,     8,     9,     0,    21,    23,    31,    33,    41,     0,
       0,    40,     0,     0,    46,     2,    11,     0,    51,     0,
      45,    35,     0,     0,    51,    22,     0,    26,     0,     0,
       0,    50,     0,    39,     0,     0,     0,    25,     0,     0,
      52,     0,    44,     0,    42,    56,     0,     0,    29,     0,
      24,    51,    53,    49,     0,     0,     0,    56,    19,    28,
       0,     0,    55,     0,     0,    58,     0,     0,     0,     0,
      43,    62,     0,     0,    61,    54,    57,     0,     0,    88,
       0,    66,     0,     0,     0,     0,    74,    75,     0,     0,
       0,     0,     0,     0,    72,    73,    70,    69,    71,     0,
      89,    64,     0,    27,    63,    59,     0,     0,     0,     0,
       0,    90,     0,     0,     0,     0,   110,   109,     0,     0,
       0,   107,     0,     0,     0,     0,    76,   118,   119,     0,
       0,     0,    65,     0,    68,     0,     0,    48,    60,     0,
       0,     0,   124,     0,     0,     0,     0,   122,     0,     0,
     113,   106,     0,     0,     0,     0,   114,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   125,    67,     0,    86,   123,    85,    84,
      91,     0,     0,     0,     0,   121,     0,     0,   124,   116,
     115,   125,   108,    93,    94,    95,    96,    97,   104,   105,
     101,   100,   103,   102,    98,    99,   123,    77,    78,     0,
       0,     0,     0,     0,     0,   117,     0,   111,   122,   122,
     122,     0,     0,     0,     0,    82,    83,   120,     0,     0,
       0,     0,    87,    92,     0,    80,    81,     0,   128,   126,
     127,     0,   112,    79
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -237,  -237,  -237,  -237,   362,  -237,   346,  -237,  -237,  -237,
     355,  -237,  -237,  -237,  -237,   304,  -237,  -237,  -237,   338,
      57,  -237,   315,  -237,   -34,   -44,   289,   276,  -237,   270,
    -237,   232,   341,   282,  -123,  -127,  -237,  -237,  -237,  -237,
    -237,   -81,   -97,  -236,  -106,  -237
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     5,     6,    22,    23,    24,     9,    14,
      15,    16,    57,    65,    66,    67,    87,    18,    33,    34,
      37,    50,    51,    38,    39,    70,    71,    96,   104,   105,
     113,   114,    40,   107,   132,   133,   134,   135,   136,   137,
     138,   139,   225,   226,   167,   168
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     140,   154,   155,   119,    54,   173,    13,   120,    19,   187,
       4,    29,   188,    48,     1,   189,     4,    49,   140,   140,
      75,    80,   269,   270,   271,    81,   140,   173,   173,    58,
       7,   166,    59,    20,    21,    19,    30,    31,     8,   156,
     157,   140,    88,   158,    26,   131,    11,   100,   140,   140,
      29,   180,   181,    99,    41,   183,   184,    98,    29,    10,
      20,    21,   191,   140,   140,    25,   179,   195,   159,    29,
     160,   161,   162,    29,    35,    30,    36,    61,   216,   215,
      62,   163,   149,    30,    31,   150,    32,   164,   211,   212,
      35,   227,   165,   145,    30,    31,   146,    46,    30,    31,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,    29,    68,    69,   111,    82,    83,    13,
     112,    69,    17,    78,    86,    83,   253,   254,   263,   264,
      28,   156,   157,    90,    91,   158,   173,   173,    30,    31,
      69,    76,   109,    83,    29,   140,   140,    43,    69,   255,
     256,   281,   103,   262,   173,   278,   256,   140,   140,   267,
     159,   103,   160,   161,   162,    44,    45,    29,   140,    30,
      31,   277,   102,   163,    52,   140,   279,   256,    63,   164,
     197,   198,   199,   200,   165,   201,   197,   198,   199,   200,
      56,   201,    30,    31,    53,   115,    64,   202,   203,   204,
     205,   206,   207,   202,   203,   204,   205,   206,   207,   202,
     203,   204,   205,   206,   207,    -1,    -1,    -1,    -1,    -1,
      -1,   208,   209,   280,   256,    60,    74,   208,   209,    72,
     220,    79,   197,   198,   199,   200,   257,   201,   197,   198,
     199,   200,    85,   201,    84,    89,    92,    95,    97,   202,
     203,   204,   205,   206,   207,   202,   203,   204,   205,   206,
     207,    94,    91,   101,   106,   110,   143,   141,   175,   144,
     147,   148,   151,   208,   209,   152,   182,   153,   171,   208,
     209,   169,   273,   170,   197,   198,   199,   200,   282,   201,
     174,   197,   198,   199,   200,   176,   201,   177,   190,   196,
     192,   202,   203,   204,   205,   206,   207,   193,   202,   203,
     204,   205,   206,   207,   194,   210,   213,   214,   217,   228,
     231,   246,   218,   223,   251,   208,   209,   224,   250,   229,
     230,   219,   208,   209,   197,   198,   199,   200,   221,   201,
     247,   197,   198,   199,   200,   248,   201,   252,   249,   258,
     259,   202,   203,   204,   205,   206,   207,   260,   202,   203,
     204,   205,   206,   207,   261,   268,   272,    12,    42,    27,
      77,    47,    93,   108,   116,   208,   209,    73,   178,    55,
       0,   222,   208,   209,   197,   198,   199,   200,   232,   201,
     142,   197,   198,   199,   200,     0,   201,     0,     0,     0,
       0,   202,   203,   204,   205,   206,   207,     0,   202,   203,
     204,   205,   206,   207,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   208,   209,     0,     0,     0,
       0,   265,   208,   209,   117,   118,   119,     0,   266,     0,
     120,     0,   199,   200,   122,   201,   274,   275,   123,   124,
       0,   125,     0,   126,   127,     0,     0,   202,   203,   204,
     205,   206,   207,     0,     0,     0,   128,     0,     0,     0,
     129,     0,     0,   117,   118,   119,     0,   130,   131,   120,
       0,   121,     0,   122,     0,     0,     0,   123,   124,     0,
     125,     0,   126,   127,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   128,     0,     0,     0,   129,
       0,     0,   117,   118,   119,     0,   130,   131,   120,     0,
     172,     0,   122,     0,     0,     0,   123,   124,     0,   125,
       0,   126,   127,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   128,     0,     0,     0,   129,     0,
       0,   117,   118,   119,     0,   130,   131,   120,     0,     0,
       0,   122,     0,     0,     0,   123,   124,     0,   125,   186,
     126,   127,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   128,     0,     0,     0,   129,     0,     0,
     117,   118,   119,     0,   130,   131,   120,     0,     0,     0,
     122,     0,     0,     0,   123,   124,   276,   125,     0,   126,
     127,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   128,     0,     0,     0,   129,     0,     0,   117,
     118,   119,     0,   130,   131,   120,     0,     0,     0,   122,
       0,     0,   283,   123,   124,     0,   125,     0,   126,   127,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   128,     0,     0,     0,   129,     0,     0,   117,   118,
     119,     0,   130,   131,   120,     0,     0,     0,   122,     0,
       0,     0,   123,   124,     0,   125,     0,   126,   127,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     128,     0,     0,     0,   129,     0,     0,   117,   118,   119,
       0,   130,   131,   120,     0,     0,     0,   122,     0,     0,
       0,   185,   124,     0,   125,     0,   126,   127,     0,     0,
       0,     0,     0,     0,     0,   197,   198,   199,   200,   128,
     201,     0,     0,   129,   197,   198,   199,   200,     0,   201,
     130,   131,   202,   203,   204,   205,   206,   207,     0,     0,
       0,   202,   203,   204,   205,   206,   207,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   208,   209
};

static const yytype_int16 yycheck[] =
{
     106,   124,   125,     8,    38,   132,     8,    12,     8,    56,
       8,     8,    59,     8,    43,    62,     8,    12,   124,   125,
      64,     8,   258,   259,   260,    12,   132,   154,   155,    56,
       0,   128,    59,    33,    34,     8,    33,    34,    45,     8,
       9,   147,    76,    12,    46,    50,    44,    91,   154,   155,
       8,   148,   149,    87,    54,   152,   153,    54,     8,    53,
      33,    34,   159,   169,   170,    47,   147,   164,    37,     8,
      39,    40,    41,     8,    17,    33,    34,    55,   175,    48,
      58,    50,    59,    33,    34,    62,    36,    56,   169,   170,
      33,   188,    61,    55,    33,    34,    58,    36,    33,    34,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,     8,    57,    58,     8,    57,    58,     8,
      12,    64,    35,    66,    57,    58,   223,   224,   251,   252,
      53,     8,     9,    55,    56,    12,   263,   264,    33,    34,
      83,    36,    57,    58,     8,   251,   252,     8,    91,    57,
      58,   274,    95,   250,   281,    57,    58,   263,   264,   256,
      37,   104,    39,    40,    41,     8,    35,     8,   274,    33,
      34,   268,    36,    50,     3,   281,    57,    58,    56,    56,
      10,    11,    12,    13,    61,    15,    10,    11,    12,    13,
      55,    15,    33,    34,     8,    36,    56,    27,    28,    29,
      30,    31,    32,    27,    28,    29,    30,    31,    32,    27,
      28,    29,    30,    31,    32,    27,    28,    29,    30,    31,
      32,    51,    52,    57,    58,     8,    57,    51,    52,     9,
      60,     8,    10,    11,    12,    13,    60,    15,    10,    11,
      12,    13,    53,    15,    60,     8,     8,    35,    53,    27,
      28,    29,    30,    31,    32,    27,    28,    29,    30,    31,
      32,    59,    56,     9,     4,    60,    55,    54,     5,     8,
      56,    56,     8,    51,    52,    56,     8,    56,    62,    51,
      52,    56,    60,    56,    10,    11,    12,    13,    60,    15,
      55,    10,    11,    12,    13,    62,    15,    54,     8,     8,
      56,    27,    28,    29,    30,    31,    32,    56,    27,    28,
      29,    30,    31,    32,    62,    62,     8,    55,     8,     8,
       8,     8,    57,    56,    17,    51,    52,    56,    59,    57,
      57,    57,    51,    52,    10,    11,    12,    13,    57,    15,
      57,    10,    11,    12,    13,    57,    15,    21,    56,    56,
      56,    27,    28,    29,    30,    31,    32,    56,    27,    28,
      29,    30,    31,    32,     8,    59,    57,     5,    22,    14,
      66,    33,    83,    97,   104,    51,    52,    62,   146,    38,
      -1,    57,    51,    52,    10,    11,    12,    13,    57,    15,
     108,    10,    11,    12,    13,    -1,    15,    -1,    -1,    -1,
      -1,    27,    28,    29,    30,    31,    32,    -1,    27,    28,
      29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    51,    52,    -1,    -1,    -1,
      -1,    57,    51,    52,     6,     7,     8,    -1,    57,    -1,
      12,    -1,    12,    13,    16,    15,    18,    19,    20,    21,
      -1,    23,    -1,    25,    26,    -1,    -1,    27,    28,    29,
      30,    31,    32,    -1,    -1,    -1,    38,    -1,    -1,    -1,
      42,    -1,    -1,     6,     7,     8,    -1,    49,    50,    12,
      -1,    14,    -1,    16,    -1,    -1,    -1,    20,    21,    -1,
      23,    -1,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,    42,
      -1,    -1,     6,     7,     8,    -1,    49,    50,    12,    -1,
      14,    -1,    16,    -1,    -1,    -1,    20,    21,    -1,    23,
      -1,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,    42,    -1,
      -1,     6,     7,     8,    -1,    49,    50,    12,    -1,    -1,
      -1,    16,    -1,    -1,    -1,    20,    21,    -1,    23,    24,
      25,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    -1,    -1,    -1,    42,    -1,    -1,
       6,     7,     8,    -1,    49,    50,    12,    -1,    -1,    -1,
      16,    -1,    -1,    -1,    20,    21,    22,    23,    -1,    25,
      26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    -1,    -1,    -1,    42,    -1,    -1,     6,
       7,     8,    -1,    49,    50,    12,    -1,    -1,    -1,    16,
      -1,    -1,    19,    20,    21,    -1,    23,    -1,    25,    26,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    38,    -1,    -1,    -1,    42,    -1,    -1,     6,     7,
       8,    -1,    49,    50,    12,    -1,    -1,    -1,    16,    -1,
      -1,    -1,    20,    21,    -1,    23,    -1,    25,    26,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      38,    -1,    -1,    -1,    42,    -1,    -1,     6,     7,     8,
      -1,    49,    50,    12,    -1,    -1,    -1,    16,    -1,    -1,
      -1,    20,    21,    -1,    23,    -1,    25,    26,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    10,    11,    12,    13,    38,
      15,    -1,    -1,    42,    10,    11,    12,    13,    -1,    15,
      49,    50,    27,    28,    29,    30,    31,    32,    -1,    -1,
      -1,    27,    28,    29,    30,    31,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    51,    52
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    43,    64,    65,     8,    66,    67,     0,    45,    71,
      53,    44,    67,     8,    72,    73,    74,    35,    80,     8,
      33,    34,    68,    69,    70,    47,    46,    73,    53,     8,
      33,    34,    36,    81,    82,    83,    34,    83,    86,    87,
      95,    54,    69,     8,     8,    35,    36,    82,     8,    12,
      84,    85,     3,     8,    87,    95,    55,    75,    56,    59,
       8,    55,    58,    56,    56,    76,    77,    78,    83,    83,
      88,    89,     9,    85,    57,    88,    36,    78,    83,     8,
       8,    12,    57,    58,    60,    53,    57,    79,    87,     8,
      55,    56,     8,    89,    59,    35,    90,    53,    54,    87,
      88,     9,    36,    83,    91,    92,     4,    96,    90,    57,
      60,     8,    12,    93,    94,    36,    92,     6,     7,     8,
      12,    14,    16,    20,    21,    23,    25,    26,    38,    42,
      49,    50,    97,    98,    99,   100,   101,   102,   103,   104,
     107,    54,    96,    55,     8,    55,    58,    56,    56,    59,
      62,     8,    56,    56,    97,    97,     8,     9,    12,    37,
      39,    40,    41,    50,    56,    61,   105,   107,   108,    56,
      56,    62,    14,    98,    55,     5,    62,    54,    94,   104,
     105,   105,     8,   105,   105,    20,    24,    56,    59,    62,
       8,   105,    56,    56,    62,   105,     8,    10,    11,    12,
      13,    15,    27,    28,    29,    30,    31,    32,    51,    52,
      62,   104,   104,     8,    55,    48,   105,     8,    57,    57,
      60,    57,    57,    56,    56,   105,   106,   105,     8,    57,
      57,     8,    57,   105,   105,   105,   105,   105,   105,   105,
     105,   105,   105,   105,   105,   105,     8,    57,    57,    56,
      59,    17,    21,   105,   105,    57,    58,    60,    56,    56,
      56,     8,   105,    97,    97,    57,    57,   105,    59,   106,
     106,   106,    57,    60,    18,    19,    22,   105,    57,    57,
      57,    97,    60,    19
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    63,    64,    64,    65,    65,    66,    66,    67,    68,
      68,    69,    70,    70,    70,    71,    71,    72,    72,    73,
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
       0,     2,     5,     4,     3,     0,     2,     1,     4,     2,
       1,     3,     1,     1,     1,     3,     0,     2,     1,     8,
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
        case 8:
#line 38 "exprtree.y" /* yacc.c:1646  */
    {
					TInstall((yyvsp[-3].no)->name,0,Fhead);
					Fhead = Ftail = NULL;
					fieldindex = -1;
				}
#line 1618 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 47 "exprtree.y" /* yacc.c:1646  */
    {FInstall(TypeID, (yyvsp[-1].no)->name);}
#line 1624 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 49 "exprtree.y" /* yacc.c:1646  */
    {TypeID = TLookup("integer");}
#line 1630 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 50 "exprtree.y" /* yacc.c:1646  */
    {TypeID = TLookup("string");}
#line 1636 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 51 "exprtree.y" /* yacc.c:1646  */
    {
					TypeID = TLookup((yyvsp[0].no)->name);
					if(TypeID == NULL)
						TypeID = TLookup("type");
				}
#line 1646 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 58 "exprtree.y" /* yacc.c:1646  */
    {
					fprintf(target_file,"L0:\n");
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
							fprintf(target_file,"MOV R0, F%d:\n",Mtemp->Flabel);
							fprintf(target_file,"PUSH R0\n");
							i++;
							Mtemp=Mtemp->next;
						}
						if(i<8)
						{
							fprintf(target_file, "MOV R0, -1\n");
							while(i<8)
							{
								fprintf(target_file, "PUSH R0\n");
								i++;
							}
						}
						Ctemp = Ctemp->next;
					}
				}
#line 1681 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 94 "exprtree.y" /* yacc.c:1646  */
    {
			Cptr->Class_index = ++ClassI;
			Cptr->Fieldcount = fieldindex + 1;
			Cptr->Methodcount = Memposition + 1;
			Cptr->Memberfield = Fhead; 
			Cptr->Vfuncptr = Mhead;
			Fhead = Ftail = NULL;
			Mhead = Mtail = NULL;
			Cptr = NULL;
			fieldindex = Memposition = -1;
		}
#line 1697 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 106 "exprtree.y" /* yacc.c:1646  */
    {Cptr = CInstall((yyvsp[0].no)->name,NULL);}
#line 1703 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 107 "exprtree.y" /* yacc.c:1646  */
    {
					Cptr = CInstall((yyvsp[-2].no)->name,(yyvsp[0].no)->name);
					Inheritance_parent_copy_child(CLookup((yyvsp[0].no)->name),Cptr);
				}
#line 1712 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 115 "exprtree.y" /* yacc.c:1646  */
    {
					if(TypeID == NULL)
						Class_FInstall(Cptr,CTypeID->name,(yyvsp[-1].no)->name);
					else
						Class_FInstall(Cptr,TypeID->name,(yyvsp[-1].no)->name);
				}
#line 1723 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 126 "exprtree.y" /* yacc.c:1646  */
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
					pbindno = 0;
				}
#line 1740 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 143 "exprtree.y" /* yacc.c:1646  */
    {
					fprintf(target_file,"MOV SP, %d\n",bindno);
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
#line 1774 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 179 "exprtree.y" /* yacc.c:1646  */
    {TypeID = TLookup("integer");}
#line 1780 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 180 "exprtree.y" /* yacc.c:1646  */
    {TypeID = TLookup("string");}
#line 1786 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 181 "exprtree.y" /* yacc.c:1646  */
    {
					TypeID = TLookup((yyvsp[0].no)->name);
					CTypeID = CLookup((yyvsp[0].no)->name);
					if(TypeID==NULL && CTypeID==NULL)
					{
						printf("Unknown type: %s\n", (yyvsp[0].no)->name);
						exit(1);
					}
				}
#line 1800 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 194 "exprtree.y" /* yacc.c:1646  */
    {
					if(CTypeID == NULL)
						GInstall(NODE_ID,(yyvsp[0].no)->name,TypeID,CTypeID,1,1,NULL);
					else
						GInstall(NODE_ID,(yyvsp[0].no)->name,TypeID,CTypeID,1,2,NULL);
				}
#line 1811 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 200 "exprtree.y" /* yacc.c:1646  */
    {GInstall(NODE_ARRAY,(yyvsp[-3].no)->name,TypeID,NULL,1,(yyvsp[-1].no)->intval,NULL);}
#line 1817 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 202 "exprtree.y" /* yacc.c:1646  */
    {GInstall(NODE_MATRIX,(yyvsp[-6].no)->name,TypeID,NULL,(yyvsp[-4].no)->intval,(yyvsp[-1].no)->intval,NULL);}
#line 1823 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 203 "exprtree.y" /* yacc.c:1646  */
    {
					GInstall(NODE_FUN,(yyvsp[-3].no)->name,TypeID,NULL,0,0,Phead);
					Phead = Ptail = NULL;
					pbindno = 0;
				}
#line 1833 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 208 "exprtree.y" /* yacc.c:1646  */
    {GInstall(NODE_PTR,(yyvsp[0].no)->name,TypeID,NULL,1,1,NULL);}
#line 1839 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 214 "exprtree.y" /* yacc.c:1646  */
    {
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
			pbindno = lbindno = 0;
		}
#line 1917 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 292 "exprtree.y" /* yacc.c:1646  */
    {PInstall(NODE_ID,(yyvsp[0].no)->name,TypeID);}
#line 1923 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 293 "exprtree.y" /* yacc.c:1646  */
    {PInstall(NODE_PTR,(yyvsp[0].no)->name,TypeID);}
#line 1929 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 307 "exprtree.y" /* yacc.c:1646  */
    {LInstall(NODE_ID,(yyvsp[0].no)->name,TypeID);}
#line 1935 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 308 "exprtree.y" /* yacc.c:1646  */
    {LInstall(NODE_PTR,(yyvsp[0].no)->name,TypeID);}
#line 1941 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 311 "exprtree.y" /* yacc.c:1646  */
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
				fprintf(target_file,"ADD SP, %d\n", Lcount);
				x = codeGen((yyvsp[-1].no));
				fprintf(target_file,"SUB SP, %d\n", Lcount);
				fprintf(target_file,"MOV BP, [SP]\n");
				fprintf(target_file,"POP R0\n");
				fprintf(target_file,"RET\n");
				Lhead = Ltail = NULL;
			}
#line 1969 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 335 "exprtree.y" /* yacc.c:1646  */
    {(yyval.no) = (yyvsp[-1].no);}
#line 1975 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 336 "exprtree.y" /* yacc.c:1646  */
    {(yyval.no) = NULL;}
#line 1981 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 338 "exprtree.y" /* yacc.c:1646  */
    {(yyval.no) = createTree(0,NULL, TLookup("void"),NULL,NODE_BODY,(yyvsp[-2].no),NULL,(yyvsp[-1].no));}
#line 1987 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 339 "exprtree.y" /* yacc.c:1646  */
    {(yyval.no) = (yyvsp[-1].no);}
#line 1993 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 342 "exprtree.y" /* yacc.c:1646  */
    {(yyval.no) = (yyvsp[0].no);}
#line 1999 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 343 "exprtree.y" /* yacc.c:1646  */
    {(yyval.no) = createTree(0,NULL, TLookup("void"),NULL,NODE_BREAK,NULL,NULL,NULL);}
#line 2005 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 344 "exprtree.y" /* yacc.c:1646  */
    {(yyval.no) = createTree(0,NULL, TLookup("void"),NULL,NODE_CONTINUE,NULL,NULL,NULL);}
#line 2011 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 345 "exprtree.y" /* yacc.c:1646  */
    {(yyval.no) = createTree(0,NULL, TLookup("void"),NULL,NODE_RET,NULL,(yyvsp[0].no),NULL);}
#line 2017 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 347 "exprtree.y" /* yacc.c:1646  */
    {
					if(!((yyvsp[-1].no)->nodetype == NODE_ID_ADDRESS 
						|| (yyvsp[-1].no)->nodetype == NODE_FIELD_ADDRESS
						|| (yyvsp[-1].no)->nodetype == NODE_FIELD_SELF_ADDRESS))
					{
						printf("ERROR:FREE argument invalid\n");
						exit(1);
					}
					(yyval.no) = createTree(0,NULL, TLookup("void"),NULL,NODE_FREE,NULL,(yyvsp[-1].no),NULL);
				}
#line 2032 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 358 "exprtree.y" /* yacc.c:1646  */
    {
					(yyval.no) = createTree(0,NULL, TLookup("void"),NULL,NODE_FREE,NULL,(yyvsp[-1].no),NULL);
				}
#line 2040 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 363 "exprtree.y" /* yacc.c:1646  */
    {(yyval.no)=createTree(0,NULL, TLookup("void"),NULL,NODE_IF_THEN_ELSE,(yyvsp[-6].no),(yyvsp[-3].no),(yyvsp[-1].no));}
#line 2046 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 365 "exprtree.y" /* yacc.c:1646  */
    {(yyval.no)=createTree(0,NULL, TLookup("void"),NULL,NODE_IF_THEN_ELSE,(yyvsp[-4].no),(yyvsp[-1].no),NULL);}
#line 2052 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 368 "exprtree.y" /* yacc.c:1646  */
    {(yyval.no)=createTree(0,NULL, TLookup("void"),NULL,NODE_WHILE_DO,(yyvsp[-4].no),NULL,(yyvsp[-1].no));}
#line 2058 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 370 "exprtree.y" /* yacc.c:1646  */
    {(yyval.no)=createTree(0,NULL, TLookup("void"),NULL,NODE_DO_WHILE,(yyvsp[-4].no),NULL,(yyvsp[-1].no));}
#line 2064 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 372 "exprtree.y" /* yacc.c:1646  */
    {(yyval.no)=createTree(0,NULL, TLookup("void"),NULL,NODE_REP_UNTIL,(yyvsp[-4].no),NULL,(yyvsp[-1].no));}
#line 2070 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 374 "exprtree.y" /* yacc.c:1646  */
    {(yyval.no) = createTree(0,NULL, TLookup("void"),NULL,NODE_WRITE,NULL,(yyvsp[-1].no),NULL);}
#line 2076 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 376 "exprtree.y" /* yacc.c:1646  */
    {(yyval.no) = createTree(0,NULL, TLookup("void"),NULL,NODE_READ,NULL,(yyvsp[-1].no),NULL);}
#line 2082 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 379 "exprtree.y" /* yacc.c:1646  */
    {
				struct Classtable *Ctemp,*Ctemp1;
				if((yyvsp[-2].no)->type == NULL)
				{
					if((yyvsp[0].no)->type == TLookup("null"))
					{
						(yyval.no) = createTree(0,NULL,TLookup("void"),NULL,NODE_CLASS_ASSIGN_NIL,(yyvsp[-2].no),NULL,(yyvsp[0].no));
					}
					else if((yyvsp[0].no)->type == NULL)
					{
						//Isparent Check?
						if((yyvsp[0].no)->nodetype == NODE_ID)
							(yyvsp[0].no)->nodetype = NODE_ID_ADDRESS;
						else if((yyvsp[0].no)->nodetype == NODE_FIELD_SELF)
							(yyvsp[0].no)->nodetype = NODE_FIELD_SELF_ADDRESS;
						else
							(yyvsp[0].no)->nodetype = NODE_FIELD_ADDRESS;
						Ctemp = (yyvsp[-2].no)->Ctype;
						Ctemp1 = (yyvsp[0].no)->Ctype;
						while(!(Ctemp == Ctemp1 || Ctemp1!=NULL))
							Ctemp1 = Ctemp1->Parentptr;
						if(Ctemp1 == NULL)
						{
							printf("ERROR:Object %s does not support assignment of Object %s\n",Ctemp->name,Ctemp1->name);
							exit(1);
						}
						(yyval.no) = createTree(0,NULL,TLookup("void"),NULL,NODE_CLASS_ASSIGN,(yyvsp[-2].no),NULL,(yyvsp[0].no));
					}
					else
					{
						printf("ERROR:Assignment type mismatch\n");
						exit(1);
					}
				}
				else
					(yyval.no) = createTree(0,NULL, TLookup("void"),NULL,NODE_ASSIGN,(yyvsp[-2].no),NULL,(yyvsp[0].no));
			}
#line 2124 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 417 "exprtree.y" /* yacc.c:1646  */
    {
				struct Classtable *Ctemp,*Ctemp1;
				Ctemp = (yyvsp[-5].no)->Ctype;
				Ctemp1 = CLookup((yyvsp[-1].no)->name);
				if(Ctemp1 == NULL)
				{
					printf("ERROR:New function argumment has invalid Classtype\n");
					exit(1);
				}
				if(!((yyvsp[-5].no)->nodetype == NODE_ID_ADDRESS 
					|| (yyvsp[-5].no)->nodetype == NODE_FIELD_ADDRESS
					|| (yyvsp[-5].no)->nodetype == NODE_FIELD_SELF_ADDRESS))
				{
					printf("ERROR:Assignment type mismatch\n");
					exit(1);
				}
				//is parent check?
				while(!(Ctemp == Ctemp1 || Ctemp1==NULL))
					Ctemp1 = Ctemp1->Parentptr;
				if(Ctemp1 == NULL)
				{
					printf("ERROR:Object assigned to wrong Class variable\n");
					exit(1);
				}
				(yyval.no) = createTree(0,NULL,TLookup("void"),(yyvsp[-1].no)->name,NODE_NEW,(yyvsp[-5].no),NULL,
					createTree(0,NULL, TLookup("void"),NULL,NODE_ASSIGN,(yyvsp[-5].no),NULL,
					createTree(0,NULL,TLookup("type"),NULL,NODE_ALLOC,NULL,NULL,NULL)));
			}
#line 2157 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 446 "exprtree.y" /* yacc.c:1646  */
    {
					IDCheck((yyvsp[0].no));
					(yyvsp[0].no)->nodetype = NODE_ID_ADDRESS;
					(yyval.no) = (yyvsp[0].no);
				}
#line 2167 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 451 "exprtree.y" /* yacc.c:1646  */
    {
					if((yyvsp[0].no)->nodetype == NODE_FIELD_SELF)
						(yyvsp[0].no)->nodetype = NODE_FIELD_SELF_ADDRESS;
					else
						(yyvsp[0].no)->nodetype = NODE_FIELD_ADDRESS;
					(yyval.no) = (yyvsp[0].no);
				}
#line 2179 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 458 "exprtree.y" /* yacc.c:1646  */
    {
					IDCheck((yyvsp[0].no));
					(yyval.no) = createTree(0,NULL, (yyvsp[0].no)->type,(yyvsp[0].no)->name,NODE_ID,NULL,NULL,NULL);
				}
#line 2188 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 462 "exprtree.y" /* yacc.c:1646  */
    {
					IDCheck((yyvsp[-3].no));
					(yyvsp[-3].no)->nodetype = NODE_ID_ADDRESS;
					(yyval.no) = createTree(0,NULL, (yyvsp[-3].no)->type,(yyvsp[-3].no)->name,NODE_ARRAY_ADDRESS,(yyvsp[-3].no),(yyvsp[-1].no),NULL);
				}
#line 2198 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 468 "exprtree.y" /* yacc.c:1646  */
    {
					IDCheck((yyvsp[-6].no));
					(yyvsp[-6].no)->nodetype = NODE_ID_ADDRESS;
					(yyval.no) = createTree(0,NULL, (yyvsp[-6].no)->type,(yyvsp[-6].no)->name,NODE_MATRIX_ADDRESS,(yyvsp[-6].no),(yyvsp[-4].no),(yyvsp[-1].no));
				}
#line 2208 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 474 "exprtree.y" /* yacc.c:1646  */
    {
					TypeCheck((yyvsp[-2].no)->type,(yyvsp[0].no)->type,NODE_PLUS);
					(yyval.no) = createTree(0,NULL, TLookup("integer"),NULL,NODE_PLUS,(yyvsp[-2].no),NULL,(yyvsp[0].no));
				}
#line 2217 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 478 "exprtree.y" /* yacc.c:1646  */
    {
					TypeCheck((yyvsp[-2].no)->type,(yyvsp[0].no)->type,NODE_MINUS);
					(yyval.no) = createTree(0,NULL, TLookup("integer"),NULL,NODE_MINUS,(yyvsp[-2].no),NULL,(yyvsp[0].no));
				}
#line 2226 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 482 "exprtree.y" /* yacc.c:1646  */
    {
					TypeCheck((yyvsp[-2].no)->type,(yyvsp[0].no)->type,NODE_MUL);
					(yyval.no) = createTree(0,NULL, TLookup("integer"),NULL,NODE_MUL,(yyvsp[-2].no),NULL,(yyvsp[0].no));
				}
#line 2235 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 486 "exprtree.y" /* yacc.c:1646  */
    {
					TypeCheck((yyvsp[-2].no)->type,(yyvsp[0].no)->type,NODE_DIV);
					(yyval.no) = createTree(0,NULL, TLookup("integer"),NULL,NODE_DIV,(yyvsp[-2].no),NULL,(yyvsp[0].no));
				}
#line 2244 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 490 "exprtree.y" /* yacc.c:1646  */
    {
					TypeCheck((yyvsp[-2].no)->type,(yyvsp[0].no)->type,NODE_MOD);
					(yyval.no) = createTree(0,NULL, TLookup("integer"),NULL,NODE_MOD,(yyvsp[-2].no),NULL,(yyvsp[0].no));
				}
#line 2253 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 494 "exprtree.y" /* yacc.c:1646  */
    {
					TypeCheck((yyvsp[-2].no)->type,(yyvsp[0].no)->type,NODE_AND);
					(yyval.no) = createTree(0,NULL, TLookup("boolean"),NULL,NODE_AND,(yyvsp[-2].no),NULL,(yyvsp[0].no));
				}
#line 2262 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 498 "exprtree.y" /* yacc.c:1646  */
    {
					TypeCheck((yyvsp[-2].no)->type,(yyvsp[0].no)->type,NODE_OR);
					(yyval.no) = createTree(0,NULL, TLookup("boolean"),NULL,NODE_OR,(yyvsp[-2].no),NULL,(yyvsp[0].no));
				}
#line 2271 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 502 "exprtree.y" /* yacc.c:1646  */
    {
					TypeCheck((yyvsp[-2].no)->type,(yyvsp[0].no)->type,NODE_EQ);
					(yyval.no) = createTree(0,NULL, TLookup("boolean"),NULL,NODE_EQ,(yyvsp[-2].no),NULL,(yyvsp[0].no));
				}
#line 2280 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 506 "exprtree.y" /* yacc.c:1646  */
    {
					TypeCheck((yyvsp[-2].no)->type,(yyvsp[0].no)->type,NODE_NE);
					(yyval.no) = createTree(0,NULL, TLookup("boolean"),NULL,NODE_NE,(yyvsp[-2].no),NULL,(yyvsp[0].no));
				}
#line 2289 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 510 "exprtree.y" /* yacc.c:1646  */
    {
					TypeCheck((yyvsp[-2].no)->type,(yyvsp[0].no)->type,NODE_LE);
					(yyval.no) = createTree(0,NULL, TLookup("boolean"),NULL,NODE_LE,(yyvsp[-2].no),NULL,(yyvsp[0].no));
				}
#line 2298 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 514 "exprtree.y" /* yacc.c:1646  */
    {
					TypeCheck((yyvsp[-2].no)->type,(yyvsp[0].no)->type,NODE_GE);
					(yyval.no) = createTree(0,NULL, TLookup("boolean"),NULL,NODE_GE,(yyvsp[-2].no),NULL,(yyvsp[0].no));
				}
#line 2307 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 518 "exprtree.y" /* yacc.c:1646  */
    {
					TypeCheck((yyvsp[-2].no)->type,(yyvsp[0].no)->type,NODE_LT);
					(yyval.no) = createTree(0,NULL, TLookup("boolean"),NULL,NODE_LT,(yyvsp[-2].no),NULL,(yyvsp[0].no));
				}
#line 2316 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 522 "exprtree.y" /* yacc.c:1646  */
    {
					TypeCheck((yyvsp[-2].no)->type,(yyvsp[0].no)->type,NODE_GT);
					(yyval.no) = createTree(0,NULL, TLookup("boolean"),NULL,NODE_GT,(yyvsp[-2].no),NULL,(yyvsp[0].no));
				}
#line 2325 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 526 "exprtree.y" /* yacc.c:1646  */
    {(yyval.no) = createTree(0,NULL, TLookup("boolean"),NULL,NODE_NOT,NULL,(yyvsp[0].no),NULL);}
#line 2331 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 527 "exprtree.y" /* yacc.c:1646  */
    {(yyval.no) = createTree(0,NULL, TLookup("null"),NULL,NODE_NIL,NULL,NULL,NULL);}
#line 2337 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 528 "exprtree.y" /* yacc.c:1646  */
    {(yyval.no) = (yyvsp[-1].no);}
#line 2343 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 529 "exprtree.y" /* yacc.c:1646  */
    {(yyval.no) = (yyvsp[0].no);}
#line 2349 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 530 "exprtree.y" /* yacc.c:1646  */
    {
					IDCheck((yyvsp[0].no));
					(yyval.no) = (yyvsp[0].no);
				}
#line 2358 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 534 "exprtree.y" /* yacc.c:1646  */
    {
					IDCheck((yyvsp[-3].no));
					(yyval.no) = createTree(0,NULL, (yyvsp[-3].no)->type,(yyvsp[-3].no)->name,NODE_ARRAY,(yyvsp[-3].no),(yyvsp[-1].no),NULL);
				}
#line 2367 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 539 "exprtree.y" /* yacc.c:1646  */
    {
					IDCheck((yyvsp[-6].no));
					(yyval.no) = createTree(0,NULL, (yyvsp[-6].no)->type,(yyvsp[-6].no)->name,NODE_MATRIX,(yyvsp[-6].no),(yyvsp[-4].no),(yyvsp[-1].no));
				}
#line 2376 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 543 "exprtree.y" /* yacc.c:1646  */
    {
					IDCheck((yyvsp[0].no));
					(yyval.no) = createTree(0,NULL, (yyvsp[0].no)->type,(yyvsp[0].no)->name,NODE_ID_VALPTR,NULL,NULL,NULL);
				}
#line 2385 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 547 "exprtree.y" /* yacc.c:1646  */
    {
					IDCheck((yyvsp[0].no));
					(yyvsp[0].no)->nodetype = NODE_ID_ADDRESS;
					(yyval.no) = (yyvsp[0].no);
				}
#line 2395 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 552 "exprtree.y" /* yacc.c:1646  */
    {(yyval.no) = createTree(0,NULL, TLookup("type"),NULL,NODE_ALLOC,NULL,NULL,NULL);}
#line 2401 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 553 "exprtree.y" /* yacc.c:1646  */
    {(yyval.no) = createTree(0,NULL, TLookup("integer"),NULL,NODE_INIT,NULL,NULL,NULL);}
#line 2407 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 555 "exprtree.y" /* yacc.c:1646  */
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
#line 2444 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 587 "exprtree.y" /* yacc.c:1646  */
    {(yyval.no) = (yyvsp[0].no);}
#line 2450 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 588 "exprtree.y" /* yacc.c:1646  */
    {(yyval.no) = (yyvsp[0].no);}
#line 2456 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 590 "exprtree.y" /* yacc.c:1646  */
    {
					struct tnode *temp = (yyvsp[-2].no);
					while(temp->ArgList!=NULL)
						temp = temp->ArgList;
					temp->ArgList = (yyvsp[0].no);
					(yyval.no) = (yyvsp[-2].no);
				}
#line 2468 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 597 "exprtree.y" /* yacc.c:1646  */
    {(yyval.no) = (yyvsp[0].no);}
#line 2474 "y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 598 "exprtree.y" /* yacc.c:1646  */
    {(yyval.no) = NULL;}
#line 2480 "y.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 600 "exprtree.y" /* yacc.c:1646  */
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
#line 2499 "y.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 614 "exprtree.y" /* yacc.c:1646  */
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
#line 2518 "y.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 628 "exprtree.y" /* yacc.c:1646  */
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
#line 2544 "y.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 651 "exprtree.y" /* yacc.c:1646  */
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
#line 2570 "y.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 673 "exprtree.y" /* yacc.c:1646  */
    {
					if((yyvsp[-5].no)->nodetype == NODE_FIELD_SELF)
						(yyvsp[-5].no)->nodetype = NODE_FIELD_SELF_ADDRESS;
					else
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
#line 2604 "y.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 703 "exprtree.y" /* yacc.c:1646  */
    {
					(yyvsp[-5].no)->nodetype = NODE_ID_ADDRESS;
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
#line 2635 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2639 "y.tab.c" /* yacc.c:1646  */
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
#line 730 "exprtree.y" /* yacc.c:1906  */


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
	fprintf(target_file,"JMP L%d:\n",getLabel());
	TypeTableCreate();
	yyparse();
	return 0;
}
