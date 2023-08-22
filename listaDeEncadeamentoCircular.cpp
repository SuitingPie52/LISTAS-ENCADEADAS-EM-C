///////////////////////////////////////////
// PROGRAMA DE LISTA ENCADEADA CIRCULAR //
/////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

/////////////////////////////////////////////////////////////////////
// em ponteiros você guarda no endereço outro endereço de memória //
// *p ---> declara ponteiro                                      //
// & ---> endereça a variável                                   //
/////////////////////////////////////////////////////////////////

///////////////////////////////////
// Definicao da Estrutura do No //
/////////////////////////////////

struct no {
	
	int numero;
	struct no *proximo;
	
};

struct no *cabeca;

///////////////////////////////////////
// Funcao que insere um No na Lista //
/////////////////////////////////////

void inserir (int parametroNumero) {
	
	struct no *novoNo = NULL;
	novoNo = (struct no *) malloc(sizeof(struct no *)); // malloc == memory allocation, do tamanho de um "struct no"
	novoNo -> numero = parametroNumero;
	novoNo -> proximo = cabeca;
	
	if (cabeca == NULL) {
		
		cabeca = novoNo;
		cabeca -> proximo = cabeca;
		
	} else {
		
		struct no *ponteiro = cabeca;
		
		while (ponteiro -> proximo != cabeca) {
			
			ponteiro = ponteiro -> proximo;
			
		}
		
		ponteiro -> proximo = novoNo;
		
	}
	
}

/////////////////////////////////
// Funcao que imprime a Lista //
///////////////////////////////

void imprimir () {
	
	struct no *ponteiro = cabeca;
	
	while (true) {
		
		printf("%d\n", ponteiro -> numero);
		ponteiro = ponteiro -> proximo;
		
		if (ponteiro == cabeca) {
			
			break;
			
		}
		
	}
	
}

/////////////////////////////////////////////
// Funcao que remove um elemento da Lista //
///////////////////////////////////////////

void remover(int parametroNumero){
	struct no *ponteiroFinal = cabeca;
	struct no *ponteiroExcluir = cabeca;
	struct no *ponteiroPenultimo = NULL;
	
	while (ponteiroFinal -> proximo != cabeca){
	
		if (ponteiroFinal -> proximo -> numero == parametroNumero){
		
			ponteiroExcluir = ponteiroFinal -> proximo;
	
		}
	
		if (ponteiroFinal -> proximo -> proximo == cabeca){
		
			ponteiroPenultimo = ponteiroFinal;
	
		}
	
		ponteiroFinal = ponteiroFinal -> proximo;

	}

	if ((ponteiroExcluir == cabeca) && (ponteiroExcluir -> proximo == cabeca)) {
		
		cabeca = NULL;
		free(ponteiroExcluir);
	
		
	} else if (ponteiroExcluir == cabeca){
	
		ponteiroFinal -> proximo = cabeca -> proximo;
		cabeca = cabeca -> proximo;
		free(ponteiroExcluir);

	} else if (ponteiroExcluir == ponteiroFinal) {
	 
		ponteiroPenultimo -> proximo = cabeca;
		ponteiroFinal = NULL;
		free(ponteiroExcluir);

	} else {
		
		ponteiroFinal = cabeca;
		
		while ((ponteiroFinal -> proximo != cabeca) && (ponteiroFinal -> proximo -> numero != parametroNumero)) {
	
			ponteiroFinal = ponteiroFinal -> proximo;
	
		}
		
		if (ponteiroFinal -> proximo != cabeca) {
		
			ponteiroExcluir = ponteiroFinal -> proximo;
			ponteiroFinal -> proximo = ponteiroExcluir -> proximo;
			free(ponteiroExcluir);
	
		}
	}
	
}

int main () {
	
	inserir(1);
	
	imprimir();
	
	printf("\n/////////////////////////////////////////////////\n");
	
	remover(1);

	imprimir();
	
}

