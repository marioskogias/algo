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

	int i,j;

		for (i=0;i<size;i++) 
		for (j=0;j<size;j++)
			scores[i][j]=0;

	for (i=0;i<size;i++)  // στοιχεία στη διαγώνιο
		scanf("%d",&scores[i][i]);

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

			//	printf("k = %d\n",k);

				for (j=i;j<=k;j++) 
					sum1 = sum1 + scores[j][j];

				if (i!=k)		// prosoxh
					sum1 = sum1 + scores[i][k];

				//printf("sum1 = %d\n",sum1);

				for (j=k+1;j<=end;j++)
					sum2 = sum2 + scores[j][j];

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