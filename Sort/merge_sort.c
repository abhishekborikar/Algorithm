#include<stdio.h>

//declare the methods
void sort(int,int);
void merge(int,int,int);

//intialize the constants
#define size 6
int a[size];
int b[size];

int main()
{
	int i;
	//Take the elements input to sort
	for(i=0;i<size;i++)
	scanf("%d",&a[i]);
	
	//call for partation
	sort(0,size-1);
	for(i=0;i<size;i++)
	printf("%d\n",a[i]);
	return 0;
}


void sort(int l,int h)//l -> low , h -> high
{
	int mid;
	if(l<h)
	{
		mid = (l+h)/2;
		printf("a %d\t%d\t%d\n",l,mid,h);
		sort(l,mid);		//create stact and push value till the condition is true and after that it pops the value
		printf("b %d\t%d\t%d\n",l,mid,h);
		sort(mid+1,h);		//creates another stact in which the values which are poped from above stack and satisfies the conditions are pushed and when condition becomes false it pops up those values
//		merge(l,mid,h);
		merge(l,mid,h);		//create the third stack where the same functioning happens as that in the second stack
	}
	return ;
}

void merge(int low, int mid, int high)
{
//	printf("\nm%d\t%d\t%d\n",low,mid,high);
	int l,m,i;
	for(l=low,m=mid+1,i=low;l<=mid && m<=high; i++)
	{
		if(a[l]<=a[m])
		b[i]=a[l++];
		else
		b[i]=a[m++];
//		printf("f1\t%d\t",b[i]);
	}
//	printf("\n");
	while(l<=mid)
	{
		b[i++]=a[l++];
//		printf("w1\t%d\t",b[--i]);
//		i++;
	}
	printf("\n");		
	while(m<=high)
	{
		b[i++]=a[m++];
//		printf("w2\t%d\t",b[--i]);
//		i++;
	}
	printf("\n");
	for(i=low;i<=high;i++)
	{
		a[i]=b[i];
//		printf("f2\t%d",b[i]);
	}
	return ;
}
