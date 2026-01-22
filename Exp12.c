#include <stdio.h>
#include <pthread.h>

// Thread function
void* printMessage(void* arg) {
    int thread_id = *(int*)arg;
    printf("Hello from Thread %d\n", thread_id);
    return NULL;
}

int main() {
    pthread_t threads[3];
    int thread_ids[3];
    int i;

    // Create threads
    for (i = 0; i < 3; i++) {
        thread_ids[i] = i + 1;
        pthread_create(&threads[i], NULL, printMessage, &thread_ids[i]);
    }

    // Wait for threads to finish
    for (i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All threads have finished execution.\n");
    return 0;
}
