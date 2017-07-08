#include <stdio.h>
#include <string.h>

int binary_search(int arr[],int n)
{
	int low=0,high=n-1;
	while(low<=high)
	{
		int mid=(low)+(high-low)/2;
		if(low<mid && arr[mid]<arr[mid-1])
		{
			return mid-1;
		}
		else if(high>mid && arr[mid]>arr[mid+1])
		{
			return mid;
		}
		else if(arr[low]>=arr[mid])
		{
			high=mid-1;
		}
		else if(arr[mid]>=arr[high])
		{
			low=mid+1;
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
	int idx=binary_search(arr,n);
	printf("%d",idx);
}
