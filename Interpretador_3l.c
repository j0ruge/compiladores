main()
{
	pc = 0
	runbit = true
	int memoria[64]
    inicializarmemoria()
	
	CarregaMemoria(nomearquivo.bin)

	conteudo do arquivo:
	11111111
	11111111
	11111111
	11111111
	11111111
	11111111
	11111111


	print("Antes")
	DumpMemoria()

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
	print("Depois")
	DumpMemoria()
}




CarregarMemoria(nome arquivo)
{

	int contador = 0
	abre arquivo leitura (nome arquivo)

	while not eof
	{
		linha = fscanf (arquivo)
		memoria[contador] = valorconvertido(linha)
		contador++
	}

	fechar arquivo
}

LerMemoria(endereco)
{
	return memoria[endereco];
}

SalvarMemoria(endereco,word)
{
	memoria[endereco] = word;
}

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
}

Exemplo do Dump
0000: 11111111 11111111 11111111 11111111 11111111 11111111 11111111 11111111
0008: 11111111 11111111 11111111 11111111 11111111 11111111 11111111 11111111

quit()
{
	runbit = false
}

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
}

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
}