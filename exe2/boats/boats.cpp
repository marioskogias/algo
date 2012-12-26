#include <vector>
using namespace std;

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


int partition(struct couple A[], int left, int right,int sel) {  // sel 0 for men sel 1 for women 
 	
 	int pivot;

 	if (sel==1) {
 		pivot = A[left].woman ; 
 		int i = left -1;
		int j = right + 1; 
		while (1) {
			while (A[++i].woman < pivot) ;
			while (A[--j].woman > pivot) ;
			if (i < j) swap(A+i, A+j);
			else return(j); 
		}
 	}
 		
 	else {
		pivot = A[left].man ;
		int i = left -1;
		int j = right + 1; 
		while (1) {
			while (A[++i].man < pivot) ;
			while (A[--j].man > pivot) ;
			if (i < j) swap(A+i, A+j);
			else return(j); 
		}    		
 	}
 		
}

void randomQuickSort(struct couple * A, int left, int right,int sel) {
	if (left >= right) return; // At most 1 element
	int pivot = (rand() % (right-left)) + left ; // random pivot in range (left,right)
	swap(A+left, A+pivot);
	int q = partition(A, left, right,sel);
	randomQuickSort(A, left, q,sel);
	randomQuickSort(A, q+1, right,sel); 
}



int main() {

	int i,size;

	scanf("%d",&size);

	/* get the data */

	struct couple * couples =(struct couple *) malloc(size*sizeof(struct couple));

	for (i=0;i<size;i++) {
		scanf("%d",&((couples+i)->man));
		scanf("%d",&((couples+i)->woman));
	}

	/* sort the men increasingly with random quicksort*/

	randomQuickSort(couples,0,size-1,0);


	/*sort the same men*/
	int j;
	i=0;

	while (i<size) {
		j=i;

		while(couples[j].man == couples[j+1].man) {
			j++;
		}

		if (j>i) {
			randomQuickSort(couples,i,j,1);
			i=j;
		} else 
			i++;
	}
	/*printf("the women are\n");

	for (i=0;i<size;i++) 
		printf("%d\n",couples[i].woman);

	printf("-----------------------------\n");*/

	/*find the longest increasing subsequence in O(nlogn)*/


    int * p = (int *) malloc(size*sizeof(int)); 

    std::vector<int> b;

    int u,v;

    b.push_back(0);

    for (i=1;i<size;i++) {

    	/*greater element needs to be added*/
    	if (couples[b.back()].woman <= couples[i].woman) {
    		p[i] = b.back();
    		b.push_back(i);
    		continue;
    	}
    	

    	/*binary search to find just bigger than couples[i].woman*/
    	for (u = 0, v = b.size()-1; u < v;) {

			int c = (u + v) / 2;
			if (couples[b[c]].woman <= couples[i].woman) 
				u=c+1; 
			else v=c;
		}

		// Update b if new value is smaller then previously referenced value 
		if (couples[i].woman <= couples[b[u]].woman) {
			if (u > 0) 
				p[i] = b[u-1];
			b[u] = i;
		}


    }

    for (u = b.size(), v = b.back(); u--; v = p[v]) b[u] = v;


    printf("%d\n",(int) b.size());

   


    

}