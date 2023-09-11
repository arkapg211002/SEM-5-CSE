#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>

void main()
{
	char s1[100],s2[100];
	int fd1,fd2;
	mkfifo("./myfifo2",0666);
	fd1=open("./myfifo1",O_RDONLY);
	read(fd1,s1,sizeof(s1));
	printf("The first input is : %s\n",s1);
	read(fd1,s2,sizeof(s2));
	printf("The second input is : %s\n",s2);

	fd2=open("./myfifo2",O_WRONLY);
	if(strcmp(s1,s2)==0)
		write(fd2,"SAME",5);
	else
		write(fd2,"NOT SAME",9);
	
	close(fd1);
	close(fd2);
	
	
}
