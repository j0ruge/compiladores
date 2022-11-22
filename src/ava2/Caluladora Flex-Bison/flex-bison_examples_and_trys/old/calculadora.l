%%
%{
#include <stdlib.h>
#include <stdio.h>
#include "calculadora.tab.h"
extern YYSTYPE yylval;
void yyerror(char*);
%}

%%

 
[0 - 9]+	{
			yylval = atoi(yytext);
			return INTEIRO;
}

"+"			{
			return '+';
}

[ \t] *		{
			; /* ignora espaços e tabs (\t) */
}


"\n"		{
			return FIM_LINHA;
}