# Ponteiros
Para muitas pessoas ponteiros são de arrepiar os cabelos... Eles são um pouco complexos mas o básico deles é simples de entender.

Um ponteiro é quando você reserva uma posição de memória que armazena uma quantidade de bytes relativo a cada tipo.

>Imagem retirada do repositório do <a href="github.com/hellowluan/">hellowluan</a>

<img src="../imgs/TiposPrimitivos.png">

Cada tipo de variável tem um gasto na memória RAM do seu computador, um ponteiro armazena um tamanho necessário para receber esse tipo. O ponteiro contém o endereço de memória que foi reservado para fazer sua alocação, porém, para armazenar o ponteiro também teremos um gasto que será independente ao tipo de dado que iremos apontar, e será definido pela arquitetura do seu processador, se for x64, o tamanho do ponteiro será de 64 bits **(8 bytes)**, ou 32 bits **(4 bytes)** caso contrário. Podemos verificar essa afirmação com o operador **sizeof**

Assim como as funções do **<stdio.h>**, para manipular ponteiros e realizar alocação dinâmica é necessário utilizar o header **<stdlib.h>**.

Exemplo inicial:

```c
#include <stdio.h>
#include <stdlib.h>

int main(void) {

    int valor = 30;

    int *ponteiro = NULL;  /* Para declarar um ponteiro, definimos seu tipo
                    e o nome com um asterisco como prefixo.
                    Chamados de 'ponteiro para inteiro'
                    pois o ponteiro aponta para um valor inteiro */

    // NULL é um ponteiro nulo, que não aponta para um
    // endereço válido, e é usado para indicar que o ponteiro
    // está vazio. Isso é útil para verificarmos a disponibilidade
    // do mesmo, pois não queremos cair no erro de "segmentation fault"
    // (erro de memória inexistente)

    ponteiro = &valor;  /* como o ponteiro armazena um endereço
                        de memória, utilizamos o operador '&'
                        para informar que estamos passando um
                        endereço e não um valor. */

    
    // Se tentarmos imprimir o valor do ponteiro
    // iremos nos deparar com o endereço que é
    // armazenado por ele
    printf("Endereço do ponteiro na memória: %p\n", ponteiro);

    // Então se quisermos o valor para qual o endereço aponta
    // precisamos desreferenciar o seu valor, indicamos isso
    // usando o operador * (operador de desreferenciação)
    printf("Variável valor: %d, Ponteiro: %d\n", valor, *ponteiro);
    // imprime 
    // Variável valor: 30, Ponteiro: 30

    // Se quisermos atribuir um valor diretamente à variável "ponteiro"
    // precisaremos informar com o operador de desreferenciação '*'
    // que é a forma que temos de acessar o valor armazenado 
    // pelo ponteiro
    (*ponteiro) = 60; /* Informamos que estamos trabalhando com valores
                        não com endereços */

    // Agora, se colocar-mos para imprimir os valores das variáveis
    // "ponteiro" e "valor" iremos ter uma surpresinha
    printf("Variável valor: %d, Ponteiro: %d\n", valor, *ponteiro);
    // imprime 
    // Variável valor: 60, Ponteiro: 60

    // Note que em momento algum alteramos a variável "valor" diretamente.
    // Essa é uma característica dos ponteiros, quando recebemos
    // o endereço da variável, agora temos formas distintas de manipular
    // a mesma variável, pois estamos compartilhando o mesmo endereço.

    return 0;
}
```

É possível também reservar uma parte da memória sem passar uma variável para o ponteiro. É utilizada a função malloc com a sizeof.

```c
#include <stdio.h>
#include <stdlib.h>

int main(void) {

    int *ponteiro;  // para declarar um ponteiro, definimos o seu tipo
                    // e o nome com o asterisco atrás dele.

    ponteiro = malloc(sizeof(int));
    //a função malloc armazena na memória o tamanho em bytes que você quiser.
    //a função sizeof retorna o tamanho do tipo que você quer, portanto o ponteiro fica alocado corretamente para o tamanho indicado e está pronto para uso.

    //como um ponteiro já é um endereço de memória
    //não é necessário utilizar o "&", como é feito normalmente
    scanf("%d", ponteiro);
    printf("%d\n", *ponteiro);

}
```

Má prática com ponteiros:
```c
#include <stdio.h>
#include <stdlib.h>

int main(void) {

    int *ponteiro;

    ponteiro = malloc(sizeof(int));

    //esse código funciona mas não é adequado
    //ao compilar o compilador dá diversos warning(avisos)
    //pois os tipos das variáveis não é o mesmo da formatação
    //podendo resultar em ações indesejadas
    scanf("%d", &ponteiro);
    printf("%d\n", ponteiro);

}
```

Maiores explicações sobre C:

<a href="https://www.embarcados.com.br/ponteiro-em-c-alocacao-dinamica/">Embarcados</a>

<a href="https://www.ime.usp.br/~pf/algoritmos/aulas/aloca.html">USP</a>


