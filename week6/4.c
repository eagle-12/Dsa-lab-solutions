#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main()
{
	int n,x,ans=0,idx;
	scanf("%d",&n);
	int arr[n],left[n],right[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
		left[i]=0;
		right[i]=0;
	}
	left[0]=arr[0];
	for(int i=1;i<n;i++)
	{	
		left[i]=arr[i];	
		if(arr[i-1]==1)
		{
			left[i]+=left[i-1];
		}	
	}
	right[n-1]=arr[n-1];
	for(int i=n-2;i>=0;i--)
	{
		right[i]=arr[i];
		if(arr[i+1]==1)
		{
			right[i]+=right[i+1];
		}
	}
	for(int i=0;i<n;i++)
	{
		if(arr[i]==0)
		{
			if(right[i]+left[i]>ans)
			{
				ans=right[i]+left[i];
				idx=i;
			}
		}
	}
	printf("%d",idx);
}
