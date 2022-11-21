%{
    #define YYSTYPE double
    #include <math.h>
    #include <ctype.h>
    #include <stdio.h>
    int yylex (void);
    void yyerror (char const *);
%}
/* 
 Reverse polish notation calculator. 
 https://www.cin.ufpe.br/~frsn/arquivos/GnuWin32/doc/bison/2.4.1/bison-2.4.1/bison.html#RPN-Calc
*/

/* Bison declarations.  */
     
%token NUM
     
%% /* Grammar rules and actions follow.  */

input:    /* empty */
             | input line
;
     
line:     '\n'
        | exp '\n'      { printf ("\t%.10g\n", $1); }
;
     
exp:      NUM           { $$ = $1;           }
        | exp exp '+'   { $$ = $1 + $2;      }
        | exp exp '-'   { $$ = $1 - $2;      }
        | exp exp '*'   { $$ = $1 * $2;      }
        | exp exp '/'   { $$ = $1 / $2;      }
        /* Exponentiation */
        | exp exp '^'   { $$ = pow ($1, $2); }
        /* Unary minus    */
        | exp 'n'       { $$ = -$1;          }
;
%%

/* The lexical analyzer returns a double floating point
number on the stack and the token NUM, or the numeric code
of the character read if not a number.  It skips all blanks
and tabs, and returns 0 for end-of-input.  */

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

/* Called by yyparse on error.  */
void
yyerror (char const *s)
{
    fprintf (stderr, "%s\n", s);
}

int
main (void)
{
    return yyparse ();
}