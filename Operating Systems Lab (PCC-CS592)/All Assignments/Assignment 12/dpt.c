/*
Dining Philosophers' Problem using multithreading
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<semaphore.h>
#include<pthread.h>
#include<signal.h>

sem_t chopstick[5];

void *philosopher(void *input)
{
	int count=*((int *)input);

	printf("Philosopher %d wants to eat\n",count);
	printf("Philosopher %d tries to pick up left chopstick\n",count);
	
	sem_wait(&chopstick[count]);
	printf("Philosopher %d picks the left chopstick\n",count);
	printf("Philosopher %d tries to pick the right chopstick\n",count);
	
	sem_wait(&chopstick[(count+1)%5]);
	printf("Philosopher %d picks the right chopstick\n",count);
	
	printf("Philosopher %d is eating\n",count);
	sleep(2);
	printf("Philosopher %d finished eating\n",count);
	
	sem_post(&chopstick[(count+1)%5]);
	printf("Philosopher %d leaves the right chopstick\n",count);
	
	sem_post(&chopstick[count]);
	printf("Philosopher %d leaves the left chopstick\n",count);
	pthread_exit(NULL);
}

void custom_handler(int signum)
{
	int i;
	for(i=0;i<5;i++)
		sem_destroy(&chopstick[i]);
	exit(0);
}

void main()
{
	int i;
	signal(SIGINT,custom_handler);
	pthread_t t[5];
	int n[5];
	for(i=0;i<5;i++)
		sem_init(&chopstick[i],0,1);
	while(1)
	{
		for(i=0;i<5;i++)
		{
			n[i]=i;
			pthread_create(&t[i],NULL,philosopher,(void *)&n[i]);
		}
		for(i=0;i<5;i++)
			pthread_join(t[i],NULL);
	}
}
