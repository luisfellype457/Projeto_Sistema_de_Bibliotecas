#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca.h"

                                                                   //FUNÇÕES PARA LIVRO (ALEC)

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
