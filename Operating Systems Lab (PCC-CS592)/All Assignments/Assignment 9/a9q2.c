/*

WAP where a newly created thread will check if a number is prime or not , which is entered in the main thread

13000121058

*/

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void *customthread(void *input)
{
	int n=*((int *)input);
	int i,c=1;
	if(n==1)
	{
		printf("\nInside new thread %ld\n",pthread_self());
		printf("%d is neither prime nor composite\n",n);
		pthread_exit(NULL);
	}
	printf("\nInside new thread %ld\n",pthread_self());
	for(i=2;i<=n;i++)
	{
		if(n%i==0) c+=1;
	}
	if(c==2) printf("%d is prime\n",n);
	else printf("%d is not prime\n",n);
	pthread_exit(NULL);
}

void main()
{
	pthread_t t;
	int n;
	printf("In default main thread %ld\n",pthread_self());
	printf("enter the number : ");
	scanf("%d",&n);
	getchar();
	pthread_create(&t,NULL,customthread,&n);
	pthread_join(t,NULL);
	printf("\nDefault main thread %ld ends\n",pthread_self());
}	

