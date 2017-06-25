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

void swap(node** head,int n)
{
	node* curr = *(head);
	if(curr==NULL || curr->next==NULL)
	{
		return;
	}
	while(curr!=NULL && (curr->next)!=NULL)
	{
		int temp=curr->data;
		curr -> data = (curr->next)->data;
		(curr->next)->data=temp;
		curr = curr->next->next;
	}
}

int main()
{
	int n,x;
	scanf("%d",&n);
	node* head=NULL;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&x);
		InsertAtBeg(x,&head);
	}
	swap(&head,n);
	while(head!=NULL)
	{
		printf("%d ",head->data);
		head=head->next;
	}
	return 0;
}
