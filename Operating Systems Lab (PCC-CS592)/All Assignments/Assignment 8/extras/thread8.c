/*
Input n in main method. Display 0 to n using custom thread.
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

void *custom(void *input)
{
	int n=atoi(input);
	int i;
	printf("Custom thread %ld\n",pthread_self());
	for(i=0;i<=n;i++) printf("%d\n",i);
	pthread_exit(NULL);
}

void  main()
{
	pthread_t t;
	char ch[10];
	printf("Default thread %ld\n",pthread_self());
	printf("Enter number : ");
	scanf("%[^\n]",ch);
	getchar();
	pthread_create(&t,NULL, custom,(void *)ch);
	pthread_join(t,NULL);
	printf("Default thread %ld ends\n",pthread_self());
}
