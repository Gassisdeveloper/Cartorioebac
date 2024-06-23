#include <stdio.h>//biblioteca de comunicação com o usuario
#include <stdlib.h>// biblioteca de alocação de espaço em memoria 
#include <locale.h>//biblioteca de alocações de texto por região
#include <string.h>//bibliote resposavel por cudar das string


int registro(){
	
	char arquivo[40];
	char cpf[20];
	char nome[40];
    char sobrenome[40];
	char cargo[40];	
	int x = 1;
	
	while(x == 1) // sempre que a variavel x for um ele voltara a registar nomes, sendo o responsavel por nao precisar voltar ao menu inicial.
	{
	
	printf("digite o cpf a ser cadastrado: ");
	scanf("%s", &cpf);
	
	strcpy(arquivo, cpf);//responsavel por copiar os valores das strings
	
	FILE* file; // cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo
	fprintf(file,cpf);//salva o arquivo
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, "\n");
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,"NOME:");
	fclose(file);
	
	printf("digite o nome a ser cadastrado: ");
	scanf("%s",&nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, "\n");
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,"SOBRENOME:" );
	fclose(file);
	
	printf("digite o sobrenome a ser cadastrado: ");
	scanf("%s", &sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, "\n");
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,"CARGO:");
	fclose(file);
	
	printf("digite o cargo a ser cadastrado: ");
	scanf("%s",&cargo);
	
	file= fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	printf("Deseja registrar outro usuario?\n");
	printf("tecle (1) para continuar registrando.\n");
	printf("tecle (2) para voltar ao menu inicial.\n");
	scanf("%d", &x);
	
	system("cls");
   }
	
	
}
int consulta()
{
	
	 char cpf [20];
	 char conteudo [200];
	 int x = 0, y = 1;
	 
	 setlocale(LC_ALL, "portuguese");
     while(y == 1)
	 {
	 
     printf("Digite o CPF a ser consultado: ");
     scanf("%s", &cpf);
    
     FILE * file;
     file = fopen(cpf, "r");
   
     if(file == NULL)
     {
     	printf("Não foi possivel localizar o arquivo!.");
	 }
     
     if(fgets(conteudo,200,file) != NULL) // vai acessar a pasta com o contudo do cpf, e se for diferente de nulo ira trazer as informações
	 {
	 printf("Localizamos essas informações.\n");
	 for(x=1;x<=4;x++)
	 {	
	 while(fgets(conteudo,200,file) != NULL)
     { 	  		 	 
	 printf("%s",conteudo);     	
	 }
    
	 }
     }
     printf("\nDeseja consultar outro cadastro?\n");
	 printf("tecle (1) para continuar consultando.\n");
	 printf("tecle (2) para voltar ao menu inicial.\n");
	 scanf("%d", &y);
	 system("cls");
	 }
	 
	 }

int deleta()
{
	
	char cpf [20];
	int confirma = 0;
	int x = 1;
	setlocale(LC_ALL, "portuguese");
	
	while(x ==1)
	{	
	printf("Digite o CPF a ser deletado:");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL ){
		printf("o aquivo nao existe.");
		printf("\n");
		fclose(file);
	}
	else 
	{
		
	fclose(file);
	printf("tem certeza que deseja deletar o cpf:%s ?",cpf);
	printf("\n");
	printf("tecle (1), para confirmar ou tecle (2), para cancelar a operação.");
    printf("\n");
	scanf("%d",&confirma);
    printf("\n");
	
	if(confirma == 1)
	{
		remove(cpf);
		FILE *file;
		file = fopen(cpf, "r");
		fclose(file);
		printf("o arquivo foi deletado com sucesso");
		printf("\n");
		
	}
	else
	{
		printf("operação cancelada");
		printf("\n");
		
	}	
	
   }

    printf("\nDeseja deletar outro cadastro?\n");
	printf("tecle (1) para continuar deletando.\n");
	printf("tecle (2) para voltar ao menu inicial.\n");
	scanf("%d", &x);
	system("cls");

   } 
}

int main()
{ 
int opcao =0, x=1;

for(x=1;x=1;)
{
system("cls");
setlocale(LC_ALL, "portuguese");
printf("\n###Bem vindo ao cartório da EBAC###");
printf("\nescolha a opção deseja do menu:\n\n");
printf("\t1 - Registrar nomes\n");
printf("\t2 - Consultar nomes\n");
printf("\t3 - Deletar nomes\n");
printf("\t4 - Sair do sistema\n");
printf("opção:");
scanf("%d",&opcao);
system("cls");

switch(opcao)
 {
	
	case 1:
	registro();   
    break;
    case 2:
    consulta();
	break;
    case 3:
    deleta();
	break;
	case 4:
	printf("Obrigado por utilizar o sitema.");
	return 0; // Responsavel por fechar o sistema
	break;
    default:
    printf("voce escolheu uma opção invalida.\n");
    system("pause");   
    break;
       
 }

}

}
