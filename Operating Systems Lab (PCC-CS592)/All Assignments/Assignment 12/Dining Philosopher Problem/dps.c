#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<signal.h>
#include<semaphore.h>

#define NUM_PHILOSOPHERS 5
#define THINKING 0
#define HUNGRY 1
#define EATING 2

typedef struct
{
	int state[NUM_PHILOSOPHERS];
	sem_t forks[NUM_PHILOSOPHERS];
	sem_t mutex;
}sd;

sd *shared;

void custom(int signum)
{
	printf("\nInterrupted\n");
	printf("Signal Number : %d\n",signum);
	exit(signum);
}

void initialize_shared(sd *shared)
{
	int i;
	for(i=0;i<NUM_PHILOSOPHERS;i++)
	{
		shared->state[i]=THINKING;
		sem_init(&shared->forks[i],1,1);
	}
	sem_init(&shared->mutex,1,1);
}

void take_forks(sd *shared,int philnum)
{
	int lf=philnum;
	int rf=(philnum+1)%NUM_PHILOSOPHERS;
	sem_wait(&shared->mutex);
	shared->state[philnum]=HUNGRY;
	printf("Philsopher %d is hungry. Picked up forks %d and %d\n",philnum,lf,rf);
	sem_post(&shared->mutex);
	sem_wait(&shared->forks[lf]);
	sem_wait(&shared->forks[rf]);
}

void put_forks(sd *shared,int philnum)
{
	int lf=philnum;
	int rf=(philnum+1)%NUM_PHILOSOPHERS;
	sem_wait(&shared->mutex);
	shared->state[philnum]=THINKING;
	printf("Philosopher %d put down forks %d and %d\n",philnum,lf,rf);
	sem_post(&shared->mutex);
	sem_post(&shared->forks[lf]);
	sem_post(&shared->forks[rf]);
}

void philosopher(sd *shared,int philnum)
{
	int ln=(philnum+NUM_PHILOSOPHERS-1)%NUM_PHILOSOPHERS;
	int rn=(philnum+1)%NUM_PHILOSOPHERS;
	while(1)
	{
		printf("Philosopher %d is thinking\n",philnum);
		sleep(1);
		if((philnum==0 && shared->state[ln]==THINKING && shared->state[rn]==THINKING) ||
		   (philnum==1 && shared->state[ln]==THINKING && shared->state[rn]==THINKING) ||
		   (philnum==2 && shared->state[ln]==THINKING && shared->state[rn]==THINKING) ||
		   (philnum==3 && shared->state[ln]==THINKING && shared->state[rn]==THINKING) ||
		   (philnum==4 && shared->state[ln]==THINKING && shared->state[rn]==THINKING))
		{	take_forks(shared,philnum);
			printf("Philosopher %d is eating\n",philnum);
			sleep(2);
			put_forks(shared,philnum);
		}
		else
			printf("Philsopher %d is not eating\n",philnum);
	}
}

int main()
{
	int shmid=shmget(IPC_PRIVATE,sizeof(sd),0666|IPC_CREAT);
	int i,pid;
	signal(SIGINT,custom);
	shared=(sd *)shmat(shmid,(void *)0,0);
	initialize_shared(shared);
	for(i=0;i<NUM_PHILOSOPHERS;i++)
	{
		pid=fork();
		if(pid==0)
		{
			signal(SIGINT,custom);
			philosopher(shared,i);
			return 0;
		}
		else if(pid==-1)
		{
			printf("failed to fork\n");
			return 1;
		}
		else
			signal(SIGINT,custom);
	}
	for(i=0;i<NUM_PHILOSOPHERS;i++)
	{
		wait(NULL);
	}
	shmdt(shared);
	shmctl(shmid,IPC_RMID,NULL);
	return 0;
}
