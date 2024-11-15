#include "catalogo.h"

Cadastro catalogo[Numero_Maximo_de_Livros];
int totalLivros = 0;

char nome[Comprimento_maximo];
char categoria[Tamanho_Maximo_da_Categoria];
int emprestado, i;

void menu_catalogo(){
	int opcao;

    CarregarCatalogo();

    do {
    	printf("\n- - - - - [Menu Catalogo] - - - - -\n\n");
        printf("\n1. Adicionar Livro\n2. Listar Livros\n3. Remover Livro\n4. Atualizar Emprestimo\n5. Verificar Emprestimo\n6. Salvar e Sair\nEscolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                printf("Nome do Livro: ");
                fgets(nome, Comprimento_maximo, stdin);
                nome[strcspn(nome, "\n")] = '\0';

                printf("Categoria do Livro: ");
                fgets(categoria, Tamanho_Maximo_da_Categoria, stdin);
                categoria[strcspn(categoria, "\n")] = '\0';

                AdicionarLivro(nome, categoria);
                break;

            case 2:
                ListarLivros();
                break;

            case 3:
                printf("Nome do Livro a remover: ");
                fgets(nome, Comprimento_maximo, stdin);
                nome[strcspn(nome, "\n")] = '\0';
                RemoverLivro(nome);
                break;

            case 4:
                printf("Nome do Livro para atualizar o emprestimo: ");
                fgets(nome, Comprimento_maximo, stdin);
                nome[strcspn(nome, "\n")] = '\0';

                printf("Emprestado? (1 para Sim, 0 para Nao): ");
                scanf("%d", &emprestado);

                AtualizarEmprestimo(nome, emprestado);
                break;

            case 5:
                printf("Nome do Livro para verificar emprestimo: ");
                fgets(nome, Comprimento_maximo, stdin);
                nome[strcspn(nome, "\n")] = '\0';

                emprestado = verificarEmprestimo(nome);
                if (emprestado == -1) {
                    printf("Livro nao encontrado.\n");
                } else {
                    printf("O livro esta %semprestado.\n", emprestado ? "" : "nao ");
                }
                break;

            case 6:
                SalvarCatalogo();
                printf("Saindo...\n");
                break;

            default:
                printf("Opção invalida. Tente novamente.\n");
        }
    } while (opcao != 6);
}

void AdicionarLivro(char *nome, char *categoria) {
    if (totalLivros < Numero_Maximo_de_Livros) {
        strncpy(catalogo[totalLivros].nome, nome, Comprimento_maximo);
        strncpy(catalogo[totalLivros].categoria, categoria, Tamanho_Maximo_da_Categoria);
        catalogo[totalLivros].emprestado = 0;
        totalLivros++;
    } else {
        printf("Catalogo cheio! Nao e possivel adicionar mais livros.\n");
    }
}

void ListarLivros() {
    for (i = 0; i < totalLivros; i++) {
        printf("Nome: %s\nCategoria: %s\nEmprestado: %s\n\n", 
               catalogo[i].nome, catalogo[i].categoria, 
               catalogo[i].emprestado ? "Sim" : "NÃ£o");
    }
}

void RemoverLivro(char *nome) {
	int j;
    for (i = 0; i < totalLivros; i++) {
        if (strcmp(catalogo[i].nome, nome) == 0) {
            for (j = i; j < totalLivros - 1; j++) {
                catalogo[j] = catalogo[j + 1];
            }
            totalLivros--;
            printf("Livro removido com sucesso.\n");
            return;
        }
    }
    printf("Livro nao encontrado.\n");
}

void AtualizarEmprestimo(char *nome, int emprestado) {
    for (i = 0; i < totalLivros; i++) {
        if (strcmp(catalogo[i].nome, nome) == 0) {
            catalogo[i].emprestado = emprestado;
            printf("Status de emprestimo atualizado.\n");
            return;
        }
    }
    printf("Livro nao encontrado.\n");
}

int verificarEmprestimo(char *nome) {
    for (i = 0; i < totalLivros; i++) {
        if (strcmp(catalogo[i].nome, nome) == 0) {
            return catalogo[i].emprestado;
        }
    }
    return -1;
}

void SalvarCatalogo() {
    FILE *file = fopen(ARQUIVO_LIVROS, "w");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo para salvar.\n");
        return;
    }
    for (i = 0; i < totalLivros; i++) {
        fprintf(file, "%s;%s;%d\n", catalogo[i].nome, catalogo[i].categoria, catalogo[i].emprestado);
    }
    fclose(file);
    printf("Catalogo salvo com sucesso.\n");
}

void CarregarCatalogo() {
    FILE *file = fopen(ARQUIVO_LIVROS, "r");
    if (file == NULL) {
        printf("Arquivo de catalogo nao encontrado.\n");
        return;
    }
    totalLivros = 0;
    while (fscanf(file, "%[^;];%[^;];%d\n", catalogo[totalLivros].nome, catalogo[totalLivros].categoria, 
                  &catalogo[totalLivros].emprestado) == 3) {
        totalLivros++;
    }
    fclose(file);
    printf("Catalogo carregado com sucesso.\n");
}
