/*

Reader for Reader Writer Problem

*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<time.h>
#include<semaphore.h>

typedef struct
{
	sem_t mutex;
	sem_t wrt;
	int val;
	int res;
}sd;
sd *shared;
void main()
{
	key_t key=ftok("memory",67);
	int shmid=shmget(key,sizeof(sd),0666|IPC_CREAT);
	int readcount=0,i=1;
	if(shmid==-1) printf("can not create shared memory\n");
	shared=(sd *)shmat(shmid,(void *)0,0);
	sem_init(&shared->mutex,1,1);
	sem_init(&shared->wrt,1,1);
	srand(time(NULL));
	shared->val=rand();
	shared->res=1;
	while(shared->res!=0)
	{
		sem_wait(&shared->mutex);
		readcount++;
		if(readcount==1)
			sem_wait(&shared->wrt);
		sem_post(&shared->mutex);
		printf("Reader %d reads : %d\n",i,shared->val);
		sem_wait(&shared->mutex);
		readcount--;
		if(readcount==0)
			sem_post(&shared->wrt);
		sem_post(&shared->mutex);
		i+=1;
		sleep(1);
	}
	sem_destroy(&shared->mutex);
	sem_destroy(&shared->wrt);
	shmdt(shared);
	shmctl(shmid,IPC_RMID,NULL);	
}
