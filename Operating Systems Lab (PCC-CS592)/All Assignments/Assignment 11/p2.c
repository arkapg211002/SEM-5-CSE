#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>

typedef struct
{
	char str[100];
	int res;
}sd;

void main()
{
	key_t key=ftok("memory",67);
	int shmid=shmget(key,sizeof(sd),0666|IPC_CREAT);
	sd *shared;
	char st[100];
	int i,len,rt=1;
	if(shmid==-1) printf("Cannot connect to shared memory\n");
	shared=(sd *)shmat(shmid,(void *)0,0);
	printf("Data read from memory is %s\n",shared->str);
	strcpy(st,shared->str);
	len=strlen(st);
	for(i=0;i<strlen(st)/2;i++)
	{
		if(st[i]!=st[len-1-i])
		{
			rt=0;
			break;
		}
	}
	shared->res=rt;
	printf("Result is ready\n");
	shmdt(shared);
}
