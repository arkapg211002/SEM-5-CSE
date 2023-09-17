/*

Write a program to create two threads, The first thread creates a file and a second thread inputs text in the file
created

13000121058

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>

void *t1(void *arg);
void *t2(void *arg);
char ch[100];
void main()
{
	pthread_t thread1,thread2;
	pthread_create(&thread1,NULL,t1,NULL);
	pthread_join(thread1,NULL);
	pthread_create(&thread2,NULL,t2,NULL);
	pthread_join(thread2,NULL);
	system("ls");
	printf("Default thread %ld ends\n",pthread_self());
}

void *t1(void *arg)
{
	//char ch[100];
	int fd;
	printf("Inside the first thread %ld\n",pthread_self());
	printf("Enter the filename to be created : ");
	scanf("%[^(\n\n)]",ch);
	getchar();
	printf("Creating file %s ...\n",ch);
	fd=open(ch,O_CREAT,0777);
	printf("File created successfully\n");
	close(fd);
	pthread_exit(NULL);
}

void *t2(void *arg)
{
	char input[100];
	int fd;
	printf("Inside the second thread %ld\n",pthread_self());
	printf("Enter text to be inserted:\n");
	scanf("%[^\n]",input);
	//getchar();
	fd=open(ch,O_WRONLY);
	write(fd,input,strlen(input)+1);
	printf("Written successfully\n");
	pthread_exit(NULL);
}
