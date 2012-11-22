#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>



struct data {
	int index;
	int value;
} ;

int search (struct data table[], int tableLength,int target) {
	int i,j;
	int mid;
	i=0;
	j=tableLength;
	i=0;
	while (j>=i) {
		mid = (i+j)/2;
		if (table[mid].value < target)
        	j = mid -1 ;
      	else if (table[mid].value > target )
        	i = mid +1;
      else
        return table[mid].index;

	}
	return table[i].index;

}

int main () {

	int  day;
	int * sums;
	int maxSum,minSum,count,n,aveTemp,i;

	

	
	scanf("%d %d",&n,&aveTemp);

	sums = malloc((n+1)*sizeof(int));

	
	sums[0] = 0;
	int negative = 0;
	int positive = 0;
	for (count=1;count<=n;count++) {
		scanf("%d",&day);
		day = day - aveTemp;
		sums[count] = sums[count-1] + day; 

	} 
	//for (i=0;i<=n;i++) printf("%d %d\n",i,sums[i]);
	
	struct data table[n+1];
	table[0].value = 0;
	table[0].index = 0;
	int current = 0;
	int maxSize = -1;
	int result;
	int min = 0;
	for (count=1;count<=n;count++) {

		if (sums[count]<min) {
				current++;
				min = sums[count];
				table[current].value=sums[count];
				table[current].index = count;
			//	printf("inserting %d at position %d",sums[count],current);

		} else {
			
				result = search(table,current,sums[count]);
		//		printf("search result = %d with target %d \n",result,sums[count]);
				result = count - result;
				if (maxSize<result) maxSize = result;	
			
			
		} 
	//	printf("the maxSize is %d and count = %d\n",maxSize,count );

	}
	printf("maxSize = %d\n",maxSize);

		 

}
	
