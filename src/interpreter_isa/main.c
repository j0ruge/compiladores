#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

#define YES 1
#define NO 0
#define MEMORYSIZE 64
#define ABORT 1
#define ONE_ARGUMENT 1
#define GARBAGE_COLLECTOR 0
#define VARCHAR_100 100
#define FIRST_ARGUMENT 1
#define END 0

int program_counter; // contador de programa contém endereços de memória.
int instruction; // um registrador para conter a instrução corrente.
bool runbit = true;

/*
*
* NOTA: A ser implementada esta funcionalidade do CLR. 
* Nesta versão ainda não fazemos uso de FLAG REGISTERS nem do ACCUMULATOR
*
*/
int CLR = 	0b1000; // <-- limpa o valor do accumulator. 
int AND = 	0b0000; // <-- Instrução A AND B.
int OR = 	0b0001; // <-- Instrução A OR B.
int XOR =	0b0010; // <-- Instrução A XOR B.
int ADD = 	0b0100; // <-- Instrução soma A e B.
int SUB = 	0b0101; // <-- Instrução subtração A e B.
int INCA = 	0b0110; // <-- Instrução para incremento de A (INCA - Increment A).
int SLT =	0b0111; // <-- Instrução A menor que B? (SLT - Set on Less Than).
int HALT = 	0b1100; // <-- Instrução que desliga o processador.
int memoria[MEMORYSIZE] = {GARBAGE_COLLECTOR}; 

int main(int argc, char *argv[]) {	
	setlocale(LC_ALL, "Portuguese");
	
	printf(" -================================================================- \n");
	printf("  |                                                              |  \n");
	printf("  |      Welcome to Gabirunner 2.0 ®                             |  \n");
	printf("  |      By 3L ChewieSoft Inc. ™                                 |  \n");
	printf("  |      Copyright 2022 - Compiladores                           |  \n");
	printf("  |      Powered by Prof. Miguel Ângelo Zaccur de Figueiredo     |  \n");
	printf("  |                                                              |  \n");
	printf(" -================================================================- \n");
	printf("\n");
	
	if (argc==ONE_ARGUMENT){
		printf("Syntax: interpreter_isa [filename]\n");
		return ABORT;
	}	
	
	printf("                          BEFORE EXECUTION - MEMORY DUMP\n");
	printf("-=-_-=-_-=-_-=-_-=-_-=-_-=-_-=-_-=-_-=-_-=-_-=-_-=-_-=-_-=-_-=-_-=-_-=-_-=-_-=-_-=-\n");
	printf("\n");	
	char file_name_in[VARCHAR_100];
	strcpy(file_name_in, argv[FIRST_ARGUMENT]);
	strcat(file_name_in,".bin");
	printf("Running file %s\n", file_name_in);
	printf("\n");		
	program_counter = 0;	 	
		
	/*
	* Via Dev-C++, a configuração do nome de arquivo deve ser apontada via menu Execute -> Parameters... 
	* colocando como parametro a ser passado o nome do arquivo, no nosso caso, "memory" (sem as aspas).	
	*/
	load_memory(file_name_in); 
	
	
	DumpMemoria();

	while (runbit)
	{
		instruction = read_memory(program_counter);		
		switch (instruction)
		{				
			case 0b0000: // AND            
	            instruction_and();
	            break;
			case 0b0001: // OR            
	            instruction_or();
	            break;
			case 0b0010: // XOR            
	            instruction_xor();
	            break;
			case 0b0100: // ADD            
	            instruction_add();            
	            break;		
	        case 0b0101: // SUB            
	            instruction_sub();            
	            break;
	        case 0b0110: // INCA - Increment A           
	            instruction_inca();            
	            break;
			case 0b0111: // SLT - Set on Less Than (A < B?) 
				instruction_slt();
				break;
			case 0b1100: //HALT
	        	instruction_quit();
	        	break;
		}						
		program_counter++;
		if(program_counter >= MEMORYSIZE) runbit=false;		
	}
	
	printf("\n");
	printf("                          AFTER EXECUTION - MEMORY DUMP\n");
	printf("-=-_-=-_-=-_-=-_-=-_-=-_-=-_-=-_-=-_-=-_-=-_-=-_-=-_-=-_-=-_-=-_-=-_-=-_-=-_-=-_-=-\n");
	printf("\n");
	DumpMemoria();
	return END;
}


void load_memory(char *file_name)
{	
	int counter = 0;
	FILE *file;
	char line[VARCHAR_100]; 
	
	file = fopen(file_name, "r");
	
	
	if(file == NULL){
		printf("Memory file does not exist.");
		exit(END);
	}		 
	//while( fscanf(file,"%s",line) != EOF)
	while(fgets(line, 100, file) != NULL)
	{
		char *instruction = strtok(line, " ");				
		memoria[counter] = strtol(instruction, NULL, 2);
		//printf("%s %d\n", instruction, counter);
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
			int address = base_address + j;
			print_binary(read_memory(address));
			printf(" ");
		}		
		printf("\n");
	}
}
	
void print_binary(unsigned char value)
{
	int bits_quantity = 7;		
    for (int i = sizeof(char) * bits_quantity; i >= 0; i--)
        printf("%d", (value & (1 << i)) >> i );	    
}


void instruction_quit()
{
	runbit = false;
}
	
void instruction_add()
{
	program_counter++;
	int operand_A = read_memory(program_counter);
	program_counter++;
	int operand_B = read_memory(program_counter);
	program_counter++;
	int memory_address = read_memory(program_counter);

	int operand_C = operand_A + operand_B;
	set_memory(memory_address,operand_C);
}
	
void instruction_sub()
{
	program_counter++;
	int operand_A = read_memory(program_counter);
	program_counter++;
	int operand_B = read_memory(program_counter);
	program_counter++;
	int memory_address = read_memory(program_counter);

	int operand_C = operand_A - operand_B;
	set_memory(memory_address,operand_C);		
}
	
void instruction_inca(){
	program_counter++;
	int operand_A = read_memory(program_counter);
	operand_A++;
	int memory_address = program_counter;
	set_memory(memory_address,operand_A);
}
	
void instruction_slt(){
	program_counter++;
	int operand_A = read_memory(program_counter);
	program_counter++;
	int operand_B = read_memory(program_counter);
	program_counter++;
	int memory_address = read_memory(program_counter);

	int operand_C = operand_A - operand_B;
	if(operand_C <= 0){
		operand_C = YES;
	} else {
		operand_C = NO;
	}		
	set_memory(memory_address,operand_C);		
}


void instruction_and(){
	program_counter++;
	unsigned char operand_A = read_memory(program_counter);
	program_counter++;
	unsigned char operand_B = read_memory(program_counter);
	program_counter++;
	int memory_address = read_memory(program_counter);

	unsigned char operand_C = operand_A & operand_B;
	set_memory(memory_address,operand_C);	
}

void instruction_or(){
	program_counter++;
	unsigned char operand_A = read_memory(program_counter);
	program_counter++;
	unsigned char operand_B = read_memory(program_counter);
	program_counter++;
	int memory_address = read_memory(program_counter);

	unsigned char operand_C = operand_A | operand_B;
	set_memory(memory_address,operand_C);
}

void instruction_xor(){
	program_counter++;
	unsigned char operand_A = read_memory(program_counter);
	program_counter++;
	unsigned char operand_B = read_memory(program_counter);
	program_counter++;
	int memory_address = read_memory(program_counter);

	unsigned char operand_C = operand_A ^ operand_B;
	set_memory(memory_address,operand_C);
}

