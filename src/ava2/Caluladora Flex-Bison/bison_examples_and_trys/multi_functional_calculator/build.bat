echo Deletando arquivos gerados na build anterior!
rm .\y.tab.c
rm .\lex.yy.c 
rm .\y.tab.h

echo Gerando novos!
REM flex projeto_calc.l
bison -d --yacc mfcalc.y
REM gcc -Wall -o projeto_calc y.tab.c lex.yy.c
gcc -Wall -o mfcalc y.tab.c -lm
mfcalc.exe