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

void reverse(node** h)
{	
	node* head=*h;
	if(head==NULL || head->next==NULL)
	{
		return;
	}
	node* n=CreateNode(head->data);
	head=head->next;
	while(head!=NULL)
	{
		InsertAtBeg(head->data,&n);
		head=head->next;
	}
	*h = n;
}

int isPalindrome(node** head)
{
	if(*head==NULL || (*head)->next==NULL)
	{
		return 1;
	}
	node* h1=*head;
	node* h2=*head;
	reverse(&h2);
	while(h1->next!=NULL && h2->next!=NULL)
	{
		if(h1->data==h2->data)
		{
			h1=h1->next;
			h2=h2->next;
		}
		else
		{
			return 0;
		}
	}
	return 1;
}

int main()
{
	node* head = NULL;
	InsertAtBeg(2,&head);
	InsertAtBeg(3,&head);
	InsertAtBeg(5,&head);
	InsertAtBeg(3,&head);
	InsertAtBeg(2,&head);
	int ans = isPalindrome(&head);
	if(ans==1)
	{
		printf("Yes");
	}
	else
	{
		printf("NO");
	}
}
