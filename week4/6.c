#include <stdio.h>
#include <string.h>

void merge(int arr[],int l,int mid,int r)
{
	int a[mid-l+1],b[r-mid];
	for(int i=0;i<(mid-l+1);i++)
	{
		a[i]=arr[l+i];
	}
	for(int j=0;j<(r-mid);j++)
	{
		b[j]=arr[mid+1+j];
	}
	int i=0,j=0,k=l;
	while(i<(mid-l+1) && j<(r-mid))
	{
		if(a[i]<b[j])
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

void merge_sort(int arr[],int l,int r)
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
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	int x;
	scanf("%d",&x);
	int i=0,j=n-1;
	for(int i=0;i<n;i++)
	{
		int key=x-arr[i];
		int low=0,high=n-1;
		int mid;
		while(low<=high)
		{
			mid=(low+high)/2;
			if(arr[mid]==key && mid!=i)
			{
				printf("found");
				return 0;
			}
			else if(arr[mid]==key && mid==i)
			{
				if(arr[mid+1]==key || arr[mid-1]==key)
				{
					printf("found");
					return 0;
				}
				else
				{
					break;
				}
			}
			else if(arr[mid]<key)
			{
				low=mid+1;
			}
			else if(arr[mid]>key)
			{
				high=mid-1;
			}
		}
	}
	printf("no");
	return 0;
}
