%{
#define YYSTYPE double // Resolver erro que ao habilitar essa linha MUL e DIV param de funcionar
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
void yyerror(char *c); /* implementação obrigatória em arquivos yacc*/
int yylex(void); /* implementação obrigatória em arquivos y, informa ao yacc que a função oriunda do Lex, existe */
FILE* input_file;
%}

/* Simbolos terminais */

%token NUM
%token FLOAT
%token EOL
%token LEFT_BRACKET
%token RIGHT_BRACKET
/* Informa ao yacc que a precedencia dos operadores se dará pela esquerda ou direita */
%left ADD 
%left SUB
%left MUL
%left DIV

%%

SENTENCE:
	SENTENCE EXP EOL {$$ = $2; printf("O valor obtido foi %d\n", $2); }
	| SENTENCE EOL {printf("\n");}			
	| error ';' /* On error, skip until ';' is read.  */	 
	|
	;

EXP:
	NUM 								{$$ = $1; printf("Encontrei um numero %d\n", $1);}	
	| EXP ADD EXP 						{$$ = $1 + $3; printf("Resolvi %d + %d = %d\n", $1, $3, $$);}
	| EXP SUB EXP 						{$$ = $1 - $3; printf("Resolvi %d - %d = %d\n", $1, $3, $$);}
	| EXP MUL EXP 						{$$ = $1 * $3; printf("Resolvi %d * %d = %d\n", $1, $3, $$);}
	| EXP DIV EXP 						{$$ = $1 / $3; printf("Resolvi %d / %d = %d\n", $1, $3, $$);}
	| LEFT_BRACKET EXP RIGHT_BRACKET	{$$ = $2;}
	| SUB EXP							{$$ = -$2; printf("Inversao do sinal de %d\n", $2);}
	;
%%

void yyerror(char *c){
	printf("Erro: %s\n", c);
}

int
yylex (void)
{
    int c;

    /* Skip white space.  */
    while ((c = getchar ()) == ' ' || c == '\t')
        ;
    /* Process numbers.  */
    if (c == '.' || isdigit (c))
        {
        ungetc (c, stdin);
        scanf ("%lf", &yylval);
        return NUM;
        }
    /* Return end-of-input.  */
    if (c == EOF)
        return 0;
    /* Return a single char.  */
    return c;
}


/* Entry point */
int main(int argc, char **argv) {	

	printf("Insira seu calculo: ");
	
	yyparse();
	return 0;
}