/*

basic thread creation.
Usage: pthread_create()

*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

void *customthread()
{
	int i;
	for(i=0;i<15;i++)
	{
		printf("%d. Hello from custom thread.\n",i);
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
		printf("%d. Hello from default thread.\n",i);
		sleep(1);
	}
}
