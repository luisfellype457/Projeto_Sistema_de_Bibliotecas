#ifndef ALUNOS_H
#define ALUNOS_H
#include <stdio.h>

//structs
typedef struct Aluno {
	char nome[100];
	char curso[50];
	char cpf[12];
}Aluno;

extern FILE *f;

void menu_alunos ();

void abrir_arquivo_alunos ();

void carregar_alunos ();

void cadastro ();

void exibir_aluno ();

void deletar_aluno ();

void atualizar_aluno ();

#endif
