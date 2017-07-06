#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct Stack{
	int top;
	unsigned int size;
	int *array;
};

typedef struct Stack stack;

struct Queue{
	stack* s1;
	stack* s2;
};

typedef struct Queue queue;

stack* CreateStack(int size)
{
	stack* s = (stack* )malloc(sizeof(stack));
	s->top = -1;
	s->size = size;
	s->array =malloc(sizeof(int)*size);
	return s;
}

void Push(stack* s,int ele)
{
	if(s->top==s->size-1)
	{
		printf("error");
		return;
	}
	s->array[++s->top]=ele;
}

int Pop(stack* s)
{
	if(s->top==-1)
	{
		printf("error");
		return -999;
	}
	char data = s->array[s->top];
	s->top = s->top-1;
	return data;
}

void enqueue(queue* q,int data)
{
	Push(q->s1,data);
}

int dequeue(queue* q)
{
	if(q->s1->top==-1 && q->s2->top==-1)
	{
		printf("Queue empty");
		return -9999;
	}
	int x;
	if(q->s2->top==-1)
	{
		int x;
		while(q->s1->top!=-1)
		{
			x = Pop(q->s1);
			Push(q->s2,x);
		}
	}
	x = Pop(q->s2);
	return x;
}

void print(stack* s1,stack* s2)
{
	if(s1->top==-1)
	{
		printf("stack1 is empty\n");
		return;
	}
	else
	{
		while(s1->top!=-1)
		{
			printf("%d ",Pop(s1));
		}
		printf("\n");
	}
	if(s2->top==-1)
	{
		printf("stack2 is empty\n");
		return;
	}
	else
	{
		while(s2->top!=-1)
		{
			printf("%d ",Pop(s2));
		}
		printf("\n");
	}	
}

int main()
{
	queue* q = malloc(sizeof(queue));
	stack* s1=CreateStack(10);
	stack* s2=CreateStack(10);
	q->s1=s1;
	q->s2=s2;
	enqueue(q,10);
	enqueue(q,20);
	int x=dequeue(q);
	printf("%d",x);
}































