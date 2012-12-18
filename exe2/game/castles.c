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

	int scores[size][size];


	int i,j;
	int * temp = scores;
	for (i=0;i<size;i++) 
		for (j=0;j<size;j++) {
			*(temp + i*size+j) = 0;
			//printf("i=%d j=%d\n",i,j);
		}
			 

	int sums[size+1];
	
	sums[0] = 0;
 
	for (i=0;i<size;i++) { // στοιχεία στη διαγώνιο
		scanf("%d",&scores[i][i]);
		sums[i+1] = sums[i]+scores[i][i];
	}  
		

	for(i=1;i<=size;i++)   // 2άδες στην υπερδιαγώνιο 
		scores[i-1][i] = min(scores[i][i],scores[i-1][i-1]);

	int l; // to mhkos parathurou
	int k; // to shmeio tomhs, thesh tou stoixeiou meta apo to opoio kovoume
	int end; // to telos tou diasthmatos pou epe3ergazomaste

	int minimum, sum1,sum2;


	for (l=3;l<=size;l++) {
		
		//printf("%d\n",l);
		for (i=0;i<=size-l;i++) {  // i η αρχή του διαστήματος που κόβουμε


			end = i+l-1;
					//	printf("the start is %d and the end is %d\n",i,end);

			minimum = 0;

			for (k=0;k<=end-1;k++) {

				sum1 = 0;
				sum2 = 0;

			//	printf("k = %d\n",k);*/

				

				sum1 = sums[k+1] - sums[i]; 

				if (i!=k)		// prosoxh
					sum1 = sum1 + scores[i][k];

				//printf("sum1 = %d\n",sum1);


				sum2 = sums[end+1] - sums[k+1]; 

				if ((k+1)!=end)
					sum2 = sum2 + scores[k+1][end];

						//		printf("sum2 = %d\n",sum2);

				if (minimum < min(sum1,sum2)) 
					minimum = min(sum1,sum2);	
			}

			scores[i][end] = minimum; 

			//printf("inserted %d\n",minimum);

		}

		
	} 

	/*for (i=0;i<size;i++) {
		for (j=0;j<size;j++)
			printf(" %d ",scores[i][j]);
		printf("\n");
	}*/

	printf("the result is %d\n",scores[0][size-1]);


}