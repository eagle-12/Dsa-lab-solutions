#include <stdio.h>
#include <string.h>

int main()
{
	int n;
	scanf("%d",&n);
	int a[n],w[n],flag1[n],flag2[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d %d",&a[i],&w[i]);
		flag1[i]=0;
		flag2[i]=0;
	}
	for(int i=0;i<n;i++)
	{
		int ele = a[i];
		for(int j=0;j<n;j++)
		{
			if(flag1[i]==0 && flag2[j]==0 && w[j]==ele && j<=i)
			{
				flag1[i]=1;
				flag2[j]=1;
			}
		}
	}
	int ct=0;
	for(int i=0;i<n;i++)
	{
		if(flag2[i]==0)
		{
			ct++;
		}
	}
	printf("%d",ct);
}
