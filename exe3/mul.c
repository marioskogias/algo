#include <stdio.h>

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

int main() {

	printf("%d\n",fastpower(2,10));
	

}
