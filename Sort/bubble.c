#include<stdio.h>
main()
{
	int i,j,n,temp;
	
	//Input
	printf("how many no.s to sort\n");
	scanf("%d",&n);
	int arr[n];
	printf("Enter the elements to be sorted\n");
	for(i=0;i<n;i++)
	scanf("%d",&arr[i]);
	
	//Bubble Sort
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(arr[i]>arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	
	//display output
	printf("sorted array is \n");
	for(i=0;i<n;i++)
	printf("%d\t",arr[i]);
}
