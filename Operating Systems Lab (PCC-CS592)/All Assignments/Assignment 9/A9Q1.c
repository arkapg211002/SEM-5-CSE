#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<semaphore.h>
sem_t mutex;
void *func1(void *arg)
{
	sem_wait(&mutex);
	printf("ba");
	sem_post(&mutex);
	pthread_exit(NULL);
}
void *func2(void *arg)
{
	sem_wait(&mutex);
	printf("ab");
	sem_post(&mutex);
	pthread_exit(NULL);
}

void main()
{
	pthread_t t1,t2;
	int i;
	sem_init(&mutex,0,1);
	for(i=0;i<3;i++)
	{
		pthread_create(&t1,NULL,func1,NULL);
		pthread_create(&t2,NULL,func2,NULL);
		pthread_join(t1,NULL);
		pthread_join(t2,NULL);
	}
	sem_destroy(&mutex);
	printf("\n");
}

