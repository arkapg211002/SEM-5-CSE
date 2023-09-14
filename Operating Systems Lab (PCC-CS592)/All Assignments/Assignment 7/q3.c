/*
	Write a Program to create a child process. 
	The parent will send a signal to the child every 5 seconds and the child will handle the signal and 
	check if an input number is a leap year or not.

	13000121058
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<signal.h>
#include<fcntl.h>

int received=0;

void leap(int y)
{
	if(y%400==0) printf("Leap Year\n");
	else if(y%100!=0 && y%4==0) printf("Leap Year\n");
	else printf("Not Leap Year\n");
}

void custom_handler(int signum)
{
	received=1;
}

void main()
{
	int pid,n,i=1;
	signal(SIGCHLD,custom_handler);
	pid=fork();
	if(pid==-1)
	{
		perror("fork");
		exit(1);
	}
	if(pid==0)
	{
		printf("Child process with PID : %d and PPID : %d started..\n",getpid(),getppid());
		while(1)
		{
			pause();
			if(received==1)
			{
				printf("Child Process %d : Enter year to check leap year or not : ",getpid());
				scanf("%d",&n);
				leap(n);
				received=0;
			}
		}
	}
	else
	{
		printf("Parent process with PID : %d started..\n",getpid());
		while(i==1)
		{
			sleep(5);
			printf("Enter 1 to continue : ");
			scanf("%d",&i);
			if(i==0) continue;
			printf("Parent sending signal to child with PID %d ..\n",pid);
			kill(pid,SIGCHLD);
		}
	}
}
