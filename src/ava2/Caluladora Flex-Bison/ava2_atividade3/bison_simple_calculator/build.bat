echo off
echo "Deletando arquivos gerados na build anterior!" 
del .\y.tab.c
del .\y.tab.h

echo "Gerando novos!"

bison -d --yacc bison_simple_calculator.y
gcc -Wall -o bison_simple_calculator y.tab.c -lm
bison_simple_calculator.exe