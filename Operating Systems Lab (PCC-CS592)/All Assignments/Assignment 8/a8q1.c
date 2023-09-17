/*

Write a C program in Linux to create a thread that determines the summation of N natural numbers using 
POSIX thread library

13000121058

*/

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int sum;

void *customthread(void *input)
{
	int n=*((int *)input);
	sum=(n*(n+1)/2);
	printf("\nHello from custom thread %ld\n",pthread_self());
	pthread_exit(&sum);
}

void main()
{
	pthread_t t;
	int n;
	void *res;
	printf("Hello I am Arka from default thread %ld\n",pthread_self());
	printf("Enter the number : ");
	scanf("%d",&n);
	getchar();
	printf("\nSending value of n to custom thread\n");
	pthread_create(&t,NULL,customthread,&n);
	pthread_join(t,&res);
	printf("The sum of %d natural numbers returned by custom thread is : %d\n",n,*((int *)res));
	printf("Default thread %ld ends\n",pthread_self());
}
