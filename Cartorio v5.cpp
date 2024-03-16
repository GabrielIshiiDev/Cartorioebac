#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h>//biblioteca responsável por cuidar das strings

int registro() //Função Responsável por cadastrar os usuários no sistema
{
	//Início criação de variáveis/string/[] indica o String
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome [40];
	char cargo [40];
	//Final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação de CPF do Usuário
	scanf("%s", cpf); //"%s" armazena a informação na String
	
	strcpy(arquivo, cpf); //strcpy > Responsável por copiar os valores das Strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); // "w" = comando write; cria o arquivo e escreve
	fprintf(file,cpf); //salvo o valor da variável; fprintf > salva a informação em file e não manda ao usuário
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //"a" > atualiza o arquivo
	fprintf(file,", ");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: "); //coletando informação de Nome do Usuário
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,", ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: "); //coletando informação de Sobrenome do Usuário
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,", ");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: "); //coletando informação de Cargo do Usuário
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
		
}

int consulta() //Função Responsável por consultar os usuários no sistema
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
		printf("Não foi possível abrir o arquivo, não localizado!\n");
		}
		
		while(fgets(conteudo, 200, file) !=NULL)
		{
			printf("\nEssas são as informações do usuário:\n");
			printf("\nCPF,Nome,Sobrenome,Cargo:\n");
			printf("%s", conteudo);
			printf("\n\n");
		}
		
	system("pause");
	fclose(file);
}

int deletar() //Função Responsável por deletar os usuários no sistema
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: "); //Entrada de dados para deletar um usuário
	scanf("%s",cpf);
	
	
	FILE *file;
	file = fopen(cpf,"r");
	fclose(file);
	
	if(file == NULL)
		{
			printf("Usuário não se encontra no sistema!.\n");
			system("pause");
		}	
		
	remove(cpf);
		
	if(file != NULL)
		{
			printf("Usuário deletado do sistema com sucesso!.\n");
			system("pause");	
		}
		
}

int main ()

{
	int opcao=0; //Definindo as variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		system("cls");
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem local PT-BR
	
		printf("*****Cartório da EBAC*****\n\n");//início do Menu
		printf("Escolha a opção desejada do menu:\n\n"); //\t equivale ao Tab
		printf("\t1 - Registrar Nomes\n");
		printf("\t2 - Consultar Nomes\n");
		printf("\t3 - Deletar Nomes\n\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Opção: ");//Fim do menu
	
		scanf("%d", &opcao); // Armazenando a escolha do usuário; scanf possui como função analisar os dados de entrada pelo usuário; "%d" = armazenar uma variável do tipo inteiro;  
	
		system("cls"); //responsável por limpar a tela
		
		switch(opcao) //Início da seleção do menu
		{
			case 1:
			registro(); //chamada de funções
			break;
			
			case 2:
			consulta(); //chamada de funções
			break;
			
			case 3:
			deletar(); ////chamada de funções
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema\n");
			return 0;
			break;
			
			default:
			printf("Essa opção não está disponível\n");
			system("pause");
			break;
		}
	
	}
	
}
