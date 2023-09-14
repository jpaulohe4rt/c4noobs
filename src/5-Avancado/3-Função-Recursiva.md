# Função recursiva

<p align="center">
    <img src="/src/imgs/recursao_drawing_hands_escher.png" alt="Drawing Hands (1948), M. C. Escher">
</p>

### 1) Definição
Em poucas palavras, uma **função recursiva é uma função que chama a si mesma**.

### 2) Quando usar
Em linguagem de programação, a recursão é uma ferramenta extremamente poderosa e sintética para resolver problemas menores que se repetem até que uma condição de encerramento seja atingida.

> :warning: McDowell, no livro "Cracking the coding interview", diz que "todo algoritmo recursivo também pode ser implementado iterativamente [...]"

Iterativamente significa _repetição_. Em termos práticos, isto significa utilizar uma estrutura de repetição, como um `for` ou um `while`, para resolver um problema. **Toda recursão pode ser "adaptada" para o uso de uma dessas duas estruturas de repetição**, conforme veremos no exemplo a seguir.

Contudo, tenha em mente que haverá situações nas quais fará mais sentido utilizar uma função recursiva em vez de uma estrutura de repetição. Por exemplo, ao percorrer elementos listados em uma estrutura de dados chamada árvore (_tree_).

### 3) Como usar

Uma função recursiva é composta de pelo menos duas partes:
* um caso base: situação em que a chamada da função recursiva é interrompida
* um caso recursivo: situação em que há a chamada da função recursiva para executar uma tarefa

### 4) Entendendo na prática

#### 4.1) Implementação de uma função de potência de forma iterativa

Na matemática, potenciação ou exponenciação é a operação que multiplica um número por ele mesmo várias vezes. Por exemplo, 2 elevado a 4 significa multiplicar 2 por ele mesmo quatro vezes (isto é, 2 * 2 * 2 * 2). O resultado desta multiplicação é 16.

Aqui, o passo a passo para realizar esta conta é:
* 2 = 2
* 2 * 2 = 4
* 4 * 2 = 8
* 8 * 2 = 16

> :warning: Lembre-se da exceção na potenciação: todo número elevado a zero é 1, assim como 0 elevado a 0 resulta em 1. Nós trataremos esta exceção no nosso código.

Perceba que a cada vez que realizamos a multiplicação, nós utilizamos o resultado desta como referência para a próxima conta. Assim, a nossa função receberá dois parâmetros: a **base**, isto é, o valor que queremos quero multiplicar, e o **expoente**, ou seja, por quantas vezes a base será multiplicada.

De forma iterativa, podemos implementar a potenciação em linguagem C da seguinte maneira:

```c
int	iterative_power(int base, int expoente)
{
	int	resultado;

	resultado = base;

	// Condição para fazer nosso programa aceitar somente números positivos
	if (base < 0)
		return (0);

	// Condição para a exceção da exponenciação
	if (base == 0 || expoente == 0)
		return (1);

	// Realização da conta de potenciação
	while (--expoente)
	{
		result *= base;
	}
	return (resultado);
}
```

Enquanto o expoente for diferente de zero, a estrutura de repetição `while` seguirá realizando a conta de potenciação. Cada vez que a conta é feita, subtraimos o valor do expoente em 1. Na prática, o fluxo de execução para o caso 2 elevado a 4 é o seguinte:

|Chamada do `while`| `resultado` | `expoente` | `base` |
|:----|:---|:---|:-----|
|1ª chamada|`2`|4 - 1 = **`3`**| `2` |
|2ª chamada|`4`|3 - 1 = **`2`**| `2` |
|3ª chamada|`8`|2 - 1 = **`1`**| `2` |
|4ª chamada|`16`|1 - 1 = **`0`**| `2` |

Quando o expoente for igual a zero, o `while` é interrompido e a nossa função retornará `resultado = 16`.

#### 4.2) Implementação de uma função de potência de forma recursiva

Perceba que nesta implementação, o código é quase o mesmo. Porém substituímos o laço de repetição `while` por uma função recursiva. Leve o tempo que for necessário para entender o código a seguir, na seção 5 estará o código completo para você compilar em sua máquina local.

```c
int	recursive_power(int base, int expoente)
{
	int	resultado;

	resultado = base;

	// Tratamento de exceção
	if (base < 0)
		return (0);

	// Tratamento de exceção
	if (base == 0 || expoente == 0)
		return (1);

	// CASO RECURSIVO
	if (expoente > 1)
		resultado = base * ft_recursive_power(base, expoente - 1);

	// CASO BASE
	// power é igual a 0. Não há mais multiplicações a fazer,
	// então ele para a chamada de função recursiva e retorna
	// o valor final da multiplicação
	return (resultado);
}
```

Assim como na implementação iterativa, aqui também ocorrerá quatro chamadas. Porém, desta vez da nossa função recursiva. Enquanto o expoente for maior que 1, a função recursiva será chamada. Na prática, isto aqui acontece:

```c
resultado = base * ft_recursive_power(base, 4 - 1) * ft_recursive_power(base, 3 - 1) * ft_recursive_power(base, 2 - 1) * ft_recursive_power(base, 1 - 1)
```

Em outras palavras, é como se resolvessemos a expressão a matémática a seguir: `resultado = 2 * {2 * [2 * (2 * 1)]}`, onde a última recursão que caiu no caso base devolve o seu resultado para a função anterior que a chamou. Por sua vez, esta devolve o valor para a anterior e assim por diante até que todas as funções recursivas sejam resolvidas.


### 5) Código completo com `main` para estudos e testes

Arquivo `main.c`

```c
#include <stdio.h>

int	iterative_power(int base, int expoente);
int	recursive_power(int base, int expoente);

int main(void)
{
	int	nb;
	int	power;

	nb = 2;
	power = 4;
	printf("O resultado é: %d\n", \
		iterative_power(nb, power));
	printf("O resultado é: %d\n", \
		recursive_power(nb, power));
	return (0);
} 

int	iterative_power(int base, int expoente)
{
	int	resultado;

	resultado = base;

	// Condição para fazer nosso programa aceitar somente números positivos
	if (base < 0)
		return (0);

	// Condição para a exceção da exponenciação
	if (base == 0 || expoente == 0)
		return (1);

	// Realização da conta de potenciação
	while (--expoente)
	{
		result *= base;
	}
	return (resultado);
}

int	recursive_power(int base, int expoente)
{
	int	resultado;

	resultado = base;

	// Tratamento de exceção
	if (base < 0)
		return (0);

	// Tratamento de exceção
	if (base == 0 || expoente == 0)
		return (1);

	// CASO RECURSIVO
	if (expoente > 1)
		resultado = base * ft_recursive_power(base, expoente - 1);

	// CASO BASE
	// power é igual a 0. Não há mais multiplicações a fazer,
	// então ele para a chamada de função recursiva e retorna
	// o valor final da multiplicação
	return (resultado);
}
```

### 6) Exercícios

Implemente em C duas funções: `fatorial_iterativo()` e `fatorial_recursivo()`. Ambas as funções recebem um número inteiro como parâmetro e devolvem o seu fatorial. Contudo, a primeira função calculará o fatorial de forma iterativa e, a segunda, de forma recursiva. Se não souber o que é um fatorial, pesquise. Faz parte da proposta do exercício.

### 7) Conclusão

Espero que tenha gostado deste tutorial sobre funções recursivas. Quaisquer dúvidas que você tiver, entre em contato comigo [Ygor Sena](https://github.com/ygor-sena)
