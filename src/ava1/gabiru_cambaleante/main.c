#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int binary_array[2] = {
	0b000000000001,
	0b000000000010
};

// ::::::::::::: binary tools :::::::::::::
void print_binary(unsigned char value)
	{
		int bits_quantity = 7;		
	    for (int i = sizeof(char) * bits_quantity; i >= 0; i--)
	        printf("%d", (value & (1 << i)) >> i );
	    putc('\n', stdout);
	};

void print_binary_array(int *binary_array, int array_size){
			int i;
		for (i = 0; i < array_size; i++)
	    {	 
	  		print_binary(binary_array[i]);
	    }
	}
//=========================================

int main(int argc, char** argv) {
	
	print_binary_array(binary_array, 2);
	
	
	/*
		Cópia funcional de Array	
	*/	
	
	int array_length = sizeof(binary_array) / sizeof(binary_array[0]);	
	int test_array[array_length];	
	for (int i = 0; i < array_length; i++) {     
	        test_array[i] = binary_array[i];     
	}  	
	//========================================
	
	print_binary_array(test_array, array_length);
	
	int new_array[2] = {0};	
	
	
	return 0;
}
