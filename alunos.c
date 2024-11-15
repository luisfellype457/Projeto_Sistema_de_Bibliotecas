#include "alunos.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 1000 // alunos

Aluno cad[MAX];
int total_alunos = 0;
FILE *f;

void menu_alunos() {
	carregar_alunos();
    int op;
    do {
        printf("\n- - - - - [Menu Alunos] - - - - -\n\n");
        printf("(1) - Cadastrar aluno.\n");
        printf("(2) - Pesquisar/listar alunos.\n");
        printf("(3) - Deletar aluno.\n");
        printf("(4) - Atualizar aluno.\n");
        printf("(5) - Sair.\n\n> ");
        scanf("%d", &op);
        fflush(stdin);
        switch (op) {
            case 1:
                cadastro();
                break;
            case 2: 
                exibir_aluno();
                break;
            case 3:
                deletar_aluno();
                break;
            case 4:
                atualizar_aluno();
                break;
            default:
                break;
        }
    } while (op < 5 && op > 0);
    return;
}

void deletar_aluno() {
    char cpf[12];
    int i, j, encontrado = 0;

    printf("Digite o CPF do aluno que deseja deletar: ");
    scanf("%[^\n]", cpf);
    fflush(stdin);

    for (i = 0; i < total_alunos; i++) {
        if (strcasecmp(cpf, cad[i].cpf) == 0) {
            encontrado = 1;
            for (j = i; j < total_alunos - 1; j++) {
                cad[j] = cad[j + 1];
            }
            total_alunos--;
            abrir_arquivo_alunos();
            printf("\nAluno deletado com sucesso.\n");
            break;
        }
    }

    if (!encontrado) {
        printf("\nCPF nao encontrado.\n");
    }
    return;
}

void atualizar_aluno() {
    char cpf[12];
    int i, encontrado = 0, opcao;

    printf("Digite o CPF do aluno que deseja atualizar: ");
    scanf("%[^\n]", cpf);
    fflush(stdin);

    for (i = 0; i < total_alunos; i++) {
        if (strcasecmp(cpf, cad[i].cpf) == 0) {
            encontrado = 1;
            printf("\nAtualizando informacoes do aluno %s\n", cad[i].nome);

            do {
                printf("\nEscolha o campo que deseja atualizar:\n");
                printf("(1) Nome\n");
                printf("(2) Curso\n");
                printf("(3) CPF\n");
                printf("(4) Sair\n> ");
                scanf("%d", &opcao);
                fflush(stdin);

                switch (opcao) {
                    case 1:
                        printf("Digite o novo nome: ");
                        scanf("%[^\n]", cad[i].nome);
                        fflush(stdin);
                        printf("Nome atualizado com sucesso!\n");
                        break;
                    case 2:
                        printf("Digite o novo curso: ");
                        scanf("%[^\n]", cad[i].curso);
                        fflush(stdin);
                        printf("Curso atualizado com sucesso!\n");
                        break;
                    case 3:
                        printf("Digite o novo CPF: ");
                        scanf("%[^\n]", cad[i].cpf);
                        fflush(stdin);
                        printf("CPF atualizado com sucesso!\n");
                        break;
                    case 4:
                        printf("Saindo da atualizacao do aluno.\n");
                        break;
                    default:
                        printf("Opção invalida! Tente novamente.\n");
                }
            } while (opcao != 4);

            abrir_arquivo_alunos();
            printf("\nAluno atualizado com sucesso!\n");
            break;
        }
    }

    if (!encontrado) {
        printf("\nCPF nao encontrado.\n");
    }
}

void abrir_arquivo_alunos() {
    int i;
    f = fopen("Alunos.txt", "w");
    if (f == NULL) {
        printf("Erro na abertura!\n");
        exit(1);
    }
    for (i = 0; i < total_alunos; i++) {
        fprintf(f, "%s\n%s\n%s\n", cad[i].nome, cad[i].curso, cad[i].cpf);
    }
    fclose(f);
}

void carregar_alunos() {
    f = fopen("Alunos.txt", "r");
    if (f == NULL) {
        printf("Ainda nao ha dados de alunos. Os dados serao carregados apos o primeiro cadastro.\n");
        return;
    }
    while (fscanf(f, " %[^\n] %[^\n] %[^\n]", cad[total_alunos].nome, cad[total_alunos].curso, cad[total_alunos].cpf) == 3) {
        total_alunos++;
    }
    fclose(f);
}

void cadastro() {
    printf("Nome do aluno: \n");
    scanf("%[^\n]", cad[total_alunos].nome);
    fflush(stdin);
    printf("Curso do aluno: \n");
    scanf("%[^\n]", cad[total_alunos].curso);
    fflush(stdin);
    printf("CPF do aluno (apenas numeros): \n");
    scanf("%[^\n]", cad[total_alunos].cpf);
    fflush(stdin);
    printf("Aluno cadastrado com sucesso!\n");
    total_alunos++;
    abrir_arquivo_alunos();
    printf("\n");
    return;
}

void exibir_aluno() {
    int op, j;
    char cpf[12];
    printf("\nDeseja exibir um unico aluno ou todos os alunos?\n");
    puts("(1) Buscar aluno.");
    printf("(2) Exibir todos.\n>");
    scanf("%d", &op);
    fflush(stdin);

    switch (op) {
        case (1): {
            int encontrado = 0;
            printf("Digite o CPF do aluno que deseja buscar\n");
            scanf("%[^\n]", cpf);
            fflush(stdin);
            for (j = 0; j < total_alunos; j++) {
                if (strcasecmp(cpf, cad[j].cpf) == 0) {
                    encontrado = 1;
                    puts("Aluno ja cadastrado!");
                    printf("Nome: %s\n", cad[j].nome);
                    printf("Curso: %s\n", cad[j].curso);
                    printf("CPF: %s\n", cad[j].cpf);
                    printf("\n");
                    break;
                }
            }
            if (encontrado == 0) {
                printf("Aluno precisa ser cadastrado!\n\n");
            }
            break;
        }

        case (2): {
            for (j = 0; j < total_alunos; j++) {
                printf("\nAluno numero %d:\n", j + 1);
                printf("Nome: %s\n", cad[j].nome);
                printf("Curso: %s\n", cad[j].curso);
                printf("CPF: %s\n", cad[j].cpf);
            }
            printf("\n");
            break;
        }
    }
}
