bison -d --yacc .\calc.y
flex .\calc.l
gcc -o gabirator .\y.tab.c .\lex.yy.c -lm
echo Build Sucessfully done!