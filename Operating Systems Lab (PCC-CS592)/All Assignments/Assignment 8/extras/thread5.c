/*

Passing single argument to thread

*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<string.h>

#define MAX 100

long int id;

void *customthread(void *input)
{
	printf("Hello from custom thread %ld.\n",pthread_self());
	printf("Input received from default thread %ld is %s\n",id,(char *)input);
	pthread_exit(NULL);
}

void main()
{
	pthread_t t;
	char ch[MAX];
	id=pthread_self();
	printf("I am deafult thread %ld\n",pthread_self());
	printf("Enter the string : ");
	scanf("%[^\n]",ch);
	getchar();
	pthread_create(&t,NULL,customthread,(void *)ch);
	pthread_join(t,NULL);
	printf("Default thread %ld ends.\n",id);
}
