#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main()
{
	int n;
	scanf("%d",&n);
	int arr[n];
	int idx=-1;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	for(int i=2;i<n-1;i++)
	{
		if(arr[i]>=arr[i-1] && arr[i]>=arr[i+1])
		{
			idx=i;
			break;
		}
	}
	if(idx==-1)
	{
		if(arr[0]>arr[1])
		{
			idx=0;
		}
		else if(arr[n-1]>arr[n-2])
		{
			idx=n-1;
		}
	}
	printf("%d",idx);
}
