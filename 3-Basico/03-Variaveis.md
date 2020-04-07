## 3.3 Variáveis

Variável é uma referência de um valor que é armazenado na memória do sistema.
Ela pode ter o seu conteúdo alterado por um comando de atribuição.
Depois da atribuição feito pelo comando elas mudam de valor.

```c
int a,b, SomaGeral;
a = 3; // a recebe o valor 3
b = a * 2; // b recebe o dobro do valor de a 
c = a + b + 2; // c recebe 11
```

### Tipo de Variáveis

- Na Linguagem C todas as variáveis tem um tipo, esses tipos definem os valores que a variável pode armazenar e o quanto ocupa na memória do sistema.

| Tipo| Valores Aceitos |
| --- | --- |
| char   | letras e símbolos: 'a', 'B', '#', '^', '1', '9'|
| int | de -32767 até 32767 (apenas números inteiros) |
| float | 	de -3.4 x 1038 até +3.4 x 10+38com até 6 dígitos de precisão |
| double | de -1.7 x 10308 até +1.7 x 10+308com até 10 dígitos de precisão


### Declaração de Variáveis

- Devem ser declaradas antes de serem usadas
- Não há uma inicialização implícita na declaração

```c
#include <stdio.h> // Inicialização do arquivo de cabeçalho 

void main()
{ 
   int contador;            // declarações simples
   float PrecoDoQuilo;
   double TaxaDeCambio;
   char Nome;
   int TamanhoManoel, TamanhoJoao, TamanhoMaria;  // Pode colocar mais de uma variável na mesma linha 

   double  TaxaDeImportacao,
           TaxaDeEmbarque,
           TaxaDoBagagem,        // Também pode trocar de linha no meio
           TaxaDeCheckin;
}    
```
### Como inicializar uma variável de declaração

```c
#include <stdio.h> // Inicialização do arquivo de cabeçalho 
void main()
{ 
   int Peso = 0;            // declara a variável (int) e inicializa com Zero
   float PrecoDoPao = 10.53;    // declara a variável (float) e inicializa com 10.53
   double  TaxaDoImposto= 1.8,
           TaxaDoCobrador = 1.956,
           TaxaDeDeslocament0 = 1.75,              
}
```