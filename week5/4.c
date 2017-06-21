#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int merge(int array[],int l,int mid,int r);

//int ct=0;

int merge_sort(int* array,int l,int r)
{
	int mid;
	static int ct=0;
	if(l<r)
	{
		mid=(l+r)/2;
		int ct1=merge_sort(array,l,mid);
		//printf("ct1=%d",ct1);
		
		int ct2=merge_sort(array,mid+1,r);
		//printf("ct2=%d",ct2);
		
		ct+= merge(array,l,mid,r);
		return ct;
	}
	
}

int merge(int* array,int l,int mid,int r)
{
	int a[mid-l+1],b[r-mid];
	int ct=0;
	for(int i=0;i<(mid-l+1);i++)
	{
		a[i]=array[l+i];
	}
	for(int i=0;i<(r-mid);i++)
	{
		b[i]=array[mid+i+1];
	}
	int i=0,j=0,k=l;
	while(i<=(mid-l) && j<(r-mid))
	{
		if(a[i]<=b[j])
		{
			array[k++]=a[i++];
		}
		else
		{	
			//for printing the inversions	
			for(int it=i;it<(mid-l+1);it++)
			{
				printf("%d %d\n",a[it],b[j]);
			}
			array[k++]=b[j++];
			//for calculating the number of inversions
			ct=ct+(mid-i+1);
			ct=ct-l;
		}
	}
	while(i<=(mid-l))
	{
		array[k++]=a[i++];
	}
	while(j<r-mid)
	{
		array[k++]=b[j++];
	}
	printf("ct=%d\n",ct);
	return ct;
}



int main()
{
	int n;
	scanf("%d",&n);
	int arr[n],ct;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	ct=merge_sort(arr,0,n-1);
	printf("number of inversions= %d\n",ct);
	for(int i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
}
