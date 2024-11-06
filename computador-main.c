#include <stdio.h>
#include <stdlib.h>
#include "computador.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	 abrir_arquivo();
	adicionar_computador();
	
	remover_computador();
	listar_computador();
    alugar_computador();
	
	return 0;
}
