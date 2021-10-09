# Ponteiro para função

Um tópico que poucas pessoas falam, mas que pode ser muito importante para alguns projetos avançados, é o ponteiro para funções. Esse tipo de ponteiro funciona parecido com os ponteiros comuns, com a diferença que ele aponta para uma função e não para uma variável.


## Criando seu próprio ponteiro

Declarar um ponteiro para função é simples:

`**tipo de retorno** (* *nome da variável*)(**tipos dos parâmetros**)`

### Exemplo

```c
// Função que vamos apontar
int add(int a, int b) {
    return a + b;
}

// Outra função que vamos apontar
int sub(int a, int b) {
    return a - b;
}

int main(void) {
/*   tipo de retorno
     |           tipo do primeiro parâmetro
     |           |    tipo do segundo parâmetro
     |           |    |      função que estamos apontando
     |           |    |      |
     |           |    |      |
    \ /         \ /  \ /    \ /
*/  int (*func)(int, int) = add;
/*        / \
           |
           nome da variável
*/
    // O uso da função é idêntico ao uso normal
    printf("Função 1: %d\n", func(5, 5));

    // Pode substituir o valor a qualquer momento também
    func = sub;
    printf("Função 2: %d\n", func(5, 5));
}
```

```
Função 1: 10
Função 2: 0
```

Essa sintaxe para declarar é feia né? Da pra deixar mais bonito? Sim! Com um typedef é possível declarar esses ponteiros como se fossem variáveis normais.
```c
typedef int (*Operacao)(int, int);
/*              / \
                 |
                nome do tipo definido
*/
int main(void) {

    Operacao op;

    op = add;
    printf("Função 1: %d\n", op(5, 5));

    op = sub;
    printf("Função 1: %d\n", op(5, 5));
}
```

[Exemplo de uso de ponteiros para função.](./1-1-qsort.md) Espero que tenham entendido, obrigado!

### Referências:
[qsort - documentação](https://www.cplusplus.com/reference/cstdlib/qsort/) <br>
[qsort - uso](https://www.galirows.com.br/meublog/programacao/utilizacao-funcao-qsort/) <br>
[tópico - stackoverflow](https://stackoverflow.com/questions/840501/how-do-function-pointers-in-c-work) <br>
[tópico - geeksforgeeks](https://www.geeksforgeeks.org/function-pointer-in-c/) <br>
