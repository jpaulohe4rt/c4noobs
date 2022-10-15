# Controle de Fluxo

Estruturas de Decisões são estruturas dentro da linguagem C que desviam os procedimentos do seu programa para uma **escolha**. Utilizamos muitas dessas estruturas quando queremos realizar testes, comparações ou redirecionar o nosso programa para outro caminho, dependendo da escolha do usuário. Existem **quatro** tipos de controle de fluxo, sendo elas:

## IF
A estrutura de decisão IF *(**se**, em inglês)* pode ser utilizada para verificar qual número é o maior, por exemplo. Você sempre deve atribuir uma condição dentro das chaves do IF, para que a condição possa ser verdadeira ou falsa.
```c
#include <stdio.h>

int main(void){

    int n1 = 10, n2 = 3, maior = 0; // Introduzimos o maior porque, conforme outros números superior a 0 apareçam, 
    // eles irão ser análisados pela estrutura de decisão.

    if(n1>n2){ // Aqui estamos inserindo uma decisão, perguntando se a variável n1 é maior que a n2.
        maior = n1; // Se a variável for maior, o programa irá acessar as chaves do IF 
        // e ler o trecho do código que está dentro dele, 
        // neste caso, irá atribuir o valor da variável n1 para a variável maior. Então, maior começará a ser 10.
    }

    printf ("%d\n", maior); // Aqui estamos exibindo na tela o maior número.

    return 0;
}
```
Utilizamos então o IF para verificar se o número 1 é maior que o número 2. No exemplo de cima, o fato é verdadeiro, porque o número 1 vale 10 e o número 2 vale 9.

### Saída

```c
10
```

## IF & ELSE
A estrutura de decisão **IF** e **ELSE** *(**Caso contrário**, em inglês)* carregam decisões opostas nas estruturas de decisão. O programa irá ler primeiramente o IF, e caso ele seja falso, irá ler o ELSE. **Por obrigação, um ELSE sempre deve vir acompanhado e posterior a um IF**, mas um IF pode existir sem possuir um ELSE posterior a ele. 

```c
#include <stdio.h>

int main(void){

    int numero = 9; // Estamos definindo a variável numero com o valor de 9.

    if( numero > 10 ){
        printf ("O número é maior que 10.\n"); // Essa mensagem irá aparecer se a variável 'número' tiver 
        // o valor MAIOR que 10.
    }else{
        printf ("O número não é maior que 10.\n"); // Essa mensagem irá aparecer se a variável 'número' tiver 
        // o valor MENOR que 10.
    }

    return 0;
}
```

### Saída

```c
O número é maior que 10.
```

## ELSE IF
A estrutura de decisão **ELSE IF** *(**Caso contrário, se,** em inglês)*funciona igualmente a um IF, carregando uma condição entre os seus parenteses, diferentemente do ELSE, que caso o IF não seja verdadeiro, ele automaticamente é acessado. 
O **ELSE IF** deve ser utilizado obrigatoriamente: após um IF ser inserido, mas antes de um ELSE. 
Ele pode ser adicionado inúmeras vezes.

```c
#include <stdio.h>

int main(void){

    int numero1 = 12; // Aqui, definimos a variável número1 com o valor de 12.

    if( numero1 > 30 ){ // A condição aqui só pode ser acessada caso a variável número1 seja maior que 30, ou seja, 31,32,33...
        printf ("O número é maior que 30\n"); //Essa mensagem só irá aparecer caso o número seja maior que 30. 
        //Como não é, não entramos nessa condição, e respectivamente, essa mensagem não aparece.
    }
    else if ( numero 1 > 15 ){
        printf ("O número é maior que 15 e menor que 30.\n");
    }
    else if ( numero1 > 10 ){ // A condição aqui é se a variável numero1 contém o valor maior que 10.
        printf ("O número é maior que 10 e menor que 15.\n"); // Como o valor da variável numero1 é 12, 
        // então acessamos esse ELSE IF e essa mensagem é exibida na tela do usuário.
    }
    else { // Como a nossa variável já achou uma condição acessível, no caso o ELSE IF, esse ELSE não será lido.
        printf ("O número é menor que 10\n"); 
    }

    return 0;
}
```
### Saída

```c
O número é maior que 10 e menor que 15.
```

## OPERADOR TERNÁRIO
O **operador ternário** é uma forma 'resumida' de escrever um IF e um ELSE. Esse comando é utilizado numa simples linha, deixando o programa limpo visualmente, porque ao invés de escrevermos inúmeras chaves e condições para o *IF, ELSE IF e ELSE*, utilizamos:

```c
condição ? se a condição é verdadeira : se a condição é falsa;
```
Ou seja, daremos uma condição e introduziremos um sinal de interrogação (?) após a condição ser apresentada. Esse sinal de interrogação funciona como um IF. 
**Se a condição for verdadeira**, o bloco de código após o sinal de interrogação vai ser realizado. **Caso a condição seja falsa**, o bloco de código após os dois pontos será realizado.
Recomendamos a utilização do operador ternário quando queremos verificar algo simples, que custará apenas uma linha de código.
Por exemplo:
```c
#include <stdio.h>

int main(void){

    int salario = 2000;
    salario > 1200 ? printf ("O salário é superior a 1200.\n") : printf ("O salário é inferior a 1200.\n");
    /* Estamos colocando a condição perguntando se o salário é maior que 1200
        Se for superior, o 'printf' após o sinal de interrogação será exibido para o usuário
        Caso contrário, o 'printf' após os dois pontos será exibido para o usuário.

        Notem que o primeiro printf não possui ponto e vírgula (;) no final, isso é padrão na operação ternária.
    */
    return 0;
}
```
### Saída
```c
O salário é superior a 1200.
```

O operador ternário também serve para retornar valores e para atribuir valores.
```c
#include <stdio.h>

int main(void){
    
    int numero = 10;

    numero >= 0 ? numero = numero + 1 : numero = numero - 1;
    printf ("O novo número é %d\n");
}
```

### Saída

```c
11.
```

## SWITCH

O comando **switch** *(**trocar**, em inglês)* é uma forma de reduzir a complexidade de vários IF & ELSE encadeados. O conteúdo de uma variável é comparado com um valor constante, e caso a comparação seja verdadeira, um determinado comando é executado.
Os **case** *(**caso**, em inglês)* são as condições que o nosso **switch** irá acessar caso seja verdadeira. Caso a variável tenha o valor '1', o **case 1** será acessado. Caso a variável tenha o valor '2', o **case 2** será acessado, e assim por diante.
Todo **case** é acompanhado com um **break** dentro dele. Caso não haja um break, o programa irá entrar num **case** e não irá realizar mais nenhuma ação.

```c
#include <stdio.h>

int main (void)
{
  int valor;
  
  printf ("Digite um valor de 1 a 7: "); // Imagine que o usuário digite 2.
  scanf ("%d", &valor); 
  
  switch ( valor )
  {
    case 1 :
        printf ("Domingo\n");
        break;
    
    case 2 :
        printf ("Segunda\n");
        break;
    
    case 3 :
        printf ("Terça\n");
        break;
    
    case 4 :
        printf ("Quarta\n");
        break;
    
    case 5 :
        printf ("Quinta\n");
        break;
    
    case 6 :
        printf ("Sexta\n");
        break;
    
    case 7 :
        printf ("Sabado\n");
        break;
    
    //Se nenhum dos casos acima é verdadeiro, o default entra em ação
    default :
        printf ("Valor invalido!\n");
  }
  
  return 0;
}
```

### Saída:

```c
Segunda
```

## BREAK

Na linguagem C o **break** *(**parar**, em inglês)* serve para dois usos, o primeiro é **forçar a saída** do **case** que o **switch** possui, assim como no exemplo a cima e para forçar a saída de um laço de repetição.

Se mais de uma condição for válida, é possivel unir os **case**, como se fosse um **IF** com várias condições. Só que de uma forma diferente e bem melhor de ser entendida.
### Exemplo:
```c
#include <stdio.h>

int main (void)
{
  int valor;
  
  printf ("Digite um valor de 1 a 7: ");
  scanf ("%d", &valor);
  
  switch ( valor )
  {
    case 1 :
    case 7 :
        printf ("Final de semana\n");
        break;
    
    case 2 :    
    case 3 :    
    case 4 :    
    case 5 :
    case 6 :
        printf ("Dia da semana\n");
        break;
    
    //Se nenhum dos casos acima é verdadeiro, o default entra em ação
    default :
        printf ("Valor invalido!\n");
  }
  
  return 0;
}
```