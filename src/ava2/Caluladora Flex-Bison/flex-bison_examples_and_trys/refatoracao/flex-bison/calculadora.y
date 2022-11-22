%{
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define YYSTYPE double
int yylex(void); /* implementação obrigatória em arquivos y, informa ao yacc que a função oriunda do Lex, existe */
void yyerror(char*); /* implementação obrigatória em arquivos yacc*/
%}

/* Simbolos terminais */
%token FLOAT INTEGER
%token EOL
%token LEFT_BRACKET
%token RIGHT_BRACKET
%token UMINUS

/* Informa ao yacc que a precedencia dos operadores se dará pela esquerda ou direita */
%left ADD SUB
%left MUL DIV
%left NEG     /* negation--unary minus */

%start input

%%

input: /* empty */ 
    | input line    
	| input EOL { printf("\n"); }
    | error ';' /* On error, skip until ';' is read.  */
;

line: 
    '\n'
    | exp EOL { $$ = $2; printf(" O valor obtido foi %lf\n", $2); }
    | exp '\n'  { printf ("\t%.10g\n", $1); }
    | exp           { $$ = $1; }	                  
;

exp: 
    INTEGER                            { $$ = (int) $1; printf("Encontrei um INTEGER %d\n", (int) $1);}
    | FLOAT                            { $$ = $1; printf("Encontrei um FLOAT %f\n", $1); }
    | exp ADD exp                      { $$ = $1 + $3; printf("Resolvi a SOMA\n");}
    | exp SUB exp                      { $$ = $1 - $3; printf("Resolvi a SUBTRACAO\n"); }
    | exp MUL exp                      { $$ = $1 * $3; printf("Resolvi o PRODUTO\n");}
    | exp DIV exp                      { $$ = $1 / $3; printf("Resolvi a DIVISAO\n");}
    | LEFT_BRACKET exp RIGHT_BRACKET   { $$ = $2; }
    | '-' exp  %prec NEG               { $$ = -$2; printf("Inversao do sinal de %f\n", $2);}
;
%%
void yyerror(char *s)
{
	fprintf(stderr, ">> %s\n", s);
}
int main()
{
	yyparse();
	return 0;
}