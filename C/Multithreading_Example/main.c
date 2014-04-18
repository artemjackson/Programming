#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <pthread.h>
#include <unistd.h>

/********************/

struct JobNode_t
{
    struct JobNode_t *next;
    int time;
};

typedef struct JobNode_t  JobNode;

/********************/

JobNode *queue;

/** Bad thread function without mutex */
void *threadFunc_1(void *arg)
{
    while(queue != NULL)
    {
        JobNode *nextJob = queue;
        queue = queue->next;
        usleep(nextJob->time);
        free(nextJob);
    }
    return NULL;
}

/**
*   MUTEX - MUTual EXception
*
*   Singnature:
*
*   pthread_mutex_t mutex mutex;    //  (1)
*   pthread_mutex_init(&mutex, NULL);   //  (2)
*
*   OR YOU CAN USE VARIENT (3) INSTED VARIENT (2) :
*
*   pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;   // (3)
*
*/

pthread_mutex_t queueMutex = PTHREAD_MUTEX_INITIALIZER;

/** Good thread function with mutex */
void *threadFunc_2(void *arg)
{
    while(1)
    {
        JobNode *nextJob;
        pthread_mutex_lock(&queueMutex);
        nextJob = queue;
        if(queue != NULL)
            queue= queue->next;

        pthread_mutex_unlock(&queueMutex);
        if(nextJob == NULL)
            break;

        usleep(nextJob->time);
        free(nextJob);
    }
    return NULL;
}

/********************/

int main()
{
    return 0;
}
