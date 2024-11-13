#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "computador.h"
#define MAX 30

int quantidade_computador = 0;
Computador computador[MAX];

void abrir_arquivo() {
	int i;
	
    f = fopen("Computadores.txt", "w");
    if (f == NULL) {
        printf("Erro na abertura do arquivo!\n");
        exit(1);
    }
    for ( i = 0; i < quantidade_computador; i++) {
    	//tirei a parte que não mostrava a situação == 3;
            fprintf(f, "Computador.id:%d Computador.situacao:%d\n", computador[i].id, computador[i].situacao);
    }
    fclose(f);
}


void carregar_arquivo() {
    f = fopen("Computadores.txt", "r");
    if (f == NULL) {
        printf("Ainda não há dados de computadores.\n");
        return;
    }
    while (fscanf(f, "%d %d", &computador[quantidade_computador].id, &computador[quantidade_computador].situacao) == 2) {
        quantidade_computador++;
    }
    fclose(f);
}

void adicionar_computador() {
    int i, teste = 0;
    if (quantidade_computador == MAX) {
        puts("Quantidade máxima de computadores atingida");
        return;
    }

    Computador novo_pc;
    puts("Digite o id do computador que deseja adicionar");
    scanf("%d", &novo_pc.id);

    for (i = 0; i < quantidade_computador; i++) {
        if (novo_pc.id == computador[i].id) {
            if (computador[i].situacao == 2) {  // Caso o computador tenha sido removido
                computador[i].situacao = 1;  // Reativa o computador removido
                puts("Computador reativado com sucesso!");
                return;
            }
            puts("Já existe um computador com esse ID");
            return;
        }
    }

    novo_pc.situacao = 1;  // Disponível
    computador[quantidade_computador++] = novo_pc;
    abrir_arquivo();
}

void remover_computador() {
    int i, id_remover;
    int computador_encontrado = 0;

    do {
        puts("Digite o id do computador que deseja remover");
        scanf("%d", &id_remover);
    } while (id_remover <= 0 || id_remover > MAX);

    for (i = 0; i < quantidade_computador; i++) {
        if (computador[i].id == id_remover) {
            computador_encontrado = 1;
            computador[i].situacao = 2;  // Marca o computador como removido
            printf("Computador com ID %d removido com sucesso.\n", id_remover);
            break;
        }
    }

    if (!computador_encontrado) {
        puts("Computador não encontrado com o ID fornecido.");
    }
    
    abrir_arquivo();
}

void listar_computador() {
    int i;

    if (!quantidade_computador) {
        puts("Nenhum computador cadastrado");
        return;
    }

    for (i = 0; i < quantidade_computador; i++) {
        if (computador[i].situacao == 2) {
            continue;  // Ignora computadores removidos
        }

        printf("\nComputador %d\n", i + 1);
        printf("ID: %d\n", computador[i].id);
        if (computador[i].situacao == 1) {
            puts("Disponível");
        } else {
            puts("Indisponível");
        }
        puts("-----------------------------");
    }
}

void alugar_computador() {
    int i, id_aluguel, situacao = 0;

    puts("\nComputadores disponíveis:\n");
    listar_computador();

    puts("Digite qual o id do computador deseja alugar?");
    scanf("%d", &id_aluguel);

    for (i = 0; i < quantidade_computador; i++) {
        if (computador[i].id == id_aluguel) {
            situacao = 1;

            if (computador[i].situacao == 1) {
                computador[i].situacao = 0;  // Marca como indisponível
                printf("Computador %d alugado com sucesso!\n", id_aluguel);
            } else {
                puts("Esse computador está indisponível para aluguel.");
            }
            break;
        }
    }

    if (!situacao) {
        puts("ID inválido. Computador não encontrado.");
    }
}

void devolver_computador() {
    int id_devolucao, i, existe = 0;

    puts("\nDigite qual computador deseja devolver:");
    scanf("%d", &id_devolucao);

    for (i = 0; i < quantidade_computador; i++) {
        if (id_devolucao == computador[i].id) {
            existe = 1;
            if (computador[i].situacao == 1) {
                puts("Esse computador ainda não foi alugado.");
            } else {
                computador[i].situacao = 1;  // Marca como disponível
                puts("Computador devolvido com sucesso.");
            }
            break;
        }
    }

    if (!existe) {
        puts("O computador inserido não existe.");
    }
}

void renovar_computador() {
    int i, renovar = 0;

    puts("Qual computador deseja renovar?");
    scanf("%d", &renovar);

    for (i = 0; i < quantidade_computador; i++) {
        if (computador[i].situacao == 0) {  // Se o computador estiver alugado
            computador[i].situacao = 0;  // Apenas confirma o status "alugado"
            printf("Computador %d renovado com sucesso!\n", computador[i].id);
            renovar++;
        }
    }

    if (!renovar) {
        puts("Não há computadores alugados com esse ID.");
    }
}
