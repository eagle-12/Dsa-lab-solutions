#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void merge(int* array,int l,int mid,int r);

void partition(int* arr,int l,int r)
{
	if(l<r)
	{
		int mid=(l+r)/2;
		partition(arr,l,mid);
		partition(arr,mid+1,r);
		merge(arr,l,mid,r);
	}
}

void merge(int* array,int l,int mid,int r)
{
	int a[mid-l+1],b[r-mid];
	int i=0,j=0,k;
	for(i=0;i<(mid-l+1);i++)
	{
		a[i]=array[l+i];
	}
	for(j=0;j<(r-mid);j++)
	{
		b[j]=array[mid+1+j];
	}
	i=0;
	j=0;
	k=l;
	while(i<(mid-l+1) && j<(r-mid) && a[i]%10==0 && b[j]%10==0)
	{	
		if(a[i]<b[j])
		{
			array[k++]=a[i++];
		}
		else
		{
			array[k++]=b[j++];
		}
			
	}
	while(i<(mid-l+1) && a[i]%10==0)
	{
		array[k++]=a[i++];
	}
	while(j<(r-mid) && b[j]%10==0)
	{
		array[k++]=b[j++];
	}
	while(i<(mid-l+1) && j<(r-mid) && a[i]%10==1 && b[j]%10==1)
	{	
		if(a[i]<b[j])
		{
			array[k++]=a[i++];
		}
		else
		{
			array[k++]=b[j++];
		}
			
	}
	while(i<(mid-l+1) && a[i]%10==1)
	{
		array[k++]=a[i++];
	}
	while(j<(r-mid) && b[j]%10==1)
	{
		array[k++]=b[j++];
	}
	while(i<(mid-l+1) && j<(r-mid) && a[i]%10==2 && b[j]%10==2)
	{	
		if(a[i]<b[j])
		{
			array[k++]=a[i++];
		}
		else
		{
			array[k++]=b[j++];
		}
			
	}
	while(i<(mid-l+1) && a[i]%10==2)
	{
		array[k++]=a[i++];
	}
	while(j<(r-mid) && b[j]%10==2)
	{
		array[k++]=b[j++];
	}
	while(i<(mid-l+1) && j<(r-mid) && a[i]%10==3 && b[j]%10==3)
	{	
		if(a[i]<b[j])
		{
			array[k++]=a[i++];
		}
		else
		{
			array[k++]=b[j++];
		}
			
	}
	while(i<(mid-l+1) && a[i]%10==3)
	{
		array[k++]=a[i++];
	}
	while(j<(r-mid) && b[j]%10==3)
	{
		array[k++]=b[j++];
	}
	while(i<(mid-l+1) && j<(r-mid) && a[i]%10==4 && b[j]%10==4)
	{	
		if(a[i]<b[j])
		{
			array[k++]=a[i++];
		}
		else
		{
			array[k++]=b[j++];
		}
			
	}
	while(i<(mid-l+1) && a[i]%10==4)
	{
		array[k++]=a[i++];
	}
	while(j<(r-mid) && b[j]%10==4)
	{
		array[k++]=b[j++];
	}
	while(i<(mid-l+1) && j<(r-mid) && a[i]%10==5 && b[j]%10==5)
	{	
		if(a[i]<b[j])
		{
			array[k++]=a[i++];
		}
		else
		{
			array[k++]=b[j++];
		}
			
	}
	while(i<(mid-l+1) && a[i]%10==5)
	{
		array[k++]=a[i++];
	}
	while(j<(r-mid) && b[j]%10==5)
	{
		array[k++]=b[j++];
	}
	while(i<(mid-l+1) && j<(r-mid) && a[i]%10==6 && b[j]%10==6)
	{	
		if(a[i]<b[j])
		{
			array[k++]=a[i++];
		}
		else
		{
			array[k++]=b[j++];
		}
			
	}
	while(i<(mid-l+1) && a[i]%10==6)
	{
		array[k++]=a[i++];
	}
	while(j<(r-mid) && b[j]%10==6)
	{
		array[k++]=b[j++];
	}
	while(i<(mid-l+1) && j<(r-mid) && a[i]%10==7 && b[j]%10==7)
	{	
		if(a[i]<b[j])
		{
			array[k++]=a[i++];
		}
		else
		{
			array[k++]=b[j++];
		}
			
	}
	while(i<(mid-l+1) && a[i]%10==7)
	{
		array[k++]=a[i++];
	}
	while(j<(r-mid) && b[j]%10==7)
	{
		array[k++]=b[j++];
	}
	while(i<(mid-l+1) && j<(r-mid) && a[i]%10==8 && b[j]%10==8)
	{	
		if(a[i]<b[j])
		{
			array[k++]=a[i++];
		}
		else
		{
			array[k++]=b[j++];
		}
			
	}
	while(i<(mid-l+1) && a[i]%10==8)
	{
		array[k++]=a[i++];
	}
	while(j<(r-mid) && b[j]%10==8)
	{
		array[k++]=b[j++];
	}							
	while(i<(mid-l+1) && j<(r-mid) && a[i]%10==9 && b[j]%10==9)
	{	
		if(a[i]<b[j])
		{
			array[k++]=a[i++];
		}
		else
		{
			array[k++]=b[j++];
		}
			
	}
	while(i<(mid-l+1) && a[i]%10==9)
	{
		array[k++]=a[i++];
	}
	while(j<(r-mid) && b[j]%10==9)
	{
		array[k++]=b[j++];
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	partition(arr,0,n-1);
	for(int i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
}
