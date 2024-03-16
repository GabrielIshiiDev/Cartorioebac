#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h>//biblioteca respons�vel por cuidar das strings

int registro() //Fun��o Respons�vel por cadastrar os usu�rios no sistema
{
	//In�cio cria��o de vari�veis/string/[] indica o String
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome [40];
	char cargo [40];
	//Final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o de CPF do Usu�rio
	scanf("%s", cpf); //"%s" armazena a informa��o na String
	
	strcpy(arquivo, cpf); //strcpy > Respons�vel por copiar os valores das Strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); // "w" = comando write; cria o arquivo e escreve
	fprintf(file,cpf); //salvo o valor da vari�vel; fprintf > salva a informa��o em file e n�o manda ao usu�rio
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //"a" > atualiza o arquivo
	fprintf(file,", ");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: "); //coletando informa��o de Nome do Usu�rio
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,", ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando informa��o de Sobrenome do Usu�rio
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,", ");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: "); //coletando informa��o de Cargo do Usu�rio
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
		
}

int consulta() //Fun��o Respons�vel por consultar os usu�rios no sistema
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem local PT-BR
	
	char cpf[40];
	char conteudo [200];
	
	printf("Digite o CPF a ser consultado: "); //Entrada de dados para a consulta
	scanf("%s",cpf);

	FILE *file;
	file = fopen(cpf,"r"); //"r" > ler o arquivo "read"
	
	if(file == NULL)
		{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!\n");
		}
		
		while(fgets(conteudo, 200, file) !=NULL)
		{
			printf("\nEssas s�o as informa��es do usu�rio:\n");
			printf("\nCPF,Nome,Sobrenome,Cargo:\n");
			printf("%s", conteudo);
			printf("\n\n");
		}
		
	system("pause");
	fclose(file);
}

int deletar() //Fun��o Respons�vel por deletar os usu�rios no sistema
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: "); //Entrada de dados para deletar um usu�rio
	scanf("%s",cpf);
	
	
	FILE *file;
	file = fopen(cpf,"r");
	fclose(file);
	
	if(file == NULL)
		{
			printf("Usu�rio n�o se encontra no sistema!.\n");
			system("pause");
		}	
		
	remove(cpf);
		
	if(file != NULL)
		{
			printf("Usu�rio deletado do sistema com sucesso!.\n");
			system("pause");	
		}
		
}

int main ()

{
	int opcao=0; //Definindo as vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		system("cls");
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem local PT-BR
	
		printf("*****Cart�rio da EBAC*****\n\n");//in�cio do Menu
		printf("Escolha a op��o desejada do menu:\n\n"); //\t equivale ao Tab
		printf("\t1 - Registrar Nomes\n");
		printf("\t2 - Consultar Nomes\n");
		printf("\t3 - Deletar Nomes\n\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Op��o: ");//Fim do menu
	
		scanf("%d", &opcao); // Armazenando a escolha do usu�rio; scanf possui como fun��o analisar os dados de entrada pelo usu�rio; "%d" = armazenar uma vari�vel do tipo inteiro;  
	
		system("cls"); //respons�vel por limpar a tela
		
		switch(opcao) //In�cio da sele��o do menu
		{
			case 1:
			registro(); //chamada de fun��es
			break;
			
			case 2:
			consulta(); //chamada de fun��es
			break;
			
			case 3:
			deletar(); ////chamada de fun��es
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema\n");
			return 0;
			break;
			
			default:
			printf("Essa op��o n�o est� dispon�vel\n");
			system("pause");
			break;
		}
	
	}
	
}
