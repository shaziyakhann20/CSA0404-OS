#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t *chopstick;
int N;

void* philosopher(void* arg) {
    int id = *(int*)arg;

    printf("Philosopher %d is thinking\n", id);
    sleep(1);

    sem_wait(&chopstick[id]);               // Pick left chopstick
    sem_wait(&chopstick[(id + 1) % N]);     // Pick right chopstick

    printf("Philosopher %d is eating\n", id);
    sleep(2);

    sem_post(&chopstick[id]);               // Put left chopstick
    sem_post(&chopstick[(id + 1) % N]);     // Put right chopstick

    printf("Philosopher %d finished eating\n", id);
    return NULL;
}

int main() {
    int i;
    printf("Enter number of philosophers: ");
    scanf("%d", &N);

    pthread_t philosopher_thread[N];
    int id[N];

    chopstick = (sem_t*)malloc(N * sizeof(sem_t));

    for (i = 0; i < N; i++) {
        sem_init(&chopstick[i], 0, 1);
        id[i] = i;
    }

    for (i = 0; i < N; i++) {
        pthread_create(&philosopher_thread[i], NULL, philosopher, &id[i]);
    }

    for (i = 0; i < N; i++) {
        pthread_join(philosopher_thread[i], NULL);
    }

    free(chopstick);
    return 0;
}
