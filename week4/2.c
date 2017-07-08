#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void merge(int *arr,int l,int mid,int r)
{
	int a[mid-l+1],b[r-mid];
	for(int i=0;i<(mid-l+1);i++)
	{
		a[i]=arr[l+i];
	}
	for(int i=0;i<(r-mid);i++)
	{
		b[i]=arr[mid+i+1];
	}
	int i=0,j=0,k=l;
	while(i<(mid-l+1) && j<(r-mid))
	{
		if(a[i]<=b[j])
		{
			arr[k++]=a[i++];
		}
		else
		{
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

void merge_sort(int *arr,int l,int r)
{
	if(l<r)
	{
		int mid=(l+r)/2;
		merge_sort(arr,l,mid);
		merge_sort(arr,mid+1,r);
		merge(arr,l,mid,r);
	}
}

int main()
{
	int n,max=0,ele;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	/*for(int i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}*/
	merge_sort(arr,0,n-1);
	int ct=1;
	for(int i=1;i<n;i++)
	{
		if(arr[i]==arr[i-1])
		{
			ct++;
		}
		else
		{
			if(ct>max)
			{
				max=ct;
				ele=arr[i-1];
				ct=1;
			}
		}
	}
	/*for(int i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");*/
	if(ct>max)
	{
		max=ct;
		ele=arr[n-1];
	}
	printf("%d %d",max,ele);
}


