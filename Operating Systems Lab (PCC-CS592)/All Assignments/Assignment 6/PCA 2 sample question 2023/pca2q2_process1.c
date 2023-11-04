/*

Make two processes. The first process takes a string, an index and number of characters as input. The second process
will make that subpart of the string as UPPERCASE and send it back

Process 1

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
	int fd1,fd2,num,index;
	mkfifo("./myfifo1",0666);
	printf("Process 1 starts\n");

	while(1)
	{
		fd1=open("./myfifo1",O_WRONLY);
		//getchar();
		printf("Enter String : ");
		scanf("%[^\n]",str);
		getchar();
		printf("Sending %s to process2...\n",str);
		write(fd1,str,strlen(str)+1);

		if(strcmp(str,"exit")==0)
		{
			close(fd1);
			break;
		}

		printf("Enter the index : ");
		scanf("%d",&index);
		printf("Sending %d to process2...\n",index);
		write(fd1,&index,sizeof(index));

		printf("Enter the number of characters : ");
		scanf("%d",&num);
		printf("Sending %d to process2...\n",num);
		write(fd1,&num,sizeof(num));


		fd2=open("./myfifo2",O_RDONLY);
		read(fd2,res,MAX);
		printf("Process 1 received output as : %s\n",res);
		getchar();
		fflush(stdin);

		close(fd1);
		close(fd2);

	}
}
