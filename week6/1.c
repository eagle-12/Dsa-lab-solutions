#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct Student{
	char name[20];
	int group;
};

typedef struct Student student;

int main()
{
	int n,s1,s2,s3,x;
	scanf("%d",&n);
	student stu[n],g1[n],g2[n],g3[n];
	int count[4]={0},ans[n+1];
	for(int i=0;i<n;i++){
		scanf("%s %d",stu[i].name,&stu[i].group);
		count[stu[i].group]++;
	}
	for(int i=2;i<4;i++)
	{
		count[i]+=count[i-1];
	}
	for(int i=n-1;i>=0;i--)
	{
		ans[count[stu[i].group]]=i;
		count[stu[i].group]--;
	}
	for(int i=1;i<=n;i++)
	{
		printf("%s\n",stu[ans[i]].name);
	}
	return 0;
}
