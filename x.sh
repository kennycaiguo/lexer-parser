bison --defines p.y
flex p.lex
gcc p.tab.c lex.yy.c
./a.out < samples/gx.x