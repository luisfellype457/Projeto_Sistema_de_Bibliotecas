#ifndef ALUNOS_H
#define ALUNOS_H
#include <stdio.h>

//structs
typedef struct Aluno {
	char nome[100];
	char curso[50];
	char cpf[12];
	char senha[20];	
}Aluno;

extern FILE *f;

extern FILE *f;

void abrir_arquivo_alunos ();

void carregar_alunos ();

void cadastro ();

void exibir_aluno ();

void continuar ();

#endif
