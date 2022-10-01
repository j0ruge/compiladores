#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>


static int MEMORYSIZE = 64;
int program_counter; // contador de programa contém endere
int instruction; // um registrador para conter a instrução corrente
bool runbit = true;

int CLR = 0b1000;// <-- limpa o valor do accumulator.
int ADD = 0b0100;// <-- instrução soma A e B.
int SUB = 0b0101;// <-- instrução subtração A e B.
int HALT = 0b1100;// <-- instrução que desliga o processador.
int memoria[64] = {0};
 

int main(int argc, char *argv[]) {	
	setlocale(LC_ALL, "Portuguese");
	
	printf("Gabiruner 2.0\n");
	printf("ChewieSoft inc.\n");
	printf("Copyright 2022 - Compiladores\n\n");
	
	char file_name_in[100];
	strcpy(file_name_in, argv[1]);
	strcat(file_name_in,".bin");
	printf("Running file %s\n\n", file_name_in);
		
	program_counter = 0;
	 	
	//load_memory("memory.bin");
	load_memory(file_name_in);
	
	printf("\nAntes\n");
	DumpMemoria();

	while (runbit)
	{

		instruction = read_memory(program_counter);		
		
		switch (instruction)
		{			
			case 0b0100: // ADD            
	            add();            
	            break;		
	        case 0b0101: // SUB            
	            sub();            
	            break;
			case 0b1100: //HALT
	        	quit();
	        	break;
		}
						
		program_counter++;
		if(program_counter >= MEMORYSIZE){
			runbit=false;
		}
	}
	
	printf("\nDepois\n");
	DumpMemoria();
	return 0;
};



void load_memory(char *file_name)
	{	
		int counter = 0;
		FILE *file;
		char line[100]; 
		
		file = fopen(file_name, "r");
		
		
		if(file == NULL){
			printf("Memory file does not exist.");
			exit(0);
		}		 
		//while( fscanf(file,"%s",line) != EOF)
		while(fgets(line, 100, file) != NULL)
		{
			char *instruction = strtok(line, " ");				
			memoria[counter] = strtol(instruction, NULL, 2);
			printf("%s %d\n", instruction, counter);
			counter++;
		}
		fclose(file);		
	};

	int read_memory(int address)
	{
		return memoria[address];
	};
	
	void set_memory(unsigned int address, unsigned int word)
	{
		memoria[address] = word;
	};

	void DumpMemoria()
	{
		char srt[7];		
		  		
		for (int i = 0; i <= (MEMORYSIZE/8)-1; i++)		
		{
			int base_address = (i*8);
			printf("%#010X", base_address); 
			printf(": ");
			
			for (int j = 0; j <= 7; j++)
			{
				//srt = int2bin(read_memory((i*8)+j), );
				//printf("%3d", read_memory((i*8)+j) ) ; //convertendo string bits 
				int address = base_address + j;
				print_binary(read_memory(address));
				printf(" ");
			}
		
			//print line feed 
			printf("\n");
		}
	};
	
	void print_binary(unsigned char value)
	{
		int bits_quantity = 7;		
	    for (int i = sizeof(char) * bits_quantity; i >= 0; i--)
	        printf("%d", (value & (1 << i)) >> i );	    
	};

	
	void quit()
	{
		runbit = false;
	};
	
	void add()
	{
		program_counter++;
		int operand_A = read_memory(program_counter);
		program_counter++;
		int operand_B = read_memory(program_counter);
		program_counter++;
		int memory_address = read_memory(program_counter);
	
		int operand_C = operand_A + operand_B;
		set_memory(memory_address,operand_C);
		};
	
	void sub()
	{
		program_counter++;
		int operand_A = read_memory(program_counter);
		program_counter++;
		int operand_B = read_memory(program_counter);
		program_counter++;
		int memory_address = read_memory(program_counter);
	
		int operand_C = operand_A - operand_B;
		set_memory(memory_address,operand_C);		
	};

