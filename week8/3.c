#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void insert(int heap[],int x,int *sz)
{
	*sz = *sz+1;
	int size = *sz, idx=size-1,par = (idx-1)/2;
	heap[idx] = x;
	while(idx!=0)
	{
		if(heap[par]<heap[idx])
		{
			swap(&heap[par],&heap[idx]);
		}
		idx=par;
		par=(idx-1)/2;
	}
}

int find_max(int heap[],int sz)
{
	if(sz==0)
	{
		printf("heap empty");
		return -999;
	}
	return heap[0];
}

void delete(int heap[],int *sz)
{
	int size=*sz;
	if(size==0)
	{
		printf("heap empty");
	}
	else if(size==1)
	{
		printf("element removed %d",heap[0]);
		*sz = *sz-1;
	}
	else
	{
		swap(&heap[0],&heap[size-1]);
		*sz = *sz-1;
		size--;
		int curr=0,ch1=1,ch2=2;
		while(ch1<size || ch2<size)
		{
			if(ch2>=size)
			{
				if(heap[curr]<heap[ch1])
				{
					swap(&heap[curr],&heap[ch1]);
					curr = ch1;
					ch1 = curr*2+1;
					ch2 = curr*2+2;
				}
				else
				{
					break;
				}
			}
			else
			{
				if(heap[ch1]>=heap[ch2])
				{
					if(heap[curr] < heap[ch1])
					{
						swap(&heap[curr],&heap[ch1]);
						curr = ch1;
						ch1 = curr*2+1;
						ch2 = curr*2+2;
					}
					else
					{
						break;
					}
				}
				else
				{
					if(heap[curr]<heap[ch2])
					{
						swap(&heap[curr],&heap[ch2]);
						curr = ch2;
						ch1 = curr*2+1;
						ch2 = curr*2+2;
					}
					else
					{
						break;
					}
				}
			}
		}
		printf("element removed%d",heap[size]);
	}
	
}

int main()
{
	int heap[100],sz=0;
	insert(heap,20,&sz);
	insert(heap,12,&sz);
	insert(heap,28,&sz);
	delete(heap,&sz);
}
















