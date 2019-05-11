/* 
    Author     : abhijithvijayan
    Created on : 11 May 19, 13:39
    title      : Readers-Writers Problem
    Aim        : Program to illustrate Readers-Writers Problem
*/

#include <stdio.h>
#include <pthread.h>
// for rand
#include <stdlib.h>
// for sleep
#include <unistd.h>

pthread_t tId;
pthread_mutex_t readState, writeState;

int readerCount, writerCount;

void initialize()
{
    // initialize the mutex
    pthread_mutex_init(&readState, NULL);
    pthread_mutex_init(&writeState, NULL);
    readerCount = writerCount = 0;
}

void *reader(void *args)
{
    int waitTime;
    waitTime = rand() % 5;

    printf("\n[R] : Reader is trying to enter");

    // set read mutex to locked state
    pthread_mutex_lock(&readState);

    // increment read count
    ++readerCount;

    // give priority to reader on the first try by locking write mutex
    if (readerCount == 1)
    {
        pthread_mutex_lock(&writeState);
    }
    printf("\n--->  %d Reader(s) inside ", readerCount);

    // unlock reader mutex for other readers
    pthread_mutex_unlock(&readState);
    sleep(waitTime);

    printf("\n[R] : Reader %d is Leaving", readerCount);
    --readerCount;
    // if all readers left, unlock write mutex
    if (readerCount == 0)
    {
        pthread_mutex_unlock(&writeState);
    }
}

void *writer(void *args)
{
    int waitTime;
    waitTime = rand() % 3;

    printf("\n[W] : Writer is trying to enter");
    // lock write mutex
    pthread_mutex_lock(&writeState);

    ++writerCount;
    printf("\n--->  Writer %d has entered", writerCount);

    sleep(waitTime);
    // unlock write mutex
    pthread_mutex_unlock(&writeState);

    printf("\n[W] : Writer %d is leaving", writerCount);
    sleep(15);
}

void main()
{
    initialize();
    int readers, writers, i;
    printf("No of readers: ");
    scanf("%d", &readers);
    printf("No of writers: ");
    scanf("%d", &writers);
    // create threads
    for (i = 0; i < readers; ++i)
    {
        pthread_create(&tId, NULL, reader, NULL);
    }
    for (i = 0; i < writers; ++i)
    {
        pthread_create(&tId, NULL, writer, NULL);
    }
    sleep(15);
    printf("\n");
}