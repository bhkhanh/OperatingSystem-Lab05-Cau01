/*#######################################
# University of Information Technology  #
# Operating System                      #
# Bui Huu Khanh - 18520897              #
# File: Semaphore.c                     #
#######################################*/
//condition: sells <= products <= sells + [2 so cuoi cua MSSV + 10]

#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>

int sells = 0;
int products = 0;

sem_t semaphoreee;

//sells function
void *processA_sells()
{
    while (1)
    {
        sem_wait(&semaphoreee);
        sells++;
        printf("Sells = %d \n", sells);
        //sleep(1);
    }
}

//products function
void *processB_products()
{
    while (1)
    {
        if (products <= sells + 97 + 10)
        {
            products++;
            printf("Products = %d \n", products);            
            sem_post(&semaphoreee);
            //sleep(0.2);
        }
    }
}

void main()
{
    sem_init(&semaphoreee, 0, 0);
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, &processA_sells, NULL);
    pthread_create(&thread2, NULL, &processB_products, NULL);
    while (1);
}