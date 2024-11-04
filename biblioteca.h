#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

                                      //FUNÇÕES E PROTÓTIPOS PARA LIVRO (ALEC)

#define q 50

typedef struct livro {
    char nome[q];
    char autor[q];
    int genero; // '1' - Exatas, '2' - Saude, '3' - Humanas
    int volume;
    int qtd;
    int disponibilidade;
} livro;

void cadastrar_livro(livro *l);
void buscarLivroPorNome(livro livros[], int quantidade, const char *nomeProcurado);
void listar_livros(const livro livros[], int quantidade); 

                                      //FUNÇÕES E PROTÓTIPOS PARA 
