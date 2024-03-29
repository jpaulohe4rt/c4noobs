# 3.3 Variáveis

Variável é uma referência de um valor que é armazenado na memória do sistema.
Ela pode ter o seu conteúdo alterado por um comando de atribuição.
Depois da atribuição feito pelo comando elas mudam de valor.

```c
int a, b, c;
a = 3; // a recebe o valor 3
b = a * 2; // b recebe o dobro do valor de a 
c = a + b + 2; // c recebe 11
```


## Tipo de Variáveis

Na Linguagem C todas as variáveis tem um tipo, esses tipos definem os valores que a variável pode armazenar e o quanto ocupa na memória do sistema.

| Tipo | Valores Aceitos | Tamanho na Memória |
| --- | --- | --- |
| char   | letras e símbolos: 'a', 'B', '#', '^', '1', '9'| 1 byte |
| int | de -32767 até 32767 (apenas números inteiros) | 4 bytes |
| float | 	de -3.4 x 1038 até +3.4 x 10+38com até 6 dígitos de precisão | 4 bytes |
| double | de -1.7 x 10308 até +1.7 x 10+308com até 10 dígitos de precisão| 8 bytes |


## Declaração de Variáveis

- Devem ser declaradas antes de serem usadas.
- Não há uma inicialização implícita na declaração.


## Requisitos de Variáveis

Precisamos seguir alguns requisitos essenciais para manter o nosso código limpo e claro:

- Deve iniciar com uma letra ou com um "_".
- Tem que ter no máximo de 31 caracteres.
- Pode conter números a partir do segundo caracter.
- Recomendo separar minúsculas e maiúsculas para separar palavras: "he4rtDevelopers".
- Tem que usar nomes que sejam significativos e que façam sentido dentro do seu programa.
- Deve ser diferente dos comandos da linguagem.

Alguns exemplos válidos:

```
Cidade, Contador, LadoA, userName, User_1
```

Alguns exemplos inválidos:

```
123var, nome completo, #idade, double, break
```

Como ficam no código:

```c
#include <stdio.h> // Inicialização do arquivo de cabeçalho 

int main(void)
{ 
   int contador;                // declarações simples
   float PrecoDoQuilo;
   double TaxaDeCambio;
   char letra;
   char nome[10];               // Para declarar um vetor é necessário [] e dizer quantos caracteres ou inteiros caberá nele
   
   int TamanhoManoel, TamanhoJoao, TamanhoMaria;  // Pode colocar mais de uma variável na mesma linha 

   double  TaxaDeImportacao,
           TaxaDeEmbarque,
           TaxaDoBagagem,       // Também pode trocar de linha no meio
           TaxaDeCheckin;
}    
```


## Escopo de Variáveis

O local onde declaramos a variável define até onde ocorrerá seu funcionamento dentro do código.
Seus subtipos são: 

- Local - funciona somente no local que foi declarada, ou seja, dentro da função onde ela 'nasceu' e as funções dentro desta e se encerra quando a função acaba sua execução. Então toda vez que a função é chamada, a variável local surge e termina junto com a execução da função.

- Global - funciona em qualquer parte do código, é declarada em somente um local e pode ser utilizada em qualquer local das funções. Então sempre tenha muito cuidado ao utiliza-la, pois a alteração de seu conteudo pode ser feita em qualquer parte.
 
```c
#include <stdio.h> 

int global;		// É declarada antes de todas as outras funçoes e depois das bibliotecas

int main(void)
{ 

   int local;          // Declarada dentro da função, nesse caso o main(void) e poderá ser utilizada por tudo que está dentro dele
   			
   int funcao( int local )
   {
   	printf("%d \n", local);       // Se temos a variável local do main e a local da função, a prioridade é da variável da função
   	//e por mais que tenham o mesmo nome, alterar a local da função não altera a local do main, somente caso a da função não existisse
   	
   	printf("%d \n", global);     // A global funcionará pelo que foi dito anteriormente
   }
   
   //Por favor, não declarem 2 variáveis com o mesmo nome, fiquem atentos
   
}
```


### Como inicializar uma variável de declaração

```c
#include <stdio.h> // Inicialização do arquivo de cabeçalho

int main(void)
{ 
   int Peso = 0;            // declara a variável (int) e inicializa com Zero
   float PrecoDoPao = 10.53;    // declara a variável (float) e inicializa com 10.53
   double  TaxaDoImposto= 1.8,
           TaxaDoCobrador = 1.956,
           TaxaDeDeslocament0 = 1.75;
   int valores[] = {1, 2, 3, 4, 5, 6};    // declara o vetor de inteiros e atribui a seu tamanho a quantidade de elementos
   					   // que neste caso temos 6 elementos inicializados 
   					   
   char vetor[] = {"c4noobs"};		   // declarando vetor de letras e inicializa com uma string
}
```
O ruim desta forma de declaração é que não podemos fazer inclusões no vetor, e aumentar seu tamanho para receber mais conteúdo demanda um conhecimento avançado que traremos futuramente
