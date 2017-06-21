#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int ans[1000]={0};

struct Pair{
	int x;
	int y;
};

typedef struct Pair pair;

void merge(pair* arr,int l,int mid,int r,int *ct);

void merge_sort(pair* arr,int l,int r,int* ct)
{
	if(l<r)
	{	
		int mid=(l+r)/2;
		merge_sort(arr,l,mid,ct);
		merge_sort(arr,mid+1,r,ct);
		merge(arr,l,mid,r,ct);
	}
}

void merge(pair* arr,int l,int mid,int r,int *ct)
{
	pair a[mid-l+1],b[r-mid];
	int it;
	int i=0,j=0,k;
	while(i<(mid-l+1))
	{
		a[i]=arr[l+i];
		i++;
	}
	while(j<(r-mid))
	{
		b[j]=arr[mid+1+j];
		j++;
	}
	i=0;
	j=0;
	k=l;
	while(i<(mid-l+1) && j<(r-mid))
	{
		if(a[i].x<=b[j].x)
		{
			arr[k++]=a[i++];
		}
		else
		{
			for(it=i;it<(mid-l+1);it++)
			{
				ct[a[it].y]++;
			}
			arr[k++]=b[j++];
		}
	}
	while(i<(mid-l+1))
	{
		arr[k++]=a[i++];
	}
	while(j<(r-mid))
	{
		arr[k++]=b[j++];
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	pair arr[n];
	int count[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i].x);
		arr[i].y=i;
		count[i]=0;
	}
	merge_sort(arr,0,n-1,count);
	for(int i=0;i<n;i++)
	{
		printf("%d ",count[i]);
	}
	return 0;
}
