/*
	Write a Program to demonstrate the use of signal. The process will print a message infinitely until an interrupt signal occurs. 
	It will handle the signal and will print a message along with the signal number that it has got.(Help: signal(SIGINT,SIG_DFL))

	13000121058

*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<signal.h>
#include<sys/wait.h>

void custom_handler(int);

void main()
{
	signal(SIGINT,custom_handler);
	while(1)
	{
		printf("Hello world. I am Arkapratim Ghosh (13000121058)\n");
		sleep(1);
	}
}

void custom_handler(int signum)
{
	printf("\nInterrupted.\n");
	printf("Signal number is : %d \n",signum);
	exit(0);
}
