#include <stdio.h>
#include <stdlib.h>
#define MAX 30

typedef struct computador{
	int id;
	//boto o id como se fosse o propio indice da string?
	int situacao;
}Computador;

int quantidade_computador = 0;
Computador computador[MAX];

//Vou supor um maximo para os computadores?? ou deixo essa função justamente para limmitar
//eu tenho que ter um limite se não vou começar a alocar memoria aqui
void adicionar_computador(){
	int teste=0,i;
	
	
	if(quantidade_computador == MAX){
		puts("Quantidade máxima de computadores atingida");
		//tirar esse exit
		exit(1);
	}
	
	Computador novo_pc;
	
	puts("Digite o id do computador");
	scanf("%d", &novo_pc.id);
	
	for(i=0;i<quantidade_computador;i++){
		if(novo_pc.id == computador[i].id){
			puts("Já existe um computador com esse ID");
			teste++;
		}
	}
	
	if(!teste){
		novo_pc.situacao = 1; //disponivel
	
		computador[quantidade_computador++]= novo_pc;
	}
	
}

void remover_computador(){
	
	int i;
	
	do{
		puts("Digite o id do computador que deseja remover");
		scanf("%d", &i);
	}while(i > 1 && i < quantidade_computador);
	
	Computador remover_pc;
	remover_pc.id = 0;
	remover_pc.situacao = 0;
	
	computador[i] = remover_pc;
	
}

void listar_computador(){
	
	int i;
	
	if(!quantidade_computador){
		puts("Nenhum computador cadastrado");
	}
	
	for(i=0;i<quantidade_computador;i++){
		printf("computador %d\n", i+1);
		printf("ID: %d\n", computador[i].id);
		//se for 1(disponivel)
		if(computador[i].situacao){
			puts("Disponivel");
		}else{
			puts("Indisponivel");
		}
		puts("-----------------------------");
		
	}
}

//uso a função listar para já especificar quais estão disponiveis?
void alugar_computador(){
	//listar para saber quais os disponiveis
	listar_computador();
	
}

void renovar_computador(){
}

void devolver_computador(){
}

int main(){

	adicionar_computador();
	adicionar_computador();
	adicionar_computador();
	listar_computador();
	
	return 0;
}
