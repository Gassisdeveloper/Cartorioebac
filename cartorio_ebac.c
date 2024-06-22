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
	
	system ("pause");
	
	
	
	
	
	
}
int consulta()
{
	
	char cpf [20];
	char conteudo [200];
	int x = 0;
	setlocale(LC_ALL, "portuguese");

     printf("Digite o CPF a ser consultado: ");
     scanf("%s", &cpf);
     
     FILE * file;
     file = fopen(cpf, "r");
     
     if(file == NULL)
     {
     	printf("Não foi possivel localizar o arquivo!.");
	 }
     
    
	
    if(fgets(conteudo,200,file) != NULL){
	printf("Localizamos essas informações.\n");
	for(x=1;x<=4;x++)
	{
	
		
	 while(fgets(conteudo,200,file) != NULL)
     { 	  	
	 	 
		 printf("%s",conteudo);
     	
	 }
    
	}
}
		printf("\n");
		system("pause");


	}





 

int deleta(){
	
	char cpf [20];
	int confirma = 0;
	
	setlocale(LC_ALL, "portuguese");
	printf("Digite o CPF a ser deletado:");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL ){
		printf("o aquivo nao existe.");
		printf("\n");
		fclose(file);
	}
	else{
	fclose(file);
	printf("tem certeza que deseja deletar o cpf:%s ?",cpf);
	printf("\n");
	printf("tecle (1), para confirmar ou tecle (2), para cancelar a operação.");
    printf("\n");
	scanf("%d",&confirma);
    printf("\n");
	
	if(confirma == 1){
		remove(cpf);
		FILE *file;
		file = fopen(cpf, "r");
		printf("o arquivo foi deletado com sucesso");
		printf("\n");
		system("pause");
	}
	else{
		printf("operação cancelada");
		printf("\n");
		system("pause");
	}





	
}
	system("pause");
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

scanf("%d",&opcao);
system("cls");

switch(opcao){
	
	case 1:
	registro();   
    break;
    case 2:
    consulta();
	break;
    case 3:
    deleta();
	break;
    default:
    printf("voce escolheu uma opcao invalida");
    system("pause");


}





printf("\n\n\nesse software é de alta confidencialidade, criado por Gustavo Assis.");


}









system("pause");
return 0;



}
