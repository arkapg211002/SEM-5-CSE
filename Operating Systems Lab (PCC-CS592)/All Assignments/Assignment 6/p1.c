#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

void main()
{
	char str1[100],str2[100],res[100];
	int fd1,fd2;
	mkfifo("./myfifo1",0666);
	fd1=open("./myfifo1",O_WRONLY);
	printf("Enter the String 1 : ");
//	fgets(str1,100,stdin);
	scanf("%s",str1);
	write(fd1,str1,strlen(str1)+1);
	printf("Enter the String 2 : ");
//	fgets(str2,100,stdin);
	scanf("%s",str2);
	write(fd1,str2,strlen(str2)+1);
	
	fd2=open("./myfifo2",O_RDONLY);
	read(fd2,res,sizeof(res));
	printf("%s and %s are %s\n",str1,str2,res);

	close(fd1);
	close(fd2);
}
