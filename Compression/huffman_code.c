#include<stdio.h>
#include<malloc.h>

//node of the tree
typedef struct Node{
	char data;
	unsigned freq;
	struct Node *left, *right;
}node;

//forest
typedef struct min_heap{
	unsigned size;
	unsigned capacity;
	struct Node **arr;//node pointers
}Heap;

void minHeapify(Heap* ,int);
void printHuffmanCode(node* ,int* ,int );
void huffmanMain(char*, int*, int);
void minHeapify(Heap*,int);
Heap* create_heap(unsigned);
void buildMinHeap(Heap*);
void insertHeap(Heap*, node*);
Heap* createNBuildHeap(char*, int*, int);

//create new node
node* newNode(char data,unsigned freq){
		
	node* newnode = (node*)malloc(sizeof(node));
	newnode->data = data;
	newnode->freq = freq;
	newnode->left = NULL;
	newnode->right = NULL;
	
	return newnode;
}

//step1 -> create heap struct inorder to fill it with new node
//step2 -> heap is ready build min_heap
//following is the step1
Heap* create_heap(unsigned capacity){
	Heap* heap = (Heap*)malloc(sizeof(Heap));
	
	heap->size = 0;//indicates that the heap is empty
	heap->capacity = capacity;//indicates the max size of the heap
	heap->arr  = (node**)malloc(heap->capacity * sizeof(Heap*));
	
	return heap;	
}

//step2 i.e. start building min_heap
void buildMinHeap(Heap *heap){
	//get the size of the min_heap
	int n = heap->size;
	int i;
	for(i=((n-1)/2);i>=0;--i){
		minHeapify(heap,i);
	}
	
	//print min heap
	
}

//minHeapify
void minHeapify(Heap* heap,int root){
	
	int smallest = root;
	//left and right child
	int left = (2*root)+1;
	int right = (2*root)+2;
	
	//get the samllest among three
	if(left < heap->size && 
		heap->arr[left]->freq < heap->arr[smallest]->freq)
		
		smallest = left;
		
	if(right < heap->size && 
		heap->arr[right]->freq < heap->arr[smallest]->freq)
		
		smallest = right;
		
	node *temp;
	if(smallest != root){
		temp = heap->arr[smallest];
		heap->arr[smallest] = heap->arr[root];
		heap->arr[root] = temp;
		
		minHeapify(heap,smallest);
	}
}

Heap* createNBuildHeap(char* data, int* freq,int size){
	
	Heap* heap = create_heap(size);
	
	int i;
	for(i=0;i<size ;++i){
		heap->arr[i] = newNode(data[i],freq[i]);
	}
	heap->size = size;
	
	buildMinHeap(heap);//return the min_heap
	return heap;
}

//delete the min element from the heap
node* extractMin(Heap* minHeap){
	
	int heap_size = minHeap->size;
	node* temp = minHeap->arr[0];
	minHeap->arr[0] = minHeap->arr[heap_size-1];
	minHeap->size--;
	minHeapify(minHeap,0);
	return temp;
}

//insert the element in the heap
void insertHeap(Heap* heap,node* newnode){
	heap->size++;
	
	int i = heap->size - 1;
	while(i && (newnode->freq) < (heap->arr[(i-1)/2]->freq)){
		minHeapify(heap,(i-1)/2);
		
		i = (i-1)/2;
	}
	heap->arr[i] = newnode;
	
}

node* huffmanTree(char data[], int freq[], int size){
	
	node *left, *right;
	
	Heap* heap = createNBuildHeap(data,freq,size);
	int heap_size = heap->size;
	node *top;
	int i;
	
	//iterate till size of heap is not one
	while(heap->size!=1){
		
		left = extractMin(heap);
		right = extractMin(heap);
		
		top = newNode('$',left->freq + right->freq);
		top->left = left;
		top->right = right;
		
		//insert in to the min heap
		insertHeap(heap,top);
		
	}
	printf("tree huffmanldkjls\n");
	//return the root node to print the tree
	return extractMin(heap);
}

//main function for the huffman
void huffmanMain(char data[], int *freq, int size){
	
	//construct the huffman tree
	node *root = huffmanTree(data,freq,size);

	//print the array
	int a[20],top = 0;
	printHuffmanCode(root,a,top);
}

//print the code 
void printHuffmanCode(node* root,int* a,int top){
	
	//assign 0 to left and 1 to right
	if(root->left!=NULL){
		a[top] = 0;
		printHuffmanCode(root->left,a,top+1);
	}
	
	if(root->right!=NULL){
		a[top] = 1;
		printHuffmanCode(root->right,a,top+1);
	}
	
	//check if it is leaf
	if((root->left==NULL) && (root->right==NULL)){
		printf("%c:  ",root->data);
		int i;
		for(i=0;i<top;i++)
			printf("%d",a[i]);
		printf("\n");
	}
	
}

int main(){
	
	char a[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {50, 20, 60, 40, 16, 45};
	
	int size = sizeof(a)/sizeof(a[0]);
	huffmanMain(a,freq,size);
	
	return 0;
}
