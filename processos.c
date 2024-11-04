// gestao_livros.c
#include <stdio.h>
#include <string.h>
#include "processos.h"

#define Numero_Maximo_de_Livros 100

// Vari?veis globais (n?o static)
Cadastro catalogo[Numero_Maximo_de_Livros];
int totalLivros = 0;
int i;

void adicionarLivro(char *nome, char *categoria) {
    if (totalLivros < Numero_Maximo_de_Livros) {
        strncpy(catalogo[totalLivros].nome, nome, sizeof(catalogo[totalLivros].nome) - 1);
        strncpy(catalogo[totalLivros].categoria, categoria, sizeof(catalogo[totalLivros].categoria) - 1);
        catalogo[totalLivros].emprestado = 0;
        totalLivros++;
    } else {
        printf("Cat?logo cheio! N?o ? poss?vel adicionar mais livros.\n");
    }
}

int emprestarLivro(char *nome) {
    for (i = 0; i < totalLivros; i++) {
        if (strcmp(catalogo[i].nome, nome) == 0) {
            if (catalogo[i].emprestado == 0) {
                catalogo[i].emprestado = 1;
                printf("Livro '%s' emprestado com sucesso!\n", nome);
                return 1;
            } else {
                printf("Livro '%s' j? est? emprestado.\n", nome);
                return 0;
            }
        }
    }
    printf("Livro '%s' n?o encontrado no cat?logo.\n", nome);
    return -1;
}

int renovarLivro(char *nome) {
	int i;
    for ( i = 0; i < totalLivros; i++) {
        if (strcmp(catalogo[i].nome, nome) == 0) {
            if (catalogo[i].emprestado == 1) {
                printf("Empr?stimo do livro '%s' renovado com sucesso!\n", nome);
                return 1;
            } else {
                printf("O livro '%s' n?o est? emprestado e n?o pode ser renovado.\n", nome);
                return 0;
            }
        }
    }
    printf("Livro '%s' n?o encontrado no cat?logo.\n", nome);
    return -1;
}

int devolverLivro(char *nome) {
	int i;
    for (i = 0; i < totalLivros; i++) {
        if (strcmp(catalogo[i].nome, nome) == 0) {
            if (catalogo[i].emprestado == 1) {
                catalogo[i].emprestado = 0;
                printf("Livro '%s' devolvido com sucesso!\n", nome);
                return 1;
            } else {
                printf("O livro '%s' j? est? dispon?vel.\n", nome);
                return 0;
            }
        }
    }
    printf("Livro '%s' n?o encontrado no cat?logo.\n", nome);
    return -1;
}
