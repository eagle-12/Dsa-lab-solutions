#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct Node{
	int data;
	struct Node* prev;
	struct Node* next;
};

typedef struct Node node;

node* CreateNode(int data)
{
	node* n=malloc(sizeof(node));
	n->data=data;
	n->next=NULL;
	n->prev=NULL;
	return n;
}

void InsertAtBeg(int data,node** head)
{
	node* curr = *(head);
	node* n=CreateNode(data);
	n->next=curr;
	if(curr!=NULL)
	{
		curr->prev = n;
	}	
	*head = n;
}

void InsertAtEnd(int data,node** head)
{
	node* n = CreateNode(data);
	node* curr = *(head);
	node* pre = NULL;
	while(curr->next!=NULL)
	{
		pre = curr;
		curr = curr->next;
	}
	curr->next = n;
	curr->prev = pre;
	n->prev = curr;
}

void InsertAtIndex(int data,int idx,node** head)
{
	node* h = CreateNode(data);
	node* curr = *(head);
	node* pre = NULL;
	int i=0;
	while(i!=idx)
	{
		pre = curr;
		curr=curr->next;
		i++;
	}
	pre->next = h;
	curr->prev = h;
	h->next = curr;
	h->prev = pre;
}

int main()
{
	 node* head=NULL;
	 InsertAtBeg(1,&head);
	 InsertAtEnd(2,&head);
	 InsertAtIndex(3,1,&head);
	 while(head!=NULL)
	 {
	 	printf("%d ",head->data);
	 	head=head->next;
	 } 
}
