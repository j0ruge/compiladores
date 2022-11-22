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
%token T_IDEN
%token LEFT_BRACKET
%token RIGHT_BRACKET

/* Informa ao yacc que a precedencia dos operadores se dará pela esquerda ou direita */
%left ADD SUB
%left MUL DIV
%left NEG     /* negation--unary minus */


%%

input: /* empty */ 
    | input line EOL { printf("= %lf\n", $2); }
	| input EOL { printf("\n"); }	
;

line: '\n'
    | exp           { $$ = $1; }	
    | error '\n'    { yyerrok;                 }
;

exp: exp ADD term                       { $$ = $1 + $3; }
    | exp SUB term                      { $$ = $1 - $3; }
    | LEFT_BRACKET exp RIGHT_BRACKET    { $$ = $2;      }
    | '-' exp  %prec NEG                { $$ = -$2;     } 
    | NEG exp                           { $$ = -$2;     } 
    | term  { $$ = $1; }
;

term: term MUL unary        { $$ = $1 * $3; }
    | term DIV unary        { $$ = $1 / $3; }
    | unary                 { $$ = $1; }
;

unary: SUB unary            { $$ = $2 * -1; }
    | pow                       { $$ = $1; }
;

factor: T_IDEN                                    { $$ = $1; }
    | INTEGER                                     { $$ = $1; }
    | FLOAT                                       { $$ = $1; }
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