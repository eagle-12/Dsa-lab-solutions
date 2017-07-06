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

int Pop(stack* s)
{
	if(s->top==-1)
	{
		//printf("error");
		return -1;
	}
	char data = s->array[s->top];
	s->top = s->top-1;
	return 0;
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
	stack* s = CreateStack(100);
	char str[100];
	scanf("%s",str);
	int l=strlen(str);
	int max=0,curr=0,ct=0;
	for(int i=0;i<l;i++)
	{
		if(str[i]=='(')
		{
			Push(s,str[i]);
		}
		else
		{
			if(Pop(s)!=-1)
			{
				curr+=2;
			}
			else
			{
				if(curr>max)
				{
					max=curr;
					curr=0;
					ct=1;
				}
				else if(curr!=0 && curr==max)
				{
					curr=0;
					ct++;
				}
			}
		}
	}
	if(curr>max)
	{
		max=curr;
		ct=1;
	}
	else if(curr==max)
	{
		ct++;
	}
	printf("%d %d",max,ct);
}













