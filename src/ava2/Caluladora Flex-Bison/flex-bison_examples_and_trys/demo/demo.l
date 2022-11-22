%{
#include <stdlib.h>
void yyerror(char* c);

#include "y.tab.h"

%}

%%


[0-9]+ {
	yylval = atoi(yytext); /* O que der match na expressão, converte para int, via atoi() e retorna o valor */
	return N; 
}

\n { return EOL;}

[+] { return OP;}

[[:space]]+ ;

. { yyerror("Token inválido\n"); }

%%

int yywrap(){
	return 1;
}
