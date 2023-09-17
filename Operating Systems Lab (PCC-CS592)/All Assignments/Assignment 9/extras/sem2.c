/*
Race condition example 2 using semaphore
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>

int a=5,b=7;
sem_t s;
void *add(void *input)
{
	sem_wait(&s);
	a=a+3;
	b=b-1;
	printf("Inside Thread %d\n",*((int *)input));
	printf("value of a is %d\n",a);
	printf("value of b is %d\n",b);
	sleep(1);
	sem_post(&s);
	pthread_exit(NULL);
}

void main()
{
	pthread_t t1,t2,t3;
	int c=1;
	sem_init(&s,0,1);
	pthread_create(&t1,NULL,add,&c);
	sleep(1);
	c+=1;
	pthread_create(&t2,NULL,add,&c);
	sleep(1);
	c+=1;
	pthread_create(&t3,NULL,add,&c);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	pthread_join(t3,NULL);
	sem_destroy(&s);
	printf("Default thread ends\n");
}
