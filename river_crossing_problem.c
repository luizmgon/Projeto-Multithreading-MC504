#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <time.h>

#define N_HACKERS 4
#define N_SERFS 4

// Variáveis globais do problema.
pthread_barrier_t barrier;
sem_t mutex;
sem_t serf_queue;
sem_t hacker_queue;
int hackers = 0;
int serfs = 0;

// Ação de embarque dos personagens no barco.
void board(char category)
{
    if (category == 's')
    {
        printf("-----------Embarcou um microsofter--------------\n\n");
    }
    else
    {
        printf("-----------Embarcou um hacker-----------------\n\n");
    }
}

// Ação de partida do barco.
void rowBoat()
{
    sleep(1);
    printf("O barco partiu\n\n");
    sleep(1);
}

// Chegada de um novo Microsofter na fila.
void newSerfArrived()
{
    serfs += 1;
    printf("Chegou um microsofter\n\n");
}

// Chegada de um novo Hacker na fila.
void newHackerArrived()
{
    hackers += 1;
    printf("Chegou um hacker\n\n");
}

// Thread de comportamento dos Microsofters.
void *thread_serfs()
{
    int is_captain = 0;
    sem_wait(&mutex);

    newSerfArrived();

    if (serfs == 4)
    {
        for (int i = 0; i < 4; i ++)
            sem_post(&serf_queue);
        serfs = 0;
        is_captain = 1;
    }
    else if ((serfs == 2) && (hackers >= 2))
    {
        for (int i = 0; i < 2; i ++){
            sem_post(&serf_queue);
            sem_post(&hacker_queue);
        }
        hackers -= 2;
        serfs = 0;
        is_captain = 1;
    }
    else
    {
        sem_post(&mutex);
    }

    sem_wait(&serf_queue);

    board('s');
    pthread_barrier_wait(&barrier);

    if (is_captain)
    {
        rowBoat();
        sem_post(&mutex);
    }
}

// Thread de comportamento dos Hackers.
void *thread_hackers()
{
    int is_captain = 0;
    sem_wait(&mutex);

    newHackerArrived();

    if (hackers == 4)
    {
        for (int i = 0; i < 4; i ++)
            sem_post(&hacker_queue);
        hackers = 0;
        is_captain = 1;
    }
    else if ((hackers == 2) && (serfs >= 2))
    {
        for (int i = 0; i < 2; i ++){
            sem_post(&hacker_queue);
            sem_post(&serf_queue);
        }
        serfs -= 2;
        hackers = 0;
        is_captain = 1;
    }
    else
    {
        sem_post(&mutex);
    }

    sem_wait(&hacker_queue);

    board('h');
    pthread_barrier_wait(&barrier);

    if (is_captain)
    {
        rowBoat();
        sem_post(&mutex);
    }
}

int main()
{
    // Inicialização de semáforos e barreiras.
    pthread_barrier_init(&barrier, NULL, 4);
    sem_init(&mutex, 0, 1);
    sem_init(&hacker_queue, 0, 0);
    sem_init(&serf_queue, 0, 0);

    // Inicialização das Threads.
    pthread_t thr_hackers[N_HACKERS];
    pthread_t thr_serfs[N_SERFS];

    int n_hackers_left = N_HACKERS;
    int n_serfs_left = N_SERFS;

    /*Correção do número de Hackers e Microsofters de entrada para evitar deadlock ao final da execução.

    Explicação:

    Existem duas condições que devem ser satisfeitas para que todos os Hackers e Microsofters
    completem a viagem:
    - Eles devem ser AMBOS múltiplos de 4.
    ou
    - Eles devem ser AMBOS pares mas não múltiplos de 4.

    Caso essas condições não sejam satisfeitas, sobrarão, ao final da execução, indivíduos que
    não formaram grupos para travessia e que ficariam eternamente aguardando.
    Por isso é feita essa correção de não colocá-los na fila e posteriormente é indicado
    quem não conseguiu atravessar.*/
    if (!(
            ((n_hackers_left % 4) == 0 && (n_serfs_left % 4) == 0) ||
            (((n_hackers_left % 2 == 0) && (n_serfs_left % 2 == 0)) && ((n_hackers_left % 4 != 0) && (n_serfs_left % 4 != 0)))))
    {
        if (n_hackers_left % 2 != 0)
        {
            n_hackers_left--;
        }
        if (n_serfs_left % 2 != 0)
        {
            n_serfs_left--;
        }
        if (!(
            ((n_hackers_left % 4) == 0 && (n_serfs_left % 4) == 0) ||
            (((n_hackers_left % 2 == 0) && (n_serfs_left % 2 == 0)) && ((n_hackers_left % 4 != 0) && (n_serfs_left % 4 != 0)))))
        {
            if (n_hackers_left > n_serfs_left)
                n_hackers_left -= 2;
            else
                n_serfs_left -= 2;
        }
    }

    int maximo = n_hackers_left > n_serfs_left ? n_hackers_left : n_serfs_left;

    int num;
    int p1, p2;
    double prob;
    int j = 0, k = 0;
    // Criação das Threads.
    prob = (double) rand() / RAND_MAX;
    for (int i = 0; i < n_serfs_left + n_hackers_left; i++)
    {
        prob = (double) rand() / RAND_MAX; // Gera um número aleatório entre 0 e 1

        if (prob < 0.5){ 
            if (j < n_hackers_left){
                num = rand() % 3 + 1; // gera um número aleatório entre 0 e 2, soma 1 para obter um número entre 1 e 3
                sleep(num);
                pthread_create(&thr_hackers[j], NULL, thread_hackers, NULL);
                j++;
            }
            else{
                num = rand() % 3 + 1; // gera um número aleatório entre 0 e 2, soma 1 para obter um número entre 1 e 3
                sleep(num);
                pthread_create(&thr_serfs[k], NULL, thread_serfs, NULL);
                k++;
            }
        }
        else{
            if (k < n_serfs_left){
                num = rand() % 3 + 1; // gera um número aleatório entre 0 e 2, soma 1 para obter um número entre 1 e 3
                sleep(num);
                pthread_create(&thr_serfs[k], NULL, thread_serfs, NULL);
                k++;
            }
            else{
                num = rand() % 3 + 1; // gera um número aleatório entre 0 e 2, soma 1 para obter um número entre 1 e 3
                sleep(num);
                pthread_create(&thr_hackers[j], NULL, thread_hackers, NULL);
                j++;
            }
        }
    }

    // Espera de finalização das Threads.
    for (int i = 0; i < maximo; i++)
    {
        if (i < n_hackers_left)
        {
            pthread_join(thr_hackers[i], NULL);
        }
        if (i < n_serfs_left)
        {
            pthread_join(thr_serfs[i], NULL);
        }
    }

    // Indicação dos indíviduos que foram removidos por não formarem grupos necessários para a travessia.
    for (int i = 0; i < (N_HACKERS - n_hackers_left); i++)
    {
        sem_post(&hacker_queue);
        printf("Um hacker não conseguiu atravessar\n\n");
    }

    for (int i = 0; i < (N_SERFS - n_serfs_left); i++)
    {
        sem_post(&serf_queue);
        printf("Um microsofter não conseguiu atravessar\n\n");
    }

    return 0;
}
