#include <stdio.h>
#include "alunos.h"
#include "livro.h"
#include "catalogo.h"
#include "computador.h"
#include "biblioteca.h"

int main(){
	int op, count=0;
	do{
		if (count && op < 1 && op > 6)
			printf("\n\tOpcao invalida!\n");
		printf("___------ [MENU PRINCIPAL DO SISTEMA] ------___\n\n");
		printf("Selecione uma categoria:\n\n");
		printf("(1) - Menu Alunos\n");
		printf("(2) - Menu Livros\n");
		printf("(3) - Catalogo\n");
		printf("(4) - Computadores\n");
		printf("(5) - Bibliotecas\n");
		printf("(6) - Sair\n\n> ");
		scanf("%d", &op);
		fflush(stdin);
		switch(op){
			case 1:
				menu_alunos();
				break;
			case 2:
				menu_livros();
				break;
			case 3:
				menu_catalogo();
				break;
			case 4:
				menu_computadores();
				break;
			case 5:
				menu_bibliotecas();
				break;
			default:
				break;
		}
		count++;
	} while (op != 6);
	printf("\nEncerrando...");
	return 0;
}
