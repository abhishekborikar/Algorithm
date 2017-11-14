#include<stdio.h>
int main(){
	int a[]={1,2,3,4,5,6,7,8,9,10};
	int s;
	printf("Enter an element to search\n");
	scanf("%d",&s);
	int ub=9,lb=0;
	int mid = (ub+lb)/2;
	while(mid>=1){
		if(s==a[mid]){
			printf("%d",mid+1);
			break;
		}
			else if(s<a[mid]){
				ub=mid-1;
			}
				else if(s>a[mid]){
					lb=mid+1;
				}
					
				mid=(lb+ub)/2;
	}
	return 0;
}
