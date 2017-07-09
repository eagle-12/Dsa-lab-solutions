#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
	return (*(char *)a - *(char *)b);
}

int main()
{
	int t,j;
	scanf("%d",&t);
	char arr[105];
	for(int i=0;i<t;i++)
	{
		scanf("%s",arr);
		int len=strlen(arr);
		for(j=len-1;j>=0;j--)
		{
			if(arr[j]>arr[j-1])
			{
				break;
			}
		}
		if(j==0)
		{
			printf("game terminated\n");
		}
		else
		{
			int flag=0,idx=-1;
			char ch,ele;
			for(int k=len-1;k>=j;k--)
			{
				if(arr[k]>arr[j-1] && flag==0)
				{
					ele=arr[k];
					idx=k;
					flag=1;
				}
				else if(arr[k]>arr[j-1])
				{
					if(arr[k]<ele)
					{
						ele=arr[k];
						idx=k;
					}
				}
			}
			ch=ele;
			arr[idx]=arr[j-1];
			arr[j-1]=ch;
			qsort(arr+j,strlen(arr+j),sizeof(char),compare);
			printf("%s",arr);
		}
	}
}
