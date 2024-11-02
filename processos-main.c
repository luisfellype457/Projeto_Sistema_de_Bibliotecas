// main.c
#include <stdio.h>
#include "gestao.h"

int main() {
    adicionarLivro("Livro de C", "Programação");
    emprestarLivro("Livro de C");
    renovarLivro("Livro de C");
    devolverLivro("Livro de C");

    return 0;
}

