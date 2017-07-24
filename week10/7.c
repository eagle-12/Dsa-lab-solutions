#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	struct node* left;
	struct node* right;
}node;

typedef struct queue{
	node** array;
	int front;
	int rear;
	int size;
	unsigned int capacity;
}queue; 

node* CreateNode(int val)
{
	node* n = malloc(sizeof(node));
	n->data = val;
	n->left = NULL;
	n->right = NULL;
	return n;
}

queue* CreateQueue(unsigned int capacity)
{
	queue* q = malloc(sizeof(queue));
	q->array = malloc(capacity*sizeof(node*));
	q->front = 0;
	q->rear = -1;
	q->size = 0;
	q->capacity = capacity;
	return q;
}

int isFull(queue* q)
{
	return (q->size==q->capacity);
}

int isEmpty(queue* q)
{
	return (q->size==0);
}

void enqueue(queue* q,node* item)
{
	if(isFull(q))
	{
		printf("queue full");
	}
	q->rear=(q->rear+1)%(q->capacity);
	q->array[q->rear] = item;
	q->size = q->size+1;
}

node* dequeue(queue* q)
{
	if(isEmpty(q))
	{
		return NULL;
	}
	node* item = q->array[q->front];
	q->front = (q->front+1)%(q->capacity);
	q->size = q->size-1;
	return item;
}

node* front(queue* q)
{
	if(isEmpty(q))
	{
		return NULL;
	}
	return (q->array[q->front]);	
}

void inOrder(node* root,unsigned int n)
{
	queue* q = CreateQueue(n);
	node* temp = root;
	enqueue(q,temp);
	while(!isEmpty(q))
	{
		temp = dequeue(q);
		printf("%d ",temp->data);
		if(temp->left!=NULL)
		{
			enqueue(q,temp->left);
		}
		if(temp->right!=NULL)
		{
			enqueue(q,temp->right);
		}
	}
	
}

int main()
{
	node* root = NULL;
	root = CreateNode(1);
    	root->left = CreateNode(3);
    	root->right = CreateNode(5);
    	root->left->left = CreateNode(7);
    	root->left->right = CreateNode(9);
    	root->right->left = CreateNode(11);
    	root->right->right = CreateNode(13);
	inOrder(root,7);
	return 0;	
}


