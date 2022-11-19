#include <stdio.h>
#include <stdlib.h>

void print_binary(unsigned char value)
{
	int bits_quantity = 7;		
    for (int i = sizeof(char) * bits_quantity; i >= 0; i--)
        printf("%d", (value & (1 << i)) >> i );	    
}
