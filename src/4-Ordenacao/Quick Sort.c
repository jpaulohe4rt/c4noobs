#include <stdio.h>
#include <stdlib.h>

void quickSort(int *vetor, int inicio, int fim){
	int i = inicio, f = fim;
	int pivot = vetor[(inicio + fim) / 2];
	int aux;
	do {
		while(vetor[i] < pivot)
			i++;
		while(vetor[f] > pivot)
			f--;
		if(i <= f){
			aux = vetor[i];
			vetor[i++] = vetor[f];
			vetor[f--] = aux;
		}
	} while(i < f);
	if(inicio < f)
		quickSort(vetor, inicio, f);
	if(i < fim)
		quickSort(vetor, i, fim);
}

int main(){
	int i, elementos, pos1, pos2;
	int *vetorptr = NULL;
	
	scanf("%d", &elementos);
	if(!(vetorptr = (int *) calloc(elementos, sizeof(int)))){
		printf("Erro de alocassaum\n");
		return 1;
	}
	
	for(i = 0; i < elementos; i++)
		scanf("%d", &vetorptr[i]);
	scanf("%d %d", &pos1, &pos2);
	
	quickSort(vetorptr, 0, elementos - 1);
	
	printf("%d", vetorptr[--pos1] + vetorptr[--pos2]);
	
	free(vetorptr);
	vetorptr = NULL;
	return 0;
}
