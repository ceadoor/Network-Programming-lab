/* 
    Author     : abhijithvijayan
    Created on : 25 Feb 19, 09:51
    title      : Threads
    Aim        : Generation of Prime and Fibonacci series using threads
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>

// create array of two threads
pthread_t tID[2];

int limit;

void prime(int limit)
{
    int num, i;

    printf("Prime numbers between the limit\n");

    for (num = 2; num < limit; ++num)
    {
        for (i = 2; i <= (num / i); ++i)
            if (!(num % i)) // found prime
                break;

        if (i > (num / i))
        {
            printf("%d ", num);
        }
    }
}

void fib(int limit)
{

    int i;

    printf("Fibonacci series upto the limit\n");
    int calcFib(int n)
    {
        if (n <= 1)
            return n;
        return calcFib(n - 1) + calcFib(n - 2);
    }
    for (i = 0; i < limit; ++i)
    {
        printf("%d ", calcFib(i));
    }
}

// A normal C function that is executed as a thread
// when its name is specified in pthread_create()
void *primeNfib(void *arg)
{
    pthread_t id = pthread_self();

    if (pthread_equal(id, tID[0]))
    {
        printf("\nFirst thread %ld processing\n", id);
        prime(limit);
    }
    else
    {
        printf("\nSecond thread %ld processing\n", id);
        fib(limit);
    }
}

void main()
{   
    printf("Enter the limit: ");
    scanf("%d", &limit);
    int i = 0;
    while(i<2) {
        pthread_create(&(tID[i]), NULL, &primeNfib, NULL);
        pthread_join(tID[1], NULL);
        ++i;
    }
}