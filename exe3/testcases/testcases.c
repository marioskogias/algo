#include <stdio.h>

struct node {
	int parent;
	int size;
} ;

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

	struct node a[7];
	a[0].parent = 0;
	a[0].size = 7;

	a[1].parent = 0;
	a[1].size = 0;

	a[2].parent = 0;
	a[2].size = 0;

	a[3].parent = 2;
	a[3].size = 0;

	a[4].parent = 3;
	a[4].size = 0;

	a[5].parent = 4;
	a[5].size = 0;

	a[6].parent = 4;
	a[6].size = 0;

	printf(" the parent is %d\n", findTreePathCompression(5,a));


}