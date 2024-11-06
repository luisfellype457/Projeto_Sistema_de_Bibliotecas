#include <stdio.h>
#include "biblioteca.h"

int main(){ 
	int op;
	do{
		printf("\tMenu Principal\n(1) - criar biblioteca\n(2) - pesquisar/listar bibliotecas\n\n> ");
		scanf("%d", &op);
		fflush(stdin);
		switch(op){
			case 1:
				criar_biblioteca();
				break;
			case 2: 
				mostrar_biblioteca();
				break;
			default:
				break;
		}
	} while (op < 3 && op > 0);
	return 0;
}
