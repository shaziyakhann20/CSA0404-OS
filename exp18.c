#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>

sem_t empty, full;
int buffer;

void* producer(void* arg) {
    sem_wait(&empty);
    buffer = 1;
    printf("Produced item\n");
    sem_post(&full);
}

void* consumer(void* arg) {
    sem_wait(&full);
    buffer = 0;
    printf("Consumed item\n");
    sem_post(&empty);
}

int main() {
    pthread_t p, c;

    sem_init(&empty, 0, 1);
    sem_init(&full, 0, 0);

    pthread_create(&p, NULL, producer, NULL);
    pthread_create(&c, NULL, consumer, NULL);

    pthread_join(p, NULL);
    pthread_join(c, NULL);

    return 0;
}
