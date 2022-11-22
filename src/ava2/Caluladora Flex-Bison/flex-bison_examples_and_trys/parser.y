% {
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define YYSTYPE double
    int yylex(void);
    void yyerror(char*);
%}

%%

%%
void yyerror(char* s)
{
    fprintf(stderr, ">> %s\n", s);
}
int main()
{
    yyparse();
    return 0;
}