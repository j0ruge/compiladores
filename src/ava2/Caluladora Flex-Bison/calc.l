%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
void yyerror(char* c);
#include "y.tab.h"
%}

%%

[0-9]+ {
	yylval = atoi(yytext); /* O que der match na expressão, converte para int, via atoi() e retorna o valor */
	return NUMBER; 
}

[0-9]+(\.[0-9]+) {
	yylval = atof(yytext); /* O que der match na expressão, converte para float, via atof() e retorna o valor */
	return NUMBER; 
}

[+] { return ADD;}

[[:space]]+ ;

[\n] { return EOL;}

. { yyerror("Token invalido\n"); }

%%

int yywrap(){
	return 1;
}
