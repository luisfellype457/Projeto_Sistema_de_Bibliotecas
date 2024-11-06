#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "livro.h"

// Variável global do tipo FILE
FILE *arquivoLivros = NULL;

// Função para abrir o arquivo de livros
void abrir_arquivo() {
    if (arquivoLivros == NULL) {
        arquivoLivros = fopen("livros_criados.txt", "a+"); // abre o arquivo para leitura e escrita
        if (arquivoLivros == NULL) {
            printf("Erro ao abrir o arquivo!\n");
            exit(1); // Fecha o programa em caso de erro ao abrir o arquivo
        }
    }
}

// Função para fechar o arquivo
void fechar_arquivo() {
    if (arquivoLivros != NULL) {
        fclose(arquivoLivros);
        arquivoLivros = NULL; // Garante que a variável global seja nula após o fechamento
    }
}

void salvar_livros(const livro livros[], int quantidade) {
    abrir_arquivo(); // Abre o arquivo (caso ainda não tenha sido aberto)

    // Salva os livros no arquivo
    for (int i = 0; i < quantidade; i++) {
        fprintf(arquivoLivros, "Livro %d:\n", i + 1);
        fprintf(arquivoLivros, "  Nome: %s\n", livros[i].nome);
        fprintf(arquivoLivros, "  Autor: %s\n", livros[i].autor);
        fprintf(arquivoLivros, "  Genero: %d\n", livros[i].genero);
        fprintf(arquivoLivros, "  Volume: %d\n", livros[i].volume);
        fprintf(arquivoLivros, "  Quantidade: %d\n", livros[i].qtd);
        fprintf(arquivoLivros, "  Disponibilidade: %s\n\n", livros[i].disponibilidade ? "Disponivel" : "Indisponivel");
    }

    // Não precisa fechar o arquivo aqui, pois a variável global será reutilizada em outras funções
}

void criar_livro(livro *l) {
    printf("Digite o nome do livro: ");
    fgets(l->nome, q, stdin);
    l->nome[strcspn(l->nome, "\n")] = 0;

    printf("Digite o nome do autor: ");
    fgets(l->autor, q, stdin);
    l->autor[strcspn(l->autor, "\n")] = 0;

    printf("Digite o genero do livro ('1' - Exatas, '2' - Saude, '3' - Humanas): ");
    scanf("%d", &l->genero);

    printf("Digite o volume do livro: ");
    scanf("%d", &l->volume);

    printf("Digite a quantidade de exemplares: ");
    scanf("%d", &l->qtd);

    l->disponibilidade = 1;
    printf("Livro criado com sucesso!\n");
}

void buscarLivroPorNome(livro livros[], int quantidade, const char *nomeProcurado) {
    int encontrado = 0;

    printf("Resultados da busca por '%s':\n", nomeProcurado);
    for (int i = 0; i < quantidade; i++) {
        if (strstr(livros[i].nome, nomeProcurado) != NULL) {
            printf("Nome: %s\n", livros[i].nome);
            printf("Autor: %s\n", livros[i].autor);
            printf("Genero: %d\n", livros[i].genero);
            printf("Volume: %d\n", livros[i].volume);
            printf("Quantidade: %d\n", livros[i].qtd);
            printf("Disponibilidade: %s\n\n", livros[i].disponibilidade ? "Disponivel" : "Indisponivel");
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
        printf("  Genero: %d\n", livros[i].genero);
        printf("  Volume: %d\n", livros[i].volume);
        printf("  Quantidade: %d\n", livros[i].qtd);
        printf("  Disponibilidade: %s\n\n", livros[i].disponibilidade ? "Disponivel" : "Indisponivel");
    }
}

void atualizar_livro(livro *l) {
    printf("Atualizando informacoes do livro:\n");

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
    (*quantidade)--; // Diminui a quantidade de livros
    printf("Livro deletado com sucesso!\n");
}

