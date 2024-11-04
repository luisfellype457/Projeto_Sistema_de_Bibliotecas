#ifndef LIVRO_H
#define LIVRO_H

#define q 50

typedef struct livro {
    char nome[q];
    char autor[q];
    int genero; // '1' - Exatas, '2' - Saúde, '3' - Humanas
    int volume;
    int qtd;
    int disponibilidade;
} livro;

void cadastrar_livro(livro *l);
void buscarLivroPorNome(livro livros[], int quantidade, const char *nomeProcurado);
void listar_livros(const livro livros[], int quantidade);
void atualizar_livro(livro *l);
void deletar_livro(livro livros[], int *quantidade, int index);
void salvar_livros(const livro livros[], int quantidade); // Nova função para salvar todos os livros no arquivo

#endif // LIVRO_H
