#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];
int in = 0, out = 0, item = 0;
sem_t empty, full, mutex;

void* producer(void* arg) {
    int n = *(int*)arg;
    for (int i = 0; i < n; i++) {
        item++;
        sem_wait(&empty);
        sem_wait(&mutex);

        buffer[in] = item;
        printf("Producer produced item %d at index %d\n", item, in);
        in = (in + 1) % BUFFER_SIZE;

        sem_post(&mutex);
        sem_post(&full);
        sleep(1);
    }
    return NULL;
}

void* consumer(void* arg) {
    int n = *(int*)arg;
    for (int i = 0; i < n; i++) {
        sem_wait(&full);
        sem_wait(&mutex);

        int consumed = buffer[out];
        printf("Consumer consumed item %d at index %d\n", consumed, out);
        out = (out + 1) % BUFFER_SIZE;

        sem_post(&mutex);
        sem_post(&empty);
        sleep(1);
    }
    return NULL;
}

int main() {
    int n;
    printf("Enter number of items to produce/consume: ");
    scanf("%d", &n);

    pthread_t prod, cons;
    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);
    sem_init(&mutex, 0, 1);

    pthread_create(&prod, NULL, producer, &n);
    pthread_create(&cons, NULL, consumer, &n);

    pthread_join(prod, NULL);
    pthread_join(cons, NULL);

    return 0;
}
