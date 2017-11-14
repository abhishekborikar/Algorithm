#include<stdio.h>

//methods
void quick(int,int);
int partation(int,int,int);

//constants
#define size 5
int a[size]={5,4,3,2,1};


int main()
{
	int i;
	quick(0,size-1);
	for(i=0;i<size;i++)
	printf("%d\t",a[i]);
}

void quick(int lptr,int rptr)
{
	
	int pivot=a[rptr];
	if(rptr	<=	lptr)
	{
		return;
	}
	else
	{
		int pindex = partation(lptr,rptr,pivot);
		quick(lptr,pindex-1);
		quick(pindex+1,rptr);
	}
	
}

int partation(int left,int right,int pivot)
{
	int temp;
	int lptr = left-1;
	int rptr = right;
	
	while(true)
	{
		while(a[++lptr]<pivot);
		
		while(a[--rptr]>pivot);
		
		if(lptr>=rptr)
		{
			break;
		}
		else
		{
			temp	= a[lptr];
			a[lptr] = a[rptr];
			a[rptr] = temp;
		}
	}
	printf("p %d r %d\n",pivot,a[right]);
	temp		= a[right];
	a[right] 	= a[lptr];
	a[lptr]		= temp;
	return lptr;
}
