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

## Como usar

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
