#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

// Shared variables
sem_t mutex, wrt;
int sharedvar = 99;
int readercount = 0;

// Reader thread function
void *reader(void *param) {
    int id = *((int *)param);

    sem_wait(&mutex);
    readercount++;
    if (readercount == 1)
        sem_wait(&wrt);  // First reader blocks writers
    sem_post(&mutex);

    // Critical section for readers
    printf("\nReader %d is reading sharedvar = %d", id, sharedvar);

    sem_wait(&mutex);
    readercount--;
    if (readercount == 0)
        sem_post(&wrt);  // Last reader unblocks writers
    sem_post(&mutex);

    printf("\nReader %d is done", id);
    return NULL;
}

// Writer thread function
void *writer(void *param) {
    int id = *((int *)param);

    printf("\nWriter %d is trying to enter", id);
    sem_wait(&wrt);

    // Critical section for writers
    printf("\nWriter %d has entered CS", id);
    sharedvar++;
    printf("\nWriter %d CHANGED sharedvar TO %d", id, sharedvar);

    sem_post(&wrt);
    printf("\nWriter %d is out of CS", id);

    return NULL;
}

int main() {
    int n, i;
    printf("Enter the number of readers/writers: ");
    scanf("%d", &n);

    pthread_t readers[n], writers[n];
    int ids[n];

    sem_init(&mutex, 0, 1);
    sem_init(&wrt, 0, 1);

    for (i = 0; i < n; i++) {
        ids[i] = i + 1;
        pthread_create(&writers[i], NULL, writer, &ids[i]);
        pthread_create(&readers[i], NULL, reader, &ids[i]);
    }

    for (i = 0; i < n; i++) {
        pthread_join(writers[i], NULL);
        pthread_join(readers[i], NULL);
    }

    sem_destroy(&mutex);
    sem_destroy(&wrt);

    return 0;
}