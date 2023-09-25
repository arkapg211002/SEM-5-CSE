#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void *prime(void *input)
{
	int n=*((int *)input);
	int c=0;
	int i;
	if(n==1) pthread_exit("Neither prime nor composite");
	for(i=1;i<=n;i++)
	{
		if(n%i==0) c+=1;
	}
	if(c==2) pthread_exit("PRIME");
	else pthread_exit("NOT PRIME");
}

void main()
{
	int n;
	pthread_t t;
	void *res;
	printf("Enter the number : ");
	scanf("%d",&n);
	getchar();
	pthread_create(&t,NULL,prime,&n);
	pthread_join(t,&res);
	printf("%d is %s\n",n,(char *)res);
}
