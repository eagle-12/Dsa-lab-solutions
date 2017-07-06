#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n,k,min,max,ans=0;
	scanf("%d %d",&n,&k);
	int arr[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	for(int i=0;i<=n-k;i++)
	{
		min=99;
		max=-99;
		for(int j=0;j<k;j++)
		{
			if(arr[i+j]<min)
				min=arr[i+j];
			if(arr[i+j]>max)
				max=arr[i+j];				
		}
		ans+=min+max;
	}
	printf("%d",ans);
}
