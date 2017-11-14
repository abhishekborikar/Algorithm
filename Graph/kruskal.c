//kruskal minimum spanning tree
#include<stdio.h>
#include<malloc.h>

#define visited 1
#define notVisited 0

void both_visited(int, int, int, int);
void not_visited(int, int, int);//one or both source and destination not visited

int total();
int no_of_tree=0;
int final_sum =0;

typedef struct Node
{
	int leaf[9];
	int sum = 0;
	struct Node *next;
}tree;
tree *head;

int main()
{
	
	int nv;//no of vertices
	printf("Enter the no of vertices\n");
	scanf("%d",&nv);
	int ne;//no of edges
	printf("Enter the no of edges\n");
	scanf("%d",&ne);
	
	int i;
	int weight[ne] 	= {7,6,5,2,3,8,3,4,2};
	int src[ne]		= {1,2,3,4,5,6,2,3,3};
	int dest[ne]	= {2,3,4,5,6,1,6,6,5};
	
  //various input to test
//	int weight[ne]	= {4,2,6,2,7,8,5,6,4};
//	int src[ne]		= {1,2,3,4,5,6,1,2,3};
//	int dest[ne]	= {2,3,4,5,6,1,3,5,6};

//	int weight[ne]	= {4,8,7,9,10,2,1,7,8,11,4,2,14,6};
//	int src[ne]		= {1,2,3,4,5,6,7,8,1,2,3,3,4,7};
//	int dest[ne]	= {2,3,4,5,6,7,8,9,8,8,6,9,6,9};
//	int trees[nv*2][nv]={};
	
  //here inputs can be taken one by one
//	int weight[ne];
//	int src[ne];
//	int dest[ne];
//	
//	
//	printf("Enter source\n");
//	for(i=0;i<ne;i++)
//	{
//		scanf("%d",&src[i]);
//	}
//	printf("Enter destination\n");
//	for(i=0;i<ne;i++)
//	scanf("%d",&dest[i]);
//	
//	printf("Enter weight\n");
//	for(i=0;i<ne;i++)		
//	scanf("%d",&weight[i]);
	
	//sort all the but according to weight
	int temp;
	for(i=0;i<ne;i++)
	{
		int keyw = weight[i];
		int keys = src[i];
		int keyd = dest[i];
		int j	 = i-1;
		
		while(weight[j]>keyw && j>=0)
		{
			weight[j+1]	= weight[j];
			src[j+1]	= src[j];
			dest[j+1]	= dest[j];
			j--;
		}
		weight[j+1]	= keyw;
		src[j+1]	= keys;
		dest[j+1]	= keyd;
	}
	
	for(i=0;i<ne;i++)
	{
		printf("%d ",weight[i]);
		printf("%d ",src[i]);
		printf("%d\n",dest[i]);
	}
	
	//check the visited and not visited edges
	int check[ne]={};
	for(i=0;i<ne;i++)
	{
		if((check[src[i]]==visited)&&(check[dest[i]]==visited))
		{
		//	printf("visited\t%d\t%d\n",src[i],dest[i]);
			both_visited(src[i],dest[i],weight[i],nv);
		}
		else
		{
		//	printf("not visited\t%d\t%d\n",src[i],dest[i]);
			check[src[i]]=1;
			check[dest[i]]=1;
			not_visited(src[i],dest[i],weight[i]);
		}
	}

	printf("Minimum sum is %d",final_sum);
	return 0;
}

void both_visited(int src, int dest,int weight,int nv)
{
	tree *temp,*store;
	tree *tree1,*tree2;
	temp = head;
	int flag1	= 0;
	int flag2	= 0;	
	while(temp!=NULL)
	{
		int flag3=0;
		int flag4=0;
		if(temp->leaf[src]==visited)
		{
			flag1  	= 1;
			flag3	= 1;
			tree1	= temp;
		}
		if(temp->leaf[dest]==visited)
		{
			flag2	= 1;
			flag4	= 1;
			tree2	= temp;
		}
		
		store = temp;
		
		if(flag3==visited && flag4==visited)
		{
		//	printf("rejected\t%d\t%d\n",src,dest);
			return;
		}
		
		temp = temp->next;
	}

	if(flag1==visited && flag2==visited)
	{
		//connect the trees and make it one and free another tree
		int i;
		for(i=0;i<nv;i++)
		{
			if(tree2->leaf[i]!=0)
			{
				printf("%d\t",i);
				tree1->leaf[i] = visited;
			}
			
			
			if(tree1->leaf[i]!=0)
			{
				printf("%d\n",i);
				tree2->leaf[i] = visited;
			}
			
		}
		final_sum = final_sum + weight;
		
	}
	return;
}

void not_visited(int src, int dest, int weight)
{
	int flag1	= notVisited;
	int flag2	= notVisited;
	tree *temp,*store;
	tree *tree1,*tree2;
	temp = head;
	while(temp!=NULL)
	{
		if(temp->leaf[src]==1)
		{
			flag1	= visited;
			tree1	= temp;			
		}
		if(temp->leaf[dest]==1)
		{
			flag2	= visited;
			tree2	= temp;
		}
		store = temp;
		temp = temp->next;
	}
	
	if((flag1==notVisited && flag2==notVisited) || (head==NULL))
	{
		tree *newnode1 = (tree *)malloc(sizeof(tree));
		if(head==NULL)
		head = newnode1;
		else
		store->next = newnode1;
		newnode1->next = NULL;
		newnode1->leaf[src]=1;
		newnode1->leaf[dest]=1;
	}
	else if(flag1==1)
		{
			tree1->leaf[dest]=1;
		}
		else if(flag2==1)
			{
				tree2->leaf[src]=1;
			}
		final_sum = final_sum + weight;

	return;
}
