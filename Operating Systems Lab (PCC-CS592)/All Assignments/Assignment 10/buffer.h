typedef struct
{
	int size;
	int in;
	int out;
	int *arr;
}Buffer;

Buffer *buffer_init(Buffer *b,int n)
{
	b=(Buffer *)malloc(sizeof(Buffer));
	b->size=n;
	b->in=0;
	b->out=0;
	b->arr=(int *)malloc((b->size)*sizeof(int));
	return b;
}

void buffer_insert(Buffer *b,int item)
{
	b->arr[b->in]=item;
	b->in=(b->in + 1)%(b->size);
}

int buffer_delete(Buffer *b)
{
	int item;
	item=b->arr[b->out];
	b->out=(b->out + 1)%(b->size);
	return item;
}

void buffer_destroy(Buffer *b)
{
	free(b->arr);
	free(b);
}

