#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node* left;
	struct node* right;
}node;

node* CreateNode(int val)
{
	node* n = malloc(sizeof(node));
	n->data = val;
	n->left = NULL;
	n->right = NULL;
	return n;
}

node* insert(node* root,int value)
{
	if(root==NULL)
	{
		node* head = CreateNode(value);
		return head;
	}
	node* head = root;
	node* pre = malloc(sizeof(node));
	pre = NULL;
	int flag=0;
	while(head!=NULL)
	{
		if(head->data > value)
		{
			pre = head;
			head = head->left;
			flag=0;
		}
		else
		{
			pre = head;
			head = head->right;
			flag=1;
		}
	}
	node* n = CreateNode(value);
	if(flag==0)
	{
		pre->left = n;
	}
	else
	{
		pre->right = n;
	}
	return root;
}

void print(node* root)
{
	if(root == NULL)
	{
		return;
	}
	print(root -> left);
	printf("%d ",root->data);
	print(root -> right);
}

int main()
{
	int n,i;
	scanf("%d",&n);
	int preOrder[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&preOrder[i]);
	}
	node* root = CreateNode(preOrder[0]);
	
	for(int j=1;j<n;j++)
	{
		root = insert(root,preOrder[j]);
	}
	//printf("%d",root->left->data);
	print(root);
}
