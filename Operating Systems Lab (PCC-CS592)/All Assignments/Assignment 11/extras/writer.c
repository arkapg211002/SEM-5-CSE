/*
Writer program
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<string.h>

void main()
{
	key_t key=ftok("memory",67); // to generate unique key
	int shmid=shmget(key,1024,0666|IPC_CREAT);
	char *str;
	if(shmid==-1) printf("Unable to create memory segment\n");
	str=(char *)shmat(shmid,(void *)0,0);
	printf("Enter data to write in the shared memory \n");
	scanf("%[^\n]",str);
	getchar();
	printf("Data written is : %s\n",str);
	shmdt(str);
}
