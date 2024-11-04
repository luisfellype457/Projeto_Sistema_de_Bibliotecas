// gestao_livros.h
#ifndef PROCESSOS_H
#define PROCESSOS_H

typedef struct {
    char nome[100];
    char categoria[50];
    int emprestado;
} Cadastro;

void adicionarLivro(char *nome, char *categoria);
int emprestarLivro(char *nome);
int renovarLivro(char *nome);
int devolverLivro(char *nome);

#endif
