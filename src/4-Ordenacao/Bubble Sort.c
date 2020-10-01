#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int *vetor, int nelementos){
	int i, troca, aux;
	do {
		troca = 0;
		for(i = 0; i < nelementos - 1; i++){
			if(vetor[i] > vetor[i + 1]){
				printf("%d <-> %d\n", vetor[i], vetor[i + 1]); //saida
				aux = vetor[i];
				vetor[i] = vetor[i + 1];
				vetor[i + 1] = aux;
				troca = 69;
			}
		}
		nelementos--;
	} while(troca);
}

int main(){
	int i, nelementos;
	int *vetorptr = NULL;
	
	scanf("%d", &nelementos);
	if(!(vetorptr = (int *) calloc(nelementos, sizeof(int)))){
		printf("Erro de alocassaum\n");
		return 1;
	}
	
	for(i = 0; i < nelementos; i++)
		scanf("%d", &vetorptr[i]);
	
	bubbleSort(vetorptr, nelementos);
	
	for(i = 0; i < nelementos; i++){
		printf("%d", vetorptr[i]);
		i < nelementos - 1 ? printf(" ") : 0 ;
	}
	
	free(vetorptr);
	vetorptr = NULL;
	return 0;
}
