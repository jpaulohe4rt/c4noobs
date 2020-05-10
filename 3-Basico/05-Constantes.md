# 3.5 Constantes 

Em constantes, podemos utilizar números ou caracteres com valores predefinidos que não mudam e não podem ter seus valores alterados durante a execução do programa.

Para criar uma constante é necessario a utilização do comando #define que é colocado no início do programa.

```c
#include <stdio.h>

#define LARGURA 50 // Não se pode colocar ponto-e-vírgula depois do valor
#define TAMANHO 1.70

int main(void) {

    printf("%d\n", LARGURA);
    //Imprime:
    //50

    printf("%f\n", TAMANHO);
    //Imprime:
    //1.700000

    printf("%.2f\n", TAMANHO);
    //Imprime:
    //1.70

    //O ".2" define a precisão do número
}
```
