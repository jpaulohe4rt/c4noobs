# Programação Multithread



### 1) Definição
**Threads** são tarefas (tasks) que concorrem simultaneamente para execução na CPU. Isso significa que o programa pode realizar várias operações ao mesmo tempo. As threads ocupam espaço na memória do programa, tendo sua própria pilha (stack) e compartilhando todas as variáveis globais disponíveis no programa. Essas variáveis compartilhadas são chamadas de **seções críticas**.

A função **main** e todo o seu programa são executados por uma única thread. Quando não utilizamos programação multithread, temos apenas uma linha de execução, representada pela **thread main**. Como as threads estão dentro da área de memória do programa, se a main for finalizada, **TODAS** as demais threads também serão finalizadas, pois o kernel irá desalocar o programa da memória.

### 2) Como usar

Para utilizarmos a programação multithread, precisamos de uma biblioteca implementada para o sistema operacional, que permita o uso de threads. Em C, a biblioteca utilizada é a **pthreads** utilizando o **#include <pthread.h>**. Ela está disponível para Linux, macOS e Windows.

Para criar uma thread, utilizamos o tipo **pthread_t** no código, o que nos permite instanciar uma thread que pode ser inicializada ou configurada conforme necessário. Mais adiante, veremos como alterar algumas dessas configurações. Para inicializar a thread, utilizamos a função **pthread_create**, cujo protótipo é mostrado abaixo:

```c
int pthread_create(pthread_t *restrict thread,
                    const pthread_attr_t *restrict attr,
                    void *(*start_routine)(void *),
                    void *restrict arg);

/*
    A função irá retornar 0 se tiver sucesso,
caso contrario um valor do erro ocorrido
*/
```

O primeiro parâmetro `*restrict thread` é um ponteiro para  variável `pthread_t`.

O segundo parâmetro `*restrict attr` é ponteiro para variável do tipo `pthread_attr_t`, que serve para configurar algumas propriedades da thread. Se quisermos usar as configurações padrão, podemos passar **NULL** nesse parâmetro.

O próximo parâmetro, `*(*start_routine)(void *)`, é um ponteiro para a **função** que queremos que a thread inicie.

Por fim, o parâmetro `*restrict arg` é um ponteiro para a variável que será utilizada como **parâmetro** da função que será executada, caso não exista parâmetros, podemos passar **NULL** nesse parâmetro.

Abaixo podemos ver um código de exemplo:

```c
#include <stdio.h>
#include <pthread.h>

void *thread_run()
{
    printf("Ola mundo !!\nEu sou a Thread que acabou de nascer\n\n");
    return NULL;
}

int main()
{
    pthread_t thread;

    printf("Main criando e iniciando a Thread\n\n");
    pthread_create(&thread, NULL, thread_run, NULL);
    /*
            Execute esse programa com a linha abaixo comentada
        para observar alguns efeitos que ocorrem quando não existe
        a sincronização das Threads.
    */
    pthread_join(thread, NULL);

    printf("Main encerrando\n");
    return 0;
}
```
No exemplo acima, utilizamos a função `pthread_join()`. Essa função faz com que a `main` (ou qualquer outra thread) espere pela finalização da thread passada como argumento. Isso significa que a execução da `main` é interrompida até que a thread termine completamente a execução da função thread_run. Isso é necessário porque, como vimos, se a thread `main` finalizar ou morrer, todas as outras threads também serão finalizadas, interrompendo seu progresso de forma prematura.

#### 2.1) Retornos e Parâmetros

Como vimos, a função de execução da thread deve utilizar tipos **void**. Assim, podemos usar o `cast` para enviar os parâmetros como **void\*** e, dentro da função, fazer o `cast` para o tipo desejado que queremos manipular.

Abaixo, utilizando um exemplo semelhante ao anterior, iremos enviar e receber dados da nossa thread. Neste exemplo, enviaremos um int, e a thread retornará o valor multiplicado por 10. Como o retorno deve ser um ponteiro, não podemos retornar uma variável local da função, pois essa será removida da *stack* após o término da função. Para resolver isso, alocaremos memória dinamicamente para um int, armazenaremos o valor multiplicado por 10 e, em seguida, retornaremos esse ponteiro.

A função `pthread_join`, além de bloquear uma thread e esperar pela finalização de outra, também tem a capacidade de receber o retorno (um ponteiro para void*) da thread finalizada. No segundo parâmetro, passaremos um ponteiro para int, para que ele possa receber e armazenar o endereço com o resultado calculado na thread.

```c
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *thread_run(void *num)
{
    int *aux = (int *)malloc(sizeof(int));
    *aux = *(int *)num;
    *aux *= 10;
    printf("Vou retornar 10 vezes o meu ID\n\n");
    return aux;
}

int main()
{
    pthread_t thread;
    int thread_id = 5;
    int *thread_return;

    printf("Main criando e iniciando a Thread\n\n");
    pthread_create(&thread, NULL, thread_run, (void *)&thread_id);

    pthread_join(thread, (void **)&thread_return);
    printf("Thread retornou %d\n\n", *thread_return);

    printf("Main encerrando\n");

    return 0;
}
/* 
    Algumas boas práticas de programação foram
removidas para manter o código simples e mais legível.
    No entanto, é importante verificar o
retorno da função pthread_create e assegurar que a
alocação dinâmica foi bem-sucedida e utilizar free
para liberar a memória alocada.
*/
```

#### 2.2) Atributos de uma Thread

A tabela abaixo mostra alguns atributos que uma thread pode receber. Se você está começando seus estudos sobre threads, pode pular o tópico 2.1. Para aprender, é possível utilizar normalmente as threads com seus atributos configurados nos valores padrão (default)

| `Atributo` | `Função` | `Valor Padrão` | `Resultado` |
| :--: | :---: | :---: | :--: |
| scope | pthread_attr_setscope() | PTHREAD_SCOPE_PROCESS | Thread está desvinculada da LWP. |
| detachstate | pthread_attr_setdetachstate() | PTHREAD_CREATE_JOINABLE | O status de saída e a thread são preservados após o término do thread.  |
| stackaddr | pthread_attr_setstackaddr() | NULL | Thread possui endereço de pilha alocado pelo sistema. |
| stacksize | pthread_attr_setstacksize() | 1 megabyte  | Thread tem tamanho de pilha definido pelo sistema. |
| priority | pthread_attr_setschedparam() | | Thread herda a prioridade da thread mãe. |
| inheritsched | pthread_attr_setinheritsched() | PTHREAD_INHERIT_SCHED | Thread herda a prioridade de agendamento da thread mãe. |
| schedpolicy | pthread_attr_setschedpolicy() | SCHED_OTHER | Thread utiliza escalonamento de prioridade fixa definido pelo Solaris; as threads executam até serem preemptadas por uma thread de maior prioridade, ou até bloquearem ou cederem voluntariamente a execução.. |

Os atributos mencionados acima também podem ser obtidos através das funções **get**. Por exemplo, para a função `pthread_attr_setscope()`, existe a correspondente `pthread_attr_getscope()`. Todas as funções mencionadas possuem a sua respectiva versão *get*

Em todos os casos, utilizar **NULL** na função `pthread_create()` é equivalente a passar um atributo que foi inicializado sem modificações, através da função `pthread_attr_init()`. Essa função inicializa o atributo com todos os valores padrão.

### 3) Problemas com Threads
Como elas operam em simultaneidade em operações não atômicas isto é operações que podem ser interrompidas pela troca de contexto (programas) na CPU isto recebe o nome de preempção, nas quais voltam depois de um tempo ao processo, nesse meio tempo pode acontecer de outra thread executar e modificar os dados dessa operação não finalizada pela outra gerando inconsistências de dados e até mesmo o bloqueio de recurso, fazendo com que o programa entre em congelamento (deadlock), ficando uma thread a espera de outras e vice versa, fazendo com que nunca avancem do estado de aguardar, pra isso é necessário sincronização !!

### 4) Sincronização entre Threads

Embora existam vantagens em utilizar threads, muitos problemas podem ocorrer quando não são tomadas as devidas precauções e métodos adequados para operá-las. Um dos problemas comuns é a **condição de corrida** entre threads que compartilham recursos que não podem ser acessados simultaneamente. Para evitar isso, é necessária a sincronização do acesso, uso e liberação desses recursos, a fim de evitar *deadlock*, que ocorre quando as threads entram em um estado de bloqueio infinito. Outro problema é o acesso de múltiplas threads a regiões de memória e funções compartilhadas, criando o que chamamos de **seção crítica**. Isso pode ocorrer em variáveis ou funções que utilizam variáveis estáticas em sua implementação. Devido à preempção, há o risco de dados serem corrompidos ou da falta de sincronização levar a uma execução incorreta da lógica do programa.

#### 4.1) Mutex

Para resolver esses problemas, precisamos de travas que sejam executadas de forma atômica, ou seja, que não possam ser interrompidas durante o processo de travamento ou liberação. Essas travas garantem que as threads executem de forma coesa e também permitem que apenas uma thread permaneça em execução dentro de um trecho de código. A thread pode sofrer preempção, mas isso não afeta a sincronização, pois, enquanto a trava não for liberada, a thread será a única na **seção crítica**. Na implementação da POSIX (pthreads), essa trava é chamada de **mutex**

Para instanciar um mutex, utilizamos o tipo `pthread_mutex_t`, que deve ser inicializado posteriormente com a função `pthread_mutex_init()`. O protótipo da função está mostrado abaixo.

```c
int pthread_mutex_init(pthread_mutex_t *restrict mutex,
        const pthread_mutexattr_t *restrict attr);
```

Assim como as threads, os mutexes também possuem seus atributos. Se você deseja trabalhar com os valores padrão, pode utilizar **NULL** como segundo parâmetro na inicialização ou usar a constante `PTHREAD_MUTEX_INITIALIZER`. Como o mutex precisa ser acessado dentro da função da thread e geralmente é instanciado em outra função, é comum que eles sejam declarados como variáveis globais no programa.

Abaixo, temos um código que utiliza mutex. Neste caso, várias threads incrementam uma variável. Se não houver sincronização nessa seção crítica, podem ocorrer inconsistências devido à preempção em operações que não são atômicas.

```c
#include <stdio.h>
#include <pthread.h>

#define NUM_ITERATIONS  10000000
#define NUM_THREADS     5

/* Variável Critica, acesso simultâneo */
unsigned long counter = 0;

/* Mutex para sincronização das Threads */
pthread_mutex_t mutex;

void *increment_counter()
{
    unsigned long i;
    for (i = 0; i < NUM_ITERATIONS; i++)
    {
        /* Trava a seção critica */
        pthread_mutex_lock(&mutex); /* Comente para observar anomalias */
        counter++;
        /* Seção critica livre, mutex liberada */
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main()
{
    size_t i;
    pthread_t threads[NUM_THREADS];

    /* Inicializa a mutex */
    pthread_mutex_init(&mutex, NULL);
    /* Equivalente a "mutex = PTHREAD_MUTEX_INITIALIZER;" */

    /* Inicia threads e a condição de corrida entre elas */
    for (i = 0; i < NUM_THREADS; i++)
        pthread_create(threads + i, NULL, increment_counter, NULL);

    /* Aguarda finalização da threads sem receber retornos */
    for (i = 0; i < NUM_THREADS; i++)
        pthread_join(threads[i], NULL);

    /* Imprime resultado da variável global (seção critica) */
    printf("Valor final do contador: %lu\n", counter);

    /* Destrói a mutex */
    pthread_mutex_destroy(&mutex);

    return 0;
}
```

Como podemos observar no código acima, as funções `pthread_mutex_lock` e `pthread_mutex_unlock` são responsáveis por gerenciar o mutex, travando a seção crítica e liberando-a após o término do processo da thread. O **lock** tenta adquirir e travar a seção crítica. Se a seção já estiver travada, a thread que tentar entrar ficará em estado de espera, aguardando a liberação pelo escalonador do kernel (ou pelo processo implementado no sistema operacional). Quando ocorre o **unlock**, as threads em espera são despertadas e tentam novamente adquirir a seção crítica. Com isso, mantemos a sincronização e a consistência dos dados compartilhados.

No entanto, em condições de corrida, pode ocorrer starvation (fome), que acontece quando uma thread sempre perde na disputa pelo lock. Por exemplo, se uma thread conseguir executar rapidamente e retornar ao lock, ela poderá monopolizar a seção crítica até que o laço do `for` termine, fazendo com que a outra thread permaneça parada e sem progresso até que a primeira termine


### 5) Conclusão

Espero que você tenha gostado deste tutorial sobre programação multithread. Se tiver alguma dúvida, não hesite em entrar em contato comigo: [JulioRats](https://github.com/Julio-Rats)
