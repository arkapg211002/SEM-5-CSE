/*
WAP to pass two parameters to a thread. Find the sum of the two paramters and return it to the main thread
13000121058
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

int sum;

void *customthread(void *input)
{
	int *x=input;
	printf("Inside custom thread %ld\n",pthread_self());
	sum=x[0]+x[1];
	pthread_exit(&sum);
}

void main()
{
	int a[2];
	pthread_t t;
	void *res;
	printf("Inside the default thread %ld\n",pthread_self());
	printf("Enter the first number : ");
	scanf("%d",&a[0]);
	getchar();
	printf("Enter the second number : ");
	scanf("%d",&a[1]);
	pthread_create(&t,NULL,customthread,(void *)a);
	pthread_join(t,&res);
	printf("The sum of %d and %d is %d\n",a[0],a[1],*((int *)res));
	printf("Default thread %ld ends \n",pthread_self());
}
