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

node* Reverse(node* head)
{
	if(head==NULL || head->next==NULL)
	{
		return head;
	}
	node* l=(node*)malloc(sizeof(node));
	l=Reverse(head->next);
	head->next->next=head;
	head->next=NULL;
	return l;
}

int main()
{	
	node* head=NULL;
	InsertAtBeg(1,&head);
	InsertAtBeg(2,&head);
	InsertAtBeg(3,&head);
	/*while(head!=NULL)
	{
		printf("%d\n",head->data);
		head=head->next;
	}*/
	node* h=Reverse(head);
	while(h!=NULL)
	{
		printf("%d\n",h->data);
		h=h->next;
	}
	
}
