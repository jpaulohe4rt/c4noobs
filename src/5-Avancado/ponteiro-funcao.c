#include <stdio.h>
#include <stdlib.h>


typedef int (Operacao)(int, int);

int add(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

int main(void) {

    Operacao op = add;

    printf("Função 1: %d\n", op(5, 5));

    printf("Função 1: %d\n", op(5, 5));
}