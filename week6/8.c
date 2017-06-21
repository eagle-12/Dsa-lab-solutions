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

void DeleteAtBeg(node** head)
{	
	node* curr=*head;
	if(curr==NULL)
	{	
		printf("ERROR: Underflow\n");
		return;
	}
	if(curr->next==NULL)
	{
		free(curr);
		*head=NULL;
		return;
	}
	curr = curr->next;
	
	*head=curr;
	
	//free(curr);
	//printf("x=%d",(*head)->data);
}

void DeleteFromEnd(node** root)
{
	node* curr=*root;
	if(curr==NULL)
	{
		printf("ERROR: Underflow\n");
		return;
	}
	else if(curr->next==NULL)
	{
		free(curr);
		*root = NULL;
	}
	else
	{	
		node* tmp=NULL;
		while(curr->next!=NULL)
		{
			tmp=curr;
			curr=curr->next;
		}
		tmp->next=NULL;
		free(curr);
	}
}

int main()
{
	node* head=NULL;
	InsertAtBeg(2,&head);
	InsertAtBeg(3,&head);
	node* l=head;
	while(l!=NULL)
	{
		printf("%d \n",l->data);
		l=l->next;
	}
	DeleteAtBeg(&head);
	l=head;
	while(l!=NULL)
	{
		printf("%d \n",l->data);
		l=l->next;
	}	
}
