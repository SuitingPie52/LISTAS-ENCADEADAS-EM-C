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

void remover (int parametroNumero) {
	
	struct no *ponteiroAnterior;
	struct no *ponteiroExcluir;
	
	ponteiroAnterior = cabeca;
	
	if (cabeca != NULL) {
		
		while(true) {
			
			if (cabeca -> proximo == cabeca 
				&& cabeca -> numero == parametroNumero) {
			
				cabeca = NULL;
				return;
						
			} else if (cabeca -> numero == parametroNumero) {
		
				ponteiroExcluir = cabeca;
				cabeca = cabeca -> proximo;
				
				while (true) {
		
					ponteiroAnterior = cabeca;
		
					if (ponteiroAnterior -> proximo == ponteiroExcluir) {
			
						ponteiroAnterior -> proximo = cabeca;
						free(ponteiroExcluir);
						return;
			
					}
											 ////////////////
					ponteiroAnterior = ponteiroAnterior -> proximo; // algum erro //
										       ////////////////				}
				
				
			
			} else if (ponteiroAnterior -> proximo -> proximo == cabeca
						&& ponteiroAnterior -> proximo -> numero == parametroNumero) {
				
				ponteiroExcluir = ponteiroAnterior -> proximo;
				ponteiroAnterior -> proximo = cabeca;
				
				free(ponteiroExcluir);
				return;
				
			} else if (ponteiroAnterior -> proximo -> numero == parametroNumero) {
				
				ponteiroExcluir = ponteiroAnterior -> proximo;
				ponteiroAnterior -> proximo = ponteiroAnterior -> proximo -> proximo;
				
				free(ponteiroExcluir);
				return;
				
			}
		
			ponteiroAnterior = ponteiroAnterior -> proximo;
		
				if (ponteiroAnterior -> proximo == cabeca) {
				
					break;
				
			}			
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
