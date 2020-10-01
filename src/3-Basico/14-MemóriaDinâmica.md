# Memória Dinâmica

Até agora, durante o curso, trabalhamos apenas com variáveis alocadas na memória estática (AKA Stack), pelo compilador.
O C, por padrão, aloca 8Mb da memória ram para a memória stack do programa. Entretanto, muitas vezes esses 8Mb podem ser
ultrapassados, o que causa um erro bem famoso chamado Stack/Buffer Overflow, fazendo o seu programa finalizar a execução imediatamente, ainda podendo gerar uma grande falha de segurança. 
Se, por exemplo, você coleta uma string de um usuário através do scanf, ele poderia acabar com esse limite,
ou então em uma leitura de arquivo que fosse maior que 8Mb. 

É aí que entra a memória dinâmica, conhecida como Heap: através das funções malloc e calloc, disponíveis na stdlib.h, você pode alocar o tamanho que você precisar da heap e
acessa-la através de um ponteiro. 

E o uso dessa memória será muito importante para lidarmos com structs e estrutura de dados! 
Vamos ver como fica no código.

# malloc
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
	/* declaramos um ponteiro inteiro e atribuímos a ele
	 *  o endereço de memória retornado pela função malloc.
	 * Na função malloc, colocamos como parâmetro quantos bytes queremos alocar na heap.
	 * Usamos a função sizeof para passar o tamanho da variável, já que não podemos ter certeza do tamanho de cada variável, 
	 *já que isso pode mudar conforme o sistema.
	 */
	int *p = (int *) malloc(sizeof(int));
	
	/* Diferente da memória stack, os bytes alocados na heap não são liberados ao finalizar o programa,
	 * portanto devemos liberá-los de forma explícita
	 * assim que o programa parar de usar a variável que está alocada na heap,
	 * através da função free(), que recebe o ponteiro como parâmetro.
	 */
	free(p);
	return 0;
}

```
OBS:
O código abaixo compila, mas não é nada recomendável, pois
a função malloc retorna um ponteiro void*, e queremos atribuí-lo a
um ponteiro int*.
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
	// sem conversão do ponteiro retornado :0

	int *p = malloc(sizeof(int));

	free(p);

	return 0;
}
```
# Falha na Alocação
Podem ocorrer casos em que a alocação não é bem sucedida. Assim, a função malloc retorna NULL.
Usar um poteiro NULL irá resultar em erro no programa e não queremos que isso aconteça.
Assim, uma boa prática é criar uma condição para lidar com a alocação mal sucedida.
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
	// sem conversão do ponteiro retornado :0

	int *p = malloc(sizeof(int));

	if (p == NULL) {
		printf("Alocação mal sucedida!");
		exit(1);
	}
	else free(p);

	return 0;
}
```
# calloc
A função calloc faz o mesmo que o malloc, mas torna todos os bytes alocados iguais a zero.

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
	/* Calloc recebe como parâmetro, além do tamanho, o número de alocações. 
	 *  Se queremos alocar 3 inteiros, devemos chamar calloc(3, sizeof(int))
	 */
	int *p = (int *) calloc(1, sizeof(int));
	if (p == NULL) {
		printf("Alocação mal sucedida!");
		exit(1);
	}
	printf("%d\n", *p);

	free(p);
	return 0;
}
```
Ao compilar e executar, o programa irá mostrar no stdout o número 0.

# Criando arrays na heap 
Podemos criar um array na heap alocando múltiplos do tamanho da variável!

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
	/* Cria um array de 5 inteiros na heap
	 */

	int *nums = (int *) malloc(5*sizeof(int));
	if (p == NULL) {
		printf("Alocação mal sucedida!");
		exit(1);
	}
	free(p);

	return 0;
}
```

