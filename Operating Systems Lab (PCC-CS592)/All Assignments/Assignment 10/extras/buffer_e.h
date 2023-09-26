typedef struct{
	int size,front,rear;
	int *data;
	}Buffer;
void buff_init(Buffer *ptr,int size)
{
	ptr->size=size;
	ptr->front=-1;
	ptr->rear=-1;
	ptr->data=(int *)malloc(size*sizeof(int));
	
}
void buff_insert(Buffer *ptr,int item)
{
	if((ptr->front==0 && ptr->rear==ptr->size-1)||(ptr->rear+1)%ptr->size==ptr->front)
	{
	printf("Queue is Full\n");
	}
	else if(ptr->front==-1)
	{
		ptr->front=ptr->rear=0;
		*(ptr->data+ptr->rear)=item;
	}
	else if(ptr->rear==ptr->size-1 && ptr->front!=0)
	{
		ptr->rear=0;
		*(ptr->data+ptr->rear)=item;
	}
	else{
	ptr->rear++;
	
		*(ptr->data+ptr->rear)=item;
	
	}
}
int buff_delete(Buffer *ptr)
{
	if(ptr->front==-1)
	{
		printf("Queue is empty.\n");
		return -1;
		
	}
	int data=*(ptr->data+ptr->front);
	if(ptr->front==ptr->rear)
	{
	ptr->front=ptr->rear=-1;
	}
	else if(ptr->front==ptr->size-1)
	ptr->front=0;
	else
	ptr->front++;
	return data;
}
void buff_destroy(Buffer *ptr)
{
	free(ptr->data);
	free(ptr);
	
}
