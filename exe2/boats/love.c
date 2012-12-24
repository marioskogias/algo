#include <stdio.h>
#include <stdlib.h>

struct couple {
	int man;
	int woman;
};

void swap(struct couple * a, struct couple * b) {
	struct couple temp;
	
	temp.man = a->man;
	temp.woman = a->woman;

	a->man = b->man;
	a->woman = b->woman;

	b->man = temp.man;
	b->woman = temp.woman;


}


int partition(struct couple A[], int left, int right) {
	int pivot = A[left].man ; 
	int i = left -1;
	int j = right + 1; 
	while (1) {
		while (A[++i].man < pivot) ;
		while (A[--j].man > pivot) ;
		if (i < j) swap(A+i, A+j);
		else return(j); 
	}   
}

randomQuickSort(struct couple * A, int left, int right) {
	if (left >= right) return; // At most 1 element
	//pivot = random(left, right); 
	int pivot = (rand() % (right-left)) + left ; // random pivot in range (left,right)
	swap(A+left, A+pivot);
	int q = partition(A, left, right);
	randomQuickSort(A, left, q);
	randomQuickSort(A, q+1, right); 
}





int main() {

	int i,size;

	scanf("%d",&size);

	/* get the data */

	struct couple * couples = malloc(size*sizeof(struct couple));

	for (i=0;i<size;i++) {
		scanf("%d",&((couples+i)->man));
		scanf("%d",&((couples+i)->woman));
	}

	/* sort the men increasingly with mergesort*/

	randomQuickSort(couples,0,size-1);

	for(i=0;i<size;i++)
		printf("%d\n",couples[i].man);

}