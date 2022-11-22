%{
    #define YYSTYPE double
    #include <math.h>
    #include <ctype.h>
    #include <stdio.h>
    int yylex (void);
    void yyerror (char const *);
%}

/* Bison declarations.  */
     
%token NUM
%left '-' '+'
%left '*' '/'
%left NEG     /* negation--unary minus */

%% /* Grammar rules and actions follow.  */

input:    /* empty */
        | input line
;

line:     '\n'
        | exp '\n'  { printf ("\t%.10g\n", $1); }
        | error '\n' { yyerrok;                 }
;

exp:      NUM                { $$ = $1;         }
        | exp '+' exp        { $$ = $1 + $3;    }
        | exp '-' exp        { $$ = $1 - $3;    }
        | exp '*' exp        { $$ = $1 * $3;    }
        | exp '/' exp        { $$ = $1 / $3;    }
        | '-' exp  %prec NEG { $$ = -$2;        }
        | '(' exp ')'        { $$ = $2;         }
;
%%
int yylex (void)
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
void yyerror (char const *s)
{
    fprintf (stderr, "%s\n", s);
}

int main (void)
{
    
	printf(" -================================================================- \n");
	printf("  |                                                              |  \n");
	printf("  |      Welcome to Bison Simple Calcutator                      |  \n");
	printf("  |      By ChewieSoft Inc.                                      |  \n");
	printf("  |      Copyright 2022 - Compiladores - AVA2                    |  \n");
	printf("  |      Powered by Prof. Miguel Angelo Zaccur de Figueiredo     |  \n");
	printf("  |                                                              |  \n");
	printf(" -================================================================- \n");
	printf("\n");
    printf("                   INSERT YOUR OPERATION BELOW\n");
    printf("\n");
    printf("Available operations: ADD ' + ', SUB ' - ', MUL ' * ' and DIV ' / '.\n");
	printf("-=-_-=-_-=-_-=-_-=-_-=-_-=-_-=-_-=-_-=-_-=-_-=-_-=-_-=-_-=-_-=-_-=-\n");
	printf("\n");
    printf("START HERE -->> "); 
   
    return yyparse ();
}