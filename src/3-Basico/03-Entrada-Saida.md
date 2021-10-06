# 3.4 Entrada e Saída.

Para que um programa em C mostre alguns resultados, ou que o programa peça algum tipo de dado ao usúario, precisamos utilizar funções existentes em C que são chamadas de `printf()` e `scanf()`. Lembrando que, é necessário utilizar no início do programa : `#include <stdio.h>` para que essas funções possam ser utilizadas.

## printf()

A função `printf()` exibe um ou mais dados na tela. contudo ele deve receber pelo menos dois parâmetros, separados por vírgula.

- Uma string que define, através de caracteres especiais, os dados a serem impressos e a suas posições na linha da impressão ou um dado a ser impresso.


### Exemplos:
Para imprimir string:

```c
printf("%s", "linguagemC");
```
- "%s": é a string para resgatar o valor que vai ser impresso
- "linguagemC": é o valor que vai ser impresso

É possível incluir um texto dentro de uma variável string de formato %s e será compilado de acordo com o que foi digitado no programa.

```c
printf("O jogador %s machucou o tornozelo", "Neymar");
```

Depois de ser compilado o resultado é:

```c
O jogador Neymar machucou o tornozelo
```

Você também pode inserir códigos especiais e alguns tipos de formatação no **printf()**.

## Tabela de Códigos Especiais:

|Código Especiais | Significado |
|-----------------| ------------
| \n| Nova linha |
| \t | Tabulação |
| \a | Beep - Toque do auto falante |
| \\\ | Barra invertida |
| \\" | Aspas duplas|

## Tabela de Formatação 

|Código Especiais | Significado |
|-----------------| ------------|
| %c | Imprime um caractere simples |
| %d | Imprime um número inteiro com sinal |
| %f | Imprime um ponto flutuante (número real) |
| %.3f | Imprime um ponto flutuante com 3 casas decimais |
| %o | Imprime um decimal como octal |
| %x | Imprime um decimal como hexadecimal |
| %s | Imprime uma string de caracteres |
| %% | Imprime um caractere % |
| %ld | Imprime um número inteiro longo com sinal |
| %p | ponteiro (endereço da memória) |
[Mais detalhes sobre formatação](http://www.cplusplus.com/reference/cstdio/printf/)

Exemplo:

```c
printf("Total de Funcionários: %d \n Lista de Funcionários: \n\t %s \n\t %s \n", 2, "Fulano de Tal", "Ciclano Beltrano");

//E será impresso

Total de Funcionários: 2
Lista de Funcionários:
	Fulano de Tal
	Ciclano d Beltrano
	
//No printf podemos fazer algo que não dá no scanf, utilizar %s em uma string com espaço, como no nome Ciclano Beltrano
//Podemos ver acima que para imprimir funciona, porém abaixo ensinarei um truque para leitura
```

## scanf()

A função é similar ao printf, os caracteres obtidos pelo **scanf()** são realizados pelo teclado. Este comando efetua uma leitura do teclado onde é esperada uma variável e o valor lido será armazenado no endereço da variável do programa. Para ficar mais claro segue o exemplo:


```c
#include <stdio.h>

int main(void){
    int a, b, soma; // declaração das variáveis de tipo inteiro

    printf("Digite um numero inteiro: ");
    scanf("%d", &a); //recebe um inteiro e armazena na variável a
  
    printf("Digite um numero inteiro: ");
    scanf("%d", &b); //recebe um inteiro e armazena na variável b
    soma = a + b;
    //Efetua adição de a com b e armazena na variável soma
    
    //scanf("%d %d", &a, &b); também pode ser feito, e mesmo que o usário insira o primeiro numero, aperte enter ou espaço 
    //e insira o segundo numero, funcionará. só não funcionará se colocar os dois numeros juntos, pois será lido como um só
  
    printf("O valor da soma = %d\n", soma); //Mostra mensagem com o resultado
  
    return 0;
}
```

Para a leitura de strings (conjunto de letras) com espaço entre elas, o segredo é usar um comando que diz ao computador para ler até o usuario apertar enter

```c
#include <stdio.h>

int main(void){
	char vetor[10];  		//nao tente entender vetor agora
	scanf("%[^\n]", vetor);	//nem porque nao foi usado &, explicaremos mais a frente
	//Dessa forma poderemos ler strings como "Ciclano Beltrano" sem qualquer problema
	//se tivessemos utilizado %s o computador teria lido somente o que estava a esquerda do espaço, o Ciclano
}

