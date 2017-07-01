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

int prec(char ch)
{
	if(ch == '+' || ch == '-')
	{
		return 1;
	}	
	else if(ch == '*' || ch == '/')
	{
		return 2;
	}	
	else if(ch == '^')
	{
		return 3;
	}	
	else
	{
		return -1;
	}	
}

int isDigit(char ch)
{
	return (ch >= '0' && ch <= '9');
}

int main()
{
	char infix[100],postfix[100];
	scanf("%s",infix);
	int len=strlen(infix);
	int i;
	stack* s=CreateStack(len);
	int k=0;
	for(i=0;i<len;i++)
	{
		if(isDigit(infix[i]))
		{
			postfix[k++]=infix[i];
		}
		else if(infix[i]=='(')
		{
			Push(s,infix[i]);
		}
		else if(infix[i]==')')
		{
			while(s->array[s->top]!='(')
			{
				postfix[k++]=Pop(s);
			}
			Pop(s);
		}
		else
		{
			while(s->top!=-1 && prec(infix[i])<=prec(s->array[s->top]))
			{
				postfix[k++]=Pop(s);
			}
			Push(s,infix[i]);
		}
	}
	while(s->top!=-1)
	{
		postfix[k++]=Pop(s);
	}
	postfix[k]='\0';
	printf("%s\n",postfix);
	for(int i=0;i<k;i++)
	{
		if(isDigit(postfix[i]))
		{
			Push(s,postfix[i]-'0');
		}
		else
		{
			int val1 = Pop(s);
			int val2 = Pop(s);
			if(postfix[i]=='+')
			{
				Push(s,val1+val2);
			}
			else if(postfix[i]=='-')
			{
				Push(s,val1-val2);
			}
			else if(postfix[i]=='*')
			{
				Push(s,val1*val2);
			}
			else if(postfix[i]=='/')
			{
				Push(s,val2/val1);
			}
		}	
	}
	printf("%d",Pop(s));	
}
