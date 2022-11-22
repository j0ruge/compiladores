bison -d --yacc .\demo.y
flex .\demo.l
gcc -o demo .\y.tab.c .\lex.yy.c -lm
.\demo.exe