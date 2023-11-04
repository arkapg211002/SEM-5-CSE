/*

WAP in C to create two threads. The Main thread will take a series of integers as input and send the first half
Thread 1 and the second half to Thread 2. Thread 1 will sort the elements in ascending order and return it back
to Main, where Thread 2 will sort the elements in descending order and send it back to Main. The Main Thread will
print these arrays on screen.

*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/wait.h>
#include<pthread.h>

int *first_half;
int *second_half;
int left_len,right_len;

void *ascending(void *input)
{
	int i,j,temp;
	first_half=(int *)input;
	printf("Thread 1 : The elements are : \n");
	for(i=0;i<left_len;i++)
		printf("%d ",first_half[i]);
	printf("\n");
	// sorting
	for(i=0;i<left_len-1;i++)
	{
		for(j=0;j<left_len-i-1;j++)
		{
			if(first_half[j]>first_half[j+1])
			{
				temp=first_half[j];
				first_half[j]=first_half[j+1];
				first_half[j+1]=temp;
			}
		}
	}
	printf("Sending the sorted first half to Main..\n");
	pthread_exit(first_half);
}

void *descending(void *input)
{
	int i,j,temp;
	second_half=(int *)input;
	printf("Thread 2 : The elements are :\n");
	for(i=0;i<right_len;i++)
		printf("%d ",second_half[i]);
	printf("\n");
	// sorting
	for(i=0;i<right_len-1;i++)
	{
		for(j=0;j<right_len-i-1;j++)
		{
			if(second_half[j]<second_half[j+1])
			{
				temp=second_half[j];
				second_half[j]=second_half[j+1];
				second_half[j+1]=temp;
			}
		}
	}

	printf("Sending the sorted second half to Main..\n");
	pthread_exit(second_half);
}

void main()
{
	pthread_t fh,sh;
	int *arr,n,i,j,*left,*right;
	void *res_left,*res_right;

	printf("Enter the number of elements : ");
	scanf("%d",&n);
	getchar();

	arr=(int *)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
	{
		printf("Enter element at index %d : ",i);
		scanf("%d",&arr[i]);
		getchar();
	}

	// display the array
	printf("\nThe array elements are :\n");
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\n");

	left_len=n/2;
	right_len=n-left_len;
	left=(int *)malloc(left_len*sizeof(int));
	right=(int *)malloc(right_len*sizeof(int));
	for(i=0;i<left_len;i++)
		left[i]=arr[i];
	for(j=0;j<right_len;j++)
	{
	//	printf("%d ",arr[j+i]);
		right[j]=arr[j+i];
	}

	pthread_create(&fh,NULL,ascending,(void *)left);
	pthread_join(fh,&res_left);

	pthread_create(&sh,NULL,descending,(void *)right);
	pthread_join(sh,&res_right);

	printf("Main Thread received results as follows :\n");
	left=(int *)res_left;
	right=(int *)res_right;
	printf("\n First Half\n");
	for(i=0;i<n/2;i++)
		printf("%d ",left[i]);
	printf("\n Second Half\n");
	for(i=0;i<(n-(n/2));i++)
		printf("%d ",right[i]);
	printf("\n");	

}
