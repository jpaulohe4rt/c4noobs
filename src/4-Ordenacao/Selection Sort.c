#include <stdio.h>
#include <stdlib.h>

void selectionSort(int *vetor, int nelementos){
	int i, j, imenor, aux;
	for(i = 0; i < nelementos - 1; i++){
		imenor = i;
		for(j = i + 1; j < nelementos; j++)
			if(vetor[j] < vetor[imenor])
				imenor = j;
		printf("%d <-> %d\n", vetor[i], vetor[imenor]); //saida
		if(imenor != i){
			aux = vetor[i];
			vetor[i] = vetor[imenor];
			vetor[imenor] = aux;
		}			
	}
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
	
	selectionSort(vetorptr, nelementos);
	
	for(i = 0; i < nelementos; i++){
		printf("%d", vetorptr[i]);
		i < nelementos - 1 ? printf(" ") : 0;
	}
	
	free(vetorptr);
	vetorptr = NULL;
	return 0;
}
