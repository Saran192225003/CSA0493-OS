#include <stdio.h>
#include <pthread.h>

void *threadFunction(void *arg) {
    printf("Thread is running\n");
    return NULL;
}

int main() {
    pthread_t thread;
    
    // Creating a thread
    pthread_create(&thread, NULL, threadFunction, NULL);

    // Joining a thread
    pthread_join(thread, NULL);

    // Exiting a thread
    pthread_exit(NULL);

    return 0;
}

