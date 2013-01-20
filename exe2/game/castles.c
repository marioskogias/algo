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

	int * scores = malloc(size*size*sizeof(int));


	int i,j;
	int * temp = scores;
	for (i=0;i<size;i++) 
		for (j=0;j<size;j++) {
			*(temp + i*size+j) = 0;
			//printf("i=%d j=%d\n",i,j);
		}
			 

	int * sums = malloc((size+1)*sizeof(int));
	
	sums[0] = 0;

	for (i=0;i<size;i++) { // στοιχεία στη διαγώνιο
		scanf("%d",scores+i*size+i);
		sums[i+1] = sums[i]+ *(scores+i*size+i);
	}  
		

	for(i=1;i<size;i++)   // 2άδες στην υπερδιαγώνιο 
		*(scores+(i-1)*size+i) = min(*(scores+i*size+i),*(scores+(i-1)*size+i-1));

	int l; // to mhkos parathurou
	int k; // to shmeio tomhs, thesh tou stoixeiou meta apo to opoio kovoume
	int end; // to telos tou diasthmatos pou epe3ergazomaste

	int minimum, sum1,sum2;

	int hbeg,hend; // temporary anti gia k 
	int sumleft,sumright;
	int presumleft=0,presumright=0;
	int found = 0;
	for (l=3;l<=size;l++) {
		
		//printf("%d\n",l);
		for (i=0;i<=size-l;i++) {  // i η αρχή του διαστήματος που κόβουμε
			

			end = i+l-1;
					//	printf("the start is %d and the end is %d\n",i,end);

			minimum = 0;
			
			found = 0;
		//	for (k=0;k<=end-1;k++) {
			hbeg = i;
			hend = end;
			while(hbeg<=hend) {
				
//				presumleft=sumleft;
//				presumright = sumright;
			//	printf("k = %d\n",k);*/
				k = (hend+hbeg)/2;
				

				sumleft = sums[k+1] - sums[i]; 

				if (i!=k)		// prosoxh
					sumleft = sumleft + *(scores+i*size+k);

				//printf("sum1 = %d\n",sum1);


				sumright = sums[end+1] - sums[k+1]; 

				if ((k+1)!=end)
					sumright = sumright + *(scores+(k+1)*size+end);

				
				//		printf("sum2 = %d\n",sum2);
			

				if (sumleft<sumright) 
					hbeg = k+1;
				else if (sumleft>sumright)
					hend = k-1;
				else {	
					found = 1;
					break;
				}
			}
			
			
			if (found) {
				minimum = min(sumleft,sumright);
			} else {

				presumleft = sums[hend+1] - sums[i]; 

				if (i!=hend)               // prosoxh
					presumleft = presumleft + *(scores+i*size+hend);

				//printf("sum1 = %d\n",sum1);


				presumright = sums[end+1] - sums[hend+1]; 

				if ((hend+1)!=end)
					presumright = presumright + *(scores+(hend+1)*size+end);

				sumleft = sums[hbeg+1] - sums[i]; 

				if (i!=hbeg)               // prosoxh
					presumleft = presumleft + *(scores+i*size+hbeg);

				//printf("sum1 = %d\n",sum1);


				presumright = sums[end+1] - sums[hbeg+1]; 

				if ((hbeg+1)!=end)
					presumright = presumright + *(scores+(hbeg+1)*size+end);
				
				minimum = max(min(presumleft,presumright),min(sumleft,sumright));
			}
			*(scores+i*size+end) = minimum; 

			//printf("inserted %d\n",minimum);

		}

		
	} 

	

	printf("%d\n",*(scores+size-1));


}
