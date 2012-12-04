#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>



struct data {
	long long int index;
	long long int value;

} ;

long long int search (struct data table[], long long int tableLength,long long int target) {
	long long int i,j;
	long long int mid;
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

	long long int  day;
	long long int * sums;
	long long int count,n,aveTemp,i;

	

	
	scanf("%lld %lld",&n,&aveTemp);

	sums = malloc((n+1)*sizeof(long long int));

	
	sums[0] = 0;
	//long long long int negative = 0;
	//long long long int positive = 0;
	for (count=1;count<=n;count++) {
		scanf("%lld",&day);
		day = day - aveTemp;
		sums[count] = sums[count-1] + day; 

	} 
	//for (i=0;i<=n;i++) printf("%d %d\n",i,sums[i]);
	
	
	struct data *table = malloc((n+1)*sizeof(struct data));
	table[0].value = 0;
	table[0].index = 0;
	long long int current = 0;
	long long int maxSize = 0;
	long long int result;
	long long int min = 0;
	
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
	scanf("%lld",&day);
	scanf("%lld",&day);
	printf("%lld\n",maxSize);

	

}
	
