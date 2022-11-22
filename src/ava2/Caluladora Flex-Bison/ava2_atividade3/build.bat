bison -d --yacc .\analisador_sintatico.y
flex .\tokenizador.l
gcc -o gabirator .\y.tab.c .\lex.yy.c -lm
echo Build Sucessfully done!