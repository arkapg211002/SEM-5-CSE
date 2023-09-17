/*
Race condition example 2
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

int a=5,b=7;

void *add(void *input)
{
	a=a+3;
	b=b-1;
	printf("Inside Thread %d\n",*((int *)input));
	printf("value of a is %d\n",a);
	printf("value of b is %d\n",b);
	sleep(1);
	pthread_exit(NULL);
}

void main()
{
	pthread_t t1,t2,t3;
	int c=1;
	pthread_create(&t1,NULL,add,&c);
	c+=1;
	pthread_create(&t2,NULL,add,&c);
	c+=1;
	pthread_create(&t3,NULL,add,&c);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	pthread_join(t3,NULL);
	printf("Default thread ends\n");
}
