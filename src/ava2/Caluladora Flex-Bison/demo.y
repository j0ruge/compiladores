%{
#include <stdio.h>

void yyerror(char *c); /* implementação obrigatória em arquivos yacc*/
int yylex(void); /* implementação obrigatória em arquivos y, informa ao yacc que a função oriunda do Lex, existe */

%}
/* Simbolos terminais */
%token N OP EOL
%left OP /* Informa ao yacc que a precedencia dos operadores se dará pela esquerda */

%%

S:
	S E EOL {$$ = $2; printf("O valor obtido é %d\n", $2); }
	|
	;

E:
	N {$$ = $1; printf("Encontrei um numero %d\n", $1);}
	| E OP E {$$ = $1 + $3; printf("Resolvi %d + %d = %d\n", $1, $3, $$);}
	;


%%

void yyerror(char *c){
	printf("Erro: %s\n", c);
}

int main() {
	yyparse();
	return 0;
}