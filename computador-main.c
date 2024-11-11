#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "computador.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	setlocale(LC_ALL,"portuguese");
	
	int op;
	
	abrir_arquivo();
	
	//como escreve no arquivo?
	
	do{
		
		puts("Digite a opção desejada:");
		
		puts("Adicionar computador(1)");
		puts("Remover computador(2)");
		puts("Listar computador(3)");
		puts("Alugar computador(4)");
		puts("Devolver computador(5)");
		puts("Renovar computador(6)");
		
		
		scanf("%d", &op);
		fflush(stdin);
		
		puts("--------------------------------------------");
		
		switch(op){
			
			case 1:
				adicionar_computador();
				break;
				
			case 2:
				remover_computador();
				break;

			case 3:
				listar_computador();
				break;
			case 4:
				alugar_computador();
				break;
			case 5:
				devolver_computador();
				break;
			case 6:
				renovar_computador();
				break;
			default:
				puts("\nPor favor digite um valor válido\n");
		}
		
	}while(1);
	
	
	
return 0;
}
