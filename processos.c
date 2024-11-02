// gestao_livros.c
#include <stdio.h>
#include <string.h>
#include "gestao.h"

#define Numero_Maximo_de_Livros 100

// Variáveis globais (não static)
Cadastro catalogo[Numero_Maximo_de_Livros];
int totalLivros = 0;

void adicionarLivro(char *nome, char *categoria) {
    if (totalLivros < Numero_Maximo_de_Livros) {
        strncpy(catalogo[totalLivros].nome, nome, sizeof(catalogo[totalLivros].nome) - 1);
        strncpy(catalogo[totalLivros].categoria, categoria, sizeof(catalogo[totalLivros].categoria) - 1);
        catalogo[totalLivros].emprestado = 0;
        totalLivros++;
    } else {
        printf("Catálogo cheio! Não é possível adicionar mais livros.\n");
    }
}

int emprestarLivro(char *nome) {
    for (int i = 0; i < totalLivros; i++) {
        if (strcmp(catalogo[i].nome, nome) == 0) {
            if (catalogo[i].emprestado == 0) {
                catalogo[i].emprestado = 1;
                printf("Livro '%s' emprestado com sucesso!\n", nome);
                return 1;
            } else {
                printf("Livro '%s' já está emprestado.\n", nome);
                return 0;
            }
        }
    }
    printf("Livro '%s' não encontrado no catálogo.\n", nome);
    return -1;
}

int renovarLivro(char *nome) {
    for (int i = 0; i < totalLivros; i++) {
        if (strcmp(catalogo[i].nome, nome) == 0) {
            if (catalogo[i].emprestado == 1) {
                printf("Empréstimo do livro '%s' renovado com sucesso!\n", nome);
                return 1;
            } else {
                printf("O livro '%s' não está emprestado e não pode ser renovado.\n", nome);
                return 0;
            }
        }
    }
    printf("Livro '%s' não encontrado no catálogo.\n", nome);
    return -1;
}

int devolverLivro(char *nome) {
    for (int i = 0; i < totalLivros; i++) {
        if (strcmp(catalogo[i].nome, nome) == 0) {
            if (catalogo[i].emprestado == 1) {
                catalogo[i].emprestado = 0;
                printf("Livro '%s' devolvido com sucesso!\n", nome);
                return 1;
            } else {
                printf("O livro '%s' já está disponível.\n", nome);
                return 0;
            }
        }
    }
    printf("Livro '%s' não encontrado no catálogo.\n", nome);
    return -1;
}

