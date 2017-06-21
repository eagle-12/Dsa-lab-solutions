#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct Node{
	int data;
	struct Node* next;
};

typedef struct Node node;

//node* head = NULL;

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

node* reverse(node* head)
{
	if(head==NULL || head->next==NULL)
	{
		return head;
	}
	node* n=CreateNode(head->data);
	head=head->next;
	while(head!=NULL)
	{
		InsertAtBeg(head->data,&n);
		head=head->next;
	}
	return n;
}

int main()
{	
	node* head=NULL;
	InsertAtBeg(1,&head);
	InsertAtBeg(2,&head);
	InsertAtBeg(3,&head);
	node* h=reverse(head);
	while(h!=NULL)
	{
		printf("%d\n",h->data);
		h=h->next;
	}
	
}
