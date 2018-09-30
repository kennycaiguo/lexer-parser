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

#ifndef YY_YY_P_TAB_H_INCLUDED
# define YY_YY_P_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "p.y" /* yacc.c:1909  */

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>

	// data types
	#define DT_NUM 1
	#define DT_STR 2
	#define DT_FLT 3
	#define DT_FNC 4

	#define CMP_GR 5
	#define CMP_EQ 6
	#define CMP_SM 7
	#define CMP_GE 8
	#define CMP_SE 9
	#define CMP_NEQ	10

	struct ops{
		char * statement;
		struct ops * next;
	};

	struct ops* add_op(char *, struct ops*);

	/* symbol table */
	struct sym_entry{
		char * varname;
		char * value;
		int type;
		struct sym_entry * next;
	};
	struct sym_entry* add_sym(char*, char*, int, struct sym_entry *);
	struct sym_entry* find_sym(char *, struct sym_entry *);


	/* parameters */
	struct param{
		int type;
		char* varname;
		struct param * next;
	};
	struct param* add_param(int, char*, struct param*);


	/* function table */
	struct fn_entry{
		char* fname;
		struct param* params;
		struct fn_entry* next;
	};
	struct fn_entry* add_fn(char*, struct param*, struct fn_entry* );
	struct fn_entry* create_fn(char*, struct param*);
	struct fn_entry* find_fn(char *, struct fn_entry *);


	/* class table */
	struct member{
		int type;
		char* name;
		char* value;
		struct param* params;
		struct member* next;
	};
	struct member* add_member(int, char*, char*, struct param*,struct member*);
	struct member* find_mbr(char *, struct member*);

	struct class_entry{
		char* cname;
		struct fn_entry* member_fns;
		struct sym_entry* member_vars;
		struct param* params;
		struct class_entry* next;
	};
	struct class_entry * add_class(char*,struct param*, struct member*, struct class_entry *);
	struct class_entry* find_class(char*, struct class_entry *);

	/* printing functions */
	void print_classes(struct class_entry * tmp);
	void print_members(struct member* tmp);
	void print_fns(struct fn_entry* tmp);
	void print_params(struct param* tmp);
	void print_syms(struct sym_entry* tmp);
	void print_ops(struct ops* tmp);

	/* intermediate var and type */
	struct ivar{
		int type;
		char * holder;
		struct ivar* next;
	};
	struct ivar* create_ivar(int, char*, struct ivar*);

	char * getFullVarName(char *);
	char * getFullFnName(char *);

#line 141 "p.tab.h" /* yacc.c:1909  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ASSGN = 258,
    SEMI = 259,
    PLUS = 260,
    MINUS = 261,
    TIMES = 262,
    DIV = 263,
    ID = 264,
    VAL_INT = 265,
    VAL_FLOAT = 266,
    NOT = 267,
    DOT = 268,
    VAL_STRING = 269,
    COMMA = 270,
    OPEN_ROUND = 271,
    CLOSE_ROUND = 272,
    OPEN_SQ = 273,
    CLOSE_SQ = 274,
    OPEN_CURLY = 275,
    CLOSE_CURLY = 276,
    SMEQ = 277,
    GREQ = 278,
    GR = 279,
    SM = 280,
    EQ = 281,
    NEQ = 282,
    WHILE = 283,
    IF = 284,
    ELSE = 285,
    FOR = 286,
    TYPE_INT = 287,
    TYPE_FLOAT = 288,
    TYPE_STRING = 289,
    HASH_INCLUDE = 290,
    FUNCTION_IDF = 291,
    CLASS_IDF = 292,
    PRINT_STR = 293,
    PRINT_VAL = 294
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 98 "p.y" /* yacc.c:1909  */

	char * word;
	int val;
	struct param* param_lst;
	struct member* members_container;
	struct ivar* ivar_instance;
	struct sym_entry* sym_instance;
	struct fn_entry* fn_instance;
	struct class_entry* class_instance;

#line 204 "p.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_P_TAB_H_INCLUDED  */
