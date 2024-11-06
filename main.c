#include <stdio.h>
#include "biblioteca.h"

int main(){ 
	int op;
	do{
		printf("- - - - - Menu Principal - - - - -\n\n");
		printf("(1) - Criar biblioteca\n");
		printf("(2) - Pesquisar/listar bibliotecas\n");
		printf("(3) - Deletar biblioteca\n");
		printf("(4) - Atualizar biblioteca\n");
		printf("(5) - Sair\n\n> ");
		scanf("%d", &op);
		fflush(stdin);
		switch(op){
			case 1:
				criar_biblioteca();
				break;
			case 2: 
				mostrar_biblioteca();
				break;
			case 3:
				deletar_biblioteca();
				break;
			case 4:
				update_biblioteca();
				break;
			default:
				break;
		}
	} while (op < 5 && op > 0);
	return 0;
}
