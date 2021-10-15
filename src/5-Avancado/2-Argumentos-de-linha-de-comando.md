# Argumentos de Linha de Comando

Provavelmente você já viu o cabeçalho `int main(int argc, char **argv)` em algum código na internet, esse cabeçalho é usado para que a função main seja capaz de receber argumentos por linha de comando e a partir desses argumentos definir comportamentos para o programa. 

Quando um programa é executado pelo terminal é possível passar parâmetros para ele. Veja o caso, por exemplo, do programa "ls": se executado com `ls`, `ls -a` ou `ls -lh`, apresentará um comportamento diferente em cada execução.

`ls` : 
```
README.MD  src
```

`ls -lh`: 
```
total 4.0K
-rwxrwxrwx 1 yansz yansz 3.1K Oct 14 13:54 README.MD
drwxrwxrwx 1 yansz yansz 4.0K Oct  9 01:40 src
```

`ls -a`: 
```
.  ..  .git  .github  .vscode  README.MD  src
```

O programa ls é o mesmo, porém, os argumentos mudaram o comportamento, isso é apenas uma parte do poder dos argumentos linha de comando, é possível definir paths e outros comportamentos, o limite é sua criatividade! 



Caso esteja curioso, os programas como `ls`, `touch` e `cat` são apenas binários na pasta `/bin`, você pode inclusive botar seus próprios comandos nessa pasta.

> :warning: Não abuse disso se você não souber usar
```
user@c4noobs:/mnt/d/c4noobs$ sudo cp hello /bin
user@c4noobs:/mnt/d/c4noobs$ hello
Hello!
```

## Como usar?

> hello.c
```c
#include <stdio.h>

int main(int argc, char **argv) {
    /*        / \         / \
               |           |
               |           argumentos recebidos, 
               |           sendo o primeiro o nome do arquivo
               quantidade de argumentos recebidos
    */
    for(int i = 0; i < argc; i++) {
        printf("%s - ", argv[i]);
    }
    printf("\n");
}
```
> :warning: Os argumentos são separados por espaços
```shell
user@c4noobs:/mnt/d/c4noobs$ ./hello c4noobs he4rts
./hello - c4noobs - he4rts -
```

### Propriedades

- É possível controlar o programa por fora do código.
- Os argumentos são passados quando o programa é invocado.
- O argv[1] armazena o primeiro argumento e assim por diante. 

### Exemplos

```c
// Vetor.cpp
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    /* 
       Esse programa espera um argumento externo, 
       O número que representa o tamanho do vetor 
    */
    if(argc != 2) {
        printf("Error: Invalid number of arguments\n");
        return -1;
    }

    // Atoi não é uma operação segura!
    int size = atoi(argv[1]);

    int *arr = (int *) malloc(size * sizeof(int));
    for(int i = 0; i < size; i++)
        arr[i] = i;

    // Print
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
```
```shell
user@c4noobs:/mnt/d/c4noobs$ ./Vetor 5
0 1 2 3 4
user@c4noobs:/mnt/d/c4noobs$ ./Vetor
Error: Invalid number of arguments
```