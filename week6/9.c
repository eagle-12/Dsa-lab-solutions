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
}

void InsertAtBeg(int data,node** head)
{
	node* n=CreateNode(data);
	n->next=*head;
	*head=n;
}

node* mergeSortedList(node* head1,node* head2)
{
	node* n;
	node* head;
	if(head1==NULL)
	{
		return head2;
	}
	if(head2==NULL)
	{
		return head1;
	}
	if(head1->data<=head2->data)
	{
		n=CreateNode(head1->data);
		head=n;
		head1=head1->next;
	}
	else
	{
		n=CreateNode(head2->data);
		head=n;
		head2=head2->next;
	}
	while(head1!=NULL && head2!=NULL)
	{
		if(head1->data<=head2->data)
		{
			n->next=head1;
			n=n->next;
			head1=head1->next;
		}
		else
		{
			n->next=head2;
			n=n->next;
			head2=head2->next;
		}
	}
	while(head1!=NULL)
	{
		n->next=head1;
		n=n->next;
		head1=head1->next;
	}
	while(head2!=NULL)
	{
		n->next=head2;
		n=n->next;
		head2=head2->next;
	}
	return head;
}

int main()
{
	node* head1=NULL;
	node* head2=NULL;
	InsertAtBeg(20,&head1);
	InsertAtBeg(3,&head1);
	InsertAtBeg(2,&head1);
	InsertAtBeg(15,&head2);
	InsertAtBeg(10,&head2);
	InsertAtBeg(5,&head2);
	node* n=mergeSortedList(head1,head2);
	while(n!=NULL)
	{	
		printf("%d \n",n->data);
		n=n->next;
	} 
}





















