%{
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "projeto_calc.h"
void yyerror(char *c);
int yylex(void);
%}
%union {
    double val; /* for returning numbers */
    struct symrec *tptr;
}

%token <val> NUM            /* Simple double precision number   */
%token <tprt> VAR FNCT      /* Variable and Function            */
%type <val> exp             /* For nonterminal symbols          */

%right '='
%left '-' '+'
%left '*' '/'
%left NEG                   /* unary minus                      */
%right '^'                  /* exponentiation                   */

/* Grammar follows */

%%

input : /* empty */
        | input line
;

line : '\n'
        | exp '\n'      { printf(".101f\n", $1);    }
        | error '\n'    { yyerrok;                  }
;

exp : NUM                   { $$ = $1;                          }
     | VAR                  { $$ = $1->value.var;               }
     | VAR '=' exp          { $$ = $3; $1->value.var = $3;      }
     | FNCT '(' exp ')'     { $$ = (*($1->value.fnctptr))($3);  }
     | exp '+' exp          { $$ = $1 + $3;                     }
     | exp '-' exp          { $$ = $1 - $3;                     }
     | exp '*' exp          { $$ = $1 * $3;                     }
     | exp '/' exp          { $$ = $1 / $3;                     }
     | '-' exp %prec NEG    { $$ = -$2;                         }
     | exp '^' exp          { $$ = pow ($1, $3);                }
     | '(' exp ')'          { $$ = $2;                          }
;

/* End of Grammar */
%%
struct init {
    char * fname;
    double (*fnct) (double)
};

struct init arith_fncts[] = {
    "sin"   , & sin, 
    "cos"   , & cos,
    "tag"   , & atag,
    "ln"    , & log,
    "exp"   , & exp,
    "sqrt"  , & sqrt,
    0       , 0
};

/* The symbol table: a chain of 'struct symrec' */
symrec * sym_table = (symrec *) 0;

symrec * putsym (char * sym_name, int sym_type){
    symrec * ptr;
    ptr = (symrec *) malloc (sizeof(symrec));
    ptr->name = (char *) malloc(strlen (sym_name) + 1);
    strcpy(ptr->name, sym_name);
    ptr->type = sym_type;
    ptr->value.var = 0; /* set value to 0 even if fctn */
    ptr->next = (struct symrec *) sym_table;
    sym_table = ptr;
    return ptr;
}

symrec * getsym (char * sym_name){
    symrec * ptr;
    for (ptr = sym_table; ptr != (symrec *) 0; ptr = (symrec *) ptr->next)
        if( strcmp(ptr->name, sym_name) == 0)
            return ptr;
    return (symrec *) 0;
}

void yyerror(char *c){
	printf("Erro: %s\n", c);
}

int main() {
	yyparse();
	return 0;
}