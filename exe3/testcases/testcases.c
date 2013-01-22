#include <stdio.h>

struct node {
	int parent;
	int size;
} ;

int find (int x, struct node * A) {
	while (x != A[x].parent)
		x = A[x].parent;
	return x ; 
}

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

}