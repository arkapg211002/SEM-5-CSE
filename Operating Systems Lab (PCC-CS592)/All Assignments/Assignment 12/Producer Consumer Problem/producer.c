/*
Producer for producer consumer problem using shared memory
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<semaphore.h>
#include<signal.h>
#include<time.h>

#define size 5

typedef struct
{
	int buffer[size];
	sem_t mutex,empty,full;
	int in,out,val,res;
}sd;
sd *shared;

void main()
{
	key_t key=ftok("memory",67);
	int item;
	int shmid=shmget(key,sizeof(sd),0666|IPC_CREAT);
	if(shmid==-1) printf("Cannot Create Shared Memory\n");
	shared=(sd *)shmat(shmid,(void *)0,0);
	shared->in=0;
	shared->out=0;
	srand(time(NULL));
	shared->val=rand();
	shared->res=1;
	sem_init(&shared->mutex,1,1);
	sem_init(&shared->empty,1,size);
	sem_init(&shared->full,1,0);
	
	while(shared->res!=0)
	{
		sem_wait(&shared->empty);
		sem_wait(&shared->mutex);
		item=shared->val;
		printf("Producer : Adding %d to the buffer\n",item);
		shared->buffer[shared->in]=item;
		shared->in=(shared->in+1)%size;
		sleep(1);
		sem_post(&shared->mutex);
		srand(time(NULL));
		shared->val=rand();
		sleep(1);
		sem_post(&shared->full);
	}
	sem_destroy(&shared->mutex);
	sem_destroy(&shared->empty);
	sem_destroy(&shared->full);
	shmdt(shared);
	shmctl(shmid,IPC_RMID,NULL);
}

