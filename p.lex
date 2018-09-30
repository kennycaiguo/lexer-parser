%option noyywrap

%{
	#include "p.tab.h"
%}


%%
\"[^\"]*\"	{yylval.word = strdup(yytext); return VAL_STRING;}
\'[^\']*\'	{yylval.word = strdup(yytext); return VAL_STRING;}
"," {return COMMA;}
"=" {return ASSGN;}
";" {return SEMI;}
"+" {return PLUS;}
"*" {return TIMES;}
"/" {return DIV;}
"." {return DOT;}
"!" {return NOT;}
"-" {return MINUS;}
"(" {return OPEN_ROUND;}
")" {return CLOSE_ROUND;}
"[" {return OPEN_SQ;}
"]" {return CLOSE_SQ;}
"{" {return OPEN_CURLY;}
"}" {return CLOSE_CURLY;}
"<=" {return SMEQ;}
">=" {return GREQ;}
"<"  {return SM;}
">"  {return GR;}
"==" {return EQ;}
"!=" {return NEQ;}
"for" {return FOR;}
"if" 	{return IF;}
"else"  {return ELSE;}
"while" {return WHILE;}
"int" 	{return TYPE_INT;}
"string" {return TYPE_STRING;}
"float" 	{return TYPE_FLOAT;}
"function" 	{return FUNCTION_IDF;} 
"class" 	{return CLASS_IDF;}
"print_str" 	{return PRINT_STR;}	
"print_val" 	{return PRINT_VAL;}
"#include com.h" {return HASH_INCLUDE;}
[0-9]+\.[0-9]+ 	{yylval.word = strdup(yytext); return VAL_FLOAT;}
[0-9]+			{yylval.word = strdup(yytext); return VAL_INT;}
[a-zA-Z][_a-zA-Z0-9]*			{yylval.word = strdup(yytext); return ID;}

%% 

void yyerror(char const *s){
	printf("%s\n",s);
	exit(1);
}
