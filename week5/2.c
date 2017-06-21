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

void Comb_sort(int* array, int size)
{
	int gap = size,it=1;
	gap/=1.3;
	while(gap!=1 || it==1)
	{
		it=0;
		gap=gap/(1.3);
		if(gap<1)
		{
			gap=1;
		}
		for(int i=0;i<size-gap;i++)
		{
			if(array[i]>array[i+gap])
			{
				swap(&array[i],&array[i+gap]);
				it=1;
			}
		}
		
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
	Comb_sort(array,n);
	for(int i=0;i<n;i++)
	{
		printf("%d ",array[i]);
	}
}
