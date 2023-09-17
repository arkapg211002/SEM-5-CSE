/*

WAP in c to implement IPC using Signal where the parent process will create a child process.
The parent will send a signal to the child after every 10 seconds.
Upon receiving the signal the child will take a string as input and print the result in aLtErNaTe case and will pause.
This will occur until a keyboard interrupt occurs from the user.

13000121058

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
#include<signal.h>

#define MAX 100
int received=0;

void child_handler(int signum)
{
	received=1;
}

void keyboard(int signum)
{
	printf("\n Interrupted \n");
	printf("The signal number is : %d \n",signum);
	exit(0);
}

void alternate(char ch[MAX])
{
	char res[MAX];
	int i,temp,j=0;
	printf("The input string is %s\n",ch);
	for(i=0;i<MAX && ch[i]!='\0';i++)
	{
		if(j%2!=0)
		{
			temp=(int)ch[i];
			if(temp>=65 && temp<=90)
			{
				res[i]=(char)temp;
				j+=1;
			}
			else if(temp>=97 && temp<=122)
			{	
				res[i]=(char)(temp-32);
				j+=1;
			}
			else
			{
				res[i]=(char)temp;
			
			}
		}
		else
		{
			temp=(int)ch[i];
			if(temp>=97 && temp<=122)
			{
				res[i]=(char)temp;
				j+=1;
			}
			else if(temp>=65 && temp<=90)
			{
				res[i]=(char)(temp+32);
				j+=1;
			}
			else
			{
				res[i]=(char)temp;
				
			}
		}
	}
	res[i]='\0';
	printf("The aLtErNaTe case for %s is %s \n",ch,res);
}

void main()
{
	int pid,i;
	char str[MAX];
	signal(SIGCHLD,child_handler);
	//signal(SIGINT,keyboard);
	pid=fork();
	if(pid==-1)
	{
		perror("fork");
		exit(1);
	}
	if(pid==0)
	{
		printf("Child process with PID : %d and PPID : %d running..\n",getpid(),getppid());
		while(1)
		{
			pause();
			if(received==1)
			{
				printf("Child process: Enter string : ");
				scanf("%[^\n]",str);
				getchar();
				alternate(str);
				received=0;
			}	
		}
	}
	else
	{
		signal(SIGINT,keyboard);
		printf("Parent process with PID : %d running ..\n",getpid());
		while(1)
		{
			sleep(10);
			printf("Parent sending signal to child with PID : %d\n",pid);
			kill(pid,SIGCHLD);
		}
	}
}
