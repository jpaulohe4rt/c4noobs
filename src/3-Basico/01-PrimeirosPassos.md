# 3.1 Primeiros Passos

Programas em C consitem em uma ou mais partes que declaramos como funções e com a extensão do arquivo em **.c** como está representado na imagem a baixo.

<p align="center">
    <img src="https://i.imgur.com/ta8FEqY.png" alt="C/C++">
</p>

## Comentários

Comentários são partes do código que não são interpretadas pelo compilador. Normalmente utilizamos para explicar alguma parte do código que pode não estar muito clara.

Para adicionar um comentário em seu  programa inicie a linha com /* e termine o seu comentário */ ou // para comentário simples.

```
// Este é um comentário simples
```

```
/* Este é um exemplo
    com múltiplas linhas
    em C */
```
Um programa C tem a seguinte estrutural geral:

```c
// importação de arquivos/bibliotecas externas
// e definição de elementos globais
#include <stdio.h>

// funções, aqui que a programação começa
int main()
{
    declaração de variáveis
    ...
    sentenças
    ...
}
```
### Mais um exemplo de um programa em C 

```c
#include <stdio.h>

int main(void)
{
    printf("Hello World\n");

    return 0;
}
```

# Compilar e Executar

A partir de agora, todo código que for exemplificado será compilado e executado segundo as seguintes linhas de comando:
> gcc nomeDoArquivo.c -o codigoCompilado -Wall

1. gcc
    * Compilador
2. nomeDoArquivo.c
    * Código fonte
3. -o codigoCompilado
    * Parâmetro que compila o código para o nome desejado(codigoCompilado)
4. -Wall
    * Parâmetro para dar mais avisos(warning) que podem indicar erros no código

> ./codigoCompilado

* Executa o codigoCompilado