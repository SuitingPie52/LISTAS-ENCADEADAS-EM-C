#include <stdio.h>
#include <stdlib.h>

//////////////////////////////////
// Lista de encadeamento duplo //
////////////////////////////////

// struct aponta para o próximo e o anterior

struct no  {
	
	int numero;
	struct no *anterior;
	struct no *proximo;
	
};

struct no *cabeca = NULL;

void inserir(int numero) {

	struct no *novoNo  = (struct no *) malloc(sizeof(struct no));
	novoNo -> anterior = NULL;
	novoNo -> proximo = NULL;
	novoNo -> numero = numero;

	if (cabeca == NULL) {
		
		cabeca = novoNo;
		
	} else {
		
		struct no *ponteiro = cabeca;
		
		while (ponteiro -> proximo != NULL) {
			
			ponteiro = ponteiro -> proximo;
			
		}
		
		ponteiro -> proximo = novoNo;
		novoNo -> anterior = ponteiro;
		
	}

}

void imprimir () {
	
	struct no *ponteiro = cabeca;
	
	while (ponteiro != NULL) {
		
		printf("%d\n", ponteiro -> numero);
		ponteiro = ponteiro -> proximo;
		
	}
	
}

void remover(int parametroNumero) {

	struct no *excluir = cabeca;
	
	while (excluir -> numero != parametroNumero) {
		
		if (excluir -> proximo == NULL) {
			
			excluir = NULL;
			break;
			
		}
		
		excluir = excluir -> proximo;
		
	}

	if (excluir != NULL) {
		
		if (excluir -> proximo == NULL) {
		
			excluir -> anterior -> proximo = NULL;
		
		} else if (excluir -> anterior != NULL) {
		
			excluir -> anterior -> proximo = excluir -> proximo;
			excluir -> proximo -> anterior = excluir -> anterior;
		
		} else {
		
			cabeca = excluir -> proximo;
			
		}
		
		free(excluir);
		
	}
	
}

int main () {
	
	inserir(1);
	remover(1);
	remover(1);
	
	imprimir();
	
}
