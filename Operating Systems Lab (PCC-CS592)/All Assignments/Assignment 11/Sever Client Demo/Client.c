/*
Client for Assignent 11
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<fcntl.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/stat.h>
#include<sys/types.h>
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
	int shmid=shmget(key,sizeof(shared),0666|IPC_CREAT);
	signal(SIGCONT,custom_handler);
	if(shmid==-1) printf("Cannot connect to the shared memory\n");
	shared=(sd *)shmat(shmid,(void *)0,0);
	shared->client_id=getpid();
	printf("Client ID is %d\n",shared->client_id);
	while(1)
	{
		printf("Enter the input : ");
		scanf("%[^\n]",input);
		getchar();
		if(strcmp(input,"exit")==0)
		{
			strcpy(shared->res,input);
			kill(shared->server_id,SIGCONT);
			break;
		}
		else
		{
			strcpy(shared->res,input);
			kill(shared->server_id,SIGCONT);			
		}
		pause();
		printf("The input %s is %s\n",input,shared->res);
	}
	shmdt(shared);
}
