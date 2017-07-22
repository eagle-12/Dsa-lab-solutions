#include <stdio.h>
#include <stdlib.h>

int Valid(int i,int j,int n,int m)
{
	if(i<0 || j<0 || i>=n || j>=m)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

void dfs(int i,int j,int n,int m,int vis[][m],char arr[][m])
{
	vis[i][j] = 1;
	if(Valid(i-1,j,n,m) && arr[i-1][j] == 'L' && vis[i-1][j]==0)
	{
		dfs(i-1,j,n,m,vis,arr);
	}
	if(Valid(i+1,j,n,m) && arr[i+1][j] == 'L' && vis[i+1][j]==0)
	{
		dfs(i+1,j,n,m,vis,arr);
	}
	if(Valid(i,j-1,n,m) && arr[i][j-1] == 'L' && vis[i][j-1]==0)
	{
		dfs(i,j-1,n,m,vis,arr);
	}
	if(Valid(i,j+1,n,m) && arr[i][j+1] == 'L' && vis[i][j+1]==0)
	{
		dfs(i,j+1,n,m,vis,arr);
	}
}

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	char arr[n][m];
	int vis[n][m];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf(" %c",&arr[i][j]);
			vis[i][j]=0;
		}
	}
	int ct = 0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(vis[i][j]==1 || arr[i][j]=='W')
			{
				continue;
			}
			dfs(i,j,n,m,vis,arr);
			ct++;
		}
	}
	printf("%d\n",ct);
}
