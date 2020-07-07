# Matrizes

De acordo com a PUCRS: 

>Uma matriz é uma coleção de variáveis de mesmo tipo, acessíveis com um único nome e armazenados contiguamente na memória.
>A individualização de cada variável de um vetor é feita através do uso de índices.
>Os Vetores são matrizes de uma só dimensão.
>(Prof. Márcio Sarroglia Pinho)

Logo, uma matriz é um array de várias posições, portanto, também é um objeto.

Declaração de Matrizes:

```c
int vetor[5]; // declara um vetor de 5 posições
int matriz[4][4]; // declara uma matriz de 4 linhas e 4 colunas
```
Preencimento de vetor de 5 posições:

```c
for ( i = 0; i < 5; i++ )
{
    scanf ("%d", &vetor[ i ]);
}
```

Impressão de vetor de 5 posições:

```c
for ( i = 0; i < 5; i++ )
{
    printf ("%d", vetor[ i ]);
}
```

Preencimento de uma matriz 4x4:

```c
for ( i = 0; i < 4; i++ )
{
    for ( j = 0; j < 4; j++ )
    {
        scanf ("%d", &matriz[ i ][ j ]);
    }
}
```

Impressão de uma matriz 4x4:

```c
for ( i = 0; i < 4; i++ )
{
    for ( j = 0; j < 4; j++ )
    {
        printf ("%d", &matriz[ i ][ j ]);
    }
}
```