/*
Consumer for Producer Consumer Problem using shared memory
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<semaphore.h>
#include<time.h>
#include<signal.h>
#include<fcntl.h>

#define size 5

typedef struct
{
	int buffer[size];
	sem_t mutex,empty,full;
	int in,out,val,res;
}sd;
sd *shared;

void custom_handler(int signum)
{
	shared->res=0;
	shmdt(shared);
	exit(0);
}

void main()
{
	key_t key=ftok("memory",67);
	int item,index;
	int shmid=shmget(key,sizeof(shared),0666|IPC_CREAT);
	if(shmid==-1) printf("Cannot conenct to the shared memory\n");
	shared=(sd *)shmat(shmid,(void *)0,0);
	signal(SIGINT,custom_handler);

	while(1)
	{
		sem_wait(&shared->full);
		sem_wait(&shared->mutex);
		item=shared->buffer[shared->out];
		index=shared->out;
		printf("Consumer : Reads %d at index %d\n",item,index);
		shared->out=(shared->out+1)%size;
		sleep(1);
		sem_post(&shared->mutex);
		sleep(1);
		sem_post(&shared->empty);
	}
}
