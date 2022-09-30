#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
FILE *file_in, *file_out;

int main(int argc, char *argv[]) {
	char file_name_in[100];
	strcpy(file_name_in, argv[1]);
	strcat(file_name_in,".asm");
	
	char file_name_out[100];
	
	strcpy(file_name_out, argv[1]);
	strcat(file_name_out,".bin");
	
		
	char line[100]; 		
	file_in = fopen(file_name_in, "r");		
	if(file_in == NULL){
		printf("Assembly file does not exist.");
		exit(0);
	}
	
	
	file_out = fopen(file_name_out, "w");		
	if(file_out == NULL){
		printf("Output file does not exist.");
		exit(0);
	}		 	
	
			 
	while(fgets(line, 100, file_in) != NULL)
	{
		//char instruction[10];	
			
		char *instruction = strtok(line, " ");		
		printf("%s\n", instruction);
				
		if(strcmp(instruction, "ADD")==0) add();		
		else if(strcmp(instruction, "SUB")==0)
		{
			printf("DENTRO SUB\n");
		}		
		else if(strcmp(instruction, "HALT")==0)
		{
			printf("DENTRO HALT\n");
		}		
		else if(strcmp(instruction, "JMP")==0)
		{
			printf("DENTRO\n");
		}
		else {
			printf("Invalid instruction\n");
		};
		
		
		
		//char * first_parameter;
		//first_parameter = strtok(NULL, " "); 		
	//	printf("%s\n", first_parameter);
	}
	fclose(file_in);		
	fclose(file_out);
	
	return 0;
}



void write_out(char *binary_code, char *comment)
{
	fprintf(file_out, "%s %s\n", binary_code, comment);		
}


void add(){
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
	fprintf(file_out, " Endere�o do Resultado (ADD)\n");	
}


void file_print_binary(unsigned char value)
{
	int bits_quantity = 7;		
    for (int i = sizeof(char) * bits_quantity; i >= 0; i--)
        fprintf(file_out, "%d", (value & (1 << i)) >> i );	    
};

/*
void add_v2(){
	char * third_parameter;
	third_parameter = strtok(NULL, " "); 		
	int p3 = atoi(third_parameter);
	char * gabiru;
	decimal_to_binary(p3, &gabiru);
	
	
	write_out(gabiru, " Endere�o do Resultado (ADD)");
}

void decimal_to_binary(int n, char **p)
{
  int c, d, t;
  //char *p;

  t = 0;
  *p = (char*)malloc(32+1);

  if (*p == NULL)
    exit(EXIT_FAILURE);

  for (c = 31 ; c >= 0 ; c--)
  {
    d = n >> c;

    if (d & 1)
      *(*p+t) = 1 + '0';
    else
      *(*p+t) = 0 + '0';

    t++;
  }
  *(*p+t) = '\0';

  //return  p;
}

void print_binary(unsigned char value, char *temp_char){
	int result[10];
	for(int i=0; value >0;i++)    
	{    
		result[i]= value%2;    
		value=value/2;		    
	}
};





/*
void print_binary(unsigned char value, char *temp_char)
{
	char result[10];
	int bits_quantity = 7;		
    for (int i = sizeof(char) * bits_quantity; i >= 0; i--)
        strcat(result, (value & (1 << i)) >> i );
    strcpy(temp_char, result);
	return result;	    
};*/
