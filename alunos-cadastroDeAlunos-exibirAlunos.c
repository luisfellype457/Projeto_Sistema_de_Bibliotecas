#include "alunos.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 1000 //alunos

Aluno cad[MAX];
int total_alunos = 0;
void continuar ();
void menu ();

void abrir_arquivo_alunos () {
	int i;
	f = fopen("Alunos.txt", "w");
	if (f== NULL) {
		printf("Erro na abertura!\n");
		exit(1);
	}
	for(i=0; i < total_alunos; i++) {
		fprintf(f, "%s\n%s\n%s\n%s\n", cad[i].nome, cad[i].curso, cad[i].cpf, cad[i].senha);
	}
    fclose(f);
}

void carregar_alunos () {
    f = fopen("Alunos.txt", "r");
    if (f == NULL) {
        printf("Ainda nao ha dados de alunos. Os dados serao caregados apos o primeiro cadastro.\n");
        return;
    }
		while (fscanf(f, " %[^\n] %[^\n] %[^\n] %[^\n]", cad[total_alunos].nome, cad[total_alunos].curso, cad[total_alunos].cpf, cad[total_alunos].senha) == 4) {
        total_alunos++;
    }
    fclose(f);
} 

void cadastro () {
	printf("Nome do aluno: \n");
	scanf("%[^\n]", cad[total_alunos].nome);
	fflush(stdin);
	printf("Curso do aluno: \n");
	scanf("%[^\n]", cad[total_alunos].curso);
	fflush(stdin);
	printf("CPF do aluno (apenas numeros): \n");
	scanf("%[^\n]", cad[total_alunos].cpf);
	fflush(stdin);
	printf("Digite a senha: \n");
	scanf("%[^\n]", cad[total_alunos].senha);
	fflush(stdin);
	printf("Aluno cadastrado com sucesso!\n");
	total_alunos++;
    abrir_arquivo_alunos();
    printf("\n");
	continuar ();
}

void exibir_aluno () {
	int op, j;
	char cpf[12];
	printf("Deseja exibir um unico aluno ou todos os alunos?\n");
	puts("(1) Buscar aluno.");
	printf("(2) Exibir todos.\n>");
	scanf("%d", &op);
	fflush(stdin);
	
	switch(op) {
		
		case (1):
			{
			int encontrado=0;
			printf("Digite o CPF do aluno que deseja buscar\n");
			scanf("%[^\n]", cpf);
			fflush(stdin);
			for(j=0; j < MAX; j++) {
				if(strcasecmp(cpf, cad[j].cpf) == 0) {
					encontrado=1;
					puts("Aluno ja cadastrado!");
					printf("Nome: %s\n", cad[j].nome);
					printf("Curso: %s\n", cad[j].curso);
					printf("CPF: %s\n", cad[j].cpf);
					printf("Senha: %s\n", cad[j].senha);
                    printf("\n");
					continuar ();
				} 
			}
			if (encontrado==0){
				printf("Aluno precisa ser cadastrado!\n\n");
				continuar ();
			}
			break;
		}	
		
		case (2):
			{
			for(j=0; j < total_alunos; j++) {
				printf("Aluno numero %d:\n", j+1);
				printf("Nome: %s\n", cad[j].nome);
				printf("Curso: %s\n", cad[j].curso);
				printf("CPF: %s\n", cad[j].cpf);
				printf("Senha: %s\n", cad[j].senha);
				printf("\n");
			}
			continuar ();
			break;
		}
	}	
}

void continuar () {
	int op;
	printf("Deseja voltar ao Menu ou Sair?\n");
	puts("(1) Menu.");
	printf("(2) Sair.\n>");
	scanf("%d", &op);

	switch(op) {
		case 1:
		{
			printf("--------------------------------------------------------------------------------\n\n");
			menu();
			break;
		}
		case 2:
		{
			exit(1);
			break;
		}
	}	
}
