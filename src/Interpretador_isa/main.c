#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

// Linguagem de entrada e sa�da estao corretas , ENTRADA E SAIDA EM BINARIO
// A da atividade dois e a sintaxe da um 
// organiza��o de c�digo
// compatibilidade 
// Linguagem e alfabeto e
// criar programa exemplo. 

int program_counter; // contador de programa cont�m endere�o da pr�xima instruction
int accumulator; // o acumulador, um registrador para efetuar aritm�tica
int instruction; // um registrador para conter a instru��o corrente
int instr_type; // o tipo da instru��o (opcode)
int data_loc; // o endere�o dos dados, ou �1 se nenhum
int data; // mant�m o operando corrente
bool run_bit = false; // um bit que pode ser desligado para parar a m�quina
int CLR = 0b1000;// <-- seta o valor no accumulator para 0
int ADDI = 0b1001;// <-- adiciona o valor x no accumulator
int ADDM = 0b1010;// <-- adiciona o valor da mem�ria y no accumulator
int HALT = 0b1100;// <-- instru��o que desliga o processador
int ADD = 0b0100;// <-- instru��o soma x e y 


int A_register = 0b0000;
int B_register = 0b0000;


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
	
	printf("\n;---------------ANTES---------------\n");
	print_binary_array(M1, 8);	
	int m2[] = { 0b0010, -5, 0b1111, CLR, // o "programa" inicia aqui
				ADDI, 12, ADDI, 7, ADDM, 0, ADDM, 1, CLR, HALT };
			printf("%s", "Imagem de mem�ria 1: \n");
			//interpreter(m2, 3);// start at CLR
			interpreter(M1, 0);// start at CLR
	
	

	printf("\n;---------------DEPOIS---------------\n");
	print_binary_array(M1, 8);	
	//add();
    
	return 0;
}



void interpreter(int memory[], int starting_address){
	
	 /**
	 * 	Esse procedimento interpreta programas para uma m�quina simples com instru��es que t�m
	 * 	um operando na mem�ria. A m�quina tem um registrador accumulator, usado para
	 * 	aritm�tica. A instru��o ADD soma um inteiro na mem�ria do accumulator, por exemplo.
	 * 	O interpretador continua funcionando at� o bit de funcionamento ser desligado pela instru��o HALT.
	 * 	O estado de um processo que roda nessa m�quina consiste em mem�ria, o
	 * 	contador de programa, bit de funcionamento e accumulator. Os par�metros de entrada consistem 
	 * 	na imagem da mem�ria e no endere�o inicial.
	 */
	program_counter = starting_address;
	run_bit = true;
	
	while (run_bit)
        {
            instruction = memory[program_counter]; // busca a pr�xima instru��o e armazena em instruction
            program_counter++; // incrementa contador de programa
            instr_type = get_instr_type(instruction); // determina tipo da instru��o
            data_loc = find_data(instruction, instr_type, memory); // localiza dados (�1 se nenhum)
            if (data_loc >= 0) // se data_loc � �1, n�o h� nenhum operando
            { data = memory[data_loc]; } // busca os dados
            execute(instr_type, data, memory); // executa instru��o
        }
}   


void select_opcode(int opcode)
{
	switch (opcode)
	{
		
		case 0b0100: // ADD
            //prinf("%s","ADD X + Y");
            program_counter++;
            //Add();
            program_counter++;
            break;		
		case 0b1100: //HALT
        	//printf("%s","HALT");
        	//Halt();
        	break;
	}	
}

void array_copy(int source_array[], int destination_array[]){	    
    int source_array_length = sizeof(source_array)/sizeof(source_array[0]);
    destination_array[source_array_length] = 0;
    for (int i = 0; i < source_array_length; i++) {     
        destination_array[i] = source_array[i];     
    }  
    
}

void add()
        {
			
            //Obter valor registrador A
            
            //int A_memory_address = get_memory_cell(selected_memory_setup, program_counter); 
            int A_memory_address = get_memory_cell(M1, program_counter); 
           // A_register = get_memory_cell(selected_memory_setup, A_memory_address);  
            A_register = get_memory_cell(M1, A_memory_address);  

            program_counter++;

            //Obter valor registrador B
            //int enderecoB = get_memory_cell(selected_memory_setup, programCounter); //Valor endereco em decimal
            int B_memory_address = get_memory_cell(M1, program_counter); //Valor endereco em decimal
           
           	
            //B_register = get_memory_cell(selected_memory_setup, B_memory_address);
           B_register = get_memory_cell(M1, B_memory_address);

            int result = A_register + B_register;
            

            //Atribuir valor ao ACC
           	A_register = result;
            

            program_counter++;

            //GUARDAR VALOR DO RESULTADO NA MEMORIA
            //int storage_address = get_memory_cell(selected_memory_setup, program_counter); //Valor endereco em decimal
            int storage_address = get_memory_cell(M1, program_counter); //Valor endereco em decimal
            set_memory_cell(M1, storage_address, A_register);
        }
        
//Utilizado para pegar a c�lula de mem�ria desejada
int get_memory_cell(int memory[], int row_number)
{            
    return memory[row_number];
}

//Utilizado para guardar valor a c�lula de mem�ria desejada
void set_memory_cell(int memory[], int row_number, int value)
{
    memory[row_number] = value;
}


int get_instr_type(int opcode){
return opcode;
}

	
int find_data(int opcode, int type, int memory[]){
        if (opcode == ADDI)
        {
            return program_counter;
        }
        if (opcode == ADDM)
        {
            return memory[program_counter];
        }
        if (opcode == ADD){
        	      	
        	return memory[program_counter];
		}
        else
            return -1;
}

void execute(int instr_type, int data, int memory[]){
    if (instr_type == CLR)
    {
        accumulator = 0;
        printf("%d", accumulator);
    }
    if (instr_type == ADDI)
    {
        accumulator = accumulator + data;
        printf("%d", accumulator);
    }
    if (instr_type == ADDM)
    {
        accumulator = accumulator + data;
        printf("%d", accumulator);
    }
    if (instr_type == ADD)
    {    	
    	program_counter++;
    	int x_value = memory[program_counter]; 
		int x_value = memory[program_counter]; 
        data =  data + x_value;        
        accumulator = accumulator + data;
        //Save em memoria temporariamente dentro de Execute
        memory[program_counter] = accumulator;
        printf("SOMA %d", accumulator);
    }
    
    if (instr_type == HALT)
    {
        run_bit = false;
    }
}




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

