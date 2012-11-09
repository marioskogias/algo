#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main () {

        int * days;
        int count,max,aveTemp,n,curent,psum,av,startIndex,endIndex;

        scanf("%d %d",&n,&aveTemp);

        days = malloc(n*sizeof(int));
        
        for (count=0;count<n;count++) 
                scanf("%d",&days[count]);
        
        curent = 0;

        while(curent < n) {
                count = 1;
                psum = 0;
                while ((curent+count) < n) {
                        psum = psum + days[curent+count];
                        av = psum / count;
                        if ((av >= aveTemp) && (max < count)) {
                                max = count;
                                startIndex = curent;
                                endIndex = count+curent;
                        }
                        count++;
                }
                curent++;       
        }

        printf("%d %d\n", startIndex, endIndex);
        

}