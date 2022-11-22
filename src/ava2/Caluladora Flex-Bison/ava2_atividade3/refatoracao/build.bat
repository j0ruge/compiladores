echo Deletando arquivos gerados na build anterior!
rm .\y.tab.c
rm .\lex.yy.c 
rm .\y.tab.h

echo Gerando novos!
flex calculadora.l
bison -d -y calculadora.y
gcc -Wall -o calculadora y.tab.c lex.yy.c
calculadora.exe