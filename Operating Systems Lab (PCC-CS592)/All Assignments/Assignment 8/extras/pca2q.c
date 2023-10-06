/*
WAP c program to create 10 threads and display the prime numbers from 1 to N
*/

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

void *prime(void *input)
{
	int *x=input;
	int count=x[0];
	int start=x[1];
	int end=x[2];
	int i,j,c;
	printf("Inside Thread %d : Prime Numbers in the Range : %d -> %d\n",count,start,end);
	for(i=start;i<=end;i++)
	{
		if(i==1) continue;
		c=0;
		for(j=1;j<=i;j++)
		{
			if(i%j==0)c+=1;
		}
		if(c==2) printf("%d ",i);
	}
	printf("\n");
	pthread_exit(NULL);
}

void main()
{
	int n,step,rem,start,end;
	int input[3];
	pthread_t t;
	printf("Enter the number : ");
	scanf("%d",&n);
	getchar();
	step=n/10;
	rem=n%10;
	start=1;
	for(int i=0;i<10;i++)
	{
		input[0]=i+1;
		end=start+step-1;
		input[1]=start;
		input[2]=end;
		if(i==9) input[2]+=rem;
		pthread_create(&t,NULL,prime,(void *)input);
		pthread_join(t,NULL);
		sleep(1);
		start+=step;
	}


}
