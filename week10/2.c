#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node* next;
	struct node* prev;
}node; 

node* CreateNode(int key)
{
	node* n = malloc(sizeof(node));
	n->data = key;
	n->next = NULL;
	n->prev = NULL;
}

void Insert(node* hashtable[],int ele)
{
	node* ptr = CreateNode(ele);
	int x = ele%10;
	int y = 7 - ele%7;
	if(hashtable[x]==NULL)
	{
		hashtable[x] = ptr;
	}
	else
	{
		if(hashtable[y]==NULL)
		{
			hashtable[y] = ptr;
		}
		else
		{
			ptr->next = hashtable[x];
			hashtable[x]->prev = ptr;
			hashtable[x] = ptr;
		}
	}
}

void print(node* hashtable[])
{
	for(int i=0;i<10;i++)
	{
		if(hashtable[i]==NULL)
		{
			printf("empty\n");
		}
		else
		{
			node* ptr = hashtable[i];
			while(ptr!=NULL)
			{
				printf("%d ",ptr->data);
				ptr = ptr->next;
			}
			printf("\n");
		}
	}
}

void Search(node* hashtable[],int key)
{
	int x = key%10;
	int y = 7 - key%7;
	if(hashtable[x]==NULL && hashtable[y]==NULL)
	{
		printf("not found\n");
	}
	else
	{
		node* ptr = hashtable[x];
		while(ptr!=NULL)
		{
			if(ptr->data==key)
			{
				printf("found\n");
				return;
			}
			ptr = ptr->next;
		}
		ptr = hashtable[y];
		while(ptr!=NULL)
		{
			if(ptr->data==key)
			{
				printf("found\n");
				return;
			}
		}
		printf("not found\n");
	}
}

void Delete(node* hashtable[],int key)
{
	int x = key%10;
	int y = 7 - key%7;
	if(hashtable[x]==NULL && hashtable[y]==NULL)
	{
		printf("no element to delete\n");
	}
	else
	{
		node* ptr = hashtable[x];
		if(ptr!=NULL && ptr->data == key)
		{
			hashtable[x] = ptr->next;
			ptr->next->prev = NULL;
		}
		else
		{
			while(ptr!=NULL)
			{
				if(ptr->data == key)
				{
					node* tmp = ptr->prev;
					ptr->prev->next = ptr->next;
					ptr->next->prev = tmp;
					return;
				}
				ptr = ptr->next;
			}
		}
		ptr = hashtable[y];
		if(ptr!=NULL && ptr->data == key)
		{
			hashtable[y] = ptr->next;
			ptr->next->prev = NULL;
		}
		else
		{
			while(ptr!=NULL)
			{
				if(ptr->data == key)
				{
					node* tmp = ptr->prev;
					ptr->prev->next = ptr->next;
					ptr->next->prev = tmp;
					return;
				}
				ptr = ptr->next;
			}
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
		Insert(hashtable,hash[i]);
	}
	Delete(hashtable,81);
	print(hashtable);
}
