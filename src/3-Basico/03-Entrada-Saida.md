# 3.4 Entrada e Saída.

Para que um programa em C mostre alguns resultados, ou que o programa peça algum tipo de dado ao usúario, precisamos utilizar funções existentes em C que são chamadas de `printf()` e `scanf()`. Lembrando que, é necessário utilizar no início do programa : `#include <stdio.h>` para que essas funções possam ser utilizadas.


## printf()

A função `printf()` exibe um ou mais dados na tela. Contudo ele deve receber pelo menos dois parâmetros, separados por vírgula.

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
	
// No printf podemos fazer algo que não é possível no scanf, utilizar %s em uma string com espaço, como no nome Ciclano Beltrano
// Podemos ver acima que para imprimir funciona, porém abaixo ensinarei um truque para leitura
```


## scanf()

A função é similar ao printf, os caracteres obtidos pelo **scanf()** são realizados pelo teclado. Este comando efetua uma leitura do teclado onde é esperada uma variável e o valor lido será armazenado no endereço da variável do programa. Para ficar mais claro segue o exemplo:

```c
#include <stdio.h>

int main(void){
    int a, b, soma;   // declaração das variáveis de tipo inteiro

    printf("Digite um numero inteiro: ");
    scanf("%d", &a);   // recebe um inteiro e armazena na variável a
  
    printf("Digite um numero inteiro: ");
    scanf("%d", &b);   // recebe um inteiro e armazena na variável b
    
    soma = a + b;   // Efetua adição de a com b e armazena na variável soma
    
    //scanf("%d %d", &a, &b); também pode ser feito, e mesmo que o usário insira o primeiro numero, aperte enter ou espaço 
    //e insira o segundo numero, funcionará. Só não funcionará se colocar os dois numeros juntos, pois será lido como um só
  
    printf("O valor da soma = %d\n", soma);   // Mostra a mensagem com o resultado
  
    return 0;
}
```

- Para a leitura de strings (conjunto de letras) com espaço entre elas, o segredo é usar um comando que diz ao computador para ler até o usuario apertar enter

```c
#include <stdio.h>

int main(void){
	char vetor[10];		// Explicamos melhor um vetor mais a frente
	scanf("%[^\n]", vetor);	//e também porque nao foi usado &
	
	// Dessa forma poderemos ler strings como "Ciclano Beltrano" sem qualquer problema
	// Se tivessemos utilizado %s o computador teria lido somente o que estava a esquerda do espaço, o Ciclano
	
	printf("%s\n", vetor);		// Para o printf não é necessário %[^\n]
	
	return 0;
}
```


### fprintf() e sscanf()

Essas variação do printf() e do scanf() servem para "imprimir" dados em outra variável, arquivo, ou também na tela, de forma mais eficiente e rápida que algumas cópias.

```c
#include <stdio.h>

int main(void){
	int variavel1;
	char variavel2[10];
	
	scanf("%[^\n]", variavel2);		// Usuário entra com os números 123
	
	sscanf(variavel2, "%d", &variavel1)	// Passa o conteúdo da variável2 convertido para inteiro para a váriavel1
	
			// Caso o sscanf não tivesse sido usado, teriamos que programar o código para passar por cada casa do vetor variavel2, 
			//transformando de texto para inteiro, multiplicando pela casa decimal que representa e somando tudo na variavel1
			
	printf("%d\n", variavel1);		// A saída é 123
	
	// fprintf( *arquivo, "formatação", ...);
	// fprintf( stdout, "formatação", ...);
	
		// fprintf pega o que está em ... e passa para o primeiro parâmentro, sendo a formatação do tipo que está em ...
	
		// ... significa que podemos ter ddde 1 até mais variáveis
		// "formatação" de impressão tanto pode ser somente %d, %s, os dois juntos, com ou sem texto
		// *arquivo será ensinado mais a frente
		// stdout é a saída padrão de dados, em geral, o monitor, o terminal onde mandamos executar o código
		
	// sprintf(variavel2, "%d", &variavel1);	passa o que está na variável1 para a variável2
	
	
	// Porém com as variações do scanf teremos a passagem do que está no primeiro parâmetro para o terceiro da função
	
	
	// fscanf( *arquivo, "formatação", ...);
	// fscanf( stdin, "formatação", ...);
	
		// fscanf é o equivalente ao fprintf, porém para a leitura
		
		// "formatação" é como a do fprintf, porém utilizando os padrões de leitura
		// stdin significa a entrada padrão de dados, nesse caso o teclado
		
	return 0;
}
```
