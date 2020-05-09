<h1>Funções</h1>

As funções são maneiras de fazer um código seperado da função principal, com a ideia de modularizar o código e fazer com que ele ficasse distribuido.

Para declarar uma função é necessário colocar o tipo dela, e o nome na frente, seguido de parênteses com parâmetros (variáveis enviadas na chamada da função) e fazer um escopo de bloco com chaves. 

As funções tem que ficar acima da main, caso o contrário terá de ser criado protótipos.

Um exemplo seria:

```c
#include <stdio.h>

void mostrarVariavel(int x) { //função do tipo void que recebe um valor inteiro e mostra ele na tela.

//por ser void ela não precisa retornar nada.

    printf("%d\n", x);
}

int soma(int a, int b) { //função do tipo inteiro que recebe duas variaveis inteiras na chamada e retona a soma das duas.

//como a função é do tipo inteiro ela deve retornar algo inteiro.

//o retorno é que quando você chamar a função irá aparecer ele no lugar, então vai aparecer a soma de dois valores passados.
    return a + b;
}

int main() {
    int a = 5;
    int b = 10;

    int c = soma(a, b); //chama a função soma, para somar os valores de a e b, atribuindo esse valor a soma.

    mostrarVariavel(c); //chama a função mostrar passando como parametro a variável c.

}
```

Se quisesse colocar a função abaixo da main teria que ser feito assim:

```c
#include <stdio.h>
//prototipos
int soma(int a, int b);
int mostrarVariavel(int x);
//fim prototipos.

int main() {
    int a = 5;
    int b = 10;

    int c = soma(a, b); //chama a função soma, para somar os valores de a e b, atribuindo esse valor a soma.

    mostrarVariavel(c); //chama a função mostrar passando como parametro a variável c.

}

int soma(int a, int b) { //função do tipo inteiro que recebe duas variaveis inteiras na chamada e retona a soma das duas.

//como a função é do tipo inteiro ela deve retornar algo inteiro.

//o retorno é que quando você chamar a função irá aparecer ele no lugar, então vai aparecer a soma de dois valores passados.
    return a + b;
}


void mostrarVariavel(int x) { //função do tipo void que recebe um valor inteiro e mostra ele na tela.

//por ser void ela não precisa retornar nada.

    printf("%d\n", x);
}

```