#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "computador.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	setlocale(LC_ALL,"portuguese");
	
	while(1){
	
	adicionar_computador();
	adicionar_computador();
	adicionar_computador();
	listar_computador();
	remover_computador();
	listar_computador();
	
}
return 0;
}
