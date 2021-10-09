# Ponteiro para função

Um tópico que poucas pessoas falam, mas que pode ser muito importante para alguns projetos avançados, é o ponteiro para funções. Esse tipo de ponteiro funciona como os ponteiros comuns, com a diferença que ele aponta para uma função e não para uma variável.


## Exemplos

O maior exemplo de ponteiro para função está na função `qsort`, da stdlib, que tem o seguinte cabeçalho:   

` void qsort(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *));`

A função qsort implementa o algoritmo [quicksort](https://pt.wikipedia.org/wiki/Quicksort) e busca conseguir se adequar a qualquer estrutura de dados, ela pode receber int, float, structs e etc.

### Usando a qsort

Para utilizar a qsort é necessário definir uma função que consigar comparar dois valores, o mesmo comportamento que teríamos na `strcmp` da string.h, se o primeiro valor é maior que o segundo valor então a função **retorna um valor maior que 0**, se são iguais, então a função **retorna 0**, se é menor então **retorna um valor menor que 0**. 

| Return   |      p1, p2    
|----------|:-------------| 
| <0       | p1 < p2      |
| 0        |   p1 == p2   |  
| >0       | p1 > p2      |

```c
int comparador(const void * a, const void * b) {
    int p1 = *((int*) a);
    int p2 = *((int*) b);

    if(p1 > p2)
        return 1;
    else if(p1 == p2)
        return 0;
    else
        return -1; 
}
```

```c
int comparador(const void *a, const void *b) {
   return *(int*)a - *(int*)b;
}
```

Não irei me aprofundar muito pois não é o objetivo, apenas veja funcionando.

```c
int main(void) {
    int size = 10;
    int * array = malloc(size * sizeof(int));

    // Valores aleatórios
    for(int i = 0; i < size; i++)
        array[i] = rand() % size;
    
    print(array, size);
    // Usando a qsort
    qsort(array, size, sizeof(int), comparador);
    print(array, size);
}
```

```
3 6 7 5 3 5 6 2 9 1
1 2 3 3 5 5 6 6 7 9
```

Esse comportamento funciona para qualquer estrutura de dados, por exemplo, se definirmos o tipo data basta definir a função de comparativo para que assim o algoritmo consiga ordenar um vetor de datas.

```c
typedef struct data Data;

struct data {
    int dia;
    int mes;
    int ano;
};

Data createData(int dia, int mes, int ano) {
    Data data;
    data.dia = dia;
    data.mes = mes;
    data.ano = ano;
    
    return data;
}

int compararData(const void * a, const void * b) {
    Data p1 = *((Data*) a);
    Data p2 = *((Data*) b);

    // Comparar Ano
    if(p1.ano > p2.ano) return 1; // Ano Maior
    else if(p1.ano < p2.ano) return -1; // Ano Menor

    // Ano Igual - Comparar Mês
    else if(p1.mes > p2.mes) return 1;
    else if(p1.mes < p2.mes) return -1;

    // Mês Igual - Comparar Dia
    else if(p1.dia > p2.dia) return 1;
    else if(p1.dia < p2.dia) return -1;

    // Tudo Igual
    return 0;
}

int main(void) {

    int size = 5;
    Data * array = malloc(size * sizeof(Data));

    array[0] = createData(10, 9, 2021);
    array[1] = createData(27, 5, 2001);
    array[2] = createData(25, 5, 2001);
    array[3] = createData(31, 12, 1917);
    array[4] = createData(11, 9, 2021);

    print(array, size);
    // Usando a srtcmp
    qsort(array, size, sizeof(Data), compararData);
    print(array, size);
}
```

```
Datas:    
10/ 9/2021
27/ 5/2001
25/ 5/2001
31/12/1917
11/ 9/2021

Datas:
31/12/1917
25/ 5/2001
27/ 5/2001
10/ 9/2021
11/ 9/2021
```

