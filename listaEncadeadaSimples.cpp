//////////////////////////////////////////
// PROGRAMA DE LISTA ENCADEADA SIMPLES //
////////////////////////////////////////

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
	novoNo -> proximo = NULL;
	
	if (cabeca == NULL) {
		
		cabeca = novoNo;
		
	} else {
		
		struct no *ponteiro = cabeca;
		
		while (ponteiro -> proximo != NULL) {
			
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
	
	while (ponteiro != NULL) {
		
		printf("%d\n", ponteiro -> numero);
		ponteiro = ponteiro -> proximo;
		
	}
	
}

/////////////////////////////////////////////
// Funcao que remove um elemento da Lista //
///////////////////////////////////////////

void remover (int parametroNumero) {
	
	struct no *ponteiroAnterior;
	struct no *ponteiroExcluir;
	
	if (cabeca != NULL) {
			
		if (cabeca -> numero == parametroNumero) {
				
			ponteiroExcluir = cabeca;
			cabeca = cabeca -> proximo;
				
			free(ponteiroExcluir);
				
		} else {
				
			ponteiroAnterior = cabeca;
				
			while ((ponteiroAnterior -> proximo != NULL) && 
					(ponteiroAnterior -> proximo -> numero != parametroNumero)) {
									
					ponteiroAnterior = ponteiroAnterior -> proximo;
					
			}
				
			if (ponteiroAnterior -> proximo != NULL) {
					
				ponteiroExcluir = ponteiroAnterior -> proximo;
				ponteiroAnterior -> proximo = ponteiroExcluir -> proximo;
					
				free(ponteiroExcluir);
				
			}
		}	
	}
}

int main () {
	
	inserir(1);
	inserir(2);
	inserir(3);
	inserir(4);
	inserir(5);
	inserir(6);
	inserir(7);
	inserir(8);
	inserir(9);
	inserir(10);
	inserir(11);
	
	imprimir();
	
	printf("\n/////////////////////////////////////////////////\n");
	
	remover(4);
	remover(11);
	remover(11);
	
	imprimir();
	
}
