// livro main.c
#include <stdio.h>
#include <string.h>
#include "livro.h"

#define MAX_LIVROS 100

int main() {
    livro livros[MAX_LIVROS];
    int quantidadeLivros = 0;
    int opcao;

    do {
        printf("Menu:\n");
        printf("1. Cadastrar Livro\n");
        printf("2. Buscar Livro por Nome\n");
        printf("3. Listar Livros\n"); 
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // Limpa o buffer do teclado

        switch (opcao) {
            case 1:
                if (quantidadeLivros < MAX_LIVROS) {
                    cadastrar_livro(&livros[quantidadeLivros]);
                    quantidadeLivros++;
                } else {
                    printf("Capacidade máxima de livros atingida!\n");
                }
                break;

            case 2: {
                char nomeProcurado[q];
                printf("Digite o nome do livro para buscar: ");
                fgets(nomeProcurado, q, stdin);
                nomeProcurado[strcspn(nomeProcurado, "\n")] = 0; // Remove o caractere de nova linha
                buscarLivroPorNome(livros, quantidadeLivros, nomeProcurado);
                break;
            }

            case 3: 
                listar_livros(livros, quantidadeLivros);
                break;

            case 4:
                printf("Saindo...\n");
                break;

            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 4);

    return 0;
}
