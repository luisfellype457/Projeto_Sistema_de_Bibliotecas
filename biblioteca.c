#include "biblioteca.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LIBRARIES 10

Biblioteca library[MAX_LIBRARIES];
int count = 0;

void criar_arquivo_biblioteca(){
	FILE *p;
	int i;
	p = fopen("Bibliotecas.txt", "w");
	if (p == NULL){
		printf("Nao foi possivel criar/acessar o arquivo!");
		exit(1);
	}
	for (i=0; i < count; i++){
		fprintf(p, "Nome: %s\nLocal: %s\nFuncionarios: %d\nAbertura: %s\nFechamento: %s\n\n", library[i].nome, library[i].local, library[i].num_funcionarios, library[i].hora_abertura, library[i].hora_fechamento);
	}
	fclose(p);
}

void ler_arquivo(){
	FILE *p;
	p = fopen("Bibliotecas.txt", "a+");
	if (p == NULL){
		printf("Nao foi possivel carregar o arquivo!");
		exit(1);
	}
	rewind(p);
	while(fscanf(p, "%19[^\n]\n %19[^\n]\n %d\n %4[^\n]\n %4[^\n]\n", library[count].nome, library[count].local, &library[count].num_funcionarios, library[count].hora_abertura, library[count].hora_fechamento) == 5){
		count++;
		if (count >= MAX_LIBRARIES)
			break;
		fscanf(p, "\n");
	}
	fclose(p);
}

void criar_biblioteca(){
	char confirm[3];
	ler_arquivo();
	do{
		printf("\nDigite o nome da biblioteca:\n> ");
		scanf("%19[^\n]", library[count].nome);
		fflush(stdin);
		printf("Digite o local da biblioteca:\n> ");
		scanf("%19[^\n]", library[count].local);
		fflush(stdin);
		printf("Digite o numero de funcionarios da biblioteca:\n> ");
		scanf("%d", &library[count].num_funcionarios);
		fflush(stdin);
		printf("Digite o horario de abertura (ex.: 07:00):\n> ");
		scanf("%5[^\n]", library[count].hora_abertura);
		fflush(stdin);
		printf("Digite o horario de fechamento (e.: 20:00):\n> ");
		scanf("%5[^\n]", library[count].hora_fechamento);
		fflush(stdin);
		printf("Biblioteca cadastrada! Deseja continuar cadastrando? (sim/nao)\n> ");
		scanf("%3[^\n]", confirm);
		fflush(stdin);
		count++;
	} while (!strcmp(confirm, "sim") || !strcmp(confirm, "s"));
	criar_arquivo_biblioteca();
}

void deletar_biblioteca() {
	int i, j, found = 0;
	char nome[20];
	ler_arquivo();
	printf("Digite o nome da biblioteca a ser excluída:\n> ");
	scanf("%19[^\n]", nome);
	for (i = 0; i < count; i++) {
		if (!strcmp(library[i].nome, nome)) {
			found = 1;
			break;
		}
	}
	if (!found) {
		printf("Biblioteca '%s' nao encontrada.\n", nome);
		return;
	}
	for (j = i; j < count - 1; j++) {
		library[j] = library[j + 1];
	}
	count--;
	criar_arquivo_biblioteca();
	printf("Biblioteca '%s' deletada com sucesso.\n", nome);
}
