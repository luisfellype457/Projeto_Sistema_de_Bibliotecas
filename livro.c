// livro.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "livro.h"

void cadastrar_livro(livro *l) {
    printf("Digite o nome do livro: ");
    fgets(l->nome, q, stdin);
    l->nome[strcspn(l->nome, "\n")] = 0; // Remove o caractere de nova linha
    printf("Digite o nome do autor: ");
    fgets(l->autor, q, stdin);
    l->autor[strcspn(l->autor, "\n")] = 0; // Remove o caractere de nova linha
    printf("Vamos cadastrar agora o genero do livro, digite '1' - Exatas, '2' - Saude, '3' - humanas: ");
    scanf("%d", &l->genero);
    printf("Digite qual o volume do livro: ");
    scanf("%d", &l->volume);
    printf("Digite a quantidade de livros deste tipo: ");
    scanf("%d", &l->qtd);
    l->disponibilidade = 1;
    printf("Livro cadastrado com sucesso!\n");
}

void buscarLivroPorNome(livro livros[], int quantidade, const char *nomeProcurado) {
    int encontrado = 0;

    printf("Resultados da busca por '%s':\n", nomeProcurado);
    for (int i = 0; i < quantidade; i++) {
        if (strstr(livros[i].nome, nomeProcurado) != NULL) {
            printf("Nome: %s\n", livros[i].nome);
            printf("Autor: %s\n", livros[i].autor);
            printf("Gênero: %d\n", livros[i].genero);
            printf("Volume: %d\n", livros[i].volume);
            printf("Quantidade: %d\n", livros[i].qtd);
            printf("Disponibilidade: %s\n\n", livros[i].disponibilidade ? "Disponível" : "Indisponível");
            encontrado = 1;
        }
    }

    if (!encontrado) {
        printf("Nenhum livro encontrado com o nome '%s'.\n", nomeProcurado);
    }
}

void listar_livros(const livro livros[], int quantidade) {
    if (quantidade == 0) {
        printf("Nenhum livro cadastrado.\n");
        return;
    }

    printf("Lista de Livros:\n");
    for (int i = 0; i < quantidade; i++) {
        printf("Livro %d:\n", i + 1);
        printf("  Nome: %s\n", livros[i].nome);
        printf("  Autor: %s\n", livros[i].autor);
        printf("  Gênero: %d\n", livros[i].genero);
        printf("  Volume: %d\n", livros[i].volume);
        printf("  Quantidade: %d\n", livros[i].qtd);
        printf("  Disponibilidade: %s\n", livros[i].disponibilidade ? "Disponível" : "Indisponível");
        printf("\n");
    }
}
