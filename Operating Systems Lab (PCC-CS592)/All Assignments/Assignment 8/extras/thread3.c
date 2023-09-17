/*

Usage: pthread_exit()

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
		printf("%d.\tHello from custom thread %ld.\n",i,pthread_self());
		sleep(1);
		if(i==3)
			pthread_exit(NULL);
	}
}

void main()
{
	pthread_t t;
	int i,status=pthread_create(&t,NULL,customthread,NULL);
	if(status==0) printf("Custom thread created successfully.\n");
	else printf("Error creating thread.\n");
	for(i=15;i<25;i++)
	{
		printf("%d.\tHello from default thread %ld.\n",i,pthread_self());
		sleep(1);
	}
}
