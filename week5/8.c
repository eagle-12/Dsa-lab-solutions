#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void merge(int* arr,int l,int mid,int r);

void partition(int* arr,int l,int r)
{
	if(l<r)
	{
		int mid=(l+r)/2;
		partition(arr,l,mid);
		partition(arr,mid+1,r);
		merge(arr,l,mid,r);
	}
}

void merge(int* arr,int l,int mid,int r)
{
	int a[mid-l+1];
	int b[r-mid];
	for(int i=0;i<(mid-l+1);i++)
	{
		a[i]=arr[l+i];
	}
	for(int i=0;i<(r-mid);i++)
	{
		b[i]=arr[mid+1+i];
	}
	int i=0,j=0,k=l;
	while(i<(mid-l+1))
	{
		if(a[i]%2==0)
		{
			arr[k++]=a[i++];
		}
		else
		{
			break;
		}
	}
	while(j<(r-mid))
	{
		if(b[j]%2==0)
		{
			arr[k++]=b[j++];
		}
		else
		{
			break;
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
	int arr[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	partition(arr,0,n-1);
	for(int i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
}
