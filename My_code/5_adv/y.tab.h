/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
    AND = 294,
    OR = 295
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
#define AND 294
#define OR 295

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 13 "exprtree.y" /* yacc.c:1909  */

	struct tnode *no;

#line 138 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
