/*
 
 Implement IPC between a parent and a child process where parent will 
 print a message received from the child, who will take the message as user input. 
 Use un-nnamed pipe for IPC.

 13000121058

*/

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

void main()
{
	int fd[2],n,len=0;
	char buffer[MAX];
	char input[MAX];
	pid_t p;
	pipe(fd);
	p=fork();
	if(p==-1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if(p==0)
	{
		printf("I am child. I am here to take to user input.\n");
		printf("Enter input\n");
		scanf("%[^\n]s",input);
		len=strlen(input);
		printf("Passing message to parent\n");
		write(fd[1],input,len+1);
	}
	else
	{
		wait(NULL);
		printf("I am parent. I received data from child\n");
		n=read(fd[0],buffer,MAX);
		write(1,buffer,n);
		printf("\n");
	}
}
