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
        printf("4. Atualizar Livro\n");
        printf("5. Deletar Livro\n");
        printf("6. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // Limpa o buffer do teclado

        switch (opcao) {
            case 1:
                if (quantidadeLivros < MAX_LIVROS) {
                    cadastrar_livro(&livros[quantidadeLivros]);
                    quantidadeLivros++;
                    salvar_livros(livros, quantidadeLivros);
                } else {
                    printf("Capacidade máxima de livros atingida!\n");
                }
                break;

            case 2: {
                char nomeProcurado[q];
                printf("Digite o nome do livro para buscar: ");
                fgets(nomeProcurado, q, stdin);
                nomeProcurado[strcspn(nomeProcurado, "\n")] = 0;
                buscarLivroPorNome(livros, quantidadeLivros, nomeProcurado);
                break;
            }

            case 3:
                listar_livros(livros, quantidadeLivros);
                break;

            case 4: {
                int index;
                listar_livros(livros, quantidadeLivros);
                printf("Digite o número do livro para atualizar: ");
                scanf("%d", &index);
                getchar();
                if (index > 0 && index <= quantidadeLivros) {
                    atualizar_livro(&livros[index - 1]);
                    salvar_livros(livros, quantidadeLivros);
                } else {
                    printf("Índice inválido.\n");
                }
                break;
            }

            case 5: {
                int index;
                listar_livros(livros, quantidadeLivros);
                printf("Digite o número do livro para deletar: ");
                scanf("%d", &index);
                if (index > 0 && index <= quantidadeLivros) {
                    deletar_livro(livros, &quantidadeLivros, index - 1);
                    salvar_livros(livros, quantidadeLivros);
                } else {
                    printf("Índice inválido.\n");
                }
                break;
            }

            case 6:
                printf("Saindo...\n");
                break;

            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 6);

    return 0;
}
