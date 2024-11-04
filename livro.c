#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "livro.h"

void salvar_livros(const livro livros[], int quantidade) {
    FILE *arquivo = fopen("livros_cadastrados.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para salvar os livros.\n");
        return;
    }

    for (int i = 0; i < quantidade; i++) {
        fprintf(arquivo, "Livro %d:\n", i + 1);
        fprintf(arquivo, "  Nome: %s\n", livros[i].nome);
        fprintf(arquivo, "  Autor: %s\n", livros[i].autor);
        fprintf(arquivo, "  Gênero: %d\n", livros[i].genero);
        fprintf(arquivo, "  Volume: %d\n", livros[i].volume);
        fprintf(arquivo, "  Quantidade: %d\n", livros[i].qtd);
        fprintf(arquivo, "  Disponibilidade: %s\n\n", livros[i].disponibilidade ? "Disponível" : "Indisponível");
    }

    fclose(arquivo);
    printf("Lista de livros salva em 'livros_cadastrados.txt'.\n");
}

void cadastrar_livro(livro *l) {
    printf("Digite o nome do livro: ");
    fgets(l->nome, q, stdin);
    l->nome[strcspn(l->nome, "\n")] = 0;

    printf("Digite o nome do autor: ");
    fgets(l->autor, q, stdin);
    l->autor[strcspn(l->autor, "\n")] = 0;

    printf("Digite o gênero do livro ('1' - Exatas, '2' - Saúde, '3' - Humanas): ");
    scanf("%d", &l->genero);

    printf("Digite o volume do livro: ");
    scanf("%d", &l->volume);

    printf("Digite a quantidade de exemplares: ");
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
        printf("  Disponibilidade: %s\n\n", livros[i].disponibilidade ? "Disponível" : "Indisponível");
    }
}

void atualizar_livro(livro *l) {
    printf("Atualizando informações do livro:\n");

    printf("Novo nome (atual: %s): ", l->nome);
    fgets(l->nome, q, stdin);
    l->nome[strcspn(l->nome, "\n")] = 0;

    printf("Novo autor (atual: %s): ", l->autor);
    fgets(l->autor, q, stdin);
    l->autor[strcspn(l->autor, "\n")] = 0;

    printf("Novo gênero (atual: %d): ", l->genero);
    scanf("%d", &l->genero);

    printf("Novo volume (atual: %d): ", l->volume);
    scanf("%d", &l->volume);

    printf("Nova quantidade (atual: %d): ", l->qtd);
    scanf("%d", &l->qtd);

    printf("Livro atualizado com sucesso!\n");
}

void deletar_livro(livro livros[], int *quantidade, int index) {
    for (int i = index; i < (*quantidade) - 1; i++) {
        livros[i] = livros[i + 1];
    }
    (*quantidade)--;
    printf("Livro deletado com sucesso!\n");
}
