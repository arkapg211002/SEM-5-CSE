/*
Simulate Producer Consumer problem using multithreading and semaphores
13000121058
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>
#include<signal.h>

#define buffer_size 5

sem_t mutex;
sem_t empty;
sem_t full;

int buffer[buffer_size];
int in=0;
int out=0;
int shared_val=0;

void custom_handler(int signum)
{
	printf("\n\nInterrupted by signal %d\n\n",signum);
	exit(0);
}

void *producer(void *input)
{
	int item;
	signal(SIGINT,custom_handler);
	while(1)
	{
		sem_wait(&empty);
		sem_wait(&mutex);
		item=shared_val;
		printf("Producer : Adding %d to the buffer\n",item);
		buffer[in]=item;
		in=(in+1)%buffer_size;
		sleep(1);
		sem_post(&mutex);
		shared_val+=1;
		sleep(1);
		sem_post(&full);
	}
	pthread_exit(NULL);
}

void *consumer(void *input)
{
	int item;
	signal(SIGINT,custom_handler);
	while(1)
	{
		sem_wait(&full);
		sem_wait(&mutex);
		item=buffer[out];
		printf("Consumer : Read from buffer -> %d\n",item);
		out=(out+1)%buffer_size;
		sleep(1);
		sem_post(&mutex);
		sleep(1);
		sem_post(&empty);
	}
	pthread_exit(NULL);
}

void main()
{
	pthread_t producert,consumert;
	sem_init(&mutex,0,1);
	sem_init(&empty,0,buffer_size);
	sem_init(&full,0,0);
	pthread_create(&producert,NULL,producer,NULL);
	pthread_create(&consumert,NULL,consumer,NULL);
	pthread_join(producert,NULL);
	pthread_join(consumert,NULL);
	sem_destroy(&mutex);
	sem_destroy(&full);
	sem_destroy(&empty);
}
