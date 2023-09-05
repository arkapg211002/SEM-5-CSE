/*

Implement IPC between two processes where proceess-1 will take two strings as user input and send them to process-2. 
Process-2 will compare them and return the result ("SAME" or "NOT SAME") back to process-1. Use FIFO for IPC.

13000121058

Process 2

*/

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>

#define MAX 100

void main()
{
	int fd1,n;
	char s1[MAX],s2[MAX];
	char *myfifo="/tmp/myfifo";
//	mkfifo(myfifo,0666);
	
	printf("Process 2\n");

	fd1=open(myfifo,O_RDONLY);
	n=read(fd1,s1,MAX);
	s1[n]='\0';
	n=read(fd1,s2,MAX);
	s2[n]='\0';
	close(fd1);

	printf("Process2 read the data\n");
	printf("%s\n",s1);
	printf("%s\n",s2);

	fd1=open(myfifo,O_WRONLY);
	if(strcmp(s1,s2)==0) write(fd1,"SAME",5);
	else write(fd1,"NOT SAME",9);
	printf("Process 2 sent the result\n");
	close(fd1);


}
