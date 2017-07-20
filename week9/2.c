#include <stdio.h>
#include <string.h>

int main()
{
	char str[105];
	scanf("%s",str);
	int flag[26]={0};
	int l = strlen(str);
	int ct=0,idx=0,id=0,ans=0;
	for(int i=0;i<l;i++)
	{
		if(flag[str[i]-97]==0)
		{
			ct++;
			flag[str[i]-97]=1;
		}
		else
		{
			if(ans<ct)
			{
				ans = ct;
				id = i-ct;
			}
			for(int j=0;j<26;j++)
			{
				flag[j]=0;
			}
			flag[str[i]-97]=1;
			ct = 1;
		}
	}
	if(ans<ct)
	{
		ans = ct;
		id = idx;
	}
	printf("%d",ans);
	for(int i=0;i<=ct;i++)
	{
		printf("%c",str[id+i]);
	}
	printf("\n");
	return 0;
}
