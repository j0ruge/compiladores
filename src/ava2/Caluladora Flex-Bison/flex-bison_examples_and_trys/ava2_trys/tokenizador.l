%{
#undef yylex
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "y.tab.h"
void yyerror(char* c);
%}

%%
[ \t]	; 
[0-9]			{return NUM; }
[+] 	        { return ADD;}

%%


int yywrap(){
	return 1;
}