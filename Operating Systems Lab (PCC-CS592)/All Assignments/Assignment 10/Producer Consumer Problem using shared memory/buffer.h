/*
 *  Program: buffer.h 
 *  Purpose: Definition of the circular buffer (queue) structure and operations.
 *  Author : Dipankar Pal
 *  Last updated: 20.09.2022
 */

#define  BUFFSIZE  5

typedef struct cqueue {
	int arr[BUFFSIZE], front, rear; 
	unsigned size;
} buffer;


int buf_init(buffer *buf)
{
	buf->size = BUFFSIZE;
	buf->front = buf->rear = -1;
	return 1;
}

int buf_insert(buffer *buf, int data)
{
	if(((buf->rear+1)%buf->size) == buf->front)   // buffer FULL 
		return 0;

	if(buf->front == -1)   // buffer EMPTY 
		buf->rear = buf->front = 0;
	else
		buf->rear = ((buf->rear+1)%buf->size);
	buf->arr[buf->rear] = data;
	return 1;
}

int buf_delete(buffer *buf, int *data)
{
	if(buf->front == -1)   // buffer EMPTY 
		return 0;

	*data = buf->arr[buf->front];
	if(buf->front == buf->rear)
		buf->front = buf->rear = -1;
	else
		buf->front = ((buf->front+1)%buf->size);
	return 1;
}

void buf_destroy(buffer *buf)
{
	buf->size = 0;
	buf->front = buf->rear = -1;
}

void buf_display(buffer *buf)
{
	int i;
	for(i=buf->front; i != buf->rear; i=(i+1)%buf->size)
	{
		printf("%d\t", buf->arr[i]);
	}
	if(buf->front > -1)
		printf("%d\n", buf->arr[i]);
}

