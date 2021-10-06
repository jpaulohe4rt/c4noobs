# Leitura e Escrita de Arquivos

Além da possibilidade de exibir resultados do usuário, também é possivel fazer a leitura e escrita de arquivos em C. As funções necessárias para tratar arquivos estão incluídas na biblioteca `#include <stdio.h>`.

## FILE

Assim como os tipos `int`, `float`, `double` e `char`, o tipo FILE é responsável por armazenar informações para controlar o arquivo que será aberto pelo `fopen()`

## fopen()

A função `fopen()` é responsável por abrir um arquivo. Para utilizar ela, é necessário incluir dois argumentos, sendo o primeiro o **caminho do arquivo** e o segundo é o **modo** que esse arquivo será tratado. Os modos são:

| Modo | Função |
| ---- | ------ |
| r | Abre o arquivo para leitura |
| r+ | Abre o arquivo para leitura e escrita |
| w | Abre o arquivo para escrita. Se já existir, o conteúdo anterior será destruído. Caso contrário, um novo arquivo é criado. |
| w+ | Abre o arquivo para leitura e escrita. Se já existir, o conteúdo anterior será destruído. Caso contrário, um novo arquivo é criado. |
| a | Abre o arquivo para escrita. Os dados são incluídos a partir do final. O arquivo é criado caso não exista |
| a+ | Abre o arquivo para leitura e escrita. A escrita é sempre inserida no final do arquivo, mas a posição inicial de leitura depende do sistema. O arquivo é criado caso não exista. |
| b | Inserir `b` no final dos modos anteriores permite a leitura ou escrita de arquivos binários |  

> Se ocorrer algum erro ao abrir um arquivo, a função retorna **NULL**.

> A função retorna um ponteiro do tipo **FILE**(FILE*).

## fclose()

A função `fclose()` encerra o uso do arquivo aberto anteriormente pelo `fopen()` e **salva** as alterações feitas.

> Se o arquivo foi encerrado com sucesso, é a função retorna **0**. Caso contrário um erro ocorre.

## fprintf()

A função `fprintf()`, muito semelhante a `printf()`, permite a escrita de texto nos arquivos abertos anteriormente pelo `fopen()`. O primeiro argumento é do tipo **FILE***, o segundo é o formato da string que será escrita e o terceiro(opcional) são os valores que serão incluídos na string formatada anterior.

## fscanf()

A função `fscanf()`, muito semelhante a `scanf()`, permite leitura de texto nos arquivos abertos anteriormente pelo `fopen()`.O primeiro argumento é do tipo **FILE***, o segundo é o formato da string que será lida e o terceiro são as variáveis que vão armazenar os dados.

## Exemplo de uso

## Escrita de Inteiros

> Código-fonte

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Variável para armazenar quantos inteiros vão ser inseridos
    int n = 10;
    int i;

    // Cria a variável do tipo FILE* e abre o arquivo para escrita em seguida
    FILE *arquivo;
    arquivo = fopen("valores.txt", "w");
    if (arquivo == NULL) {
        printf("ERRO AO ABRIR O ARQUIVO\n");
        exit(-1);
    }

    // Loop que salva valores entre 0 e n separados por espaço
    for (i = 0; i < n; i++) {
        fprintf(arquivo, "%d ", i);
    }

    int sucesso = fclose(arquivo);
    if (sucesso != 0) {
        printf("ERRO AO ENCERRAR O ARQUIVO\n");
        exit(-1);
    }
    return 0;
}
```

## Leitura de Inteiros

Considere que, na mesma pasta no qual o código-fonte tenha um arquivo com nome `valores.txt` e **10** valores **separados por espaço**:
> valores.txt
```
0 1 2 3 4 5 6 7 8 9
```

> Código-fonte

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Número de valores armazenados no valores.txt
    int n = 10;
    int i;
    // Inicia um array alocado dinâmicamente com tamanho n
    int *valores = (int*) malloc(sizeof(int)*n); 

    // Cria a variável do tipo FILE* e abre o arquivo para leitura em seguida
    FILE *arquivo;
    arquivo = fopen("valores.txt", "r");

    if (arquivo == NULL) {
        printf("ERRO AO ABRIR O ARQUIVO\n");
        exit(-1);
    }

    // Faz a leitura do arquivo para encontrar os valores indicados pelo formato da string
    for (i = 0; i < n; i++) {
        fscanf(arquivo, "%d ", &valores[i]);
    }

    // Exibe os valores obtidos e armazenados anteriormente
    for (i = 0; i < n; i++) {
        printf("%d ", valores[i]);
    }
    printf("\n");

    int sucesso = fclose(arquivo);
    if (sucesso != 0) {
        printf("ERRO AO ENCERRAR O ARQUIVO\n");
        exit(-1);
    }

    // Libera os valores da memória
    free(valores);
    return 0;
}
```