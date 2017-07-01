#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct Stack{
	int top;
	unsigned int size;
	char *array;
};

typedef struct Stack stack;

stack* CreateStack(int size)
{
	stack* s = (stack* )malloc(sizeof(stack));
	s->top = -1;
	s->size = size;
	s->array =malloc(sizeof(char)*size);
	return s;
}

void Push(stack* s,char ele)
{
	if(s->top==s->size-1)
	{
		printf("error");
		return;
	}
	s->array[++s->top]=ele;
}

char Pop(stack* s)
{
	if(s->top==-1)
	{
		printf("error");
		return;
	}
	char data = s->array[s->top];
	s->top = s->top-1;
	return data;
}

char Peak(stack* s)
{
	if(s->top==-1)
	{
		printf("error");
		return;
	}
	char data = s->array[s->top];
	return data;
}

int main()
{
	int size;
	scanf("%d",&size);
	char arr[size+1];
	scanf("%s",arr);
	stack* s = CreateStack(size);
	int ans=0,x=0,n=0;
	//Push(s,arr[0]);
	for(int i=0;i<size;i++)
	{
		if(arr[i]==')')
		{
			if(s->top!=-1 && Peak(s)=='(')
			{
				Pop(s);
				x--;
			}
			else
			{
				Push(s,arr[i]);
				ans++;
			}
		}
		else
		{
			Push(s,arr[i]);
			x++;
		}
	}
	n+=ans/2;
	ans=ans%2;
	n+=(x/2);
	n+=(2*ans);
	printf("%d",n);
}
