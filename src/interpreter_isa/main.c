#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

//#define NUMBERBASE 2;

int program_counter; // contador de programa contém endere
int instruction; // um registrador para conter a instrução corrente
bool runbit = true;

int CLR = 0b1000;// <-- limpa o valor do accumulator.
int ADD = 0b0100;// <-- instrução soma A e B
int HALT = 0b1100;// <-- instrução que desliga o processador
//int operand_A;
//int operand_B;
//int operand_C;
int memoria[64] = {0};
 

//ADD Reg_A Reg_B
int M1[] = 
{
    0b0100,
    0b0110,
    0b0111,
    0b0111,
    0b1111,
    0b0000,
    0b0100,
    0b0011    
};


	

int main(int argc, char *argv[]) {	
	setlocale(LC_ALL, "Portuguese");
		
	program_counter = 0;
	 	
	load_memory("memory.bin");

	
	printf("Antes");
	DumpMemoria();

	while (runbit)
	{

		instruction = read_memory(program_counter);		
		
		switch (instruction)
		{
			
			case 0b0100: // ADD            
	            add();            
	            break;		
			case 0b1100: //HALT
	        	quit();
	        	break;
		}
		
		
		
		program_counter++;
	}
	
	printf("Depois");
	DumpMemoria();
	return 0;
};



void load_memory(char *file_name)
	{	
		printf("Gabiru!");
		int counter = 0;
		FILE *file;
		char *line; 
		
		file = fopen(file_name, "r");
		if(file_name == NULL){
			printf("File does not exist.");
		}
	
		while(fscanf(file,"%s",line) != EOF)
		{
			memoria[counter] = strtol(line, NULL, 2);
			counter++;
		}
	
		//fechar arquivo;
	};

	int read_memory(int address)
	{
		return memoria[address];
	};
	
	void set_memory(endereco,word)
	{
		memoria[endereco] = word;
	};

	void DumpMemoria()
	{
		for (int i = 0; i <=7; i++)
		{
			printf("%d",i); 
			printf(": ");
			
			for (int j = 0; j <= 7; j++)
			{
				//(não dar print line feed, só espaço)
				printf("%d", read_memory(j)) ; //convertendo string bits 
				printf(" ");
			}
		
			//print line feed 
			printf("\n");
		}
	};

	/*
	Exemplo do Dump
	0000: 11111111 11111111 11111111 11111111 11111111 11111111 11111111 11111111
	0008: 11111111 11111111 11111111 11111111 11111111 11111111 11111111 11111111
	*/
	quit()
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

