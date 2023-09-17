/*

WAP to create threads while user wants. Inside each thread take year as input and check leap year or not. 
Use signal handling to end the program

*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<signal.h>
#include<pthread.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/wait.h>

#define MAX 100

void custom_handler(int signum)
{
	printf("\nInterrupted by signal %d\n",signum);
	printf("Default thread ends\n");
	exit(0);
}

void *custom_thread(void *input)
{
	int c=*((int *)input);
	int n;
	printf("Inside Custom thread %d\n",c);
	printf("Enter the year : ");
	scanf("%d",&n);
	getchar();
	if(n%400==0) printf("%d is Leap year\n",n);
	else if(n%100!=0 && n%4==0) printf("%d is Leap Year\n",n);
	else printf("%d is not leap year\n",n);
	pthread_exit(NULL);
}

void main()
{
	pthread_t t;
	int count=0;
	printf("Hello from default thread\n");
	signal(SIGINT,custom_handler);
	while(1)
	{
		pthread_create(&t,NULL,custom_thread,&count);
		pthread_join(t,NULL);
		count+=1;
	}
}
