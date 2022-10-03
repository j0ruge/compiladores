#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#include <string.h>
#include "instructions.h"
#include "memory.h"

#define MEMORYSIZE 64
#define ABORT 1
#define ONE_ARGUMENT 1
#define VARCHAR 100
#define FIRST_ARGUMENT 1

int instruction; // um registrador para conter a instrução corrente.
int program_counter; // contador de programa contém endereços de memória.

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
int INC = 	0b0110; // <-- Instrução para incremento de X (INCA - Increment).
int SLT =	0b0111; // <-- Instrução A menor que B? (SLT - Set on Less Than).
int HALT = 	0b1100; // <-- Instrução que desliga o processador.


void instruction_quit()
{
	runbit = false;
}


int main(int argc, char *argv[]) {	
	setlocale(LC_ALL, "pt_BR.UTF-8");
	
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
		
	char file_name_in[VARCHAR];
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
	
	memory_dump();

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
	        case 0b0110: // INC - Increment X           
	            instruction_inc();            
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
	memory_dump();
	return EXIT_SUCCESS;
}








