#include <stdio.h>

struct node {
	int parent;
	int size;
} ;

struct edge {
	int s;
	int e;
	int w;
};

/*sorting functions*/

void swap(struct edge * a, struct edge * b) {
	struct edge temp;
	
	temp.s = a->s;
	temp.e = a->e;
	temp.w = a->w;

	a->s = b->s;
	a->e = b->e;
	a->w = b->w;

	b->s = temp.s;
	b->e = temp.e;
	b->w = temp.w;
}


int partition(struct edge A[], int left, int right) {  // sel 0 for men sel 1 for women 
 	
 	int pivot;

 	pivot = A[left].w ; 
 	int i = left -1;
	int j = right + 1; 
	while (1) {
		while (A[++i].w < pivot) ;
		while (A[--j].w > pivot) ;
		if (i < j) 
			swap(A+i, A+j);
		else return(j); 
	}
 	 		
}

void randomQuickSort(struct edge * A, int left, int right) {
	if (left >= right) return; // At most 1 element
	int pivot = (rand() % (right-left)) + left ; // random pivot in range (left,right)
	swap(A+left, A+pivot);
	int q = partition(A, left, right);
	randomQuickSort(A, left, q);
	randomQuickSort(A, q+1, right); 
}



/*union find functions*/
/*int find (int x, struct node * A) {
	while (x != A[x].parent)
		x = A[x].parent;
	return x ; 
}*/

void unionTree(int x, int y, struct node * A) {
	if (x == y) return;
	A[y].parent = x;
	A[x].size += A[y].size; 
}  

int findTreePathCompression(int x, struct node * A) {
	if (x != A[x].parent) 
		A[x].parent = findTreePathCompression(A[x].parent,A);
	
	return(A[x].parent);    
} 

int main() {

	/*struct node a[7];

	a[0].parent = 0;
	a[0].size = 7;

	a[1].parent = 1;
	a[1].size = 1;

	a[2].parent = 0;
	a[2].size = 1;

	a[3].parent = 2;
	a[3].size = 1;

	a[4].parent = 3;
	a[4].size = 1;

	a[5].parent = 4;
	a[5].size = 1;

	a[6].parent = 4;
	a[6].size = 1;

	printf(" the parent is %d\n", findTreePathCompression(5,a));*/

	struct edge a[5];

	int i;

	for (i=0;i<5;i++)
		scanf("%d %d %d",&a[i].s,&a[i].e,&a[i].w);

	randomQuickSort(a,0,4);
	for (i=0;i<5;i++)
		printf("%d\n",a[i].w);




}