%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define YYSTYPE double
void yyerror(char *c); /* implementação obrigatória em arquivos yacc*/
int yylex(void); /* implementação obrigatória em arquivos y, informa ao yacc que a função oriunda do Lex, existe */
%}

/* Simbolos terminais */

%token NUMBER
%token FLOAT
%token EOL
/* Informa ao yacc que a precedencia dos operadores se dará pela esquerda ou direita */
%left ADD 
%left SUB
%left MUL
%left DIV
%right '='

%%

SENTENCE:
	SENTENCE EXP EOL {$$ = $2; printf("O valor obtido foi %d\n", $2); }
	| SENTENCE EOL {printf("\n");}	
	|
	;

EXP:
	NUMBER {$$ = $1; printf("Encontrei um numero %d\n", $1);}
	| FLOAT {$$ = $1; printf("Encontrei um numero %f\n", $1);}
	| EXP ADD EXP {$$ = $1 + $3; printf("Resolvi %d + %d = %d\n", $1, $3, $$);}
	| EXP SUB EXP {$$ = $1 - $3; printf("Resolvi %d - %d = %d\n", $1, $3, $$);}
	| EXP MUL EXP {$$ = $1 * $3; printf("Resolvi %d * %d = %d\n", $1, $3, $$);}
	| EXP DIV EXP {$$ = $1 / $3; printf("Resolvi %d / %d = %d\n", $1, $3, $$);}
	;
%%

void yyerror(char *c){
	printf("Erro: %s\n", c);
}

int main() {	
	yyparse();
	return 0;
}