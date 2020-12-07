# Arrays

Como C é uma linguagem bem próxima da memória, os arrays são alocações sequenciais na memória que armazenam um tipo de variável. Um array ou vetor, é uma estrutura que faz como se fosse um aglomerado de varias váriaveis de um mesmo tipo. Vale lembrar que um array é uma variável homogênea unidimensional, ou seja, um array só pode armazenar elementos do mesmo tipo básico(int, double, float, char, etc.) em uma única dimensão.

Os arrays são de extrema importância para fazer armazenamentos rápidos e simples.

Toda declaração de array **deve** ter a quantidade de posições, ou seja, quantas variáveis ou itens ele consegue armazenar.

As posições se iniciam com 0 e vai até o tamanho declarado - 1.

Exemplo de declaração de um array:

```c
#include <stdio.h>

int main(void) { 
    int array[10]; //declaração de um array de inteiros.
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

Existem outras formas de inserir dados no array,como:
```c
#include <stdio.h>

int main(void) {
  int array[3] = {1, 2, 3};
  int array[] = {1, 2, 3};
  //Ambas as declarações são semelhantes, criamos um vetor com 3 posições(indíces de 0 a 2), e atribuímos 3 elementos à eles. Note que quando você atribui valores a um vetor na sua declaração, não é necessário você especificar o tamanho do vetor, já que essa informação é subentendida.
}
```
Também podemos inicializar um array com o valor 0, conforme os exemplos:
```c
#include <stdio.h>

int main(void) {
  int array[5] = {1, 2, 3}; //Nesse caso, criamos um vetor de 5 posições e declaramos o valor das 3 primeiras posições. Nesse caso, o restante é preenchido com o valor 0. 
  int array[100] = {0}; //Nesse caso, criamos um vetor de 100 posições e inicializamos TODAS as posições com o valor 0.

}

```

A estrutura de repetição for é bem utilizado com arrays, por exemplo, podemos somar todas as posições do array e fazer a média de itens lá dentro facilmente.

Veremos ela com mais detalhes mais para frente, mas fique com uma prévia de como usa-la com arrays:

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

Observação: Se você utilizar a palavra array como nome da variável vetor, é possível que sua IDE a marque como uma palavra reservada, no entanto, não se preocupe, pois seguindo os padrões da linguagem C, ela não é.
