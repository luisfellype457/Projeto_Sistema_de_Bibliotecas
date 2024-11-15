//computador.h
#ifndef COMPUTADOR_H
#define COMPUTADOR_H
#define MAX 30

typedef struct computador{
	int id;
	int situacao;
}Computador;

FILE *f;


void abrir_arquivo();
void carregar_arquivo();
void adicionar_computador();
void remover_computador();
void listar_computador();
void alugar_computador();
void devolver_computador();
void renovar_computador();
void menu_computadores();

#endif
