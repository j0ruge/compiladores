%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "y.tab.h"
void yyerror(char* c);
%}

digit [0-9]
integer {digit}+
real ({digit}+[\.]{digit}*)|({digit}*[\.]{digit}+)
exp ({integer}|{real})[eE]-?{integer}

%%
[ \t]	; 
{integer}+ {
	yylval = atoi(yytext); /* O que der match na expressão, converte para int, via atoi() e retorna o valor */
	//sscanf(yytext, "%lf", &yylval);
	return NUMBER;
}
([0-9]+((\.|\,)[0-9]+)) {
	printf("TIPO FLOAT ");
	yylval = atof(yytext); /* O que der match na expressão, converte para float, via atof() e retorna o valor */
	return FLOAT; 
}
[+] 	{ return ADD;}
[-] 	{ return SUB;}
[*] 	{ return MUL;}
[/]		{ return DIV;}
[(]		{ return LEFT_BRACKET;}
[)]		{ return RIGHT_BRACKET;}
[\n] 	{ return EOL;}
. { yyerror("Token invalido\n"); }

%%

int yywrap(){
	return 1;
}
