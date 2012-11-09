#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main () {

	int * days;
	int maxSum,maxStartIndex,maxEndIndex,n,aveTemp,count;

	

	maxStartIndex = 0;
	maxEndIndex = 0;
	maxSum = -214783647;
	scanf("%d %d",&n,&aveTemp);

	days = malloc(n*sizeof(int));
	for (count=0;count<n;count++) {
		scanf("%d",&days[count]);
		days[count] = days[count] - aveTemp;
	} 
		
	
	int currentMaxSum = 0;
	int currentStartIndex = 0;
	int currentEndIndex;
	for (currentEndIndex=1;currentEndIndex<=n;currentEndIndex++) {
		currentMaxSum = currentMaxSum + days[currentEndIndex];

		
		if (currentMaxSum > maxSum) {
			maxSum=currentMaxSum;
			maxStartIndex = currentStartIndex;
			maxEndIndex = currentEndIndex;
		}

		 if (currentMaxSum < 0) {
            currentMaxSum = 0;
            currentStartIndex = currentEndIndex + 1 ;
		}

    	
	}

	while ((maxSum>=0) && (maxEndIndex<n) && (maxStartIndex>=0)){
		if (days[maxStartIndex-1]>days[maxEndIndex+1]) {
				maxStartIndex = maxStartIndex-1;
				maxSum = maxSum + days[maxStartIndex];
		}
		else {
			maxEndIndex = maxEndIndex+1;
			maxSum = maxSum + days[maxEndIndex];
		}

		
			
	}
	
	int res = maxEndIndex - maxStartIndex - 1;

	printf("%d %d %d\n", maxStartIndex, maxEndIndex, maxSum);
	//printf("%d\n", res);

}