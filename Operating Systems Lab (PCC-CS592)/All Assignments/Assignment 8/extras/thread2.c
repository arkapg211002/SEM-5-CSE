/*

Usage: pthread_create() , pthread_join() , pthread_self()

*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

long int custom;

void *customthread()
{
	int i;
	custom=pthread_self();
	for(i=0;i<15;i++)
	{
		printf("%d. Hello from custom thread %ld.\n",i,pthread_self());
		sleep(1);
	}
	return NULL;
}

void main()
{
	pthread_t t;
	int i;
	int status;
	status=pthread_create(&t,NULL,customthread,NULL);
	if(status==0) printf("Thread created successfully\n");
	else printf("Error creating thread\n");
	for(i=15;i<=20;i++)
	{
		printf("%d. Hello from default thread %ld.\n",i,pthread_self());
		sleep(1);
	}
	pthread_join(t,NULL);
	printf("The custom thread %ld is done.\n",custom);
}
