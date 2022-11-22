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

/* Informa ao yacc que a precedencia dos operadores se dará pela esquerda ou direita */
%left ADD SUB
%left MUL DIV
%left NEG     /* negation--unary minus */


%%

input: /* empty */ 
    | input line EOL { $$ = $2; printf(" O valor obtido foi %lf\n", $2); }
	| input EOL { printf("\n"); }
    | error ';' /* On error, skip until ';' is read.  */
;

line: 
    '\n'
    | exp           { $$ = $1; }	                  
;

exp: 
    INTEGER                            { $$ = (int) $1; printf("Encontrei um INTEGER %d\n", (int) $1);}
    | FLOAT                            { $$ = $1; printf("Encontrei um FLOAT %f\n", $1); }
    | exp ADD exp                      { $$ = $1 + $3; }
    | exp SUB exp                      { $$ = $1 - $3; }
    | exp MUL exp                      { $$ = $1 * $3; }
    | exp DIV exp                      { $$ = $1 / $3; }
    | LEFT_BRACKET exp RIGHT_BRACKET   { $$ = $2;      }
    | '-' exp  %prec NEG               { $$ = -$2;     }  
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