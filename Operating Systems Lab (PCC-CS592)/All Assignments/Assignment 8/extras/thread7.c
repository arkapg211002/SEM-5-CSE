/*

Custom thread prints from 0 to 4
Default thread prints from 20 to 24

*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

long int id;

void *custom()
{
	int i;
	printf("Hello from custom thread %ld.\n",pthread_self());
	for(i=0;i<5;i++)
	{
		printf("%d\tfrom custom thread\n",i);
	}
	pthread_exit(NULL);
}

void main()
{
	pthread_t t;
	int i;
	id=pthread_self();
	pthread_create(&t,NULL,custom,NULL);
	pthread_join(t,NULL);
	printf("Hello from the deafult thread %ld\n",id);
	for(i=20;i<=24;i++)
	{
		printf("%d\tfrom default thread\n",i);
	}
	printf("Program ends\n");
}
