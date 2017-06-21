#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int compare(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

int binary_search(int* array,int low,int high,int key)
{	
	int mid;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(low==high && array[low]==key)
		{
			return low;
		}
		else if(high==low+1)
		{
			if(array[low]==key)
			{
				return low;
			}
			if(array[high]==key)
			{
				return high;
			}
		}
		if(array[mid]==key)
		{
			high=mid;
		}
		else if(array[mid]<key)
		{
			low=mid+1;
		}
		else if(array[mid>key])
		{
			high=mid-1;
		}
	}
	return -1;
}

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int a[n],b[m],temp[n],vis[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		temp[i]=a[i];
		vis[i]=0;
	}
	for(int i=0;i<m;i++)
	{
		scanf("%d",&b[i]);
	}
	qsort(temp,n,sizeof(int),compare);
	int idx=0;
	for(int i=0;i<m;i++)
	{
		int ind = binary_search(temp,0,n-1,b[i]);
		if(ind==-1)
		{
			continue;
		}
		else
		{
			for(int j=ind;(j<n && temp[j]==b[i]);j++)
			{
				a[idx++]=b[i];
				vis[j]=1;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		if(vis[i]==0)
		{
			a[idx++]=temp[i];
		}
	}
	for(int i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	
	return 0;
}
