#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node* left;
	struct node* right;
}node;

typedef struct stack{
	int size;
	int top;
	node** array;// it has to be a node** because array stores pointer to a node hence as it is pointer to first element of the array so its a pointer to a pointer	
}stack;

node* CreateNode(int val)
{
	node* n = malloc(sizeof(node));
	n->data = val;
	n->left = NULL;
	n->right = NULL;
	return n;
}

void Push(stack* s,node* n)
{
	s->array[++s->top] = n;
}

node* Pop(stack* s)
{
	if(s->top==-1)
	{
		return NULL;
	}
	return s->array[s->top--];
}

void PostOrder(node* root)
{
	if(root == NULL)
	{
		return;
	}
	stack* s1 = malloc(sizeof(stack));
	stack* s2 = malloc(sizeof(stack));
	s1 -> size = 0;
	s2 -> size = 0;
	s1 -> top = -1;
	s2 -> top = -1;
	s1 -> array = malloc(100*sizeof(node*));
	s2 -> array = malloc(100*sizeof(node*));
	Push(s1,root);
	node* temp;
	while(s1->top!=-1)
	{
		temp = Pop(s1);
		Push(s2,temp);
		if(temp->left)
		{
			Push(s1,temp->left);
		}
		if(temp->right)
		{
			Push(s1,temp->right);
		}
	}
	while(s2->top!=-1)
	{
		temp = Pop(s2);
		printf("%d ",temp->data);
	}
}

int main()
{
	node* root = NULL;
	root = CreateNode(1);
    	root->left = CreateNode(2);
    	root->right = CreateNode(3);
    	root->left->left = CreateNode(4);
    	root->left->right = CreateNode(5);
    	root->right->left = CreateNode(6);
    	root->right->right = CreateNode(7);
	PostOrder(root);
	return 0;	
}
