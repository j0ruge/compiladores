#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	etlocale(LC_ALL, "Portuguese");
	
	
	int pc = 0;
	bool runbit = true;
	int memoria[64];
    inicializarmemoria();
	
	CarregaMemoria(nomearquivo.bin);

	/*
	conteudo do arquivo:
	11111111
	11111111
	11111111
	11111111
	11111111
	11111111
	11111111
	*/

	printf("Antes");
	DumpMemoria();

	while runbit
	{

		inst = lermemoria(pc)

		switch inst
		{

			case 1:
				add()
			case 2:
				sub()
			case 255:
				quit();
		}
		pc++

	}
	printf("Depois");
	DumpMemoria();
	return 0;
};




	CarregarMemoria(nome arquivo);
	{
	
		int contador = 0;
		abre arquivo leitura (nome arquivo);
	
		while not eof
		{
			linha = fscanf (arquivo)
			memoria[contador] = valorconvertido(linha)
			contador++
		}
	
		fechar arquivo;
	};

	LerMemoria(endereco)
	{
		return memoria[endereco];
	};
	
	SalvarMemoria(endereco,word)
	{
		memoria[endereco] = word;
	};

	DumpMemoria()
	{
		for i = 0 to 7
		{
			print i
			print ": "
			
			for j = 0 to 7
			{
				(não dar print line feed, só espaço)
				print lermemoria(j) convertendo string bits 
				print " "
			}
		
			print line feed printf("\n");
		}
	};

	/*
	Exemplo do Dump
	0000: 11111111 11111111 11111111 11111111 11111111 11111111 11111111 11111111
	0008: 11111111 11111111 11111111 11111111 11111111 11111111 11111111 11111111
	*/
	quit()
	{
		runbit = false
	};
	
	add()
	{
		pc++
		a = lermemoria(pc)
		pc++
		b = lermemoria(pc)
		pc++
		endc = lermemoria(pc)
	
		c = a + b
		salvarmemoria(pc,c)
		};
	
	sub()
	{
		pc++
		a = lermemoria(pc)
		pc++
		b = lermemoria(pc)
		pc++
		endc = lermemoria(pc)
	
		c = a - b
		salvamemoria(c)
		
		
		
	};

