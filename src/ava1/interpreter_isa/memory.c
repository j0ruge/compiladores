#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MEMORY_CELL_SIZE 8
#define MEMORYSIZE 64
#define GARBAGE_COLLECTOR 0
#define VARCHAR 100


int instruction; // um registrador para conter a instrução corrente.

int memoria[MEMORYSIZE] = {GARBAGE_COLLECTOR}; 


void load_memory(char *file_name)
{	
	int counter = 0;
	FILE *file;
	char line[VARCHAR];
	
	file = fopen(file_name, "r");	
	if(file == NULL){
		printf("Memory file does not exist.");
		exit(EXIT_SUCCESS);
	}		 
	while(fgets(line, 100, file) != NULL)
	{
		char *instruction = strtok(line, " ");				
		memoria[counter] = strtol(instruction, NULL, 2);		
		counter++;
	}
	fclose(file);		
}



int read_memory(int address)
{
	return memoria[address];
}
	
void set_memory(unsigned int address, unsigned int word)
{
	memoria[address] = word;
}

void memory_dump()
{	  		
	for (int i = 0; i <= (MEMORYSIZE/MEMORY_CELL_SIZE)-1; i++)		
	{
		int base_address = (i*MEMORY_CELL_SIZE);
		printf("%#010X", base_address); 
		printf(": ");		
		for (int j = 0; j <= 7; j++)
		{
			int address = base_address + j;
			print_binary(read_memory(address));
			printf(" ");
		}		
		printf("\n");
	}
}
	
