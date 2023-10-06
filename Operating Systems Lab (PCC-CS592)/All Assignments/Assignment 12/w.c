/*
Writer for Reader Writer problem
*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<semaphore.h>
#include<time.h>
#include<signal.h>

typedef struct
{
	sem_t mutex;
	sem_t wrt;
	int val;
	int res;
}sd;
sd *shared;
/*void custom_handler(int signum)
{
	shared->res=0;
	shmdt(shared);
	exit(0);
}
*/
void main()
{
	key_t key=ftok("memory",67);
	//signal(SIGINT,custom_handler);
	int shmid=shmget(key,sizeof(sd),0666|IPC_CREAT);
	int i=1;
	if(shmid==-1) printf("Can not read from shared memory");
	shared=(sd *)shmat(shmid,(void *)0,0);
	while(i<=5)
	{
		sleep(3);
		sem_wait(&shared->wrt);
		printf("\nWriter %d started\n",i);
		printf("Original Value %d\n",shared->val);
		srand(time(NULL));
		shared->val=rand();
		sleep(2);
		printf("New Value %d\n",shared->val);
		printf("Writer %d stopped\n",i);
		i+=1;
		sem_post(&shared->wrt);
	}
}
