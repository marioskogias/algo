#include <stdio.h>
#include <stdlib.h>

void matrixMul(long long int  * a, long long int  * b, long long int  * res, long long int  size) { // η res πρέπει να είναι αρχικοποιημένη
	long long int  i,j,k,temp1, temp2;
	 
	for (i=0;i<size;i++) {
		temp1 = 0;
		for (k=0;k<size;k++) {
			temp1 = 0;
			for(j=0;j<size;j++) {
				temp2 = (*(a+i*size+j) % 100000007) * (*(b+j*size+k) % 100000007);
				printf("%lld * %lld = %lld\n",*(a+i*size+j) % 100000007,*(b+j*size+k) % 100000007,temp2);
				temp1 = temp1+temp2;
			}
			*(res+i*size+k) = temp1;
		}	
	}
	
}

long long int  fastpower(long long int  a,long long int  n) {
	long long int  result = 1;
	while (n>0)  {
		if (n&1) 
			result=result*a;
		n = n>>1;
		a = a*a;
	} 
	return result;	
}

long long int  * fastPowerMatrix(long long int  *a,long long int  size,long long int  power) { 
	
	int i;
	long long int  * temp;
	long long int  *tempTable = calloc(size*size,sizeof(long long int ));  //αρχικοποίηση σε μοναδιαίο πίνακα
	for (i=0;i<size;i++)
		*(tempTable+i*size+i)=1;

	long long int  * res = calloc(size*size,sizeof(long long int ));  //αρχικοποίηση σε μοναδιαίο πίνακα
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

int  main() {
	/*long long int  i;
	long long int  a[4];
	a[0] = 1;
	a[1] = 2;
	a[2] = 3;
	a[3] = 4;
	long long int  * c;
	
	

	
	
	
	long long int  * d = malloc(4*sizeof(long long int ));

	matrixMul(a,a,d,2);
	for (i=0;i<4;i++)
		printf("%d\n",*(d+i));	

	c = fastPowerMatrix(a,2,2);

	
	printf("the last\n");
	for (i=0;i<4;i++)
		printf("%d\n",*(c+i));*/

	int  k,N,M,i,x,y,start,end;
	
	scanf("%d",&k); // επίπεδα
	scanf("%d",&N); // αιθουσες ανα επίπεδο
	scanf("%d",&M); // διάδρομοι 
	scanf("%d",&start);
	scanf("%d",&end);


	

	long long int  * table = calloc(N*N,sizeof(long long int ));

	for(i=0;i<M;i++) {
		scanf("%d %d",&y,&x);
		*(table+N*(y-1)+(x-1)) = 1; 
	}

	for (i=1;i<=N*N;i++) {
		printf("%lld ",*(table+i-1));
		if(i%N == 0) printf("\n");
	}

	

	long long int  *res = fastPowerMatrix(table,N,k-2);
	printf("---------\n");
	for (i=1;i<=N*N;i++) {
		printf("%lld ",*(res+i-1));
		if(i%N == 0) printf("\n");
	}	





	

}
