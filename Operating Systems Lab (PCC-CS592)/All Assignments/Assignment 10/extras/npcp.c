#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include "buffer.h"
sem_t mutex,empty,full;
Buffer *ptr;

int shared=0;

void *producer(void *arg)
{
	do{
	sem_wait(&empty);
	sem_wait(&mutex);
	//printf("Enter the element you want to produce: ");
	int n=shared;
	//scanf("%d",&n);
	buff_insert(ptr,n);
	printf("%d is successfully produced.\n",n);
	sleep(1);
	sem_post(&mutex);
	shared+=1;
	sleep(1);
	sem_post(&full);
	}while(1);
	pthread_exit(NULL);
}
void *consumer(void *arg)
{
	do{
	sem_wait(&full);
	sem_wait(&mutex);
	int n;
	n=buff_delete(ptr);
	printf("%d is successfully consumed.\n",n);
	sleep(1);
	sem_post(&mutex);
	sleep(1);
	sem_post(&empty);
	}while(1);
	pthread_exit(NULL);
}
int main()
{
	pthread_t th1,th2;
	ptr=(Buffer *)malloc(sizeof(Buffer *));
	buff_init(ptr,100);
	sem_init(&mutex,0,1);
	sem_init(&empty,0,ptr->size);
	sem_init(&full,0,0);
	
	pthread_create(&th1,NULL,producer,NULL);
	pthread_create(&th2,NULL,consumer,NULL);
	pthread_join(th1,NULL);
	pthread_join(th2,NULL);
	
	buff_destroy(ptr);
	sem_destroy(&mutex);
	sem_destroy(&full);
	sem_destroy(&empty);
	return 0;
}
