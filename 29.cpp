#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 2

int sharedData = 0;
pthread_mutex_t mutex;

void *incrementThread(void *arg) {
    for (int i = 0; i < 5; ++i) {
        pthread_mutex_lock(&mutex);
        sharedData++;
        printf("Increment Thread: %d\n", sharedData);
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);
}

void *decrementThread(void *arg) {
    for (int i = 0; i < 5; ++i) {
        pthread_mutex_lock(&mutex);
        sharedData--;
        printf("Decrement Thread: %d\n", sharedData);
        pthread_mutex_unlock(&mutex);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    pthread_mutex_init(&mutex, NULL);

    pthread_create(&threads[0], NULL, incrementThread, NULL);
    pthread_create(&threads[1], NULL, decrementThread, NULL);

    for (int i = 0; i < NUM_THREADS; ++i) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&mutex);

    return 0;
}

