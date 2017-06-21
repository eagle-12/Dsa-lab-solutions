#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct Node{
	int data;
	struct Node* next;
};

typedef struct Node node;

node* head = NULL;

node* CreateNode(int data)
{
	node* n=malloc(sizeof(node));
	n->data=data;
	n->next=NULL;
}

void InsertAtBeg(int data)
{
	node* n=CreateNode(data);
	n->next=head;
	head=n;
}

void InsertAtEnd(int data)
{
	node* n=CreateNode(data);
	node* h=head;
	if(head==NULL)
	{
		head=n;
		return;
	}
	while(h->next!=NULL)
	{
		h=h->next;
	}
	h->next=n;
}

void Insert(int data,int key)
{
	node* n=CreateNode(data);
	node* pre=NULL;
	node* curr=head;
	while(curr->data!=key)
	{
		pre=curr;
		curr=curr->next;
	}
	n->next=curr;
	pre->next=n;
}

int main()
{
	InsertAtBeg(6);
	node* h=head;
	while(h!=NULL)
	{
		printf("%d\n",h->data);
		h=h->next;
	}
	InsertAtEnd(5);
	h=head;
	while(h!=NULL)
	{
		printf("%d\n",h->data);
		h=h->next;
	}
	Insert(4,5);
	h=head;
	while(h!=NULL)
	{
		printf("%d\n",h->data);
		h=h->next;
	}	
}
