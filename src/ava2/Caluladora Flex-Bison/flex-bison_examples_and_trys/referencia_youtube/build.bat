echo Deletando arquivos gerados na build anterior!
rm .\y.tab.c
rm .\lex.yy.c 
rm .\y.tab.h

echo Gerando novos!
flex projeto_calc.l
bison -d -y projeto_calc.y
gcc -Wall -o projeto_calc y.tab.c lex.yy.c
projeto_calc.exe