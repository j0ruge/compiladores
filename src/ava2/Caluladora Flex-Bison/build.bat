bison -dy .\calc.y
flex .\calc.l
gcc -o gabirator .\y.tab.c .\lex.yy.c -lm
.\gabirator.exe