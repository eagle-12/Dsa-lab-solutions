#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct Node{
	int data;
	struct Node* next;
};

typedef struct Node node;

node* CreateNode(int data)
{
	node* n=malloc(sizeof(node));
	n->data=data;
	n->next=NULL;
	return n;
}

void InsertAtBeg(int data,node** head)
{
	node* n=CreateNode(data);
	n->next=*head;
	*head=n;
}

void InsertAtEnd(int data,node** head)
{
	node* h=CreateNode(data);
	node* h1=*(head);
	if(h1==NULL)
	{
		(*head)=h;
		return;
	}
	while(h1->next!=NULL)
	{
		h1=h1->next;
	}
	h1->next=h;
}

node* modify(node* head)
{
	node* even=NULL;
	node* odd=NULL;
	while(head!=NULL)
	{
		if((head->data)%2==0)
		{
			InsertAtEnd(head->data,&even);
			head=head->next;
		}
		else
		{
			InsertAtEnd(head->data,&odd);
			head=head->next;
		}
	}
	node* h=even;
	while(even->next!=NULL)
	{
		even=even->next;
	}
	even->next=odd;
	return h;
}

int main()
{
	node* head = NULL;
	int x;
	for(int i=0;i<5;i++)
	{
		scanf("%d",&x);
		InsertAtEnd(x,&head);
	}
	node* h=modify(head);
	//node* h=head;
	while(h!=NULL)
	{
		printf("%d\n",h->data);
		h=h->next;
	}
	return 0;
}
