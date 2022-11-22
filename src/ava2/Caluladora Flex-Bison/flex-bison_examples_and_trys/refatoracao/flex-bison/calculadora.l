%{
#include <stdlib.h>
#include <stdio.h>
#include "y.tab.h"
void yyerror(char*);
%}

digit [0-9]
integer {digit}+
real ({digit}+[\.]{digit}*)|({digit}*[\.]{digit}+)

%%
[+] 	{ return ADD; }
[-] 	{ return SUB; }
[*] 	{ return MUL; }
[/] 	{ return DIV; }
[(]		{ return LEFT_BRACKET;}
[)]		{ return RIGHT_BRACKET;}


{integer} {    	
	sscanf(yytext, "%lf", (double*) &yylval);
	return INTEGER;
}
{real}  {	
	sscanf(yytext, "%lf", (double*) &yylval);	
	return FLOAT;
}

\n { return EOL; }
[ \t]+ ;

. 	{ yyerror("Invalid Token!\n"); }

%%

int yywrap()
{
	return 1;
}