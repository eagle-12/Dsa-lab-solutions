#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void reverse(char* c,char* s)
{
	char temp;
	while(c<s)
	{
		temp=*c;
		*c++ = *s;
		*s-- = temp;
	}
}

int main()
{
	char line[1000];
	scanf("%[^\n]",line);
	//printf("%s",line);
	int len=strlen(line);
	reverse(line,line+len-1);
	int low=0,high;
	for(int i=0;i<len;i++)
	{
		if(line[i]==' ')
		{
			high=i-1;
			reverse(line+low,line+high);
			low=i+1;
		}
		else if(i==len-1)
		{
			high=len-1;
			reverse(line+low,line+high);
		}
	}
	printf("%s",line);
}
