#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca.h"

                                                                   //FUNÇÕES PARA LIVRO (ALEC)

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

                                                                   //FUNÇÕES PARA ALUNO (KELVYN)

void abrir_arquivo_alunos () {
	int i;
	FILE *f;
	f = fopen("Alunos.txt", "w");
	if (f == NULL) {
		printf("Erro na abertura!\n");
		exit(1);
	}
	for(i=0; i < total_alunos; i++) {
		fprintf(f, "%s\n%s\n%s\n%s\n", cad[i].nome, cad[i].curso, cad[i].cpf, cad[i].senha);
	}
    fclose(f);
}

void carregar_alunos () {
	FILE *f;
    f = fopen("Alunos.txt", "r");
    if (f == NULL) {
        printf("Ainda nao ha dados de alunos. Os dados serao caregados apos o primeiro cadastro.\n");
        return;
    }
		while (fscanf(f, " %[^\n] %[^\n] %[^\n] %[^\n]", cad[total_alunos].nome, cad[total_alunos].curso, cad[total_alunos].cpf, cad[total_alunos].senha) == 4) {
        total_alunos++;
    }
    fclose(f);
} 

void cadastro () {
	printf("Nome do aluno: \n");
	scanf("%[^\n]", cad[total_alunos].nome);
	fflush(stdin);
	printf("Curso do aluno: \n");
	scanf("%[^\n]", cad[total_alunos].curso);
	fflush(stdin);
	printf("CPF do aluno (apenas numeros): \n");
	scanf("%[^\n]", cad[total_alunos].cpf);
	fflush(stdin);
	printf("Digite a senha: \n");
	scanf("%[^\n]", cad[total_alunos].senha);
	fflush(stdin);
	printf("Aluno cadastrado com sucesso!\n");
	total_alunos++;
    abrir_arquivo_alunos();
    printf("\n");
	continuar ();
}

void exibir_aluno () {
	int op, j;
	char cpf[12];
	printf("Deseja exibir um unico aluno ou todos os alunos?\n");
	puts("(1) Buscar aluno.");
	printf("(2) Exibir todos.\n>");
	scanf("%d", &op);
	fflush(stdin);
	
	switch(op) {
		
		case (1):
			{
			int encontrado=0;
			printf("Digite o CPF do aluno que deseja buscar\n");
			scanf("%[^\n]", cpf);
			fflush(stdin);
			for(j=0; j < MAX; j++) {
				if(strcasecmp(cpf, cad[j].cpf) == 0) {
					encontrado=1;
					puts("Aluno ja cadastrado!");
					printf("Nome: %s\n", cad[j].nome);
					printf("Curso: %s\n", cad[j].curso);
					printf("CPF: %s\n", cad[j].cpf);
					printf("Senha: %s\n", cad[j].senha);
                    printf("\n");
					continuar ();
				} 
			}
			if (encontrado==0){
				printf("Aluno precisa ser cadastrado!\n\n");
				continuar ();
			}
			break;
		}	
		
		case (2):
			{
			for(j=0; j < total_alunos; j++) {
				printf("Aluno numero %d:\n", j+1);
				printf("Nome: %s\n", cad[j].nome);
				printf("Curso: %s\n", cad[j].curso);
				printf("CPF: %s\n", cad[j].cpf);
				printf("Senha: %s\n", cad[j].senha);
				printf("\n");
			}
			continuar ();
			break;
		}
	}	
}
