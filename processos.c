#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
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
		//
		teste++;
		//tirar esse exit
	}
	
	Computador novo_pc;
	if(!teste){
		puts("Digite o id do computador que queira adicionar");
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
	
	int i,id_aluguel,situacao=0;
	
	//listar para saber quais os disponiveis
	puts("\ncomputadores disponiveis:\n");
	listar_computador();
	
	puts("Digite qual o id do computador deseja alugar?");
	scanf("%d", &id_aluguel);
	
	for(i=0;i<quantidade_computador;i++){
		//verifica se o id digitado já está salvo(procura o computador)
		if(computador[i].id == id_aluguel){
			//situacao encontrado
			situacao = 1;
		
		
		//Se tiver disponivel aluga
		if(computador[i].situacao == 1){
			//se torna indisponivel
			computador[i].situacao = 0;
			printf("Computador %d alugado com sucesso!", id_aluguel);
		}else{
			puts("Esse computdor está indisponível");
		}
		break;
			}
		
		}
		
		if(!situacao){
			puts("ID inválido. Computador não encontrado");
	}
	
	// se digitar um computador indiponivel?
	
	
	
}


void devolver_computador(){
	//Er
	int id_devolucao,i,existe=0;
	
	puts("\nDigite qual computador a devolver");
	scanf("%d", &id_devolucao);
	
	for(i=0; i<quantidade_computador; i++){
		//verifica se existe
		if(id_devolucao == computador[i].id){
			existe=1;
		
		
		//verifica se está disponivel
		if(computador[i].id){
			//computador não foi alugado ainda
			puts("Esse computador ainda não foi alugado");
		}else{
			computador[i].id = 1;
			puts("Computador devolvido com sucesso");
		}
		}
		break;
	}
	
	if(!existe){
		puts("O computador inserido não existe");
	}
	//verificar se essse computador existe e se esta indisponivel  
	//e o que não existe
}

void renovar_computador(){
	
	int i,renovar=0;
	
	puts("Qual computador deseja renovar?");
	scanf("%d", &renovar);
	
	for(i=0;i<quantidade_computador;i++){
		//verifica se o computador está alugado(indisponivel)
		if(computador[i].situacao == 0){
			 computador[i].situacao = 0;  // Apenas confirma que o status continua "alugado"
            printf("Computador %d renovado com sucesso!\n", computador[i].id);
            renovar++;
		}
	}
	
	if(!renovar){
		puts("Não há computadores alugados com esse ID");
	}
}
int main(){
	setlocale(LC_ALL,"portuguese");
	
	
	adicionar_computador();
	//adicionar_computador();
	adicionar_computador();
	//listar_computador();
	alugar_computador();
	//printf("situacao do cmopu 1%d", computador[0].situacao);
	devolver_computador();
	
	return 0;
}
