# Lexer-parser
Bison, Lex/Flex

#### Files
required files - p.y, p.lex

generated files - p.tab.c, p.tab.h, lex.yy.c

#### Usage
bison --defines p.y (p.y is the parser file, produces p.tab.c and p.tab.h)

flex p.lex (p.lex is the lexer file, produces p.yy.c)


gcc p.tab.c lex.yy.c
