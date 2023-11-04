/*

Make two processes. The first process takes a string, an index and number of characters as input. The second process
will make that subpart of the string as UPPERCASE and send it back

Process 2

*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<wait.h>

#define MAX 100

void main()
{
	char str[MAX],res[MAX];
	int fd1,fd2,num,index,temp;
	mkfifo("./myfifo2",0666);
	printf("Process 2 starts\n");
	while(1)
	{
		fd1=open("./myfifo1",O_RDONLY);
		
		read(fd1,str,MAX);
		printf("Received String from process1 : %s\n",str);

		if(strcmp(str,"exit")==0)
		{
			close(fd1);
			break;
		}

		read(fd1,&index,sizeof(index));
		printf("Received Index from process1 : %d\n",index);

		read(fd1,&num,sizeof(num));
		printf("Received Number of Characters from process1 : %d\n",num);

		if(index >= strlen(str) || num > (strlen(str)-index))
		{
			fd2=open("./myfifo2",O_WRONLY);
			write(fd2,"Invalid Input",14);
			close(fd1);
			close(fd2);
		}
		else
		{
			fd2=open("./myfifo2",O_WRONLY);
			while(num>0 && str[index]!='\0')
			{
				temp=(int)str[index];
				if(temp>=65 && temp<=90)
					str[index]=(char)temp;
				else if(temp>=97 && temp<=122)
					str[index]=(char)(temp-32);
				else
					str[index]=(char)temp;
				index+=1;
				num-=1;
			}
			write(fd2,str,sizeof(str));

			close(fd1);
			close(fd2);
		}
	}
}
