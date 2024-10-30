#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define Numero_Maximo_de_Livros 100
#define Comprimento_maximo 100
#define Tamanho_Maximo_da_Categoria 50

typedef struct {
    char nome[Comprimento_maximo];
    char categoria[Tamanho_Maximo_da_Categoria];
    int emprestado; 
} Cadastro;//struct feita para cadastro

Cadastro catalogo[Numero_Maximo_de_Livros];
int totalLivros = 0;//Inicializa totalLivros com 0

void AdicionarLivro(char *nome, char *categoria) {
    if (totalLivros < Numero_Maximo_de_Livros) {
        strncpy(catalogo[totalLivros].nome, nome, Comprimento_maximo);
        strncpy(catalogo[totalLivros].categoria, categoria, Tamanho_Maximo_da_Categoria);
        catalogo[totalLivros].emprestado = 0; 
        totalLivros++;
    } else {
        printf("Catálogo cheio! Não é possível adicionar mais livros. :(\n");
    }
}//Funcao de adicionar livros feita

int verificarEmprestimo(char *nome) {
    for (int i = 0; i < totalLivros; i++) {
        if (strcmp(catalogo[i].nome, nome) == 0) {
            return catalogo[i].emprestado;
        }
    }
    return -1; //Caso o livro não seja encontrado
}
