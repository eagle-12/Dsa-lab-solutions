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
	int n,flag=0;
	scanf("%d",&n);
	int arr[n][n];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	stack* s = CreateStack(n*n);
	int i=0,j=0;
	arr[0][0]++;
	while(i!=n-1 || j!=n-1)
	{
		if(j<n-1 && arr[i][j+1]==1)
		{
			Push(s,'1');
			arr[i][j+1]++;
			j++;
		}
		else if(i<n-1 && arr[i+1][j]==1)
		{
			Push(s,'2');
			arr[i+1][j]++;
			i++;
		}
		else if(j>=0 && arr[i][j-1]==1)
		{
			Push(s,'3');
			arr[i][j-1]++;
			j--;
		}
		else if(i>=0 && arr[i-1][j]==1)
		{
			Push(s,'4');
			arr[i-1][j]++;
			i--;
		}
		else if(s->top!=-1)
		{
			char c=Pop(s);
			if(c=='1')
			{
				j--;
			}
			else if(c=='2')
			{
				i--;
			}
			else if(c=='3')
			{
				j++;
			}
			else if(c=='4')
			{
				i++;
			}
		}
		else
		{
			flag=-1;
		}				
	}
	if(flag==-1)
	{
		printf("not possible");
	}
	else
	{
		for(i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				printf("%d ",arr[i][j]);
			}
			printf("\n");
		}
	}	
}






















