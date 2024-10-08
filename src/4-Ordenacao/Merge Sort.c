#include <stdio.h>
#include <stdlib.h>

typedef int data_t;

void printArray(data_t vet[], size_t n)
{
    for (size_t i = 0; i < n; i++)
        printf("%d ", vet[i]);
    printf("\n\n");
}

/*
    Função que recebe 2 vetores embutidos no vetor 'aux' através dos indices

    Exemplo: start = 0, mid = 2, end = 4
        isso quer dizer que de [0 .. 2] é um vetor e de [3 .. 4] o outro
        ambos vetores estão ordenado em relação a ele mesmo

    A função irá pegar em ordem do menor e colocar em aux, após irá devolver
    ordenado para o vet, com ordenação de [0 .. 4] no exemplo dado

*/
void _merge(data_t vet[], data_t aux[], size_t start, size_t mid, size_t end)
{
    size_t i = start;
    size_t j = mid + 1;
    size_t k = start;

    /* Consome do inicio de cada vetor, pegando sempre o menor primeiro */
    while (i <= mid && j <= end)
        if (vet[i] <= vet[j])
            aux[k++] = vet[i++];
        else
            aux[k++] = vet[j++];

    /* Caso reste algum elemento entre um dos dois vetores é consumido por fim */
    while (i <= mid)
        aux[k++] = vet[i++];

    while (j <= end)
        aux[k++] = vet[j++];

    /* Agora já ordenado os 2 vetores, devolve para o vet os elementos ordenados */
    for (i = start; i <= end; i++)
        vet[i] = aux[i];
}

/* Função local para gerar recursão da "divisão e conquista" do método */
void _mergeSort(data_t vet[], data_t aux[], size_t start, size_t end)
{
    if (start < end)
    {
        size_t mid = start + (end - start) / 2;
        _mergeSort(vet, aux, start, mid);
        _mergeSort(vet, aux, mid + 1, end);
        _merge(vet, aux, start, mid, end);
    }
}

/* Chamada mais amigável ao usuário */
void mergeSort(data_t vet[], size_t vetLen)
{
    /*
                            MergeSort

        Custo assintótico de tempo para todos os casos: BigO(n*log(n))
        Espaço assintótico utilizado pelo método: BigO(n)

        obs: onde 'n' é o tamanho do vetor, no caso 'vetLen'
    */

    /*
        Alocação de um vetor de tamanho 'n' para uma única alocação de memoria para
    todo o método, trabalhando com subvetores contido dentro do vetor
    */
    data_t *aux;
    if (!(aux = (data_t *)malloc(vetLen * sizeof(data_t))))
    {
        printf("\n-[ERROR] Falha ao tentar alocar memoria para o vetor auxiliar\n\n");
        exit(3);
    }

    _mergeSort(vet, aux, 0, vetLen - 1);

    free(aux);
}

int main()
{
    size_t i;    /* Iterador do FOR */
    int vetLen;  /* Quantidade de elementos no vetor (input user) */
    data_t *vet; /* Vetor de dados (input user) */

    /* Recebe do usuário o tamanho do vetor desejado */
    printf("Informe o comprimento do vetor: ");
    scanf("%d", &vetLen);

    /* Verifica quantidade nula ou negativa */
    if (vetLen < 1)
    {
        printf("\n-[ERROR] O comprimento do vetor deve ser um inteiro maior do que 0\n\n");
        return 1;
    }

    /* Aloca memoria para o vetor e verifica o sucesso do processo */
    if (!(vet = (data_t *)malloc(vetLen * sizeof(data_t))))
    {
        printf("\n-[ERROR] Falha ao tentar alocar memoria para o vetor\n\n");
        return 2;
    }

    /* Recebe do usuário os elementos do vetor */
    for (i = 0; i < vetLen; i++)
    {
        printf("Insira o vetor[%d]: ", i);
        scanf("%d", vet + i);
    }

    /* Printa vetor de entrada */
    printf("\nVetor de entrada:\n");
    printArray(vet, vetLen);

    /* Chama o método de ordenação MergeSort */
    mergeSort(vet, vetLen);

    /* Printa vetor ordenado */
    printf("Vetor ordenado:\n");
    printArray(vet, vetLen);

    /* Desaloca memoria alocada (*opcional, mas boa pratica) */
    free(vet);

    return 0;
}