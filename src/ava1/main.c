#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

#define MEMORY_SIZE 8

// REMOVER INCREMENT_B

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


        int menuOp = -1;
        
        char instructorRegister[] = "0000";
        bool run_bit = true; //um bit que pode ser desligado para parar a m�quina

        // Registers
        int programCounter = 0;
        char registrador_A[] = "0000";
        char registrador_B[] = "0000";        

        // OP Code
        char ADD[] = "0001";
        char SUB[] = "0010";
        char AND[] = "0011";
        char OR[]  = "0100";
        char XOR[] = "0101";
        char INCREMENT_A[] = "0110";
        char CLEAR[] = "0111";
        char HALT[] = "1111";
        

        // Flags
        bool flag_transbordo = false;
        bool flag_negativo = false;
        bool flag_zero = false;      
		
      	//4 Bits Instructions
		
		//ADD Reg_A Reg_B
        char *M1[MEMORY_SIZE] = 
        {
            "0001",
            "0110",
            "0111",
            "0111",
            "1111",
            "0000",
            "1000",
            "0011",
        };	
		
  
        //SUB Reg_A Reg_B
        char *M2[MEMORY_SIZE] =
        {
            "0010",
            "0110",
            "0111",
            "0111",
            "1111",
            "0000",
            "1111",
            "1000"
        };

        //AND Reg_A Reg_B
        char *M3[8] =
        {
            "0011",
            "0110",
            "0111",
            "0111",
            "1111",
            "0000",
            "1001",
            "0011"
        };

        //OR Reg_A Reg_B
        char *M4[8] =
        {
            "0100",
            "0110",
            "0111",
            "0111",
            "1111",
            "0000",
            "1001",
            "0011"
        };

        //XOR Reg_A Reg_B
        char *M5[8] =
        {
            "0101",
            "0110",
            "0111",
            "0111",
            "1111",
            "0000",
            "1001",
            "0011"
        };

        //INCREMENT_A
        char *M6[8] =
        {
            "0110",
            "0110",
            "0111",
            "1111",
            "0000",
            "0000",
            "1111",
            "0000"
        };

        //INCREMENT_A CLEAR
        char *M7[MEMORY_SIZE] =
        {
            "0110",
            "0110",
            "0111",
            "0111",
            "1111",
            "0000",
            "1011",
            "0000"
        };        
        
        
      int M0[MEMORY_SIZE] = 
	  {
	  		0b0001,
            0b0010,
            0b0111,
            0b0111,
            0b1111,
            0b0000,
            0b1000,
            0b0011
	  };
		


	char *selectedMemorySetup[MEMORY_SIZE] = {0};
	
	/*
	void copy_array(char source_array[MEMORY_SIZE][250], char destinatin_array[MEMORY_SIZE][250]){
		int i;
   		 for(i=0;i<6;i++)
        strcpy(destinatin_array[i], source_array[i]);
	}*/
	
		
	
	
	//IR PRA LIB
	void print_binary(unsigned char value)
	{
		int bits_quantity = 3;
		int i;
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
		

//Utilizado para pegar a c�lula de mem�ria desejada
char GetMemoryCell(char memory[MEMORY_SIZE], int rowNumber)
{            
    return memory[rowNumber];
}		
		
		
		
/*
static void Programa()
        {
            PrintMemory(selectedMemorySetup, "INICIAL");
            PrintFlags("INICIAIS");
            PrintRegisters("INICIAIS");

            printf("%s","== EXECU��O ==\n");
            //Console.WriteLine();

            //INICIO CICLO
            while (run_bit)
            {
                instructorRegister = GetMemoryCell(selectedMemorySetup, programCounter);
                SelectOpCode(instructorRegister);
            }

            Console.WriteLine();
            Console.WriteLine("== FIM EXECU��O ==");
            Console.WriteLine();

            PrintMemory(selectedMemorySetup, "FINAL");
            PrintFlags("FINAIS");
            PrintRegisters("FINAIS");

            Console.WriteLine();
            Console.WriteLine("Aperte qualquer tecla para continuar");
            Console.ReadLine();
        }		
*/		



int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "Portuguese");
	
	
	print_binary_array(M0, MEMORY_SIZE);

	/*	
	int i;
		for (i = 0; i < MEMORY_SIZE; i++)
    {
 
  		print_binary(M0[i]);

    }
	*/

	int soma = M0[0] + 
	
	
	return 0;
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}
