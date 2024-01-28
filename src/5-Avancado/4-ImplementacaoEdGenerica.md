# Implementando estruturas de dados genêricas em C

Neste Módulo, vamos aprender como implementar estruturas de dados genéricas em C, usando ponteiros para void e funções de comparação e liberação. Como exemplo vamos abordar a implementação de uma Hash Table, utilizando a técnica de encadeamento separado para lidar com colisões. A implementação completa está disponível em: [hsc hash separate chaining](https://github.com/hscHeric/hsc_hash_separate-chaining)
  
### 1) Motivação
As estruturas de dados são fundamentais para organizar e manipular informações de forma eficiente. No entanto, muitas vezes precisamos lidar com dados de tipos diferentes, como inteiros, strings, structs, etc. Como podemos criar estruturas de dados que possam armazenar qualquer tipo de dado, sem precisar reescrever o código para cada tipo?

A solução é usar estruturas de dados genéricas, que usam ponteiros para void para armazenar os dados, e funções de comparação e liberação para definir como os dados devem ser comparados e liberados da memória. Assim, podemos reutilizar o mesmo código para diferentes tipos de dados, bastando passar as funções adequadas como parâmetros.

### 3) Objetivos
- Aprender o conceito de estruturas de dados genéricas e suas vantagens e desvantagens
- Implementar uma tabela hash genêrica que aceite diferentes tipos de dados
  
### 4) Estruturas de dados
As estruturas de dados utilizadas são duas:

#### node_t

```c
typedef struct node_t {
  void *key;        // Ponteiro para a chave (geralmente um ponteiro para algum tipo de dado)
  size_t key_len;   // Tamanho da chave em bytes

  void *value;      // Ponteiro para o valor associado à chave
  size_t value_len; // Tamanho do valor em bytes

  struct node_t *next; // Ponteiro para o próximo nó na lista (encadeamento para implementar uma estrutura de dados como lista ligada)
} node_t;

```

A estrutura node_t representa um nó na tabela de hash com encadeamento separado. Ela foi projetada com flexibilidade para permitir o uso de qualquer tipo de dado como chave e valor, graças ao uso de ponteiros void *. Essa abordagem permite que diferentes tipos de dados, incluindo tipos personalizados, sejam usados como chave e valor na tabela de hash.

Esta flexibilidade é proporcionada pela utilização de ponteiros void * para os campos key (chave) e value (valor). Isso significa que qualquer tipo de dado da linguagem C pode ser utilizado como chave e valor na tabela de hash. Por exemplo, é possível empregar tipos básicos de dados (como inteiros, caracteres, etc.) ou até mesmo tipos de dados personalizados definidos pelo usuário.

#### hash_tab_t

A estrutura hash_tab_t é a estrutura principal que representa a tabela de hash com encadeamento separado. Essa estrutura foi projetada para oferecer flexibilidade e eficiência no armazenamento e recuperação de dados, permitindo o uso de qualquer tipo de dado como chave e valor.

```c
typedef struct hash_tab_t {
  node_t **buckets; // Ponteiro para um array de ponteiros de nós (representa os baldes ou buckets da tabela de hash)
  size_t size;      // Número total de buckets na tabela de hash
  int count;        // Número total de elementos armazenados na tabela de hash
  int (*hash_func)(void *, size_t, size_t);  // Ponteiro para a função de hash utilizada para calcular o índice do bucket
} hash_tab_t;

```

- `node_t **buckets:` É um vetor de ponteiros para nós (node_t) que serve como os buckets (compartimentos) da tabela de hash. Cada bucket armazena um ponteiro para o primeiro nó de uma lista encadeada, permitindo a manipulação eficiente de colisões.

- `size_t size:` Indica o tamanho total da tabela de hash, determinando o número de buckets disponíveis para distribuir os elementos.

- `int count:` Representa o número atual de elementos armazenados na tabela de hash. Esse valor é atualizado dinamicamente durante a inserção e remoção de elementos.

- `int (*hash_func) (void *, size_t, size_t):` É um ponteiro para uma função de hash personalizada ou a função de hash padrão. Essa função é responsável por calcular o índice onde um elemento será armazenado na tabela de hash, com base na chave fornecida. A flexibilidade dessa função permite a adaptação da tabela de hash para diferentes tipos de dados e tamanhos de tabela.

### Funções de inserção e remoção de dados genêricos 
Vamos focar em como adicionar e remover coisas de uma tabela de hash. Queremos que essa tabela seja capaz de lidar com diferentes tipos de informações, como números, palavras ou qualquer outra coisa. Vamos criar maneiras de colocar coisas nessa tabela (inserir) e tirar coisas dela (remover), e queremos que isso funcione para diferentes tipos de dados. Usaremos truques como ponteiros para funções e uma estrutura chamada node_t que pode armazenar diferentes tipos de informações. Isso nos permite construir uma tabela de hash que pode ser usada de maneira flexível para armazenar e recuperar informações, não importa que tipo elas sejam. Ao fazer isso, estamos criando ferramentas que podem ser usadas de muitas formas diferentes e são úteis para resolver diferentes tipos de problemas
Mais especificamente vamos analizar as seguintes funções:

#### Inicialização 
```c
/**
 * @brief Inicializa uma tabela de hash.
 * 
 * @param size Tamanho da tabela.
 * @param hash_func Função de hash, se NULL, usa a função de hash padrão.
 * @return hash_tab_t* Ponteiro para a tabela de hash.
 */
hash_tab_t *hash_tab_init(size_t size, int (*hash_func)(void *key, size_t keylen, size_t hash_tab_size));

/**
 * @brief Busca um nó na tabela de hash.
 * 
 * @param hash_table Tabela de hash.
 * @param key Chave do nó.
 * @param key_len Tamanho da chave.
 * @return void* Ponteiro para o valor do nó.
 */
void *hash_tab_search(hash_tab_t *hash_table, void *key, size_t key_len);

/**
 * @brief Insere um nó na tabela de hash.
 * 
 * @param hash_table Tabela de hash.
 * @param key Chave do nó.
 * @param key_len Tamanho da chave.
 * @param value Valor do nó.
 * @param value_len Tamanho do valor.
 * @return void* Ponteiro para o valor do nó.
 */
void *hash_tab_insert(hash_tab_t *hash_table, void *key, size_t key_len, void *value, size_t value_len);

/**
 * @brief Remover um nó da tabela de hash.
 * 
 * @param hash_table Tabela de hash.
 * @param key Chave do nó.
 * @param key_len Tamanho da chave.
 */
void hash_tab_remove(hash_tab_t *hash_table, void *key, size_t key_len);
```

#### hash_tab_init
A função hash_tab_init é responsável por criar e inicializar uma tabela de hash para armazenar elementos, sendo uma operação fundamental para utilizar a estrutura de dados de tabela de hash oferecida neste projeto.


```c
//Assinatura da função: hash_tab_t *hash_tab_init(size_t size, int (*hash_func)(void *key, size_t keylen, size_t hash_tab_size));


hash_tab_t *ht = hash_tab_init(100, NULL);
if (ht == NULL) {
    printf("Erro ao inicializar a tabela de hash!\n");
    // Lidar com o erro, se necessário
}
```
A Implementação é a seguinte: 
```c
 /**
 * Função de hash padrão para converter uma chave em um índice de bucket.
 * @param key Ponteiro para a chave.
 * @param key_len Tamanho da chave em bytes.
 * @param hash_tab_size Tamanho total da tabela de hash (número de buckets).
 * @return Índice do bucket calculado.
 */
static int default_hash_func(void* key, size_t key_len, size_t hash_tab_size){
    int sum = 0;
    for(int i = 0; i < (int) key_len; i++){
         sum += ((unsigned char *) key)[i] * (i + 1); // (i + 1) para evitar colisões entre palavras que são anagramas
    }

    return (sum % (int)hash_tab_size); // Retorna o resto da divisão da soma dos caracteres pela quantidade de buckets
}

/**
 * Inicializa uma tabela de hash.
 * @param size Tamanho total da tabela de hash (número de buckets).
 * @param hash_func Função de hash para calcular o índice do bucket.
 * @return Ponteiro para a tabela de hash inicializada ou NULL em caso de falha na alocação de memória.
 */
hash_tab_t *hash_tab_init(size_t size, int (*hash_func)(void *key, size_t key_len, size_t hash_tab_size)) {
  hash_tab_t *hash_tab = (hash_tab_t *)malloc(sizeof(hash_tab_t));
  if(hash_tab == NULL) {
    return NULL; // Erro ao alocar memória
  }

  hash_tab->buckets = (node_t**)malloc(sizeof(node_t*) * size);
  if(hash_tab->buckets == NULL) {
    free(hash_tab);
    return NULL; // Erro ao alocar memória
  }

  hash_tab->size = size;
  hash_tab->count = 0;

  // Inicializa os buckets com NULL
  for (int i = 0; i < (int) size; i++) {
    hash_tab->buckets[i] = NULL;
  }

  // Define a função de hash padrão se não fornecida
  if(hash_func == NULL){
    hash_tab->hash_func = &default_hash_func;
  } else {
    hash_tab->hash_func = hash_func;
  }

  return hash_tab;
}
```

A função default_hash_func é responsável por converter uma chave em um índice de bucket em uma tabela de hash. Ela opera sobre os bytes da chave, multiplicando cada byte por sua posição (incrementada por 1) para evitar colisões entre palavras que são anagramas. O índice do bucket é calculado como o resto da divisão da soma desses valores pela quantidade total de buckets na tabela de hash.

A função hash_tab_init cria e inicializa uma tabela de hash. Ela recebe o tamanho desejado da tabela (size) e uma função de hash opcional (hash_func). A alocação de memória é realizada para a estrutura hash_tab_t e para o array de ponteiros para nós (buckets). Os buckets são inicializados com valores nulos, e a função de hash padrão (default_hash_func) é utilizada se nenhuma função de hash for fornecida. A função retorna um ponteiro para a tabela de hash inicializada ou NULL em caso de falha na alocação de memória.

Essas funções são projetadas para serem genéricas, permitindo a manipulação de pares chave-valor de diferentes tipos de dados. Elas podem ser usadas como base para construir uma estrutura de dados flexível, capaz de armazenar e recuperar informações independentemente do tipo subjacente. Ao fornecer uma função de hash personalizada, é possível adaptar a tabela de hash para requisitos específicos da aplicação.

#### Inserção
```c
/**
 * Insere um par chave-valor em uma tabela de hash, permitindo o uso de estruturas genéricas.
 * @param hash_table Ponteiro para a tabela de hash onde inserir o par chave-valor.
 * @param key Ponteiro para a chave a ser inserida.
 * @param key_len Tamanho da chave em bytes.
 * @param value Ponteiro para o valor a ser inserido.
 * @param value_len Tamanho do valor em bytes.
 * @return Ponteiro para o valor inserido na tabela de hash ou NULL em caso de falha na alocação de memória.
 */
void *hash_tab_insert(hash_tab_t *hash_table, void *key, size_t key_len, void *value, size_t value_len) {
  // Calcula o índice do bucket usando a função de hash
  int index = default_hash_func(key, key_len, hash_table->size);

  node_t *next_node, *last_node;
  next_node = hash_table->buckets[index];
  last_node = NULL;

  // Procura se já existe um nó com a mesma chave
  while (next_node != NULL) {
    if (next_node->key_len == key_len) {
      // Se já existe um nó com a mesma chave, atualiza o valor
      if (memcmp(key, next_node->key, key_len) == 0) {
        if (next_node->value_len != value_len) {
          // Se o tamanho do valor é diferente, realoca a memória
          free(next_node->value);
          next_node->value = malloc(value_len);
          if (next_node->value == NULL) {
            return NULL; // Erro ao alocar memória para o novo valor
          }
        }
        // Copia o novo valor para o nó existente
        memcpy(next_node->value, value, value_len);
        next_node->value_len = value_len;
        return next_node->value; // Retorna o ponteiro para o valor atualizado
      }
    }
    last_node = next_node;
    next_node = next_node->next;
  }

  // Se não existe um nó com a mesma chave, cria um novo nó
  node_t *p_node = (node_t *)malloc(sizeof(node_t));
  if(p_node == NULL) {
    return NULL; // Erro ao alocar memória para o novo nó
  }

  // Aloca memória para a chave e o valor
  p_node->key = malloc(key_len);
  p_node->value = malloc(value_len);
  if (p_node->key == NULL || p_node->value == NULL) {
    // Erro ao alocar memória para a chave ou o valor
    free(p_node->key);
    free(p_node->value);
    free(p_node);
    return NULL;
  }

  // Copia a chave e o valor para o novo nó
  memcpy(p_node->key, key, key_len);
  memcpy(p_node->value, value, value_len);
  p_node->key_len = key_len;
  p_node->value_len = value_len;
  p_node->next = NULL;

  // Adiciona o novo nó ao final da lista encadeada no bucket correspondente
  if (last_node != NULL) {
    last_node->next = p_node;
  } else {
    hash_table->buckets[index] = p_node;
  }

  // Atualiza a contagem total de elementos na tabela
  hash_table->count++;
  return p_node->value; // Retorna o ponteiro para o valor inserido
}
```

vou analisar algumas partes específicas do código da função hash_tab_insert e explicar como funcionam:
```c
int index = default_hash_func(key, key_len, hash_table->size);
```
Nesta linha, a função de hash padrão (default_hash_func) é chamada para calcular o índice do bucket onde o novo nó será inserido. O índice é obtido considerando a chave, seu tamanho e o tamanho total da tabela de hash

```c
node_t *next_node, *last_node;
next_node = hash_table->buckets[index];
last_node = NULL;
```
Estas linhas inicializam ponteiros para os nós existentes no bucket (next_node) e para o último nó na lista encadeada (last_node). Isso é crucial para percorrer a lista e verificar se já existe um nó com a mesma chave.

```c
while (next_node != NULL) {
  if (next_node->key_len == key_len) {
    if (memcmp(key, next_node->key, key_len) == 0) {
      // Código para atualizar valor existente omitido
    }
  }
  last_node = next_node;
  next_node = next_node->next;
}
```
Este trecho percorre a lista encadeada no bucket para verificar se já existe um nó com a mesma chave. A função memcmp é utilizada para comparar as chaves e determinar se são iguais. Se uma chave igual for encontrada, o código para atualizar o valor existente é executado, mas foi omitido aqui para simplificar a explicação.

```c
node_t *p_node = (node_t *)malloc(sizeof(node_t));
if(p_node == NULL) {
  return NULL;
}
```
Essas linhas alocam dinamicamente memória para o novo nó. O tipo de dado genérico é usado para o ponteiro do nó (void*), e malloc é empregado para alocar memória do tamanho adequado.

```c
p_node->key = malloc(key_len);
p_node->value = malloc(value_len);
if (p_node->key == NULL || p_node->value == NULL) {
  // Código para tratamento de erro omitido
}
```
Aqui, memória é alocada para as chaves e valores do novo nó. O código trata de forma adequada situações em que a alocação de memória para chave ou valor falha, mas o código específico para tratamento de erro foi omitido por questões de brevidade.

```c
memcpy(p_node->key, key, key_len);
memcpy(p_node->value, value, value_len);
p_node->key_len = key_len;
p_node->value_len = value_len;
p_node->next = NULL;
```
Estas linhas realizam a cópia dos dados da chave e do valor para o novo nó, e os tamanhos são armazenados nos campos key_len e value_len, respectivamente. O campo next é definido como NULL porque o novo nó será o último na lista encadeada.

```c
if (last_node != NULL) {
  last_node->next = p_node;
} else {
  hash_table->buckets[index] = p_node;
}
```
Este bloco adiciona o novo nó à lista encadeada no bucket apropriado. Se last_node não for NULL, significa que já existem nós na lista, e o novo nó é adicionado ao final. Se last_node for NULL, significa que o bucket estava vazio, e o novo nó é atribuído diretamente ao bucket.

```c
hash_table->count++;
return p_node->value;
```

Por fim, a contagem total de elementos na tabela é atualizada, e o ponteiro para o valor inserido é retornado, possibilitando a manipulação do valor na aplicação que utiliza a tabela de hash.

#### Busca
```c
/**
 * Procura um valor associado a uma chave na tabela de hash.
 * @param hash_table Ponteiro para a tabela de hash onde realizar a busca.
 * @param key Ponteiro para a chave a ser procurada.
 * @param key_len Tamanho da chave em bytes.
 * @return Ponteiro para o valor associado à chave ou NULL se a chave não for encontrada.
 */
void *hash_tab_search(hash_tab_t *hash_table, void *key, size_t key_len) {
  // Calcula o índice do bucket usando a função de hash padrão
  int index = default_hash_func(key, key_len, hash_table->size);

  // Verifica se o bucket não está vazio
  if (hash_table->buckets[index] != NULL) {
    // Inicializa o ponteiro para o último nó na lista encadeada
    node_t *last_node = hash_table->buckets[index];

    // Percorre a lista encadeada
    while (last_node != NULL) {
      // Verifica se os tamanhos das chaves são iguais
      if (last_node->key_len == key_len) {
        // Compara as chaves byte a byte usando memcmp
        if (memcmp(key, last_node->key, key_len) == 0) {
          // Retorna o valor associado à chave se a chave for encontrada
          return last_node->value;
        }
      }

      // Move para o próximo nó na lista
      last_node = last_node->next;
    }
  }

  // Retorna NULL se a chave não for encontrada
  return NULL;
}
```
A função começa calculando o índice do bucket usando a função de hash padrão. Em seguida, ela verifica se o bucket correspondente não está vazio. Se o bucket estiver vazio, a função retorna NULL, indicando que a chave não foi encontrada na tabela de hash.

Se o bucket não estiver vazio, a função percorre a lista encadeada associada a esse bucket. Durante esse percurso, ela compara o tamanho da chave (key_len) com o tamanho da chave no nó atual. Se os tamanhos forem iguais, a função usa memcmp para comparar as chaves byte a byte. Se as chaves forem consideradas iguais, o valor associado a essa chave é retornado.

Se a função percorrer toda a lista encadeada sem encontrar a chave correspondente, ela retorna NULL, indicando que a chave não está presente na tabela de hash.

Essa função é fundamental para recuperar valores associados a chaves específicas na tabela de hash, tornando-a útil para consultas e operações de busca eficientes.

#### Remoção 
```c
/**
 * Remove um nó associado a uma chave na tabela de hash.
 * @param hash_table Ponteiro para a tabela de hash onde realizar a remoção.
 * @param key Ponteiro para a chave do nó a ser removido.
 * @param key_len Tamanho da chave em bytes.
 */
void hash_tab_remove(hash_tab_t *hash_table, void *key, size_t key_len) {
  // Inicializa ponteiros para os nós atual e anterior na lista encadeada
  node_t *next_node, *last_node;
  
  // Calcula o índice do bucket usando a função de hash padrão
  int index = default_hash_func(key, key_len, hash_table->size);

  // Inicializa next_node com o primeiro nó na lista encadeada do bucket
  next_node = hash_table->buckets[index];
  
  // Inicializa last_node como NULL, pois ainda não há nó anterior
  last_node = NULL;

  // Percorre a lista encadeada procurando o nó com a chave
  while (next_node != NULL) {
    if (next_node->key_len == key_len) {
      // Compara as chaves byte a byte usando memcmp
      if (memcmp(key, next_node->key, key_len) == 0) {
        // Libera a memória alocada para a chave e o valor do nó
        free(next_node->value);
        free(next_node->key);

        // Atualiza o ponteiro do nó anterior para "pular" o nó a ser removido
        if (last_node != NULL) {
          last_node->next = next_node->next;
        } else {
          // Se não há nó anterior, atualiza o ponteiro do bucket
          hash_table->buckets[index] = next_node->next;
        }

        // Libera a memória alocada para o nó
        free(next_node);
        break; // Sai do loop, pois o nó foi removido
      }
    }

    // Move para o próximo nó na lista
    last_node = next_node;
    next_node = next_node->next;
  }
}
```
A função hash_tab_remove tem como objetivo remover um nó associado a uma chave na tabela de hash. Inicialmente, calcula-se o índice do bucket usando a função de hash padrão, e os ponteiros next_node e last_node são inicializados para percorrer a lista encadeada. O loop de busca compara as chaves byte a byte utilizando memcmp, e se a chave desejada é encontrada, realiza-se a remoção do nó. Durante esse processo, a função libera de forma adequada a memória alocada para a chave, o valor e o próprio nó. Os ponteiros são atualizados para manter a integridade da lista encadeada, seja removendo um nó no meio da lista ou ajustando o ponteiro do bucket. Essa função assegura uma operação eficiente de remoção na tabela de hash, adequando-se dinamicamente às mudanças na estrutura da lista encadeada e garantindo a correta liberação de recursos.

#### Liberação 
```c
void hash_tab_free(hash_tab_t *hash_table) {
  node_t *next_node, *last_node;
  
  // Libera a memória de cada nó
  for (int i = 0; i < (int) hash_table->size; i++) {
    next_node = hash_table->buckets[i];
    while (next_node != NULL) { 
      free(next_node->key);
      free(next_node->value);
      last_node = next_node;
      next_node = next_node->next;
      free(last_node);
    }
  }
  free(hash_table->buckets);
  free(hash_table);
}
```

A função hash_tab_free desempenha um papel crucial na liberação de memória associada a uma tabela de hash e seus nós. Utilizando um loop, ela percorre cada bucket da tabela, liberando a memória alocada para as chaves e valores em cada nó da lista encadeada. O processo inclui a liberação de recursos dinâmicos e o ajuste dos ponteiros para garantir uma desalocação adequada. Após a conclusão desse processo para todos os buckets, a função libera a memória alocada para o array de buckets e, por fim, para a própria estrutura da tabela de hash. Essa função é crucial para evitar vazamentos de memória, garantindo a correta desalocação de todos os recursos associados à tabela de hash e seus elementos.

### Técnicas utilizadas
De forma resumida neste projeto, foram utilizadas as seguintes técnicas de programação em C:

- Uso de Ponteiros void para Genéricos*: A utilização de ponteiros do tipo void* permite a criação de estruturas de dados genéricas, permitindo o armazenamento e manipulação de diferentes tipos de dados na tabela de hash.
- Memcpy para Cópia Eficiente de Dados Genéricos: A função memcpy é empregada para realizar cópias eficientes de dados genéricos, sendo crucial para manipular estruturas heterogêneas de maneira flexível. Isso é especialmente útil na função de inserção (hash_tab_insert), onde se copiam chaves e valores para os nós da tabela.
- Memcmp para Comparação de Chaves Genéricas: A função memcmp é utilizada para comparar chaves genéricas, permitindo a busca eficiente na tabela de hash. Essa técnica é aplicada na função de busca (hash_tab_search), possibilitando a identificação de chaves iguais, independentemente do tipo de dado.
- Alocação Dinâmica e Liberação de Memória: A alocação dinâmica de memória é essencial para lidar com estruturas de dados genéricas. Utilizando malloc e free, é possível alocar e liberar memória de forma dinâmica para chaves, valores e nós na tabela de hash.
- Casting Adequado para Manutenção da Genericidade: O uso de castings apropriados, como (void*) e (int ()(void, size_t, size_t)), é essencial para garantir a compatibilidade e manutenção da genericidade ao longo do código.

### Referências:
[hscHeric - hsc_hash_separate-chaining](https://github.com/hscHeric/hsc_hash_separate-chaining)<br>

Kernighan, B. W., & Ritchie, D. M. (1988). The C Programming Language (2nd ed.). Prentice Hall.

Robbins, A., & Robbins, A. (2004). Unix systems programming: Communication, concurrency and threads (Vol. 2). Prentice Hall PTR.

[Manpage oficial da função memcpy](https://www.man7.org/linux/man-pages/man3/memcpy.3.html) <br>

[Manpage oficial da função memcmp](https://www.man7.org/linux/man-pages/man3/memcmp.3.html) <br>

