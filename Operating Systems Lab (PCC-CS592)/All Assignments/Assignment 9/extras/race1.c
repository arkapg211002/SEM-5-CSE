/*
Race condition Example 1
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

void *func1(void *);
void *func2(void *);

int shared=1;

void main()
{
	pthread_t t1,t2;
	pthread_create(&t1,NULL,func1,NULL);
	pthread_create(&t2,NULL,func2,NULL);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	printf("Final value received from the two threads is %d\n",shared);
}

void *func1(void *input)
{
	int x=shared;
	printf("Inside first thread\n");
	printf("Value received in first thread is %d\n",x);
	x++;
	printf("After local updation in Thread 1 value is %d\n",x);
	sleep(1);
	shared=x;
	pthread_exit(NULL);
}

void *func2(void *input)
{
	int y=shared;
	printf("Inside second thread\n");
	printf("Value received in second thread is %d\n",y);
	y--;
	printf("After local updation in Thread 2 value is %d\n",y);
	sleep(1);
	shared=y;
	pthread_exit(NULL);
}
