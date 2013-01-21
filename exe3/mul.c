#include <stdio.h>
#include <stdlib.h>

void matrixMul(int * a, int * b, int * res, int size) { // η res πρέπει να είναι αρχικοποιημένη
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

int * fastPowerMatrix(int *a,int size,int power) { 
	
	int i;
	int * temp;
	int *tempTable = calloc(size*size,sizeof(int));  //αρχικοποίηση σε μοναδιαίο πίνακα
	for (i=0;i<size;i++)
		*(tempTable+i*size+i)=1;

	int * res = calloc(size*size,sizeof(int));  //αρχικοποίηση σε μοναδιαίο πίνακα
	for (i=0;i<size;i++)
		*(res+i*size+i)=1;
	
	while(power>0) {
		if(power&1) {
			matrixMul(a,res,tempTable,size);
			temp = res;
			res = tempTable;
			tempTable = temp;
		}
			
		power = power>>1;
		matrixMul(a,a,tempTable,size);
		temp = a;
		a = tempTable;
		tempTable = a;
	}
	

	return res;
	

}

int main() {
	/*int i;
	int a[4];
	a[0] = 1;
	a[1] = 2;
	a[2] = 3;
	a[3] = 4;
	int * c;
	
	

	
	
	
	int * d = malloc(4*sizeof(int));

	matrixMul(a,a,d,2);
	for (i=0;i<4;i++)
		printf("%d\n",*(d+i));	

	c = fastPowerMatrix(a,2,2);

	
	printf("the last\n");
	for (i=0;i<4;i++)
		printf("%d\n",*(c+i));*/

	int k,N,M,i,x,y,start,end;
	
	scanf("%d",&k); // επίπεδα
	scanf("%d",&N); // αιθουσες ανα επίπεδο
	scanf("%d",&M); // διάδρομοι 
	scanf("%d",&start);
	scanf("%d",&end);
	

	int * table = calloc(N*N,sizeof(int));

	for(i=0;i<M;i++) {
		scanf("%d %d",&y,&x);
		*(table+N*(y-1)+(x-1)) = 1; 
	}

	for (i=1;i<=N*N;i++) {
		printf("%d ",*(table+i-1));
		if(i%N == 0) printf("\n");
	}

	printf("---------\n");

	int *res = fastPowerMatrix(table,N,k-1);

	for (i=1;i<=N*N;i++) {
		printf("%d ",*(res+i-1));
		if(i%N == 0) printf("\n");
	}	





	

}
