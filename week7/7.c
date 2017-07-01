#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct Queue{
	int front,rear,size;
	unsigned int capacity;
	int* array;
};

typedef struct Queue queue;

queue* CreateQueue(unsigned int capacity)
{
	queue* q=malloc(sizeof(queue));
	q->capacity = capacity;
	q->front=0;
	q->size=0;
	q->rear = capacity-1;
	q->array = malloc(sizeof(int)*capacity);
	return q;
}

int isFull(queue* q)
{
	return (q->size==q->capacity);
}

int isEmpty(queue* q)
{
	return (q->size==0);
}

void enqueue(queue* q,int data)
{
	if(isFull(q))
	{
		return;
	}
	q->rear = (q->rear+1)%(q->capacity);
	q->array[q->rear] = data;
	q->size = q->size+1;		
}

int dequeue(queue* q)
{
	if(isEmpty(q))
	{
		return -9999;
	}
	int ele=q->array[q->front];	
	q->size=q->size-1;
	q->front = (q->front+1)%(q->capacity);
	return ele;
}

int front(queue* q)
{
	if(isEmpty(q))
	{
		return -9999;
	}
	int ele=q->array[q->front];
	return ele;
}

int main()
{
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	queue* q=CreateQueue(n);
	int ct=0;
	enqueue(q,arr[0]);
	for(int i=1;i<n;i++)
	{
		if((q->array[q->rear])<=arr[i])
		{
			enqueue(q,arr[i]);
		}
		else
		{
			ct+=((q->size)*((q->size)+1))/2;
			q->front=0;
			q->size=0;
			q->rear = n-1;
			enqueue(q,arr[i]);
		}
	}
	printf("%d",ct);
}
