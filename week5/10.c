#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char dict[105][105];
char ans[105];

void Longest_Prefix(char* str,int n)
{	
	char temp[105],temp1[105];
	int a=0;
	for(int i=0;i<n;i++)
	{
		strcpy(temp,dict[i]);
		int l=strlen(temp);
		for(int j=0;j<l;j++)
		{
			temp1[j]=str[j];
		}
		temp1[l]='\0';
		if(strcmp(temp1,temp)==0)
		{
			if(a<l)
			{
				strcpy(ans,temp1);
				a=l;
			}
		}
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	char temp[105];
	for(int i=0;i<n;i++)
	{
		scanf("%s",dict[i]);
	}
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(strcmp(dict[i],dict[j])>0)
			{
				strcpy(temp,dict[j]);
				strcpy(dict[j],dict[i]);
				strcpy(dict[i],temp);
			}
		}
	}
	char str[105];
	scanf("%s",str);
	Longest_Prefix(str,n);
	printf("%s",ans);
	return 0;
}
