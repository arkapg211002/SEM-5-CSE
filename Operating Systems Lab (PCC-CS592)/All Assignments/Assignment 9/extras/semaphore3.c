/*

WAP to achieve synchronization among multiple threads. The threads try to acquire resource that has two instances.

*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>

void *func();
sem_t s;
int shared=0;
void main()
{
	int num,i;
	sem_init(&s,0,2);
	printf("Enter the number of threads : ");
	scanf("%d",&num);
	getchar();
	pthread_t t[num];
	for(i=0;i<num;i++) pthread_create(&t[i],NULL,func,NULL);
	for(i=0;i<num;i++) pthread_join(t[i],NULL);
	printf("Default thread ends\n");
}

void *func(void *input)
{
	int n;
	sem_wait(&s);
	n=shared;
	printf("Thread %d and %ld\n",n,pthread_self());
	shared+=1;
	sleep(1);
	sem_post(&s);
	printf("Thread %d and %ld finishes\n",n,pthread_self());
}

