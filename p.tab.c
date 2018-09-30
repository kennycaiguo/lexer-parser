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

#line 67 "p.tab.c" /* yacc.c:339  */

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
   by #include "p.tab.h".  */
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
#line 1 "p.y" /* yacc.c:355  */

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

#line 194 "p.tab.c" /* yacc.c:355  */

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
#line 98 "p.y" /* yacc.c:355  */

	char * word;
	int val;
	struct param* param_lst;
	struct member* members_container;
	struct ivar* ivar_instance;
	struct sym_entry* sym_instance;
	struct fn_entry* fn_instance;
	struct class_entry* class_instance;

#line 257 "p.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_P_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */
#line 132 "p.y" /* yacc.c:358  */

	/* symbol table */
	struct sym_entry * sym_table = NULL;
	/* functions list */
	struct fn_entry * fn_table = NULL;
	/* classes list */
	struct class_entry* class_table = NULL;
	/* list of ops */
	struct ops * all_ops = NULL;

	/* current function */
	char * curFn = NULL;
	char * curClass = NULL;

	/* list of registers */
	char  *Names[] = { "$t0", "$t1", "$t2", "$t3", "$t4", "$t5", "$t6", "$t7" };   
	char  **Namep  = Names;  

	char  *newname()   
	{   
	    if( Namep >= &Names[ sizeof(Names)/sizeof(*Names) ] )   
	    {   
	        printf("Expression too complex\n");
	    }   
	   
	    return( *Namep++ );   
	}   
	   
	void freename(s)   
	char    *s;   
	{   
	    if( Namep > Names )   
	    *--Namep = s;   
	    else   
	    printf("(Internal error) Name stack underflow\n");   
	}   

	// head pointer to the stack of tag names
	struct Stack *head=NULL;

	struct Stack
	{
	    int val; // current counter value of the tag
	    struct Stack *next; // pointer to next name tag
	};

	/* counts the line tag number */
	static int tag_counter = 0;

	// pushing new tag names
	void push(){
	    struct Stack *temp=(struct Stack*)malloc(sizeof(struct Stack));
	    temp->val=++tag_counter;
	    temp->next=head;
	    head = temp;
	}

	// popping pushed entry again
	int pop(){
	    int num=head->val;
	    head=head->next;
	    return num;
	}
	// reading top entry
	int read(){
	    int num=head->val;
	    return num;

	}
	/* counts the line tag number */


#line 346 "p.tab.c" /* yacc.c:358  */

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   263

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  69
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  150

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   294

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   206,   206,   208,   209,   211,   212,   213,   214,   216,
     249,   261,   275,   283,   293,   303,   308,   315,   322,   326,
     335,   345,   346,   348,   367,   369,   371,   376,   379,   389,
     400,   402,   404,   418,   434,   435,   436,   438,   469,   478,
     479,   480,   481,   482,   483,   485,   499,   513,   516,   527,
     542,   554,   558,   569,   572,   589,   602,   619,   650,   657,
     690,   705,   709,   713,   714,   715,   716,   718,   719,   720
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ASSGN", "SEMI", "PLUS", "MINUS",
  "TIMES", "DIV", "ID", "VAL_INT", "VAL_FLOAT", "NOT", "DOT", "VAL_STRING",
  "COMMA", "OPEN_ROUND", "CLOSE_ROUND", "OPEN_SQ", "CLOSE_SQ",
  "OPEN_CURLY", "CLOSE_CURLY", "SMEQ", "GREQ", "GR", "SM", "EQ", "NEQ",
  "WHILE", "IF", "ELSE", "FOR", "TYPE_INT", "TYPE_FLOAT", "TYPE_STRING",
  "HASH_INCLUDE", "FUNCTION_IDF", "CLASS_IDF", "PRINT_STR", "PRINT_VAL",
  "$accept", "START", "headers", "pgm", "varDeclare", "funcDeclare", "fid",
  "classDeclare", "cid", "decList", "decParamList", "stmt_list", "stmt",
  "dtype", "cmp", "relop", "expr", "term", "factor", "paramList", "param",
  "exprList", "exprListItems", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294
};
# endif

#define YYPACT_NINF -99

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-99)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -99,    47,   172,   -99,   -99,   -99,   -99,   -99,    25,    58,
     -99,    66,    82,    86,    73,   -99,    77,   -99,    90,   194,
     194,   194,   -99,    29,    32,   -99,   -99,   -99,   183,   101,
     119,   112,   118,    55,   -99,   -99,   -99,     1,   183,   130,
     138,   145,   178,   189,   -99,   -99,    50,   237,   -99,   183,
     186,   200,   152,     1,   201,    93,     1,     0,    20,   105,
     220,     1,     1,   183,   -99,   -99,   165,   165,   165,   165,
     -99,    45,   231,   235,   192,   200,    50,   230,    56,   -99,
       1,    50,   141,   -99,   -99,     3,   -99,   -99,   245,   -99,
     233,    18,   234,   248,   237,   237,   -99,   -99,   -99,   200,
     200,   -99,   232,   113,    78,    70,   236,   139,   -99,   251,
     -99,   183,   -99,   -99,   -99,   -99,   -99,   -99,     1,   209,
       1,   -99,   -99,   -99,   -99,   185,    50,   -99,     1,   -99,
     -99,     1,   -99,    50,   183,   -99,   252,   -99,   -99,    50,
     131,   183,   227,   241,   239,   183,   183,   -99,   157,   -99
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     8,     1,    34,    35,    36,     3,     0,     0,
       2,     0,     0,     0,     0,    12,     0,    15,     0,     8,
       8,     8,     9,     0,     0,     5,     6,     7,     0,     0,
       0,     0,     0,    54,    52,    55,    48,     0,     0,     0,
       0,     0,     0,     0,    31,    11,    25,    47,    51,     0,
      20,    18,     0,     0,     0,     0,     0,    54,     0,     0,
       0,     0,     0,     0,    32,    33,     0,     0,     0,     0,
      10,     0,     0,     0,     0,    18,    23,    60,    54,    56,
       0,    63,     0,    62,    65,     0,    53,    30,     0,    22,
       0,    38,     0,     0,    45,    46,    49,    50,    19,    18,
      18,    14,     0,     0,     0,    69,     0,     0,    57,     0,
      21,     0,    39,    40,    41,    42,    43,    44,     0,     0,
       0,    16,    17,    13,    58,     0,    64,    66,     0,    67,
      61,     0,    29,    37,     0,    26,     0,    59,    68,    24,
       0,     0,    30,     0,     0,     0,     0,    28,     0,    27
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -99,   -99,   -99,   163,    -1,   -48,   -99,   -99,   -99,   -71,
     -17,   -98,   -28,   -18,   -60,   -99,   -23,    34,   111,   158,
     153,   159,   134
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,    10,    44,    12,    16,    13,    18,    74,
      29,    59,    60,    14,    90,   118,    46,    47,    48,    82,
      83,    84,   106
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      45,    11,    92,    73,   102,    30,    30,    32,    66,    67,
      57,    34,    35,    54,    58,    36,    55,    37,    11,    11,
      11,    70,   109,    66,    67,    66,    67,    73,   121,   122,
      76,    88,    81,    85,    15,    93,   140,    86,    91,    91,
     112,   113,   114,   115,   116,   117,    28,     3,   148,    31,
      72,    73,    73,    30,    98,    66,    67,   105,    53,   104,
     136,     4,     5,     6,     4,     5,     6,    17,    54,    54,
      19,    55,    55,    56,    72,    66,    67,     4,     5,     6,
      81,   126,    22,   132,    81,   128,    20,    57,    34,    35,
      21,   135,    36,    23,    37,   133,    80,    91,    72,    72,
      94,    95,    78,    34,    35,   105,    24,    36,   139,    37,
      79,    80,    88,   143,    33,    34,    35,   147,    49,    36,
      88,    37,    78,    34,    35,    38,    87,    36,    50,    37,
     124,    80,    51,    39,    40,    52,    41,     4,     5,     6,
      33,    34,    35,    42,    43,    36,    61,    37,    78,    34,
      35,    38,   142,    36,    62,    37,   107,    80,   108,    39,
      40,    63,    41,     4,     5,     6,    33,    34,    35,    42,
      43,    36,    75,    37,    57,    34,    35,    38,   149,    96,
      97,    37,    25,    26,    27,    39,    40,    64,    41,     4,
       5,     6,    33,    34,    35,    42,    43,    36,    65,    37,
     107,    71,   137,    38,     4,     5,     6,     7,     8,     9,
      77,    39,    40,   101,    41,     4,     5,     6,    33,    34,
      35,    42,    43,    36,    89,    37,     4,     5,     6,   134,
       8,     9,     4,     5,     6,    99,     8,    39,    40,   100,
      41,     4,     5,     6,    68,    69,   103,    42,    43,   110,
     111,   119,   120,   123,   131,   129,   141,   144,   145,   146,
     130,   125,   138,   127
};

static const yytype_uint8 yycheck[] =
{
      28,     2,    62,    51,    75,    23,    24,    24,     5,     6,
       9,    10,    11,    13,    37,    14,    16,    16,    19,    20,
      21,    49,    19,     5,     6,     5,     6,    75,    99,   100,
      53,    59,    55,    56,     9,    63,   134,    17,    61,    62,
      22,    23,    24,    25,    26,    27,    17,     0,   146,    17,
      51,    99,   100,    71,    71,     5,     6,    80,     3,     3,
     120,    32,    33,    34,    32,    33,    34,     9,    13,    13,
       4,    16,    16,    18,    75,     5,     6,    32,    33,    34,
     103,   104,     9,   111,   107,    15,     4,     9,    10,    11,
       4,   119,    14,    16,    16,   118,    18,   120,    99,   100,
      66,    67,     9,    10,    11,   128,    16,    14,   131,    16,
      17,    18,   140,   141,     9,    10,    11,   145,    17,    14,
     148,    16,     9,    10,    11,    20,    21,    14,     9,    16,
      17,    18,    20,    28,    29,    17,    31,    32,    33,    34,
       9,    10,    11,    38,    39,    14,    16,    16,     9,    10,
      11,    20,    21,    14,    16,    16,    15,    18,    17,    28,
      29,    16,    31,    32,    33,    34,     9,    10,    11,    38,
      39,    14,    20,    16,     9,    10,    11,    20,    21,    68,
      69,    16,    19,    20,    21,    28,    29,     9,    31,    32,
      33,    34,     9,    10,    11,    38,    39,    14,     9,    16,
      15,    15,    17,    20,    32,    33,    34,    35,    36,    37,
       9,    28,    29,    21,    31,    32,    33,    34,     9,    10,
      11,    38,    39,    14,     4,    16,    32,    33,    34,    20,
      36,    37,    32,    33,    34,     4,    36,    28,    29,     4,
      31,    32,    33,    34,     7,     8,    16,    38,    39,     4,
      17,    17,     4,    21,     3,    19,     4,    30,    17,    20,
     107,   103,   128,   104
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    41,    42,     0,    32,    33,    34,    35,    36,    37,
      43,    44,    45,    47,    53,     9,    46,     9,    48,     4,
       4,     4,     9,    16,    16,    43,    43,    43,    17,    50,
      53,    17,    50,     9,    10,    11,    14,    16,    20,    28,
      29,    31,    38,    39,    44,    52,    56,    57,    58,    17,
       9,    20,    17,     3,    13,    16,    18,     9,    56,    51,
      52,    16,    16,    16,     9,     9,     5,     6,     7,     8,
      52,    15,    44,    45,    49,    20,    56,     9,     9,    17,
      18,    56,    59,    60,    61,    56,    17,    21,    52,     4,
      54,    56,    54,    52,    57,    57,    58,    58,    50,     4,
       4,    21,    49,    16,     3,    56,    62,    15,    17,    19,
       4,    17,    22,    23,    24,    25,    26,    27,    55,    17,
       4,    49,    49,    21,    17,    59,    56,    61,    15,    19,
      60,     3,    52,    56,    20,    52,    54,    17,    62,    56,
      51,     4,    21,    52,    30,    17,    20,    52,    51,    21
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    40,    41,    42,    42,    43,    43,    43,    43,    44,
      45,    45,    46,    47,    47,    48,    49,    49,    49,    50,
      50,    51,    51,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    53,    53,    53,    54,    54,    55,
      55,    55,    55,    55,    55,    56,    56,    56,    56,    57,
      57,    57,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    59,    59,    60,    60,    60,    60,    61,    62,    62
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     0,     3,     3,     3,     0,     2,
       6,     5,     1,     8,     7,     1,     3,     3,     0,     4,
       2,     3,     2,     3,     6,     1,     5,    11,     9,     5,
       3,     1,     2,     2,     1,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     1,     1,     3,
       3,     1,     1,     3,     1,     1,     3,     4,     5,     6,
       3,     3,     1,     1,     3,     1,     3,     3,     3,     1
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
        case 3:
#line 208 "p.y" /* yacc.c:1646  */
    { }
#line 1542 "p.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 209 "p.y" /* yacc.c:1646  */
    { }
#line 1548 "p.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 211 "p.y" /* yacc.c:1646  */
    { }
#line 1554 "p.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 212 "p.y" /* yacc.c:1646  */
    { }
#line 1560 "p.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 213 "p.y" /* yacc.c:1646  */
    { }
#line 1566 "p.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 214 "p.y" /* yacc.c:1646  */
    { }
#line 1572 "p.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 216 "p.y" /* yacc.c:1646  */
    {
				char *tvar = getFullVarName((yyvsp[0].word));
				if(find_sym(tvar, sym_table) == NULL){
					(yyval.sym_instance) = add_sym(tvar,NULL,(yyvsp[-1].val), sym_table);
					sym_table = (yyval.sym_instance);

				}else{
					printf("Variable %s has already been delcared in function %s.\n", (yyvsp[0].word), curFn);
					YYABORT;
				}
			}
#line 1588 "p.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 249 "p.y" /* yacc.c:1646  */
    {
					if(find_fn((yyvsp[-4].word), fn_table) == NULL){
						(yyval.fn_instance) = add_fn((yyvsp[-4].word), (yyvsp[-2].param_lst), fn_table);
						fn_table = (yyval.fn_instance);
						// char * dst = (char *)malloc(100);
						// sprintf(dst, "\tjr\t$ra");
						// all_ops = add_op(dst, all_ops);
					}else{
						printf("Function %s has already been declared.\n",(yyvsp[-4].word));
						YYABORT;
					}
					curFn = NULL;
				}
#line 1606 "p.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 261 "p.y" /* yacc.c:1646  */
    {
					if(find_fn((yyvsp[-3].word), fn_table) == NULL){
						(yyval.fn_instance) = add_fn((yyvsp[-3].word), NULL, fn_table);
						fn_table = (yyval.fn_instance);
						// char * dst = (char *)malloc(100);
						// sprintf(dst, "\tjr\t$ra");
						// all_ops = add_op(dst, all_ops);
					}else{
						printf("Function %s has already been declared.\n",(yyvsp[-3].word));
						YYABORT;
					}
					curFn = NULL;
				}
#line 1624 "p.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 275 "p.y" /* yacc.c:1646  */
    {
				curFn = getFullFnName(strdup((yyvsp[0].word)));
				(yyval.word) = curFn;
				char * dst = (char *) malloc(100);
				sprintf(dst, "%s:",curFn);
				all_ops = add_op(dst, all_ops);
			}
#line 1636 "p.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 283 "p.y" /* yacc.c:1646  */
    {

					if(find_class((yyvsp[-6].word), class_table) == NULL){
						(yyval.class_instance) = add_class((yyvsp[-6].word), (yyvsp[-4].param_lst), (yyvsp[-1].members_container), class_table);
						class_table = (yyval.class_instance);
					}else{
						printf("Class %s has already been declared.\n", (yyvsp[-6].word));
						YYABORT;
					}
					curClass = NULL;
				}
#line 1652 "p.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 293 "p.y" /* yacc.c:1646  */
    {
					if(find_class((yyvsp[-5].word), class_table) == NULL){
						(yyval.class_instance) = add_class((yyvsp[-5].word), NULL, (yyvsp[-1].members_container), class_table);
						class_table = (yyval.class_instance);
					}else{
						printf("Class %s has already been declared.\n", (yyvsp[-5].word));
						YYABORT;
					}
					curClass = NULL;
				}
#line 1667 "p.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 303 "p.y" /* yacc.c:1646  */
    { 
					(yyval.word) = (yyvsp[0].word);
					curClass = (yyvsp[0].word);
				}
#line 1676 "p.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 308 "p.y" /* yacc.c:1646  */
    { 
					if(find_mbr((yyvsp[-2].sym_instance)->varname, (yyvsp[0].members_container)) == NULL)
						(yyval.members_container) = add_member((yyvsp[-2].sym_instance)->type, (yyvsp[-2].sym_instance)->varname,(yyvsp[-2].sym_instance)->value,NULL, (yyvsp[0].members_container)); 
					else{
						printf("Member name %s has already been used.\n", (yyvsp[-2].sym_instance)->varname);
						YYABORT;
					}
				}
#line 1689 "p.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 315 "p.y" /* yacc.c:1646  */
    { 
					if(find_mbr((yyvsp[-2].fn_instance)->fname, (yyvsp[0].members_container)) == NULL)
						(yyval.members_container) = add_member(DT_FNC, (yyvsp[-2].fn_instance)->fname, NULL, (yyvsp[-2].fn_instance)->params, (yyvsp[0].members_container));
					else{
						printf("Member name %s has already been used.\n", (yyvsp[-2].fn_instance)->fname);
						YYABORT;
					} 
				}
#line 1702 "p.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 322 "p.y" /* yacc.c:1646  */
    { 
					(yyval.members_container) = NULL; 
				}
#line 1710 "p.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 326 "p.y" /* yacc.c:1646  */
    { 
					char *tvar = getFullVarName((yyvsp[-2].word));
					if(find_sym(tvar, sym_table) != NULL){
						printf("Variable %s already declared in function %s.\n",(yyvsp[-2].word), curFn);
						YYABORT;
					}else{
						(yyval.param_lst) = add_param((yyvsp[-3].val), tvar, (yyvsp[0].param_lst)); 
					}
				}
#line 1724 "p.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 335 "p.y" /* yacc.c:1646  */
    {
					char *tvar = getFullVarName((yyvsp[0].word));
					if(find_sym(tvar, sym_table) != NULL){
						printf("Variable %s already declared in function %s.\n",(yyvsp[0].word), curFn);
						YYABORT;
					}else{ 
						(yyval.param_lst) = add_param((yyvsp[-1].val), tvar, NULL);
					} 
				}
#line 1738 "p.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 345 "p.y" /* yacc.c:1646  */
    { all_ops = add_op("\n",all_ops); }
#line 1744 "p.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 346 "p.y" /* yacc.c:1646  */
    { }
#line 1750 "p.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 348 "p.y" /* yacc.c:1646  */
    { 
				char *tvar = getFullVarName((yyvsp[-2].word));
				struct sym_entry * tmpsym = find_sym(tvar, sym_table);
				if(tmpsym == NULL){
					printf("Variable %s not declared.\n",(yyvsp[-2].word));
					YYABORT;
				}else{
					if(tmpsym->type != (yyvsp[0].ivar_instance)->type){
						printf("Type mismatch in variable assignment : %s",(yyvsp[-2].word));
					}else{
						char * dst = (char*)malloc(100);
						strcpy(dst, "\tsw\t");
						strcat(dst, (yyvsp[0].ivar_instance)->holder);
						strcat(dst, ", ");
						strcat(dst, tvar);
						all_ops = add_op(dst, all_ops);
						freename((yyvsp[0].ivar_instance)->holder);
					}
				}
			}
#line 1775 "p.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 367 "p.y" /* yacc.c:1646  */
    { 

			}
#line 1783 "p.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 369 "p.y" /* yacc.c:1646  */
    {

			}
#line 1791 "p.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 371 "p.y" /* yacc.c:1646  */
    { 
				char * dst = (char*)malloc(100);
				sprintf(dst, "tag_%d:",pop());
				all_ops = add_op(dst, all_ops);
				pop();
			}
#line 1802 "p.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 377 "p.y" /* yacc.c:1646  */
    { 

			}
#line 1810 "p.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 379 "p.y" /* yacc.c:1646  */
    { 
				int tmpTag = pop();
				int tmpTag_ = pop();

				char * dst = (char*)malloc(100);
				sprintf(dst, "\tj\ttag_%d", tmpTag_);
				all_ops = add_op(dst, all_ops);

				sprintf(dst, "tag_%d:", tmpTag);
				all_ops = add_op(dst, all_ops);
			}
#line 1826 "p.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 389 "p.y" /* yacc.c:1646  */
    { 
				int tmpTag = pop();
				int tmpTag_ = pop();

				char * dst = (char*)malloc(100);
				sprintf(dst, "\tj\ttag_%d", tmpTag_);
				all_ops = add_op(dst, all_ops);

				sprintf(dst, "tag_%d:", tmpTag);
				all_ops = add_op(dst, all_ops);

			}
#line 1843 "p.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 400 "p.y" /* yacc.c:1646  */
    { 

			}
#line 1851 "p.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 402 "p.y" /* yacc.c:1646  */
    { 

			}
#line 1859 "p.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 404 "p.y" /* yacc.c:1646  */
    {
				char * symname = getFullVarName((yyvsp[0].word));
				struct sym_entry *tmpsym = find_sym(symname, sym_table);
				if(tmpsym!=NULL){
					if(tmpsym->type == DT_STR){
						char * dst = (char *) malloc(100);
						sprintf(dst, "\tla\t$a0, %s\n\tli\t$v0, 4\n\tsyscall",symname);
						all_ops = add_op(dst, all_ops);
					}else{
						printf("Print string type-mismatch : %s\n",(yyvsp[0].word));
					}
				}else{
					printf("Variable %s not found.\n",(yyvsp[0].word));
				}
			}
#line 1879 "p.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 418 "p.y" /* yacc.c:1646  */
    {
				char * symname = getFullVarName((yyvsp[0].word));
				struct sym_entry *tmpsym = find_sym(symname, sym_table);
				if(tmpsym!=NULL){
					if(tmpsym->type == DT_NUM){
						char * dst = (char *) malloc(100);
						sprintf(dst, "\tlw\t$a0, %s\n\tli\t$v0, 1\n\tsyscall",symname);
						all_ops = add_op(dst, all_ops);
					}else{
						printf("Print string type-mismatch : %s\n",(yyvsp[0].word));
					}
				}else{
					printf("Variable %s not found.\n",(yyvsp[0].word));
				}
			}
#line 1899 "p.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 434 "p.y" /* yacc.c:1646  */
    { (yyval.val) = DT_NUM; }
#line 1905 "p.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 435 "p.y" /* yacc.c:1646  */
    { (yyval.val) = DT_FLT; }
#line 1911 "p.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 436 "p.y" /* yacc.c:1646  */
    { (yyval.val) = DT_STR; }
#line 1917 "p.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 438 "p.y" /* yacc.c:1646  */
    { 
				if((yyvsp[-2].ivar_instance)->type!=(yyvsp[0].ivar_instance)->type){
					printf("type mismatch in comparison\n");
					YYABORT;
				}
				push();
				char * dst = (char*)malloc(100);
				sprintf(dst, "tag_%d:\t",read());
				if((yyvsp[-1].val) == CMP_SE){
					strcat(dst, "ble\t");
				}else if((yyvsp[-1].val) == CMP_SM){
					strcat(dst, "blt\t");
				}else if((yyvsp[-1].val) == CMP_GE){
					strcat(dst, "bge\t");
				}else if((yyvsp[-1].val) == CMP_GR){
					strcat(dst, "bgt\t");
				}else if((yyvsp[-1].val) == CMP_EQ){
					strcat(dst, "beq\t");
				}else if((yyvsp[-1].val) == CMP_NEQ){
					strcat(dst, "bne\t");
				}
				strcat(dst, (yyvsp[-2].ivar_instance)->holder);
				strcat(dst, ", ");
				strcat(dst, (yyvsp[0].ivar_instance)->holder);

				push();
				char * tmpStr = (char*)malloc(100);
				sprintf(tmpStr, ", tag_%d",read());
				strcat(dst, tmpStr);
				all_ops = add_op(dst, all_ops);
			}
#line 1953 "p.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 469 "p.y" /* yacc.c:1646  */
    { 
				push();
				int tmpTag = read();
				push();
				char * dst = (char*)malloc(100);
				sprintf(dst, "tag_%d:\tbne\t%s, $zero, tag_%d",tmpTag, (yyvsp[0].ivar_instance)->holder, read());
				all_ops = add_op(dst, all_ops);
			}
#line 1966 "p.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 478 "p.y" /* yacc.c:1646  */
    { (yyval.val) = CMP_SE; }
#line 1972 "p.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 479 "p.y" /* yacc.c:1646  */
    { (yyval.val) = CMP_GE; }
#line 1978 "p.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 480 "p.y" /* yacc.c:1646  */
    { (yyval.val) = CMP_GR; }
#line 1984 "p.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 481 "p.y" /* yacc.c:1646  */
    { (yyval.val) = CMP_SM; }
#line 1990 "p.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 482 "p.y" /* yacc.c:1646  */
    { (yyval.val) = CMP_EQ; }
#line 1996 "p.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 483 "p.y" /* yacc.c:1646  */
    { (yyval.val) = CMP_NEQ; }
#line 2002 "p.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 485 "p.y" /* yacc.c:1646  */
    {
				(yyval.ivar_instance) = (yyvsp[-2].ivar_instance); 

				char * dst = (char*)malloc(100);
				strcpy(dst, "\tadd\t");
				strcat(dst, (yyval.ivar_instance)->holder);
				strcat(dst, ", ");
				strcat(dst, (yyval.ivar_instance)->holder);
				strcat(dst, ", ");
				strcat(dst, (yyvsp[0].ivar_instance)->holder);
				all_ops = add_op(dst, all_ops);

				freename((yyvsp[0].ivar_instance)->holder);
			}
#line 2021 "p.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 499 "p.y" /* yacc.c:1646  */
    { 
				(yyval.ivar_instance) = (yyvsp[-2].ivar_instance);

				char * dst = (char*)malloc(100);
				strcpy(dst, "\tsub\t");
				strcat(dst, (yyval.ivar_instance)->holder);
				strcat(dst, ", ");
				strcat(dst, (yyval.ivar_instance)->holder);
				strcat(dst, ", ");
				strcat(dst, (yyvsp[0].ivar_instance)->holder);
				all_ops = add_op(dst, all_ops);
				
				freename((yyvsp[0].ivar_instance)->holder);
			}
#line 2040 "p.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 513 "p.y" /* yacc.c:1646  */
    {
				(yyval.ivar_instance) = (yyvsp[0].ivar_instance);
			}
#line 2048 "p.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 516 "p.y" /* yacc.c:1646  */
    {
				(yyval.ivar_instance) = create_ivar(DT_STR,newname(),NULL);
				
				char * dst = (char*)malloc(100);
				strcpy(dst, "\tla\t");
				strcat(dst, (yyval.ivar_instance)->holder);
				strcat(dst, ", ");
				strcat(dst, (yyvsp[0].word));
				all_ops = add_op(dst, all_ops);
			}
#line 2063 "p.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 527 "p.y" /* yacc.c:1646  */
    { 
				(yyval.ivar_instance) = (yyvsp[-2].ivar_instance);

				char * dst = (char*)malloc(100);
				strcpy(dst, "\tmul\t");
				strcat(dst, (yyval.ivar_instance)->holder);
				strcat(dst, ", ");
				strcat(dst, (yyval.ivar_instance)->holder);
				strcat(dst, ", ");
				strcat(dst, (yyvsp[0].ivar_instance)->holder);
				all_ops = add_op(dst, all_ops);

				
				freename((yyvsp[0].ivar_instance)->holder);
			}
#line 2083 "p.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 542 "p.y" /* yacc.c:1646  */
    { 
				(yyval.ivar_instance) = (yyvsp[-2].ivar_instance);

				char * dst = (char*)malloc(100);
				strcpy(dst, "\tdiv\t");
				strcat(dst, (yyval.ivar_instance)->holder);
				strcat(dst, ", ");
				strcat(dst, (yyvsp[0].ivar_instance)->holder);
				all_ops = add_op(dst, all_ops);

				freename((yyvsp[0].ivar_instance)->holder);
			}
#line 2100 "p.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 554 "p.y" /* yacc.c:1646  */
    {
				(yyval.ivar_instance) = (yyvsp[0].ivar_instance);
			}
#line 2108 "p.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 558 "p.y" /* yacc.c:1646  */
    {
				(yyval.ivar_instance) = create_ivar(DT_NUM,newname(),NULL);

				char * dst = (char*)malloc(100);
				strcpy(dst, "\tli\t");
				strcat(dst, (yyval.ivar_instance)->holder);
				strcat(dst, ", ");
				strcat(dst, (yyvsp[0].word));
				all_ops = add_op(dst, all_ops);

			}
#line 2124 "p.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 569 "p.y" /* yacc.c:1646  */
    {
				(yyval.ivar_instance) = (yyvsp[-1].ivar_instance);
			}
#line 2132 "p.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 572 "p.y" /* yacc.c:1646  */
    { 
				char *tvar = getFullVarName((yyvsp[0].word));
				struct sym_entry* tmp = find_sym(tvar, sym_table);
				if(tmp!=NULL){
					(yyval.ivar_instance) = create_ivar(tmp->type, newname(), NULL);

					char * dst = (char*)malloc(100);
					strcpy(dst, "\tlw\t");
					strcat(dst, (yyval.ivar_instance)->holder);
					strcat(dst, ", ");
					strcat(dst, tvar);
					all_ops = add_op(dst, all_ops);
				}else{
					printf("Variable %s not declared.\n",(yyvsp[0].word));
					YYABORT;
				}
			}
#line 2154 "p.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 589 "p.y" /* yacc.c:1646  */
    {
				(yyval.ivar_instance) = create_ivar(DT_FLT,newname(), NULL);
				
				char * dst = (char*)malloc(100);
				strcpy(dst, "\tli\t");
				strcat(dst, (yyval.ivar_instance)->holder);
				strcat(dst, ", ");
				strcat(dst, (yyvsp[0].word));
				all_ops = add_op(dst, all_ops);
			}
#line 2169 "p.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 602 "p.y" /* yacc.c:1646  */
    {
				char * fname = getFullFnName((yyvsp[-2].word));
				struct fn_entry* tmp = find_fn(fname, fn_table);
				if(tmp == NULL){
					printf("Function %s not defined.\n",(yyvsp[-2].word));
					YYABORT;
				}else{
					if(tmp->params!=NULL){
						printf("No arguments provided for function %s",(yyvsp[-2].word));
						YYABORT;
					}else{
						char * dst = (char*)malloc(100);
						sprintf(dst, "\tjal\t%s",tmp->fname);
						all_ops = add_op(dst, all_ops);
					}
				}
			}
#line 2191 "p.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 619 "p.y" /* yacc.c:1646  */
    {
				char * fname = getFullFnName((yyvsp[-3].word));
				struct fn_entry* tmp = find_fn(fname, fn_table);
				if(tmp == NULL){
					printf("Function %s not defined.\n",(yyvsp[-3].word));
					YYABORT;
				}else{
					struct param* tmp_param = tmp->params;
					struct ivar * tmp_ivar = (yyvsp[-1].ivar_instance);
					while(tmp_param!=NULL && tmp_ivar!=NULL){
						if(tmp_param->type != tmp_ivar->type){
							printf("Parameters type mismatch in function %s.\n",(yyvsp[-3].word));
							YYABORT;
						}
						char *dst = (char *)malloc(100);
						sprintf(dst, "\tsw\t%s, %s\n",tmp_ivar->holder,tmp_param->varname);
						all_ops = add_op(dst, all_ops);

						tmp_param = tmp_param->next;
						tmp_ivar = tmp_ivar->next;
					}
					if(tmp_param != NULL || tmp_ivar != NULL){
						printf("Parameter count mismatch in function %s.",(yyvsp[-3].word));
						YYABORT;
					}else{
						char * dst = (char*)malloc(100);
						sprintf(dst, "\tjal\t%s",fname);
						all_ops = add_op(dst, all_ops);
					}
				}
			}
#line 2227 "p.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 650 "p.y" /* yacc.c:1646  */
    { 
				char * fname = (char*)malloc(100);
				sprintf(fname,"class_%s_%s",(yyvsp[-4].word), (yyvsp[-2].word));
				struct fn_entry * tmpf = find_fn(fname, fn_table);
				if(tmpf== NULL){
					printf("No member function %s found for class %s", (yyvsp[-2].word), (yyvsp[-4].word));
				}
			}
#line 2240 "p.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 657 "p.y" /* yacc.c:1646  */
    {
				char * classBuf = curClass;
				curClass = (yyvsp[-5].word);
				char * fname = getFullFnName((yyvsp[-3].word));
				struct fn_entry* tmp = find_fn(fname, fn_table);
				if(tmp == NULL){
					printf("Function %s not defined.\n",(yyvsp[-3].word));
					YYABORT;
				}else{
					struct param* tmp_param = tmp->params;
					struct ivar * tmp_ivar = (yyvsp[-1].ivar_instance);
					while(tmp_param!=NULL && tmp_ivar!=NULL){
						if(tmp_param->type != tmp_ivar->type){
							printf("Parameters type mismatch in function %s.\n",(yyvsp[-3].word));
							YYABORT;
						}
						char *dst = (char *)malloc(100);
						sprintf(dst, "\tsw\t%s, %s\n",tmp_ivar->holder,tmp_param->varname);
						all_ops = add_op(dst, all_ops);

						tmp_param = tmp_param->next;
						tmp_ivar = tmp_ivar->next;
					}
					if(tmp_param != NULL || tmp_ivar != NULL){
						printf("Parameter count mismatch in function %s.",(yyvsp[-3].word));
						YYABORT;
					}else{
						char * dst = (char*)malloc(100);
						sprintf(dst, "\tjal\t%s",fname);
						all_ops = add_op(dst, all_ops);
					}
				}
				curClass = classBuf;
			}
#line 2279 "p.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 690 "p.y" /* yacc.c:1646  */
    {
				char * vname = (char *)malloc(100);
				sprintf(vname, "var_class_%s_%s", (yyvsp[-2].word), (yyvsp[0].word));
				struct sym_entry* tvar = find_sym(vname, sym_table);
				if(tvar == NULL){
					printf("Variable %s not declared in class %s.\n",(yyvsp[0].word), (yyvsp[-2].word));
					YYABORT;
				} else{
					(yyval.ivar_instance) = create_ivar(tvar->type, newname(),NULL);
					char * dst = (char *)malloc(100);
					sprintf(dst, "\tlw\t%s, %s",(yyval.ivar_instance)->holder, tvar->varname);
					all_ops = add_op(dst, all_ops);
				}
			}
#line 2298 "p.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 705 "p.y" /* yacc.c:1646  */
    { 
				(yyvsp[0].ivar_instance)->next = (yyvsp[-2].ivar_instance);
				(yyval.ivar_instance) = (yyvsp[0].ivar_instance);
			}
#line 2307 "p.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 709 "p.y" /* yacc.c:1646  */
    { 
				(yyval.ivar_instance) = (yyvsp[0].ivar_instance);
			}
#line 2315 "p.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 713 "p.y" /* yacc.c:1646  */
    { (yyval.ivar_instance) = (yyvsp[0].ivar_instance); }
#line 2321 "p.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 714 "p.y" /* yacc.c:1646  */
    { (yyval.ivar_instance) = (yyvsp[0].ivar_instance); }
#line 2327 "p.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 715 "p.y" /* yacc.c:1646  */
    { }
#line 2333 "p.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 716 "p.y" /* yacc.c:1646  */
    { }
#line 2339 "p.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 718 "p.y" /* yacc.c:1646  */
    { }
#line 2345 "p.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 719 "p.y" /* yacc.c:1646  */
    { }
#line 2351 "p.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 720 "p.y" /* yacc.c:1646  */
    { }
#line 2357 "p.tab.c" /* yacc.c:1646  */
    break;


#line 2361 "p.tab.c" /* yacc.c:1646  */
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
#line 723 "p.y" /* yacc.c:1906  */


#include <stdio.h>

char * getFullFnName(char * txt){
	char * dst = (char *)malloc(100);
	if(curClass==NULL)
		sprintf(dst, "noclass_%s",txt);
	else
		sprintf(dst, "class_%s_%s",curClass, txt);
	return dst;
}

char * getFullVarName(char * txt){
	char * dst = (char*)malloc(100);
	if(curClass == NULL){
		if(curFn == NULL)
			sprintf(dst, "sym_%s", txt);
		else
			sprintf(dst, "fn_%s_%s",curFn, txt);
	}else{
		if(curFn == NULL)
			sprintf(dst, "var_class_%s_%s",curClass, txt);
		else 
			sprintf(dst, "fn_%s_%s",curFn, txt);
	}
	return dst;
}

struct ivar* create_ivar(int type, char * holder, struct ivar* next){
	struct ivar * tmp = (struct ivar*)malloc(sizeof(struct ivar));
	tmp->type = type;
	tmp->holder = strdup(holder);
	tmp->next = next;
	return tmp;
}

struct ops* add_op(char * statement, struct ops* head){
	struct ops* tmp = (struct ops*)malloc(sizeof(struct ops));
	tmp->statement = strdup(statement);
	tmp->next = NULL;

	if(head == NULL){
		return tmp;
	}else{
		struct ops* newHead = head;
		while(head->next!=NULL){
			head = head->next;
		}
		head->next = tmp;
		return newHead;
	}
}

struct class_entry* add_class(char* cname, struct param* params, struct member* members, struct class_entry* next){
	struct class_entry* tmp = (struct class_entry*)malloc(sizeof(struct class_entry));
	tmp->cname = strdup(cname);
	tmp->params = params;
	while(members!=NULL){
		if(members->type == DT_FNC){
			tmp->member_fns = add_fn(members->name, members->params, tmp->member_fns);
		}
		else{
			tmp->member_vars = add_sym(members->name, members->value, members->type, tmp->member_vars);
		}
		members = members->next;
	}
	tmp->next = next;
	return tmp;
}

struct member* add_member(int type, char* name, char* value, struct param* params, struct member* members){
	struct member* tmp = (struct member*)malloc(sizeof(struct member));
	tmp->type = type;
	tmp->name = strdup(name);

	// for vars
	if(value!=NULL)
		tmp->value = strdup(value);
	// for funcs
	if(params!=NULL)
		tmp->params = params;
	tmp->next = members;
	return tmp;
}

struct sym_entry* add_sym(char * name, char * value, int type, struct sym_entry* next){
	struct sym_entry * tmp = (struct sym_entry*) malloc(sizeof(struct sym_entry));
	tmp->varname = (char*)malloc(100);
	sprintf(tmp->varname, "%s",name);
	if(value!= NULL) tmp->value = strdup(value);
	tmp->type = type;

	// add to symbol symbols list
	tmp->next = next;
	return tmp;
}

struct param* add_param(int type, char* name, struct param* head){
	struct param* tmp = (struct param*) malloc(sizeof(struct param));
	tmp->type = type;
	tmp->varname = strdup(name);

	sym_table = add_sym(name, NULL, type, sym_table);

	if(head == NULL){
		return tmp;
	}else{
		struct param* newHead = head;
		while(head->next!=NULL){
			head = head->next;
		}
		head->next = tmp;
		return newHead;
	}
}

struct fn_entry* add_fn(char*name, struct param* param_list, struct fn_entry* next){
	struct fn_entry * tmp = create_fn(name, param_list);
	tmp->next = next;
	return tmp;
}

struct fn_entry* create_fn(char *name, struct param* param_list){
	struct fn_entry* tmp = (struct fn_entry*) malloc(sizeof(struct fn_entry));
	tmp->fname = strdup(name);
	tmp->params = param_list;
	return tmp;
}


/*  finding 
	functions
*/

struct sym_entry * find_sym(char *name, struct sym_entry * tmp){
	while(tmp!=NULL){
		if(strcmp(name, tmp->varname)==0)
			return tmp;
		tmp = tmp->next;
	}
	return NULL;
}

struct fn_entry * find_fn(char * name, struct fn_entry * tmp){
	while(tmp!=NULL){
		if(strcmp(name, tmp->fname) == 0)
			return tmp;
		tmp = tmp->next;
	}
	return NULL;
}

struct member* find_mbr(char * name, struct member* members){
	while(members!=NULL){
		if(strcmp(name, members->name) == 0)
			return members;
		members = members->next;
	}
	return NULL;
}

struct class_entry* find_class(char *name, struct class_entry* tmp){
	while(tmp!=NULL){
		if(strcmp(name, tmp->cname) == 0)
			return tmp;
		tmp = tmp->next;
	}
	return NULL;
}

/* 	printing 
	functions 
*/

void print_classes(struct class_entry * tmp){
	while(tmp!=NULL){
		printf("%s",tmp->cname);
		print_params(tmp->params);
		print_fns(tmp->member_fns);
		print_syms(tmp->member_vars);
		tmp = tmp->next;
	}
}

void print_members(struct member* tmp){
	while(tmp!=NULL){
		printf("%s : %d", tmp->name, tmp->type);
		tmp = tmp->next;
	}
}

void print_fns(struct fn_entry* tmp){
	while(tmp!=NULL){
		printf("%s(",tmp->fname);
		print_params(tmp->params);
		printf(")\n");
		tmp = tmp->next;
	}
}

void print_params(struct param* tmp){
	while(tmp!=NULL){
		printf(" %d %s, ",tmp->type, tmp->varname);
		tmp = tmp->next;
	}
}

void print_syms(struct sym_entry* tmp){
	printf(".data\n");
	while(tmp!=NULL){
		if(tmp->value != NULL){
			if(tmp->type == DT_NUM)
				printf("\t%s:  .word %s\n",tmp->varname, tmp->value);
			else if(tmp->type == DT_FLT)
				printf("\t%s:  .float %s\n",tmp->varname, tmp->value);
			else if(tmp->type == DT_STR)
				printf("\t%s:  .asciiz %s\n",tmp->varname, tmp->value);
		}else{
			if(tmp->type == DT_NUM)
				printf("\t%s:  .word 0\n",tmp->varname);
			else if(tmp->type == DT_FLT)
				printf("\t%s:  .float 0.0\n",tmp->varname);
			else if(tmp->type == DT_STR)
				printf("\t%s:  .asciiz \"\"\n",tmp->varname);
		}
		tmp = tmp->next;
	}
}

void print_ops(struct ops* tmp){
	printf(".text\nmain:\tjal\tnoclass_main\n");
	while(tmp!=NULL){
		printf("%s\n", tmp->statement);
		tmp = tmp->next;
	}
}

int main(){
	if(yyparse()){
		printf("Error occurred. Terminating program.\n");
	}
	else{
		// printf("\nFunctions:\n\n");
		// print_fns(fn_table);
		// printf("Variables:\n\n");
		print_syms(sym_table);
		// printf("Classes:\n\n");
		// print_classes(class_table);
		// printf("Code:\n\n");
		print_ops(all_ops);
	}
}
