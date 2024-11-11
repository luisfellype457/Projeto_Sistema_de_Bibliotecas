#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "livro.h"


static FILE *arquivoLivros = NULL; 

int i, encontrado, opcao, index;
char nomeProcurado[q];

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

// Função para salvar os livros no arquivo
void salvar_livros(const livro livros[], int quantidade) {
    abrir_arquivo(); // Abre o arquivo (caso ainda não tenha sido aberto)

    // Salva os livros no arquivo
    for (i = 0; i < quantidade; i++) {
        fprintf(arquivoLivros, "Livro %d:\n", i + 1);
        fprintf(arquivoLivros, "  Nome: %s\n", livros[i].nome);
        fprintf(arquivoLivros, "  Autor: %s\n", livros[i].autor);
        fprintf(arquivoLivros, "  Genero: %d\n", livros[i].genero);
        fprintf(arquivoLivros, "  Volume: %d\n", livros[i].volume);
        fprintf(arquivoLivros, "  Quantidade: %d\n", livros[i].qtd);
        fprintf(arquivoLivros, "  Disponibilidade: %s\n\n", livros[i].disponibilidade ? "Disponivel" : "Indisponivel");
    }
}

// Função para criar um novo livro
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

// Função para buscar um livro pelo nome
void buscarLivroPorNome(livro livros[], int quantidade, const char *nomeProcurado) {
    encontrado = 0;

    printf("Resultados da busca por '%s':\n", nomeProcurado);
    for (i = 0; i < quantidade; i++) {
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

// Função para listar todos os livros cadastrados
void listar_livros(const livro livros[], int quantidade) {
    if (quantidade == 0) {
        printf("Nenhum livro cadastrado.\n");
        return;
    }

    printf("Lista de Livros:\n");
    for (i = 0; i < quantidade; i++) {
        printf("Livro %d:\n", i + 1);
        printf("  Nome: %s\n", livros[i].nome);
        printf("  Autor: %s\n", livros[i].autor);
        printf("  Genero: %d\n", livros[i].genero);
        printf("  Volume: %d\n", livros[i].volume);
        printf("  Quantidade: %d\n", livros[i].qtd);
        printf("  Disponibilidade: %s\n\n", livros[i].disponibilidade ? "Disponivel" : "Indisponivel");
    }
}

// Função para atualizar informações de um livro
void atualizar_livro(livro *l) {
    do {
        printf("\nO que deseja atualizar?\n");
        printf("1. Nome\n");
        printf("2. Autor\n");
        printf("3. Gênero\n");
        printf("4. Volume\n");
        printf("5. Quantidade\n");
        printf("6. Disponibilidade\n");
        printf("7. Atualizar todos os campos\n");
        printf("8. Voltar\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // Limpa o buffer do teclado

        switch (opcao) {
            case 1:
                printf("Novo nome (atual: %s): ", l->nome);
                fgets(l->nome, q, stdin);
                l->nome[strcspn(l->nome, "\n")] = 0;
                break;
            case 2:
                printf("Novo autor (atual: %s): ", l->autor);
                fgets(l->autor, q, stdin);
                l->autor[strcspn(l->autor, "\n")] = 0;
                break;
            case 3:
                printf("Novo genero (atual: %d): ", l->genero);
                scanf("%d", &l->genero);
                getchar();
                break;
            case 4:
                printf("Novo volume (atual: %d): ", l->volume);
                scanf("%d", &l->volume);
                getchar();
                break;
            case 5:
                printf("Nova quantidade (atual: %d): ", l->qtd);
                scanf("%d", &l->qtd);
                getchar();
                break;
            case 6:
                printf("Nova disponibilidade (atual: %s): ", l->disponibilidade ? "Disponivel" : "Indisponivel");
                printf("Digite 1 para disponivel ou 0 para indisponivel: ");
                scanf("%d", &l->disponibilidade);
                break;
            case 7:
                criar_livro(l);
                break;
            case 8:
                printf("Voltando...\n");
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }
    } while (opcao != 8);
}

// Função para deletar um livro da lista
void deletar_livro(livro livros[], int *quantidade, int index) {
    for (i = index; i < (*quantidade) - 1; i++) {
        livros[i] = livros[i + 1];
    }
    (*quantidade)--; // Diminui a quantidade de livros
    printf("Livro deletado com sucesso!\n");
}
