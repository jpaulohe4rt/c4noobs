# Switch e Break

## Switch

O comando **switch** é uma forma de reduzir a complexidade de vários if … else encadeados. O conteúdo de uma variável é comparado com um valor constante, e caso a comparação seja verdadeira, um determinado comando é executado.

```c
#include <stdio.h>

int main (void)
{
  int valor;
  
  printf ("Digite um valor de 1 a 7: ");
  scanf("%d", &valor);
  
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

<p align="center">
<img src="https://i.imgur.com/AweibTR.png">
</p>

## Break

Na linguagem C o **break** serve para dois usos, o primeiro é *forçar a saída* de um switch...case, assim como no exemplo a cima e para forçar a saída de um laço de repetição.

Se mais de uma condição for válida, é possivel unir os **case**, como se fosse um **if** com várias condições. Só que de uma forma diferente e bem melhor de ser entendida.
### Exemplo:
```c
#include <stdio.h>

int main (void)
{
  int valor;
  
  printf ("Digite um valor de 1 a 7: ");
  scanf("%d", &valor);
  
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