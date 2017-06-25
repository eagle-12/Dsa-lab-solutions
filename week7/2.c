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

void reverse(node **head)
{
	node *prev = NULL, *curr = *head, *next;
	while(curr != NULL){
		next = curr -> next;
		curr -> next = prev;
		prev = curr;
		curr = next;
	}
	*head = prev;
}

int main()
{
	int l,m;
	scanf("%d%d",&l,&m);
	node *head=NULL;
	InsertAtBeg(1,&head);
	InsertAtBeg(2,&head);
	InsertAtBeg(9,&head);
	InsertAtBeg(3,&head);
	InsertAtBeg(5,&head);
	while(head!=NULL)
	{
		printf("%d ",head->data);
		head=head->next;
	}
	return 0;
}
