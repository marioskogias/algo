#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main () {

	int * days;
	int count,max,aveTemp,n,curent,psum,av;

	scanf("%d %d",&n,&aveTemp);

	days = malloc(n*sizeof(int));
	
	for (count=0;count<n;count++) {
		scanf("%d",&days[count]);
		days[count] = days[count] - aveTemp;
	} 
		
	
	curent = 0;
	curent = -1;
	while(curent < n) {
		count = 1;
		psum = 0;
		while ((curent+count) < n) {
			psum = psum + days[curent+count];
			if ((psum >= 0) && (max < count)) max = count;
			count++;
		}
		curent++;	
	}

	printf("%d\n", max);
	

}