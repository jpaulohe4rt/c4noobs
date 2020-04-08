<h1>Ponteiros</h1>

Para muitas pessoas ponteiros são de arrepiar os cabelos... Eles são um pouco complexos mas o básico deles é simples de entender.

Um ponteiro é quando você reserva uma posição de memória que armazena uma quantidade de bytes relativo a cada tipo.

>Imagem retirada do repositório do <a href="github.com/hellowluan/">hellowluan</a>

<img src="../images/TiposPrimitivos.png">

Cada tipo de variável tem um gasto na memória ram do seu computador, um porteiro armazena um tamanho necessário para receber esse tipo. O ponteiro ele contém o endereço de memória que foi reservado para fazer sua alocação.

Exemplo inicial:

```c
#include <stdio.h>
int main() {

    int valor = 30;

    int *ponteiro; //para declarar um ponteiro é seu tipo e o nome como asterisco atrás dele.

    ponteiro = &valor; //como o ponteiro armazena o endereço de memória, para passar o valor da variável para ele deve-se passar seu endereço.

}
```

É possível também reservar uma parte da memória sem passar uma variável para o ponteiro. É utilizada a função malloc com a sizeof.

```c
int main() {


    int *ponteiro; //para declarar um ponteiro é seu tipo e o nome como asterisco atrás dele.

    ponteiro = malloc(sizeof(int));
    // a função malloc armazena na memória o tamanho em bytes que você quiser.
    //a função sizeof retorna o tamanho do tipo que você quer, portanto o ponteiro fica alocado corretamente e está pronto para uso.

}
```

Maiores explicações sobre C:

<a href="https://www.embarcados.com.br/ponteiro-em-c-alocacao-dinamica/">Embarcados</a>

<a href="https://www.ime.usp.br/~pf/algoritmos/aulas/aloca.html">USP</a>


