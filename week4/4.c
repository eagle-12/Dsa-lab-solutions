#include <stdio.h>
#include <string.h>

int binary_search(int arr[],int n,int key)
{
	int low=0,high=n-1;
	while(low<=high)
	{
		int mid=(low)+(high-low)/2;
		if(arr[mid]==key)
		{
			return mid;
		}
		else if(arr[mid]<key)
		{
			low=mid+1;
		}
		else
		{
			high=mid-1;
		}
	}
	return -1;
}

int ternary_search(int arr[],int n,int key)
{
	int low=0,high=n-1;
	while(low<=high)
	{
		int mid1=low+(high-low)/3;
		int mid2=high-(high-low)/3;
		if(arr[mid1]==key)
		{
			return mid1;
		}
		else if(arr[mid2]==key)
		{
			return mid2;
		}
		else if(arr[mid1]>key)
		{
			high=mid1-1;
		}
		else if(arr[mid2]<key)
		{
			low=mid2+1;
		}
		else
		{
			low=mid1+1;
			high=mid2-1;
		}
	}
	return -1;
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
	int ele;
	scanf("%d",&ele);
	int idx=ternary_search(arr,n,ele);
	if(idx!=-1)
	{
		printf("%d",idx);
	}
	else
	{
		printf("not found");
	}	
}
