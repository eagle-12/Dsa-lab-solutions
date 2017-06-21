#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main()
{	
	int n,len,ct=0;
	scanf("%d",&n);
	char arr[n][55];
	int arr1[n],Ones[n];
	int count[16]={0};
	for(int i=0;i<n;i++)
	{
		scanf("%s",arr[i]);
		arr1[i]=0;
		len=strlen(arr[i]);
		for(int j=0;j<len;j++)
		{
			arr1[i]+=(int)arr[i][j];
		}
		printf("%d ",arr1[i]);
		ct=0;
		while(arr1[i]>0)
		{
			if(arr1[i]%2==1)
			{
				ct++;
			}
			arr1[i]=arr1[i]/2;
		}
		printf("%d ",ct);
		Ones[i]=ct;
		count[ct]++;
	}
	for(int i=1;i<16;i++)
	{
		count[i]+=count[i-1];
	}
	char ans[n+1][55];
	for(int i=n-1;i>=0;i--)
	{
		strcpy(ans[count[Ones[i]]],arr[i]);
		count[Ones[i]]--;
	}
	for(int i=1;i<=n;i++)
	{
		printf("%s\n",ans[i]);
	}
}
