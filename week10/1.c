#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node* next;
}node; 

node* CreateNode(int ele)
{
	node* n = malloc(sizeof(node));
	n->data = ele;
	n->next = NULL;
	return n;
}

void insert(node* hashtable[],int ele)
{
	int x = ele%10;
	node* n = CreateNode(ele);
	if(hashtable[x]==NULL)
	{
		hashtable[x] = n;
	}
	else
	{
		n->next = hashtable[x];
		hashtable[x] = n;
	}
}

void print(node* hashtable[])
{
	node* ptr = NULL;
	for(int i=0;i<10;i++)
	{
		ptr = hashtable[i];
		while(ptr!=NULL)
		{
			printf("%d ",ptr->data);
			ptr = ptr->next;
		}
		printf("\n");
	}
}

void Search(node* hashtable[],int key)
{
	int x = key%10;
	if(hashtable[x]==NULL)
	{
		printf("not found\n");
	}
	else
	{
		node* ptr = hashtable[x];
		while(ptr!=NULL)
		{
			if(ptr->data == key)
			{
				printf("found\n");
				break;
			}
			ptr = ptr->next;
		}
	}
}

void delete(node* hashtable[],int key)
{
	int x = key%10;
	if(hashtable[x]==NULL)
	{
		printf("no element to delete\n");
	}
	else
	{
		node* ptr = hashtable[x];
		node* prev = NULL;
		while(ptr!=NULL)
		{
			if(ptr->data == key)
			{
				prev->next = ptr->next;
				break;
			}
			prev = ptr;
			ptr = ptr->next;
		}
		if(ptr->data != key)
		{
			printf("no element to delete\n");
		}
	}
}

int main()
{
	int hash[10]={71,23,73,99,44,19,49,93,81,39};
	node* hashtable[10];
	for(int i=0;i<10;i++)
	{
		hashtable[i] = NULL;
	}
	for(int i=0;i<10;i++)
	{
		insert(hashtable,hash[i]);
	}
	print(hashtable);
}
