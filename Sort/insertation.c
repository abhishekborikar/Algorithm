#include<stdio.h>
int main()
{
	int n,temp;
	printf("Enter the no of records\n");
	scanf("%d",&n);
	
	int a[n],i,j;
	printf("Enter an array of size %d \n",n);
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	
	int key,k,count=0;
	for(i=1;i<n;i++)
	{
		key = a[i];
		j=i-1;
		while(j>=0&&a[j]>key)
		{
			a[j+1]=a[j];
			count++;
			j--;
		}
		a[j+1]=key;
		

	}
//	printf("count = %d\n",count);
	printf("sorted array\n");
	for(i=0;i<n;i++)
	printf("%d\n",a[i]);
	
	return 0;
}
