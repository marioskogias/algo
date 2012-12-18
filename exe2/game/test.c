#include <stdio.h>
#include <stdlib.h>

int main() {

	int size;
	scanf("%d",&size);

	int * scores = malloc(size*size*sizeof(int));
	//int scores[size][size];

	int i,j;

	for (i=0;i<size;i++) 
		for (j=0;j<size;j++) {
			*(scores + i*size+j) = 0;
		}

	scores[1][2]=0;
}