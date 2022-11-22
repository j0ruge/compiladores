flex calculadora.l
bison -d -y calculadora.y
gcc -Wall -o calculadora y.tab.c lex.yy.c
calculadora.exe