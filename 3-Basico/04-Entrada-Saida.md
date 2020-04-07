## 3.4 Entrada e Saída.

Para que um programa em C mostre alguns resultados, ou que o programa peça algum tipo de dado ao usúario, precisamos utilizar funções existes em C que são chamadas de **printf()** e **scanf().**. lembrando que é necessário ulitizar no início do programa : **#include**

#### printf()

A função **printf()** exibe um ou mais dados na tela. contudo ele deve receber pelo menos dois parâmetros, separados por vírgula.

- Uma string que define, através de caracteres especiais, os dados a serem impressos e a suas posições na linha da impressão ou um dado a ser impresso.


#### Exemplos:
para imprimir string:

```c
printf("%s, "linguagemc");
```
"%s": é a strinf de formato
"teste": é o dado que vai ser impresso

- É possível incluir um texto dentro de uma variável string de formotado e será compilado de acordo com o que foi digitado no programa.

```c
    printf("O jogador %s machucou o tornozelo", "Neymar");
```

Depois de ser compilado o resultado é:

```c
    O jogador Neymr machucou o tornozelo
```

Você também pode inserir códigos especiais e alguns tipos de formatação no **printf()**.

### Tabela de Códigos Especiais:

|Código Especiais | Significado |
|-----------------| ------------
| \n| Nova linha |
| \t | Tabulação |
| \a | Beep - Toque do auto falante |
| \\\ | Barra invertida |
| \\" | Aspas duplas|

### Tabela de Formatação 

|Código Especiais | Significado |
|-----------------| ------------|
| %c | Imprime um caractere simples |
| %d | Imprime um número inteiro com sinal |
| %f | Imprime um ponto flutuante (número real) |
| %s | Imprime uma string de caracteres |
| %% | Imprime um caractere % |
| %ld | Imprime um número inteiro longo com sinal |
| %p | ponteiro (endereço da memória) |

#### scanf()

A função é similar à printf, os caracteres obtidos pelo **scanf()** são realizados pelo teclado,
este comando efetua uma leitura do teclado onde é esperada uma variável e o valor lido será armazenado no endereço da variável do programa. para ficar mais claro segue o exemplo:


```c
#include <stdio.h>

int main(){
    int a, b, soma; // declaração das variáveis de tipo inteiro

    printf("Digite um numero inteiro: ");
    scanf("%d", &a); //recebe um inteiro e armazena na variável a
  
    printf("Digite um numero inteiro: ");
    scanf("%d", &b); //recebe um inteiro e armazena na variável b
    soma = a + b;
    //Efetua adição de a com b e armazena na variável soma
  
    printf("O valor da soma = %d\n", soma); //Mostra mensagem com o resultado
  

    return 0;
}
```

