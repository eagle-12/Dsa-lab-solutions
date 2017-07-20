#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node{
	char data;
	struct node* left;
	struct node* right;
}node;

node* construct(char inorder[],char postorder[],int min,int max,int* postIdx)
{
	if(min > max)
	{
		return NULL;
	}
	node* n = malloc(sizeof(node*));
	n->data = postorder[(*postIdx)];
	(*postIdx)--;
	n->right = NULL;
	n->left = NULL;
	int i;
	for(i=min;i<=max;i++)
	{
		if(inorder[i]==n->data)
		{
			break;
		}
	}
	int index = i;
	n->right = construct(inorder,postorder,index+1,max,postIdx);
	n->left = construct(inorder,postorder,min,index-1,postIdx);
	return n;
}

void print(node* root)
{
	if(root==NULL)
	{
		return;
	}
	printf("%c",root->data);
	print(root->left);
	print(root->right);
}

int main()
{
	char inorder[105],postorder[105];
	scanf("%s",inorder);
	scanf("%s",postorder);
	int n = strlen(inorder);
	int postIdx = n-1;
	node* root = construct(inorder,postorder,0,n-1,&postIdx);
	print(root);
}
