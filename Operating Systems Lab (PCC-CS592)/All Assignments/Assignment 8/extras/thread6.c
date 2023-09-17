/*

Multiple arguments to the thread

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>

#define MAX 100

long int id;

typedef struct
{
	char name[MAX];
	int age;
}args;

void *customthread(void *input)
{
	printf("\nHello I am custom thread %ld.\n",pthread_self());
	printf("I received the following inputs from default thread %ld.\n",id);
	printf("Name: %s\n",((args *)input)->name);
	printf("Age: %d\n",((args *)input)->age);
	pthread_exit(NULL);
}

void main()
{
	pthread_t t;
	char name[MAX];
	int age;
	args *person=(args *)malloc(sizeof(args));
	id=pthread_self();
	printf("Hello I am the default thread %ld.\n",id);
	printf("Enter the name : ");
	scanf("%[^\n]",name);
	getchar();
	printf("Enter the age : ");
	scanf("%d",&age);
	getchar();
	strcpy(person->name,name);
	person->age=age;
	pthread_create(&t,NULL,customthread,(void *)person);
	pthread_join(t,NULL);
	printf("Default thread %ld ends.\n",id);
}
