#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
	return (*(char *)a - *(char *)b);
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
	qsort(arr,n,sizeof(int),compare);
	int ct=0;
	for(int i=0;i<n;i++)
	{
		int key=arr[i];
		int low=0,high=n-1;
		while(low<high)
		{
			int sum=arr[low]+arr[high];
			if(sum==key)
			{
				if(low!=i && high!=i)
				{
					ct++;
				}
				low++;
			}
			else if(sum>key)
			{
				high--;
			}
			else if(sum<key)
			{
				low++;
			}
		}
	}
	printf("%d",2*ct);
	return 0;
}
