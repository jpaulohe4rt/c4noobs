<h1>Funções</h1>

As funções são maneiras de fazer um código seperado da função principal, com o intuito de modularizar o código e isolar as responsabilidades.

Para declarar uma função é necessário colocar o tipo de retorno dela, e o nome na frente, seguido dos parâmetros entre parênteses (variáveis enviadas na chamada da função) e fazer um escopo de bloco com chaves. 

As funções criadas devem vir antes da função main, caso o contrário terão de ser criados protótipos.

Um exemplo seria:

```c
#include <stdio.h>

void mostrarVariavel(int x) { //função de retorno tipo void que recebe um valor inteiro e mostra ele na tela.

//por ser void ela não precisa retornar nada.

    printf("%d\n", x);
}

int soma(int a, int b) { //função de retorno tipo inteiro que recebe duas variaveis inteiras na chamada e retona a soma das duas.

//como a função é de retorno tipo inteiro ela deve retornar algo inteiro.

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

int soma(int a, int b) { //função de retorno tipo inteiro que recebe duas variaveis inteiras na chamada e retona a soma das duas.

//como a função é de retorno tipo inteiro ela deve retornar algo inteiro.

//o retorno é que quando você chamar a função irá aparecer ele no lugar, então vai aparecer a soma de dois valores passados.
    return a + b;
}


void mostrarVariavel(int x) { //função de retorno tipo void que recebe um valor inteiro e mostra ele na tela.

//por ser void ela não precisa retornar nada.

    printf("%d\n", x);
}

```