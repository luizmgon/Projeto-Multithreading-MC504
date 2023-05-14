#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>


#define N_hackers 10
#define N_serfs 12

pthread_barrier_t barrier;
pthread_barrierattr_t attr;
sem_t mutex;
sem_t serf_queue;
sem_t hacker_queue;
int hackers = 0;
int serfs = 0;

void board(char category){
    if (category == 's'){
        printf("-----------Embarcou um microsofter--------------\n\n");
    }
    else{
        printf("-----------Embarcou um hacker-----------------\n\n");
    }
}

void rowBoat(){
    printf("O barco partiu\n\n");
}

void *thread_serfs(){
    int is_captain = 0;
    sem_wait(&mutex);

    serfs += 1;
    printf("Chegou um microsofter\n\n");

    if (serfs == 4){
        sem_post(&serf_queue);
        sem_post(&serf_queue);
        sem_post(&serf_queue);
        sem_post(&serf_queue);
        serfs = 0;
        is_captain = 1;
    }
    else if ((serfs == 2) && (hackers >= 2)){
        sem_post(&serf_queue);
        sem_post(&serf_queue);
        sem_post(&hacker_queue);
        sem_post(&hacker_queue);
        hackers -= 2;
        serfs = 0;
        is_captain = 1;
    }
    else{
        sem_post(&mutex);
    }

    sem_wait(&serf_queue);

    board('s');
    pthread_barrier_wait(&barrier);

    if (is_captain){
        rowBoat();
        sem_post(&mutex);
    }
}

void *thread_hackers(){
    int is_captain = 0;
    sem_wait(&mutex);

    hackers += 1;
    printf("Chegou um hacker\n\n");

    if (hackers == 4){
        sem_post(&hacker_queue);
        sem_post(&hacker_queue);
        sem_post(&hacker_queue);
        sem_post(&hacker_queue);
        hackers = 0;
        is_captain = 1;
    }
    else if ((hackers == 2) && (serfs >= 2)){
        sem_post(&hacker_queue);
        sem_post(&hacker_queue);
        sem_post(&serf_queue);
        sem_post(&serf_queue);
        serfs -= 2;
        hackers = 0;
        is_captain = 1;
    }
    else{
        sem_post(&mutex);
    }

    sem_wait(&hacker_queue);

    board('h');
    pthread_barrier_wait(&barrier);

    if (is_captain){
        rowBoat();
        sem_post(&mutex);
    }
}


int main(){
    // Instanciando o problema inicial
    
    pthread_barrier_init(&barrier, &attr, 4);

    sem_init(&mutex, 0, 1);
    sem_init(&hacker_queue, 0, 0);
    sem_init(&serf_queue, 0, 0);

    pthread_t thr_hackers[N_hackers];
    pthread_t thr_serfs[N_serfs];

    int n_hackers_left = N_hackers;
    int n_serfs_left = N_serfs;

    while (!(((n_hackers_left % 4) == 0 && (n_serfs_left % 4) == 0) || (((n_hackers_left % 2 == 0) && (n_serfs_left % 2 == 0)) && ((n_hackers_left % 4 != 0) && (n_serfs_left % 4 != 0))))){
        if (n_hackers_left % 2 != 0){
            n_hackers_left--;
        }
        if (n_serfs_left % 2 != 0){
            n_serfs_left--;
        }
        if (!(((n_hackers_left % 2 == 0) && (n_serfs_left % 2 == 0)) && ((n_hackers_left % 4 != 0) && (n_serfs_left % 4 != 0)))){
            if (n_hackers_left > n_serfs_left)
                n_hackers_left -= 2;
            else
                n_serfs_left -= 2;
        }
    }
    int maximo = n_hackers_left > n_serfs_left ? n_hackers_left : n_serfs_left;


    printf("%d %d %d\n", maximo, n_hackers_left, n_serfs_left);
    for (int i = 0; i < maximo; i++){
        if (i < n_hackers_left){
            // sleep(1);
            pthread_create(&thr_hackers[i], NULL, thread_hackers, NULL);
        }
        if (i < n_serfs_left){
            // sleep(1);
            pthread_create(&thr_serfs[i], NULL, thread_serfs, NULL);
        }
    }

    for (int i = 0; i < maximo; i++){
        if (i < n_hackers_left){
            pthread_join(thr_hackers[i], NULL);
        }
        if (i < n_serfs_left){
            pthread_join(thr_serfs[i], NULL);
        }
    }


    for (int i = 0; i < (N_hackers - n_hackers_left); i++){
        sem_post(&hacker_queue);
        printf("Um hacker não conseguiu atravessar\n\n");
    }

    for (int i = 0; i < (N_serfs - n_serfs_left); i++){
        sem_post(&serf_queue);
        printf("Um microsofter não conseguiu atravessar\n\n");
    }

    // for (int i = 0; i < N_serfs; i++){
    // }

    // for (int i = 0; i < N_serfs; i++){
    // }

    return 0;

}