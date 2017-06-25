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

void reverse(node** head)
{
	node* curr=*(head);
	node* temp=NULL;
	while(curr!=NULL)
	{
		temp = curr->prev;
		curr->prev = curr->next;
		curr->next = temp;
		curr = curr->prev;
	}
	if(temp!=NULL)
	{
		*head = temp->prev;
	}
}

void recursive_reverse(node** head,node* pre,node* curr)
{
	if(*head==NULL)
	{
		return;
	}
	else if(curr->next==NULL)
	{
		*head=curr;
		curr->prev=NULL;
		curr->next = pre;
		return;
	}
	node* temp=curr->prev;
	curr->prev=curr->next;
	curr->next=pre;
	pre=curr;
	curr=curr->prev;
	recursive_reverse(head,pre,curr);		
}

int main()
{
	 node* head=NULL;
	 node* pre=NULL;
	 InsertAtBeg(1,&head);
	 InsertAtEnd(2,&head);
	 //InsertAtIndex(3,1,&head);
	 recursive_reverse(&head,pre,head);
	 while(head!=NULL)
	 {
	 	printf("%d ",head->data);
	 	head=head->next;
	 }
}
