// main.c
#include <stdio.h>
#include "processos.h"

int main() {
    adicionarLivro("Livro de C", "Programa??o");
    emprestarLivro("Livro de C");
    renovarLivro("Livro de C");
    devolverLivro("Livro de C");

    return 0;
}
