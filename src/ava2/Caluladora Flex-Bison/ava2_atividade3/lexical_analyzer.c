#include "lexical_analyzer.h"

/* The lexical analyzer returns a double floating point
number on the stack and the token NUMBER, or the numeric code
of the character read if not a number.  It skips all blanks
and tabs, and returns 0 for end-of-input.  */


int yylex (void)
{
    int character;

    /* Skip white space.  */
    while ((character = getchar ()) == ' ' || character == '\t')
        ;
    /* Process numbers.  */
    if (character == '.' || isdigit (character))
        {
        ungetc (character, stdin);
        scanf ("%lf", &yylval);
        return NUMBER;
        }
    /* Return end-of-input.  */
    if (character == EOF)
        return 0;
    /* Return a single char.  */
    return character;
}
