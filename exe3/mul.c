#include <stdio.h>
#include <stdlib.h>

void matrixMul(int * a, int * b, int * res, int size) {
	int i,j,k,temp1, temp2;
	 
	for (i=0;i<size;i++) {
		temp1 = 0;
		for (k=0;k<size;k++) {
			temp1 = 0;
			for(j=0;j<size;j++) {
				temp2 = *(a+i*size+j)* (*(b+j*size+k));
				temp1 = temp1+temp2;
			}
			*(res+i*size+k) = temp1;
		}	
	}
	
}

int fastpower(int a,int n) {
	int result = 1;
	while (n>0)  {
		if (n&1) 
			result=result*a;
		n = n>>1;
		a = a*a;
	} 
	return result;	
}

int * fastPowerMatrix(int *a,int * res, int size,int power) {  // το res είναι μοναδιαίος πίνακας
	

	while(power>0) {
		if(power&1) {
			temp = matrixMul(a,res,size);
			//free(res);
			res = temp;
		}
			
		power = power>>1;
		temp = matrixMul(a,a,size);
		free(a);
		a = temp;

	}
	return res;

}

int main() {
	int i;
	int a[4];
	a[0] = 1;
	a[1] = 2;
	a[2] = 3;
	a[3] = 4;
	int * c =  malloc(4*sizeof(int)) ;
	
	matrixMul(a,a,c,2);
		
	//c =  fastPowerMatrix(a,2,2);
	//printf("----------\n");
	for (i=0;i<4;i++)
		printf("%d\n",*(c+i));

	//printf("%d\n",fastpower(2,10));
	

}
