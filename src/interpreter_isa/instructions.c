#include <stdbool.h>
#include "memory.h"

#define YES 1
#define NO 0

int program_counter; // contador de programa contém endereços de memória.

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
	
void instruction_inc(){
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
