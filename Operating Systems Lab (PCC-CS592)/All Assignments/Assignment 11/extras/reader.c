/*
Reader program
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/shm.h>

void main()
{
	key_t key=ftok("memory",67);
	int shmid=shmget(key,1024,0666|IPC_CREAT);
	char *str;
	if(shmid==-1) printf("Unable to connect to the shared memory\n");
	str=(char *)shmat(shmid,(void *)0,0);
	printf("Data read from the memory is %s\n",str);
	shmdt(str);
	shmctl(shmid,IPC_RMID,NULL);
}
