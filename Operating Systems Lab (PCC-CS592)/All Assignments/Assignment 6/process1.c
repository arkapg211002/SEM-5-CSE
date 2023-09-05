/*

Implement IPC between two processes where proceess-1 will take two strings as user input and send them to process-2. 
Process-2 will compare them and return the result ("SAME" or "NOT SAME") back to process-1. Use FIFO for IPC.

13000121058

Process 1

*/

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<string.h>
#include<unistd.h>

#define MAX 100

void main()
{
	int fd,i;
	char str1[MAX],str2[MAX],buffer[MAX];
	char *myfifo="/tmp/myfifo";
	mkfifo(myfifo,0666);

	printf("Process 1\n");
	printf("Enter the strings :\n");
	scanf("%s %s",str1,str2);
	fflush(stdin);
//	printf("Enter the second string :\n");
//	scanf("%[^\n]",str2);
	
	printf("Process 1 took input as follows\n");
	printf("%s\n",str1);
	printf("%s\n",str2);

	fd=open(myfifo,O_WRONLY);
	write(fd,str1,strlen(str1)+1);
	write(fd,str2,strlen(str2)+1);
	close(fd);

	fd=open(myfifo,O_RDONLY);
	read(fd,buffer,MAX);
	printf("Data sent by process 2\n");
	printf("%s and %s are %s \n",str1,str2,buffer);
	close(fd);
}
