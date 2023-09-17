/*
Deadlock using 2 threads
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<signal.h>

pthread_mutex_t first,second,third;

void custom_handler(int signum)
{
	printf("\n--- Interrupted due to deadlock ---\n");
	printf("Signal %d\n",signum);
	exit(0);
}
void *func1(void *);
void *func2(void *);
void *func3(void *);

void main()
{
	pthread_t t1,t2,t3;
	pthread_mutex_init(&first,NULL);
	pthread_mutex_init(&second,NULL);
	pthread_mutex_init(&third,NULL);
	pthread_create(&t1,NULL,func1,NULL);
	pthread_create(&t2,NULL,func2,NULL);
	pthread_create(&t3,NULL,func3,NULL);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	pthread_join(t3,NULL);
	printf("Default thread ends\n");
}

void *func1(void *arg)
{
	signal(SIGINT,custom_handler);
	printf("Thread 1 acquiring resource 1\n");
	pthread_mutex_lock(&first);
	printf("Thread 1 acquired resource 1\n");
	sleep(1);
	printf("Thread 1 trying to acquire resource 2\n");
	pthread_mutex_lock(&second);
	printf("Thread 1 acquired resource 2\n");
	pthread_mutex_unlock(&second);
	printf("Thread 1 released resource 2\n");
	pthread_mutex_unlock(&first);
	printf("Thread 1 released resource 1\n");
	pthread_exit(NULL);
}


void *func2(void *arg)
{
	signal(SIGINT,custom_handler);
	printf("Thread 2 acquiring resource 2\n");
	pthread_mutex_lock(&second);
	printf("Thread 2 acquired resource 2\n");
	sleep(1);
	printf("Thread 2 trying to acquire resource 3\n");
	pthread_mutex_lock(&third);
	printf("Thread 2 acquired resource 3\n");
	pthread_mutex_unlock(&third);
	printf("Thread 2 released resource 3\n");
	pthread_mutex_unlock(&second);
	printf("Thread 1 released resource 2\n");
	pthread_exit(NULL);
}


void *func3(void *arg)
{
	signal(SIGINT,custom_handler);
	printf("Thread 3 acquiring resource 3\n");
	pthread_mutex_lock(&third);
	printf("Thread 3 acquired resource 3\n");
	sleep(1);
	printf("Thread 3 trying to acquire resource 1\n");
	pthread_mutex_lock(&first);
	printf("Thread 3 acquired resource 1\n");
	pthread_mutex_unlock(&first);
	printf("Thread 3 released resource 1\n");
	pthread_mutex_unlock(&third);
	printf("Thread 3 released resource 3\n");
	pthread_exit(NULL);
}
