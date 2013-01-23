#include <stdio.h>
#include <stdlib.h>

#ifndef min
        #define min( a, b ) ( ((a) < (b)) ? (a) : (b) )
#endif

#ifndef max
        #define max(a,b) ( ((a) > (b)) ? (a) : (b) )
#endif

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

	int nodesNo;

	unsigned long long int sum = 0;  // το τελικό βάρος της εξόδου

	scanf("%d",&nodesNo);

	struct node * nodes = malloc(nodesNo*sizeof(struct node));

	int i;

	for (i=0;i<nodesNo;i++) {  // αρχικοποίηση του union find
		nodes[i].parent = i;
		nodes[i].size = 1;
	}

	struct edge * edges = malloc((nodesNo-1)*sizeof(struct edge));

	for (i=0;i<(nodesNo-1);i++) {
		scanf("%d %d %d",&edges[i].s,&edges[i].e,&edges[i].w);
		edges[i].e--;
		edges[i].s--;
	}
		
		
		
	
		
	randomQuickSort(edges,0,nodesNo-2);
	int val1;
	int val2;
	unsigned long long int temp;
	for (i=0;i<(nodesNo-1);i++) {
		val1 = findTreePathCompression(edges[i].s,nodes);
		val2 = findTreePathCompression(edges[i].e,nodes);

		if ((nodes[val1].size == 1) && (nodes[val2].size == 1)) {
			sum = sum + edges[i].w;
		}
			
		else if ((nodes[val1].size == 1) || (nodes[val2].size == 1))  {// αν κάποιο άκρο σε μόνο του κόμβο
			sum = sum + edges[i].w;
			sum = sum + (max(nodes[val1].size,nodes[val2].size)-1)*(edges[i].w + 1);
		}
		else {
			sum = sum + edges[i].w;
			temp = nodes[val1].size*nodes[val2].size -1 ;
			temp = temp * (edges[i].w + 1 ) ;
			sum = sum + temp;
		}   	

		unionTree(val1,val2,nodes);
	}

	printf("%llu\n",sum);




}