# Arrays

Como C é uma linguagem bem próxima da memória, os arrays são alocações sequenciais na memória que armazenam um tipo de variável. Um array ou vetor, é uma estrutura que faz como se fosse um aglomerado de varias váriaveis de um mesmo tipo.

Os arrays são de extrema importância para fazer armazenamentos rápidos e simples.

Toda declaração de array **deve** ter a quantidade de posições, ou seja, quantas variáveis ou itens ele consegue armazenar.

As posições se iniciam com 0 e vai até o tamanho declarado - 1.

Exemplo de como fazer um array:

```c
#include <stdio.h>

int main(void) { 
    int array[10]; //declaração de um array
    //esse colchetes com 10 dentro significa que o array tem 10 posições.

    //o array tem posições de 0 a 9.
}
```

Para inserir dados no array segue o seguinte modelo:

```c
#include <stdio.h>

int main(void) {
    int array[5] = {1, 2, 3, 4, 5};

    int array2[5];

    //abaixo inserindo em cada posição do array um valor.
    array2[0] = 1;
    array2[1] = 2;
    array2[2] = 3;
    array2[3] = 4;
    array2[4] = 5;
}
```

A estrutura de repetição for é bem utilizado com arrays, por exemplo, podemos somar todas as posições do array e fazer a média de itens lá dentro facilmente.

```c
#include <stdio.h>

int main(void) {
    int array[5] = {1, 2, 3, 4, 5};

    int acumulaSoma = 0;

    for(int i = 0; i < 5; i++) {
        acumulaSoma += array[i];
        // a cada loop o i incrementa permitindo acessar todas as posições do array.
    }

    float media = acumulaSoma / 5;
}
