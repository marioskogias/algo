#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifndef max
        #define max(a,b) ( ((a) > (b)) ? (a) : (b) )
#endif
#ifndef min
        #define min( a, b ) ( ((a) < (b)) ? (a) : (b) )
#endif

void fixOne(long double  * previous, long double * beg, long double * end,long long int amount,long long int place,long long int minimum,long double * maxSofar) { //υπολογισμός άκρων διστήματος
        long double step = (amount-1)*minimum/2.0;
        *previous = *end;
        *beg = place - step;
        *end = place + step;

//      if (*maxSofar<step) *maxSofar = step;   
        
}


int main() {

long long int pointNo,minDis;

scanf("%lld",&pointNo);
scanf("%lld",&minDis);



long long int i;
long long int position;
long long int amount;
long double maxMove = 0;
long double previousRight ;
long double left,right;
long double offset;

scanf("%lld",&position); // adding the first double
scanf("%lld",&amount);

offset = (amount-1)*minDis/2.0;
left = position - offset;
right = position + offset;
maxMove = offset;
previousRight = right;


//printf ("maxMove = %.2f\n",(float)maxMove/2);

long double rest;
long double mustMove;

for (i=1;i<pointNo;i++) {
        scanf("%lld",&position); 
        scanf("%lld",&amount);
        offset = (amount-1)*minDis/2.0;
        previousRight = right; 
        left = position - offset;
        right = position + offset;
//      printf("from main begin = %.2f and end = %.2f\n", (float)left/2, (float)right/2);

        
        
        mustMove = previousRight+minDis-left; 
//      printf("mustMove = %.2f\n",(float)mustMove/2 ); 
        
        
        

        
//      printf("offset is = %.2f\n",(float)offset/2);
        if (mustMove>0) { 
  
                if (mustMove > fabs(maxMove - offset)) {
                        rest = mustMove - fabs(offset-maxMove); 
                        if (offset>maxMove) {
                            right = right + rest/2;
                            maxMove = offset + rest/2;
                        }
                        else {
                            right = right + (maxMove - offset) + rest/2;
                            maxMove = maxMove + rest/2;
                        } 
                             
                        

                       
                        
                } else{
                      //  printf("fits ok\n");
                        if (offset<maxMove) right = right + mustMove; // added condition
                        
                        maxMove = max(maxMove,offset);
                       
                       
                        }
        }                
        else if (mustMove < 0)   { //prepei na meiwsw
            //printf("mustMove < 0\n");
            if (maxMove>offset) right = right - min(fabs(mustMove),fabs(maxMove-offset)); 
            maxMove = max(maxMove,offset); 
        } 
        else {  
               // printf("mustMove = 0\n"); 
                maxMove = max(maxMove,offset);     
        }
   
                //printf("The New max just became:%f NewMostRight=%f\n",(float)maxMove/2,(float)right/2);       
        
}
        printf("%.2Lf\n",maxMove);
        
}