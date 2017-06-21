#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void swap(int* x,int* y)
{
	int temp;
	temp = (*x);
	(*x) = (*y);
	(*y) = temp;
}

void Bubble_Sort(int* array,int size)
{
	int i=0,ele=0,idx,j;
	for(i=0;i<size;i++)
	{
		ele=array[i];
		for(j=i;j<size;j++)
		{
			if(array[j]<ele)
			{
				ele=array[j];
				idx=j;
			}
		}
		swap(&array[i],&array[idx]);
	}
}

void BBS(int* array, int size)
{
	int low=0,high=size-1;
	int min,max;
	int it=0,idx;
	while(low<=high)
	{
		if(it==0)
		{	
			idx=high;
			max=array[high];
			for(int i=low;i<=high;i++)
			{
				if(array[i]>max)
				{
					max=array[i];
					idx=i;
				}
			}
			swap(&array[idx],&array[high]);
			high--;
			it=1;
		}
		else
		{
			idx=low;
			min=array[low];
			for(int i=low;i<=high;i++)
			{
				if(array[i]<min)
				{
					idx = i;
					min = array[i];
				}
			}
			swap(&array[idx],&array[low]);
			low++;
			it=0;
		}
	}
}

void Insertion_Sort(int* array, int size)
{
	int i,j,ele;
	for(i=1;i<size;i++)
	{
		ele= array[i];
		j=i-1;
		while(j>0 && array[j]>ele)
		{
			array[j+1]=array[j];
			j--;
		}
		array[j+1]=ele;
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	int* array = (int*)malloc(sizeof(int)*n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",array+i);
	}
	BBS(array,n);
	for(int j=0;j<n;j++)
	{
		printf("%d ",*(array+j));
	}
}
