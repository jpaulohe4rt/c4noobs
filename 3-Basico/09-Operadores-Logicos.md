# Operadores Lógicos e de Comparação

Os operadores lógicos são utilizados quando é necessário usar duas ou mais condições dentro da mesma instrução if para que seja tomada uma única decisão cujo resultado será verdadeiro ou falso.

| Operadores Lógicos | Significado |
|-----------------|----------------|
| &&    | e |
| !     | não |
| \|\|  | ou |

Se você conhece algum tipo de logica de programação, já entende como eles funcionam, mas para esclarecer entrarei em mais detalhes.

| Operadores de Comparação |  Significado |
| ----------------------- | ------------ |
| > | maior que |
| < | menor que |
| >=| maior ou igual|
| <= | menor ou igual |
| == | igual |
| != | não igual (diferente) |

Esses operadores são como na matemática, é possível comparar valores na programação também, e os operadores lógicos entram nessa brincadeira também.

Exemplos:
```c
#include <stdio.h>

int main(void) {

    int idade;

    printf("Qual a sua idade? ");
    scanf("%d", &idade);

    if (idade >= 18) {
        printf("Você pode assistir esse filme\n");
    }
    else {
        printf("Você não tem idade suficiente para poder assistir esse filme\n");
    }

}
```