/*
Assignment 11 Server
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<signal.h>
#include<string.h>
typedef struct
{
	char res[100];
	int server_id;
	int client_id;
}sd;
sd *shared;

void custom_handler(int signum)
{
	int n=signum;
}

void main()
{
	key_t key=ftok("memory",67);
	char input[100];
	int i,len,flag=1;
	int shmid=shmget(key,sizeof(shared),0666|IPC_CREAT);
	signal(SIGCONT,custom_handler);
	if(shmid==-1) printf("Cannot Create Shared memory\n");
	shared=(sd *)shmat(shmid,(void *)0,0);
	strcpy(shared->res,"\0");
	shared->client_id=0;
	shared->server_id=getpid();
	printf("Server ID is : %d\n",shared->server_id);
	while(1)
	{
		pause();
		flag=1;
		strcpy(input,shared->res);
		printf("Server received : %s\n",input);
		if(strcmp(input,"exit")==0)
			break;
		else
		{
			len=strlen(input);
			for(i=0;i<len/2;i++)
			{
				if(input[i]!=input[len-i-1])
				{
					strcpy(shared->res,"Not Palindrome");
					flag=0;
					break;
				}
			}
			if(flag==1)
				strcpy(shared->res,"Palindrome");
			printf("Server sent : %s\n",shared->res);
			kill(shared->client_id,SIGCONT);
		}
	}
	shmdt(shared);
	shmctl(shmid,IPC_RMID,NULL);
}
