#ifndef LIVRO_H
#define LIVRO_H
#define q 50
//livro.h

#include <stdio.h>

extern FILE *arquivoLivros; // Declaração da variável global FILE

typedef struct livro {
    char nome[q];
    char autor[q];
    int genero; // '1' - Exatas, '2' - Saude, '3' - Humanas
    int volume;
    int qtd;
    int disponibilidade;
} livro;
void abrir_arquivo();  // Função que abre o arquivo de livros
void fechar_arquivo(); // Função que fecha o arquivo
void criar_livro(livro *l); // CREATE 'C'-> 'CRUD'.
void buscarLivroPorNome(livro livros[], int quantidade, const char *nomeProcurado); // READ 'R'-> 'CRUD' 
void listar_livros(const livro livros[], int quantidade); // READ 'R'-> 'CRUD' 
void atualizar_livro(livro *l); // UPDATE 'U'-> 'CRUD' 
void deletar_livro(livro livros[], int *quantidade, int index); // DELETE 'D'-> 'CRUD' 
void salvar_livros(const livro livros[], int quantidade); // SALVAR

#endif // LIVRO_H
