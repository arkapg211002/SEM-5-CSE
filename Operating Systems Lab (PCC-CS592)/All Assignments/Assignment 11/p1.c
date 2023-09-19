#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>

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
	if(shmid==-1) printf("Cannot create shared memory\n");
	shared=(sd *)shmat(shmid,(void *)0,0);
	printf("Enter data in the shared memory\n");
	scanf("%[^\n]",shared->str);
	getchar();
	printf("Data written in process P1 is : %s\n",shared->str);
	shared->res=2;
	while(shared->res == 2);
	printf("process returned the result %d\n",shared->res);
	if(shared->res==0) printf("Not palindrome string\n");
	else printf("Palindrome string\n");
	shmdt(shared);
	shmctl(shmid,IPC_RMID,NULL);

	
}
