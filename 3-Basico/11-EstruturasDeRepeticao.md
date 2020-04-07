# Estruturas de Repetição

Os comandos de repetição são um recurso que permite que um certo trecho do código de um programa seja repetido um certo número de vezes.

Na liguagem C existem três comandos de repetição: while, do-while e for.

### While 

O While é uma estrutura que inicia olhando a condição de parada condição de parada, se a condição de parada já tiver sido atingida não entra no bloco de repetição, se não tiver atingido a condição de parada roda o que tem dentro das chaves e depois verifica a condição novamente. A variável que vai gerar a condição de parada precisa ser criada fora da estrutura.

```c
#include <stdio.h>
int main(void)
{
  int contador = 1; //declarando e inicializando a variável de controle
  
  while (contador <= 10) // Testando a condição
  {
    printf("%d ", contador); //Executando um comando dentro do laço
    
    contador++; //atualizando a variável de controle
  }  
  
  return 0;
}
```
### Saída
<p align="center">
    <img src="https://i.imgur.com/X600Nwh.png"  >
</p>

### For

O For é uma estrutura de repetição mais compacta, na qual, o bloco já determina aonde começa, a condição de parada e o passo dela (que é como essa variável se comportará para atingir a condição de parada), não é necessário declarar a váriavel antes, ela pode ser criada ao criar o for.

```c
//Exemplo1: Programa usando loop for em C
#include <stdio.h>

int main(void)
{
  int contador; //variável de controle do loop
  
  for(contador = 1; contador <= 20; contador++)
  {
    printf("%d ", contador);
  }
  
  return(0);
}
```
### Saída
<p align="center">
<img src="https://i.imgur.com/DAmRXIe.png">
</p>

### Do/While

O do/while é uma estrutura que inicia sem olhar nenuma condição de parada, roda o que tem dentro das chaves e depois verifica a condição. A variável que vai gerar a condição de parada precisa ser criada fora da estrutura.

```c
#include <stdio.h>
int main(void)
{
  float nota1=0,nota2=0,media=0;
  int resp;
  
  do
  {
    printf("Digite a primeira nota: ");
    scanf("%f",&nota1);
    printf("Digite a segunda nota: ");
    scanf("%f",&nota2);
    
    media = (nota1 + nota2)/2;
    printf("Media do aluno = %f\n",media);
    
    printf("Digite 1 para continuar ou 2 para sair\n");
    scanf("%d", &resp);
  
  }while (resp==1);
  
  return 0;
```
### Saída

<p align="center">
<img src="https://i.imgur.com/6sGB7Ye.png">
</p>
