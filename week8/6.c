#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void insert(int heap[],int x,int* sz)
{
	*sz = *sz+1;
	int size = *sz,idx=size-1,par=(idx-1)/2;
	heap[idx] = x;
	while(idx!=0)
	{
		if(heap[par]<heap[idx])
		{
			swap(&heap[par],&heap[idx]);
		}
		idx = par;
		par = (idx-1)/2;
	}
}

int findMax(int heap[], int sz)
{
	if(sz==0)
	{
		printf("empty");
		return -1;
	}
	return heap[0];
}

void delete(int heap[],int *sz)
{
	int size = *sz;
	if(size==0)
	{
		printf("heap empty");
	}
	else if(size==1)
	{
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
					ch1 = 2*curr+1;
					ch2 = 2*curr+2;
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
					if(heap[curr]<heap[ch1])
					{
						swap(&heap[curr],&heap[ch1]);
						curr=ch1;
						ch1 = 2*curr+1;
						ch2 = 2*curr+2;
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
						ch1=2*curr+1;
						ch2=2*curr+2;
					}
					else
					{
						break;
					}
				}
			}
			
		}
	}
}

int kthlargestnumber(int heap[],int *sz,int k)
{
	int f=*sz;
	f=f-1;
	if(k==1)
	{
		return heap[0];
	}
	else
	{
		int ct=0;
		while(ct!=k)
		{
			delete(heap,sz);
			ct++;
		}
		int ans=heap[*sz];
		int i=*sz;
		printf("i=%d\n",i);
		printf("f=%d\n",f);
		for(int k=i;k<=f;k++)
		{
			insert(heap,heap[k],sz);
		}
		return ans;
	}
}

int main()
{
	int n,sz=0;
	scanf("%d",&n);
	int heap[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&heap[i]);
		insert(heap,heap[i],&sz);
	}
	printf("%d",heap[0]);
	int k;
	scanf("%d",&k);
	int ele=kthlargestnumber(heap,&sz,k);
	printf("%d\n",ele);
	for(int i=0;i<n;i++)
	{
		printf("%d ",heap[i]);
	}
}








