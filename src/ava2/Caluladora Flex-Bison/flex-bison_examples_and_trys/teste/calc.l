%{
#undef yylex
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
