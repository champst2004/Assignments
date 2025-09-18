#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

sem_t mutex, wrt;
int sharedvar = 99;
int readercount = 0;

void *reader(void *param) {
    int id = *((int *)param);
    sem_wait(&mutex);
    readercount++;
    if (readercount == 1) sem_wait(&wrt);
    sem_post(&mutex);
    printf("\nReader %d is reading sharedvar = %d", id, sharedvar);
    sem_wait(&mutex);
    readercount--;
    if (readercount == 0) sem_post(&wrt);
    sem_post(&mutex);
    printf("\nReader %d is done", id);
    return NULL;
}

void *writer(void *param) {
    int id = *((int *)param);
    printf("\nWriter %d is trying to enter", id);
    sem_wait(&wrt);
    printf("\nWriter %d has entered CS", id);
    sharedvar++;
    printf("\nWriter %d CHANGED sharedvar TO %d", id, sharedvar);
    sem_post(&wrt);
    printf("\nWriter %d is out of CS", id);
    return NULL;
}
