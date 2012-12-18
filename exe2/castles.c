#include <stdio.h>
#include <stdlib.h>

#ifndef max
        #define max(a,b) ( ((a) > (b)) ? (a) : (b) )
#endif
#ifndef min
        #define min( a, b ) ( ((a) < (b)) ? (a) : (b) )
#endif



int main() {

	int size;
	scanf("%d",&size);

	//int * scores = malloc(size*size*sizeof(int));
	int scores[size][size];
	int i;

	for (i=0;i<size;i++)  // στοιχεία στη διαγώνιο
		scanf("%d",&scores[i][i]);

	for(i=1;i<=size;i++)
		scores[i-1][i] = min(scores[i][i],scores[i-1][i-1]);

	int l; // to mhkos parathurou
	int k; // to shmeio tomhs, thesh tou stoixeiou meta apo to opoio kovoume
	int end; // to telos tou diasthmatos pou epe3ergazomaste

	for (l=3;l<size;l++) {
		
		for (i=0;i<size;i=i+l) {

			end = i+l;

			for (k=0;k<end-2;k++) {
				
			}

		}

		
	}


}