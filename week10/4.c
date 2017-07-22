#include <stdio.h>
#include <stdlib.h>

void Insert(int hashtable[],int key)
{
	for(int i=0;i<10;i++)
	{
		if(hashtable[(key+(i*i))%10]==-1)
		{
			hashtable[(key+(i*i))%10] = key;
			break;
		}
	}
}

void Print(int hashtable[])
{
	for(int i=0;i<10;i++)
	{
		printf("%d ",hashtable[i]);
	}
	printf("\n");
}

void Search(int hashtable[],int key)
{
	for(int i=0;i<10;i++)
	{
		if(hashtable[(key+(i*i))%10]==key)
		{
			printf("found\n");
			return;
		}
	}
	printf("not found\n");
}

void Delete(int hashtable[],int key)
{
	int flag = 0,idx,ele;
	for(int i=0;i<10;i++)
	{
		if(hashtable[(key+(i*i))%10]==key)
		{
			hashtable[(key+(i*i))%10] = -1;
			idx = (key+(i*i))%10;
			flag = -1;
			break;
		}
	}
	
	int prev = idx;
	if(flag==0)
	{
		printf("no match found\n");
	}
	else
	{	
		printf("element deleted\n");	
		for(int j=0;j<10;j++)
		{
			ele = hashtable[(idx+(j*j))%10];
			if(hashtable[(idx+(j*j))%10]==-1)
			{
				break;
			}
			else if(ele%10 == (idx+(j*j))%10)
			{
				continue;
			}
			else
			{
				hashtable[prev] = ele;
				prev = (idx+(j*j))%10;
			}
		}
	}
}

int main()
{
	int hash[10]={71,23,73,99,44,19,49,93,81,39};
	int hashtable[10];
	for(int i=0;i<10;i++)
	{
		hashtable[i] = -1;
	}
	for(int i=0;i<10;i++)
	{
		Insert(hashtable,hash[i]);
	}
	//Delete(hashtable,81);
	Print(hashtable);
}
