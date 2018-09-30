%code requires{
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
}

%union{
	char * word;
	int val;
	struct param* param_lst;
	struct member* members_container;
	struct ivar* ivar_instance;
	struct sym_entry* sym_instance;
	struct fn_entry* fn_instance;
	struct class_entry* class_instance;
}

%token 	ASSGN SEMI PLUS MINUS TIMES DIV 
		ID VAL_INT VAL_FLOAT NOT DOT VAL_STRING COMMA
		OPEN_ROUND CLOSE_ROUND OPEN_SQ CLOSE_SQ 
		OPEN_CURLY CLOSE_CURLY
		SMEQ GREQ GR SM EQ NEQ
		WHILE IF ELSE FOR
		TYPE_INT TYPE_FLOAT TYPE_STRING
		HASH_INCLUDE FUNCTION_IDF CLASS_IDF PRINT_STR PRINT_VAL;

%type <val> dtype
%type <word> fid cid
%type <val> relop
%type <ivar_instance> expr term factor paramList param
%type <members_container> decList
%type <sym_instance> varDeclare
%type <fn_instance> funcDeclare
%type <class_instance> classDeclare
%type <word> exprList exprListItems
%type <word> VAL_INT VAL_FLOAT VAL_STRING ID
%type <param_lst> decParamList

%start START

%{
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

%}

%%
START 		: headers pgm ;

headers 	: headers HASH_INCLUDE 	{ }
			| 						{ };

pgm 		: varDeclare SEMI pgm 	{ }
			| funcDeclare SEMI pgm	{ }
			| classDeclare SEMI pgm { }
			| 						{ };

varDeclare 	: dtype ID{
				char *tvar = getFullVarName($2);
				if(find_sym(tvar, sym_table) == NULL){
					$$ = add_sym(tvar,NULL,$1, sym_table);
					sym_table = $$;

				}else{
					printf("Variable %s has already been delcared in function %s.\n", $2, curFn);
					YYABORT;
				}
			}
			// | dtype ID ASSGN expr{ 
			// 	char *tvar = getFullVarName($2);

			// 	if(find_sym(tvar, sym_table) == NULL){
			// 		/* add value to id */
			// 		char * dst_ = (char*)malloc(100);
			// 		strcpy(dst_, "\tsw\t");
			// 		strcat(dst_, $4->holder);
			// 		strcat(dst_, ", ");
			// 		strcat(dst_, tvar);
			// 		all_ops = add_op(dst_, all_ops);
			// 		freename($4->holder);

			// 		/* add id */
			// 		$$ = add_sym(tvar,$4->holder,$1, sym_table);
			// 		sym_table = $$;
			// 	}else{
			// 		printf("Variable %s has already been delcared in function %s.\n", $2, curFn);
			// 		YYABORT;
			// 	}
			// };

funcDeclare 	: FUNCTION_IDF fid OPEN_ROUND decParamList CLOSE_ROUND stmt{
					if(find_fn($2, fn_table) == NULL){
						$$ = add_fn($2, $4, fn_table);
						fn_table = $$;
						// char * dst = (char *)malloc(100);
						// sprintf(dst, "\tjr\t$ra");
						// all_ops = add_op(dst, all_ops);
					}else{
						printf("Function %s has already been declared.\n",$2);
						YYABORT;
					}
					curFn = NULL;
				}| FUNCTION_IDF fid OPEN_ROUND CLOSE_ROUND stmt{
					if(find_fn($2, fn_table) == NULL){
						$$ = add_fn($2, NULL, fn_table);
						fn_table = $$;
						// char * dst = (char *)malloc(100);
						// sprintf(dst, "\tjr\t$ra");
						// all_ops = add_op(dst, all_ops);
					}else{
						printf("Function %s has already been declared.\n",$2);
						YYABORT;
					}
					curFn = NULL;
				};

fid  		: ID {
				curFn = getFullFnName(strdup($1));
				$$ = curFn;
				char * dst = (char *) malloc(100);
				sprintf(dst, "%s:",curFn);
				all_ops = add_op(dst, all_ops);
			};

classDeclare	: CLASS_IDF cid OPEN_ROUND decParamList CLOSE_ROUND OPEN_CURLY decList CLOSE_CURLY {

					if(find_class($2, class_table) == NULL){
						$$ = add_class($2, $4, $7, class_table);
						class_table = $$;
					}else{
						printf("Class %s has already been declared.\n", $2);
						YYABORT;
					}
					curClass = NULL;
				}| CLASS_IDF cid OPEN_ROUND CLOSE_ROUND OPEN_CURLY decList CLOSE_CURLY {
					if(find_class($2, class_table) == NULL){
						$$ = add_class($2, NULL, $6, class_table);
						class_table = $$;
					}else{
						printf("Class %s has already been declared.\n", $2);
						YYABORT;
					}
					curClass = NULL;
				};
cid 			: ID { 
					$$ = $1;
					curClass = $1;
				};

decList 		: varDeclare SEMI decList { 
					if(find_mbr($1->varname, $3) == NULL)
						$$ = add_member($1->type, $1->varname,$1->value,NULL, $3); 
					else{
						printf("Member name %s has already been used.\n", $1->varname);
						YYABORT;
					}
				}| funcDeclare SEMI decList { 
					if(find_mbr($1->fname, $3) == NULL)
						$$ = add_member(DT_FNC, $1->fname, NULL, $1->params, $3);
					else{
						printf("Member name %s has already been used.\n", $1->fname);
						YYABORT;
					} 
				}| { 
					$$ = NULL; 
				};

decParamList 	: dtype ID COMMA decParamList { 
					char *tvar = getFullVarName($2);
					if(find_sym(tvar, sym_table) != NULL){
						printf("Variable %s already declared in function %s.\n",$2, curFn);
						YYABORT;
					}else{
						$$ = add_param($1, tvar, $4); 
					}
				}
				| dtype ID {
					char *tvar = getFullVarName($2);
					if(find_sym(tvar, sym_table) != NULL){
						printf("Variable %s already declared in function %s.\n",$2, curFn);
						YYABORT;
					}else{ 
						$$ = add_param($1, tvar, NULL);
					} 
				};

stmt_list 	: stmt_list stmt SEMI 	{ all_ops = add_op("\n",all_ops); }
			| stmt SEMI 			{ }

stmt 		: ID ASSGN expr { 
				char *tvar = getFullVarName($1);
				struct sym_entry * tmpsym = find_sym(tvar, sym_table);
				if(tmpsym == NULL){
					printf("Variable %s not declared.\n",$1);
					YYABORT;
				}else{
					if(tmpsym->type != $3->type){
						printf("Type mismatch in variable assignment : %s",$1);
					}else{
						char * dst = (char*)malloc(100);
						strcpy(dst, "\tsw\t");
						strcat(dst, $3->holder);
						strcat(dst, ", ");
						strcat(dst, tvar);
						all_ops = add_op(dst, all_ops);
						freename($3->holder);
					}
				}
			}| ID OPEN_SQ expr CLOSE_SQ ASSGN expr { 

			}| expr {

			}| IF OPEN_ROUND cmp CLOSE_ROUND stmt { 
				char * dst = (char*)malloc(100);
				sprintf(dst, "tag_%d:",pop());
				all_ops = add_op(dst, all_ops);
				pop();
			}| IF OPEN_ROUND cmp CLOSE_ROUND OPEN_CURLY stmt_list 
				CLOSE_CURLY ELSE OPEN_CURLY stmt_list CLOSE_CURLY { 

			}| FOR OPEN_ROUND stmt SEMI cmp SEMI stmt CLOSE_ROUND stmt { 
				int tmpTag = pop();
				int tmpTag_ = pop();

				char * dst = (char*)malloc(100);
				sprintf(dst, "\tj\ttag_%d", tmpTag_);
				all_ops = add_op(dst, all_ops);

				sprintf(dst, "tag_%d:", tmpTag);
				all_ops = add_op(dst, all_ops);
			}| WHILE OPEN_ROUND cmp CLOSE_ROUND stmt { 
				int tmpTag = pop();
				int tmpTag_ = pop();

				char * dst = (char*)malloc(100);
				sprintf(dst, "\tj\ttag_%d", tmpTag_);
				all_ops = add_op(dst, all_ops);

				sprintf(dst, "tag_%d:", tmpTag);
				all_ops = add_op(dst, all_ops);

			}| OPEN_CURLY stmt_list CLOSE_CURLY { 

			}| varDeclare { 

			}| PRINT_STR ID{
				char * symname = getFullVarName($2);
				struct sym_entry *tmpsym = find_sym(symname, sym_table);
				if(tmpsym!=NULL){
					if(tmpsym->type == DT_STR){
						char * dst = (char *) malloc(100);
						sprintf(dst, "\tla\t$a0, %s\n\tli\t$v0, 4\n\tsyscall",symname);
						all_ops = add_op(dst, all_ops);
					}else{
						printf("Print string type-mismatch : %s\n",$2);
					}
				}else{
					printf("Variable %s not found.\n",$2);
				}
			}| PRINT_VAL ID{
				char * symname = getFullVarName($2);
				struct sym_entry *tmpsym = find_sym(symname, sym_table);
				if(tmpsym!=NULL){
					if(tmpsym->type == DT_NUM){
						char * dst = (char *) malloc(100);
						sprintf(dst, "\tlw\t$a0, %s\n\tli\t$v0, 1\n\tsyscall",symname);
						all_ops = add_op(dst, all_ops);
					}else{
						printf("Print string type-mismatch : %s\n",$2);
					}
				}else{
					printf("Variable %s not found.\n",$2);
				}
			};

dtype 		: TYPE_INT 		{ $$ = DT_NUM; }
			| TYPE_FLOAT 	{ $$ = DT_FLT; }
			| TYPE_STRING 	{ $$ = DT_STR; };

cmp 	 	: expr relop expr 	{ 
				if($1->type!=$3->type){
					printf("type mismatch in comparison\n");
					YYABORT;
				}
				push();
				char * dst = (char*)malloc(100);
				sprintf(dst, "tag_%d:\t",read());
				if($2 == CMP_SE){
					strcat(dst, "ble\t");
				}else if($2 == CMP_SM){
					strcat(dst, "blt\t");
				}else if($2 == CMP_GE){
					strcat(dst, "bge\t");
				}else if($2 == CMP_GR){
					strcat(dst, "bgt\t");
				}else if($2 == CMP_EQ){
					strcat(dst, "beq\t");
				}else if($2 == CMP_NEQ){
					strcat(dst, "bne\t");
				}
				strcat(dst, $1->holder);
				strcat(dst, ", ");
				strcat(dst, $3->holder);

				push();
				char * tmpStr = (char*)malloc(100);
				sprintf(tmpStr, ", tag_%d",read());
				strcat(dst, tmpStr);
				all_ops = add_op(dst, all_ops);
			}
			| expr { 
				push();
				int tmpTag = read();
				push();
				char * dst = (char*)malloc(100);
				sprintf(dst, "tag_%d:\tbne\t%s, $zero, tag_%d",tmpTag, $1->holder, read());
				all_ops = add_op(dst, all_ops);
			};

relop  		: SMEQ 	{ $$ = CMP_SE; }
			| GREQ 	{ $$ = CMP_GE; }
			| GR 	{ $$ = CMP_GR; }
			| SM 	{ $$ = CMP_SM; }
			| EQ 	{ $$ = CMP_EQ; }
			| NEQ 	{ $$ = CMP_NEQ; };

expr		: expr PLUS term 	{
				$$ = $1; 

				char * dst = (char*)malloc(100);
				strcpy(dst, "\tadd\t");
				strcat(dst, $$->holder);
				strcat(dst, ", ");
				strcat(dst, $$->holder);
				strcat(dst, ", ");
				strcat(dst, $3->holder);
				all_ops = add_op(dst, all_ops);

				freename($3->holder);
			} 
			| expr MINUS term 	{ 
				$$ = $1;

				char * dst = (char*)malloc(100);
				strcpy(dst, "\tsub\t");
				strcat(dst, $$->holder);
				strcat(dst, ", ");
				strcat(dst, $$->holder);
				strcat(dst, ", ");
				strcat(dst, $3->holder);
				all_ops = add_op(dst, all_ops);
				
				freename($3->holder);
			} 
			| term 				{
				$$ = $1;
			}
			| VAL_STRING {
				$$ = create_ivar(DT_STR,newname(),NULL);
				
				char * dst = (char*)malloc(100);
				strcpy(dst, "\tla\t");
				strcat(dst, $$->holder);
				strcat(dst, ", ");
				strcat(dst, $1);
				all_ops = add_op(dst, all_ops);
			};

term		: term TIMES factor { 
				$$ = $1;

				char * dst = (char*)malloc(100);
				strcpy(dst, "\tmul\t");
				strcat(dst, $$->holder);
				strcat(dst, ", ");
				strcat(dst, $$->holder);
				strcat(dst, ", ");
				strcat(dst, $3->holder);
				all_ops = add_op(dst, all_ops);

				
				freename($3->holder);
			}
			| term DIV factor 	{ 
				$$ = $1;

				char * dst = (char*)malloc(100);
				strcpy(dst, "\tdiv\t");
				strcat(dst, $$->holder);
				strcat(dst, ", ");
				strcat(dst, $3->holder);
				all_ops = add_op(dst, all_ops);

				freename($3->holder);
			}
			| factor {
				$$ = $1;
			};

factor 		: VAL_INT {
				$$ = create_ivar(DT_NUM,newname(),NULL);

				char * dst = (char*)malloc(100);
				strcpy(dst, "\tli\t");
				strcat(dst, $$->holder);
				strcat(dst, ", ");
				strcat(dst, $1);
				all_ops = add_op(dst, all_ops);

			}
			| OPEN_ROUND expr CLOSE_ROUND {
				$$ = $2;
			}
			| ID { 
				char *tvar = getFullVarName($1);
				struct sym_entry* tmp = find_sym(tvar, sym_table);
				if(tmp!=NULL){
					$$ = create_ivar(tmp->type, newname(), NULL);

					char * dst = (char*)malloc(100);
					strcpy(dst, "\tlw\t");
					strcat(dst, $$->holder);
					strcat(dst, ", ");
					strcat(dst, tvar);
					all_ops = add_op(dst, all_ops);
				}else{
					printf("Variable %s not declared.\n",$1);
					YYABORT;
				}
			}
			| VAL_FLOAT {
				$$ = create_ivar(DT_FLT,newname(), NULL);
				
				char * dst = (char*)malloc(100);
				strcpy(dst, "\tli\t");
				strcat(dst, $$->holder);
				strcat(dst, ", ");
				strcat(dst, $1);
				all_ops = add_op(dst, all_ops);
			}
			// | NOT factor { 
			// 	// $$ = $2;
			// }
			| ID OPEN_ROUND CLOSE_ROUND	{
				char * fname = getFullFnName($1);
				struct fn_entry* tmp = find_fn(fname, fn_table);
				if(tmp == NULL){
					printf("Function %s not defined.\n",$1);
					YYABORT;
				}else{
					if(tmp->params!=NULL){
						printf("No arguments provided for function %s",$1);
						YYABORT;
					}else{
						char * dst = (char*)malloc(100);
						sprintf(dst, "\tjal\t%s",tmp->fname);
						all_ops = add_op(dst, all_ops);
					}
				}
			}
			| ID OPEN_ROUND paramList CLOSE_ROUND {
				char * fname = getFullFnName($1);
				struct fn_entry* tmp = find_fn(fname, fn_table);
				if(tmp == NULL){
					printf("Function %s not defined.\n",$1);
					YYABORT;
				}else{
					struct param* tmp_param = tmp->params;
					struct ivar * tmp_ivar = $3;
					while(tmp_param!=NULL && tmp_ivar!=NULL){
						if(tmp_param->type != tmp_ivar->type){
							printf("Parameters type mismatch in function %s.\n",$1);
							YYABORT;
						}
						char *dst = (char *)malloc(100);
						sprintf(dst, "\tsw\t%s, %s\n",tmp_ivar->holder,tmp_param->varname);
						all_ops = add_op(dst, all_ops);

						tmp_param = tmp_param->next;
						tmp_ivar = tmp_ivar->next;
					}
					if(tmp_param != NULL || tmp_ivar != NULL){
						printf("Parameter count mismatch in function %s.",$1);
						YYABORT;
					}else{
						char * dst = (char*)malloc(100);
						sprintf(dst, "\tjal\t%s",fname);
						all_ops = add_op(dst, all_ops);
					}
				}
			}
			| ID DOT ID OPEN_ROUND CLOSE_ROUND { 
				char * fname = (char*)malloc(100);
				sprintf(fname,"class_%s_%s",$1, $3);
				struct fn_entry * tmpf = find_fn(fname, fn_table);
				if(tmpf== NULL){
					printf("No member function %s found for class %s", $3, $1);
				}
			}|ID DOT ID OPEN_ROUND paramList CLOSE_ROUND {
				char * classBuf = curClass;
				curClass = $1;
				char * fname = getFullFnName($3);
				struct fn_entry* tmp = find_fn(fname, fn_table);
				if(tmp == NULL){
					printf("Function %s not defined.\n",$3);
					YYABORT;
				}else{
					struct param* tmp_param = tmp->params;
					struct ivar * tmp_ivar = $5;
					while(tmp_param!=NULL && tmp_ivar!=NULL){
						if(tmp_param->type != tmp_ivar->type){
							printf("Parameters type mismatch in function %s.\n",$3);
							YYABORT;
						}
						char *dst = (char *)malloc(100);
						sprintf(dst, "\tsw\t%s, %s\n",tmp_ivar->holder,tmp_param->varname);
						all_ops = add_op(dst, all_ops);

						tmp_param = tmp_param->next;
						tmp_ivar = tmp_ivar->next;
					}
					if(tmp_param != NULL || tmp_ivar != NULL){
						printf("Parameter count mismatch in function %s.",$3);
						YYABORT;
					}else{
						char * dst = (char*)malloc(100);
						sprintf(dst, "\tjal\t%s",fname);
						all_ops = add_op(dst, all_ops);
					}
				}
				curClass = classBuf;
			}|ID DOT ID {
				char * vname = (char *)malloc(100);
				sprintf(vname, "var_class_%s_%s", $1, $3);
				struct sym_entry* tvar = find_sym(vname, sym_table);
				if(tvar == NULL){
					printf("Variable %s not declared in class %s.\n",$3, $1);
					YYABORT;
				} else{
					$$ = create_ivar(tvar->type, newname(),NULL);
					char * dst = (char *)malloc(100);
					sprintf(dst, "\tlw\t%s, %s",$$->holder, tvar->varname);
					all_ops = add_op(dst, all_ops);
				}
			};

paramList 	: paramList COMMA param 	{ 
				$3->next = $1;
				$$ = $3;
			}
			| param 					{ 
				$$ = $1;
			};

param 		: expr 					{ $$ = $1; } 
			| ID ASSGN expr 		{ $$ = $3; }
			| exprList 				{ }
			| ID ASSGN exprList 	{ };

exprList 		: OPEN_SQ exprListItems CLOSE_SQ 	{ };
exprListItems	: expr COMMA exprListItems			{ }
				| expr 								{ }


%%

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