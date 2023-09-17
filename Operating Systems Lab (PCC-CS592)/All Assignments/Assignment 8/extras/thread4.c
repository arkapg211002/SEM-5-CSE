/*

Usage: pthread_equal()

*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

void *customthread()
{
	printf("I am custom thread %ld\n",pthread_self());
}

void main()
{
	pthread_t t1,t2;
	pthread_create(&t1,NULL,customthread,NULL);
	pthread_create(&t2,NULL,customthread,NULL);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	if(pthread_equal(t1,t2)==0) printf("Two threads : %ld and %ld are not equal\n",t1,t2);
	else printf("Two threads : %ld and %ld are equal\n",t1,t2);
	printf("Program ends\n");
}
