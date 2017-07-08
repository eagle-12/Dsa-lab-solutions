#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n,x,ans;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	for(int i=0;i<n;i++)
	{
		x = arr[i];
		int ct[10]={0};
		ans=1;
		while(x)
		{
			ct[x%10]++;
			x=x/10;
		}
		for(int j=0;j<10;j++)
		{
			if(ct[j]>1 || ct[1]==1 && j!=1 && ct[j]==1)
			{
				ans=0;
				break;
			}
			else if(j!=0 && ct[j]==1 && ct[0]==1)
			{
				ans=0;
				break;
			}
		}
		if(ct[8]==1 && ct[4]==1 && ct[2]==1)
		{
			ans=0;
			//break;
		}
		else if(ct[6]==1 && ct[2]==1 && ct[3]==1)
		{
			ans=0;
			//break;
		}
		if(ans==1)
		{
			printf("%d ",arr[i]);
		}
	}
	return 0;
}
