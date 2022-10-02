#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VARCHAR 100
#define FIRST_ARGUMENT 1

FILE *file_in, *file_out;

int main(int argc, char *argv[]) {
	char file_name_in[VARCHAR];
	strcpy(file_name_in, argv[FIRST_ARGUMENT]);
	strcat(file_name_in,".asm");
	
	char file_name_out[VARCHAR];	
	strcpy(file_name_out, argv[FIRST_ARGUMENT]);
	strcat(file_name_out,".bin");	
		
	char line[VARCHAR]; 		
	file_in = fopen(file_name_in, "r");		
	if(file_in == NULL){
		printf("Assembly file does not exist.");
		exit(EXIT_SUCCESS);
	}	
	
	file_out = fopen(file_name_out, "w");		
	if(file_out == NULL){
		printf("Output file does not exist.");
		exit(EXIT_SUCCESS);
	}	
			 
	while(fgets(line, VARCHAR, file_in) != NULL)
	{	
		char *instruction = strtok(line, " ");		
		if((strcmp(instruction, 	"AND")==0))	instruction_and();
		else if(strcmp(instruction, "OR")==0) 	instruction_or();
		else if(strcmp(instruction, "XOR")==0) 	instruction_xor();
		else if(strcmp(instruction, "ADD")==0) 	instruction_add_v2();		
		else if(strcmp(instruction, "SUB")==0)	instruction_sub();
		else if(strcmp(instruction, "INCA")==0) instruction_inca();
		else if(strcmp(instruction, "SLT")==0) 	instruction_slt();		
		else if(strcmp(instruction, "HALT")==0)	instruction_halt();	
		else printf("Invalid instruction\n");
	}
	fclose(file_in);		
	fclose(file_out);	
	return EXIT_SUCCESS;
}

void write_out(char *binary_code, char *comment)
{
	fprintf(file_out, "%s %s\n", binary_code, comment);		
}

void instruction_and(){
	write_out("00000000", "AND");
	
	char * first_parameter;
	first_parameter = strtok(NULL, " "); 		
	int p1 = atoi(first_parameter);
	file_print_binary(p1);
	fprintf(file_out, " Operador A (AND)\n");
	
	char * second_parameter;
	second_parameter = strtok(NULL, " "); 		
	int p2 = atoi(second_parameter);
	file_print_binary(p2);
	fprintf(file_out, " Operador B	(AND)\n");
		
	char * third_parameter;
	third_parameter = strtok(NULL, " "); 		
	int p3 = atoi(third_parameter);
	file_print_binary(p3);
	fprintf(file_out, " Endereço do Resultado (AND)\n");
}

void instruction_or(){
	write_out("00000001", "OR");
	
	char * first_parameter;
	first_parameter = strtok(NULL, " "); 		
	int p1 = atoi(first_parameter);
	file_print_binary(p1);
	fprintf(file_out, " Operador A (OR)\n");
	
	char * second_parameter;
	second_parameter = strtok(NULL, " "); 		
	int p2 = atoi(second_parameter);
	file_print_binary(p2);
	fprintf(file_out, " Operador B	(OR)\n");
		
	char * third_parameter;
	third_parameter = strtok(NULL, " "); 		
	int p3 = atoi(third_parameter);
	file_print_binary(p3);
	fprintf(file_out, " Endereço do Resultado (OR)\n");
}

void instruction_xor(){
	write_out("00000010", "XOR");
	
	char * first_parameter;
	first_parameter = strtok(NULL, " "); 		
	int p1 = atoi(first_parameter);
	file_print_binary(p1);
	fprintf(file_out, " Operador A (XOR)\n");
	
	char * second_parameter;
	second_parameter = strtok(NULL, " "); 		
	int p2 = atoi(second_parameter);
	file_print_binary(p2);
	fprintf(file_out, " Operador B	(XOR)\n");
		
	char * third_parameter;
	third_parameter = strtok(NULL, " "); 		
	int p3 = atoi(third_parameter);
	file_print_binary(p3);
	fprintf(file_out, " Endereço do Resultado (XOR)\n");
};

void instruction_add(){
	write_out("00000100", "ADD");	
	
	char * first_parameter;
	first_parameter = strtok(NULL, " "); 		
	int p1 = atoi(first_parameter);
	file_print_binary(p1);
	fprintf(file_out, " Operador A (ADD)\n");
	
	char * second_parameter;
	second_parameter = strtok(NULL, " "); 		
	int p2 = atoi(second_parameter);
	file_print_binary(p2);
	fprintf(file_out, " Operador B	(ADD)\n");
		
	char * third_parameter;
	third_parameter = strtok(NULL, " "); 		
	int p3 = atoi(third_parameter);
	file_print_binary(p3);
	fprintf(file_out, " Endereço do Resultado (ADD)\n");	
}

void file_print_binary(unsigned char value)
{
	int bits_quantity = 7;		
    for (int i = sizeof(char) * bits_quantity; i >= 0; i--)
        fprintf(file_out, "%d", (value & (1 << i)) >> i );	    
};


void instruction_sub(){
	write_out("00000101", "SUB");
	char * to_binary;
	
	int p1 = atoi(strtok(NULL, " "));
	int_to_binary(p1, &to_binary);	
	write_out(to_binary, "Operador A (SUB)");	
	
	int p2 = atoi(strtok(NULL, " "));
	int_to_binary(p2, &to_binary);	
	write_out(to_binary, "Operador B (SUB)");
	
	int p3 = atoi(strtok(NULL, " "));
	int_to_binary(p3, &to_binary);	
	write_out(to_binary, "Endereço do Resultado (SUB)");
}


void instruction_add_v2(){
	write_out("00000100", "ADD");
	char * to_binary;
	
	int p1 = atoi(strtok(NULL, " "));
	int_to_binary(p1, &to_binary);	
	write_out(to_binary, "Operador A (ADD)");	
	
	int p2 = atoi(strtok(NULL, " "));
	int_to_binary(p2, &to_binary);	
	write_out(to_binary, "Operador B (ADD)");
	
	int p3 = atoi(strtok(NULL, " "));
	int_to_binary(p3, &to_binary);	
	write_out(to_binary, "Endereço do Resultado (ADD)");
}


void instruction_inca(){
	write_out("00000110", "INCA");	
	char * to_binary;		
	int p1 = atoi(strtok(NULL, " "));
	int_to_binary(p1, &to_binary);	
	write_out(to_binary, "Operador A (INCA) | Endereço do Resultado (INCA)");
} 

void instruction_slt(){
	write_out("00000111", "SLT");
	char * to_binary;
	
	int p1 = atoi(strtok(NULL, " "));
	int_to_binary(p1, &to_binary);	
	write_out(to_binary, "Operador A (SLT)");
	
	int p2 = atoi(strtok(NULL, " "));
	int_to_binary(p2, &to_binary);	
	write_out(to_binary, "Operador B (SLT)");
	
	int p3 = atoi(strtok(NULL, " "));
	int_to_binary(p3, &to_binary);	
	write_out(to_binary, "Endereço do Resultado (SLT)");
}

void instruction_halt(){
	write_out("00001100", "HALT");
}

void int_to_binary(int value_to_convert, char **binary_string_output)
{
  int bit_position_counter, extracted_single_bit, output_bit_position;  

  output_bit_position = 0;
  *binary_string_output = (char*)malloc(32+1);

  if (*binary_string_output == NULL) exit(EXIT_FAILURE);

  for (bit_position_counter = 7 ; bit_position_counter >= 0 ; bit_position_counter--)
  {
	    extracted_single_bit = value_to_convert >> bit_position_counter;	
	    if 	  (extracted_single_bit & 1) *(*binary_string_output + output_bit_position) = 1 + '0';
	    else *(*binary_string_output + output_bit_position) = 0 + '0';
	    output_bit_position++;
  }
  *(*binary_string_output + output_bit_position) = '\0';  
}