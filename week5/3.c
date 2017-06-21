#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main()
{
	int n,ct=0,ele;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
		if(ct==0)
		{
			ele=arr[i];
			ct=1;
		}
		else
		{
			if(ele==arr[i])
			{
				ct++;
			}
			else
				ct--;
		}
	}
	if(ct==0)
	{
		printf("None");
	}
	else
	{
		ct=0;
		for(int i=0;i<n;i++)
		{
			if(arr[i]==ele)
			{
				ct++;
			}
		}
		if(ct>(n/2))
		{
			printf("%d",ele);
		}
		else
		{
			printf("None");
		}
	}
	return 0;
}	
