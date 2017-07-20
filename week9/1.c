#include <stdio.h>
#include <string.h>

int main()
{
	char arr[100];
	scanf("%s",arr);
	int l = strlen(arr);
	int flag[256]={0};
	for(int i=0;i<l;i++)
	{
		if(flag[arr[i]]==0)
		{
			printf("%c",arr[i]);
			flag[arr[i]]=1;
		}
	}
	return 0;
}
