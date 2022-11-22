%{
    #define YYSTYPE double    
    #include <stdio.h>    
    #include <math.h>    
    #include <ctype.h>
    #include <stdio.h>
    int yylex (void);
    void yyerror (char const *);
%}
/* Bison declarations.  */
%token NUM
%left ADD

%% /* Grammar rules and actions follow.  */
input:    /* empty */
        | input line
;

line:     '\n'
        | exp '\n'  { printf ("\t%.10g\n", $1); }
        | error '\n' { yyerrok;                 }
;

exp:      NUM             { $$ = $1;         }
        | exp ADD exp        { $$ = $1 + $3;    }

;
%%


/* Called by yyparse on error.  */
void yyerror (char const *s)
{
    fprintf (stderr, "%s\n", s);
}


int main (void)
{
    return yyparse ();
}