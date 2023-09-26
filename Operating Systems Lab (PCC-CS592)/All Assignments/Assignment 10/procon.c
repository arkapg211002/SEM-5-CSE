#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include "buffer.h"
#include<time.h>
#include<unistd.h>

sem_t mutex;
sem_t empty;
sem_t full;

Buffer *buffer;
int shared=0;

void *producer(void *input)
{
	int item;
	while(1)
	{
		sem_wait(&empty);
		sem_wait(&mutex);
		srand(time(NULL));
		//item=shared;
		item=rand();
		printf("Producer added %d at index %d\n",item,(buffer->in));
		buffer_insert(buffer,item);
		sleep(1);
		//shared+=1;
		sem_post(&mutex);
		sleep(1);
		sem_post(&full);
	}
	pthread_exit(NULL);
}
void *consumer(void *input)
{
	int item,id;
	while(1)
	{
		sem_wait(&full);
		sem_wait(&mutex);
		id=buffer->out;
		item=buffer_delete(buffer);
		printf("Consumer displayed %d found at index %d\n",item,id);
		sem_post(&mutex);
		sleep(1);
		sem_post(&empty);
	}
	pthread_exit(NULL);
}

void main()
{
	int n;
	pthread_t producert,consumert;
	printf("Enter the size of the buffer : ");
	scanf("%d",&n);
	buffer=buffer_init(buffer,n);
	printf("%d %d %d\n",buffer->size,buffer->in,buffer->out);
	sem_init(&mutex,0,1);
	sem_init(&empty,0,(buffer->size));
	sem_init(&full,0,0);
	pthread_create(&producert,NULL,producer,NULL);
	pthread_create(&consumert,NULL,consumer,NULL);
	pthread_join(producert,NULL);
	pthread_join(consumert,NULL);
	buffer_destroy(buffer);
	sem_destroy(&mutex);
	sem_destroy(&full);
	sem_destroy(&empty);
	printf("\n");
}
