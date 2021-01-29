# Structs
**Structs**, também conhecidas como **Registros**, definem um tipo de dado que agrupa outras variáveis dentro dele mesmo, como se fossem atributos daquela variável.

Por exemplo, eu posso criar um tipo de dado chamado **Pessoa** e posso definir que **Pessoa** têm ***idade***, ***altura*** e ***peso***

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct // Cria uma STRUCT para armazenar os dados de uma pessoa
{
    int idade;    // Define o campo idade
    float altura; // Define o campo altura
    float peso; // Define o campo peso
} Pessoa; // Define o nome do novo tipo criado. No caso, Pessoa
```
Dessa forma, nós acabamos de criar nosso próprio tipo de dado, e podemos definir variáveis do tipo **Pessoa**:
```c
int main() {
    
    Pessoa julio, heloisa; // Cria variáveis do tipo Pessoa (julio e heloisa)

    return 0;
}
```
Cada variável do tipo **Pessoa** têm campos dentro dela como a ***idade***, ***altura*** e ***peso***. Mas você me pergunta, como eu posso acessar esses campos? Muito simples! Basta utilizar a sintaxe **nomeDaVariavel.nomeDoCampo**:
```c
int main() {
    
    Pessoa julio, heloisa; 

    // Define os campos do julio
    julio.idade = 21;
    julio.altura = 1.70;
    julio.peso = 50.6;

    // Define os campos da heloisa
    heloisa.idade = 23;
    heloisa.altura = 1.60;
    heloisa.peso = 47;

    // Printa os dados do Julio
    printf("Dados do Julio:\n");
    printf("Idade: %d\n", julio.idade);
    printf("Altura: %.2f\n", julio.altura);
    printf("Peso: %.2f\n", julio.peso);

    // Printa os dados da Heloisa
    printf("\nDados da Heloisa:\n");
    printf("Idade: %d\n", heloisa.idade);
    printf("Altura: %.2f\n", heloisa.altura);
    printf("Peso: %.2f\n", heloisa.peso);

    return 0;
}
```
Também é possível definir um Array de **Pessoa**, como o exemplo a seguir:
```c
int main () {

    Pessoa listaDePessoas[5]; // Cria um Array do tipo pessoa

    // Conseguimos definir os campos da Pessoa utilizando o índice do Array
    listaDePessoas[0].idade = 32; // Define a idade da pessoa do índice [0]
    listaDePessoas[0].altura = 1.78; // Define a altura da pessoa do índice [0]
    listaDePessoas[0].peso = 67; // Define o peso da pessoa do índice [0]

    listaDePessoas[1].idade = 18; // Define a idade da pessoa do índice [1]
    listaDePessoas[1].altura = 1.67; // Define a altura da pessoa do índice [1]
    listaDePessoas[1].peso = 60; // Define o peso da pessoa do índice [1]

    // Como no exemplo anterior, aqui eu também consigo Printar os dados de cada pessoa no Array
    printf("Dados da pessoa do indice [0]:\n");
    printf("Idade: %d\n", listaDePessoas[0].idade);
    printf("Altura: %.2f\n", listaDePessoas[0].altura);
    printf("Peso: %.2f\n", listaDePessoas[0].peso);

    printf("\nDados da pessoa do indice [1]:\n");
    printf("Idade: %d\n", listaDePessoas[1].idade);
    printf("Altura: %.2f\n", listaDePessoas[1].altura);
    printf("Peso: %.2f\n", listaDePessoas[1].peso);

    return 0;
}
```
Também posso preencher o Array de outras formas mais eficientes, criando uma variável do tipo ***Pessoa***, atribuindo os dados a ela e definindo-a como parte da ***listaDePessoas***, dessa forma poderemos fazer um mini-programa de cadastro de Pessoas:
```c
// Esse é um simples programa de cadastro, nesse caso de no máximo 5 pessoas

#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int idade;    
    float altura;
    float peso; 
} Pessoa; 


int main () {
    
    Pessoa listaDePessoas[5]; // Definimos um Array de 5 posições
    int indice = 0; // Define um indice inicial para controlar a estrutura de repetição;

    Pessoa p; // Variável Pessoa apenas para armazenar os dados da Pessoa durante o cadastro
    
    printf("Bem-vindo ao cadastro de pessoas!\n\n");
    do 
    {
        printf("Digite a idade da pessoa %d: ", indice+1);
        scanf("%d", &p.idade);

        printf("Digite a altura da pessoa %d: ", indice+1);
        scanf("%f", &p.altura);

        printf("Digite o peso da pessoa %d: ", indice+1);
        scanf("%f", &p.peso);

        system("cls"); // Mude para system("clear") se estiver no Linux!

        listaDePessoas[indice] = p; // Armazena os dados de p dentro do Array

        indice++;
    } while(indice < 5);

    // Estrutura de repetição simples para mostrar os dados de todas as pessoas do Array
    for (indice = 0; indice < 5; indice++) {
        printf("\n\nDados da pessoa %d:\n", indice+1);
        printf("Idade: %d\n", listaDePessoas[indice].idade);
        printf("Altura: %.2f\n", listaDePessoas[indice].altura);
        printf("Peso: %.2f\n", listaDePessoas[indice].peso);
    }

    return 0;
}
```
**Structs** são muito importantes pois na linguagem C é o que mais se assemelha a um Objeto de uma linguagem Orientada a Objetos. Se você entender bem sobre **Structs**, terá maior facilidade na Programação Orientada a Objetos.

## Sugestão
Faça esse mesmo programa de cadastro de Pessoas, porém, adicione o campo ***nome*** no tipo de dado **Pessoa**. PS: Você terá que utilizar as funções da biblioteca **<string.h>** para manipular cadeias de caracteres (Strings) 
