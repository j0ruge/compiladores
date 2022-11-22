%{
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define YYSTYPE double
int yylex(void);
void yyerror(char*);
%}

%token FLOAT INTEGER
%right OP_EQL
%token EOL
%token FUNC_L FUNC_R
%token T_IDEN
%left ADD SUB
%left MUL DIV
%left OP_POW


%%

input: /* empty */ 
    | input line EOL { printf("= %lf\n", $2); }
	| input EOL { printf("\n"); }	
;

line: '\n'
    | exp           { $$ = $1; }	
    | error '\n'    { yyerrok;                 }
;

exp: exp ADD term          { $$ = $1 + $3; }
    | exp SUB term          { $$ = $1 - $3; }
    | term  { $$ = $1; }
;

term: term MUL unary        { $$ = $1 * $3; }
    | term DIV unary        { $$ = $1 / $3; }
    | unary                 { $$ = $1; }
;

unary: SUB unary            { $$ = $2 * -1; }
    | pow                       { $$ = $1; }
;

pow: factor OP_POW pow           { $$ = pow($1,$3); }
    | factor                    { $$ = $1; }
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