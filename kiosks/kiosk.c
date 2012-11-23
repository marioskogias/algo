#include <stdio.h>
#include <stdlib.h>

#ifndef min
	#define min( a, b ) ( ((a) < (b)) ? (a) : (b) )
#endif

void fixOne(int  * table,int no,int place,int minimum,int * maxSofar) { //υπολογισμός άκρων διστήματος
	int step = (no/2)*minimum;
	//if (no%2==0) step = step/2;	

	if (no%2==0) step = step - minimum/2; 
	printf("step = %d\n",step/2);
	*table = place - step;
	*(table+1) = place + step;

	if (*maxSofar<step) *maxSofar = step;	
	
}


int main() {

int pointNo,minDis;

scanf("%d",&pointNo);
scanf("%d",&minDis);

minDis = 2*minDis;
int  * table = malloc(pointNo*2*sizeof(int)); //μέσα θα έχω τις διπλάσιες τιμές για να γλιτώσω με τα μισά

int i;
int position;
int amount;
int maxMove = 0;

int * temp = table;

scanf("%d",&position); // adding the first double
position = position*2;
scanf("%d",&amount);
fixOne(table,amount,position,minDis,&maxMove);
printf("from main begin = %.2f and end = %.2f\n", (float)(*table)/2, (float)*(table+1)/2);
table = table +2;
printf ("maxMove = %.2f\n",(float)maxMove/2);

int rest;
int mustMove;
int offset;
for (i=1;i<pointNo;i++) {
	scanf("%d",&position);
	position = position*2; 
	scanf("%d",&amount);
	fixOne(table,amount,position,minDis,&maxMove);
	printf("from main begin = %.2f and end = %.2f\n", (float)(*table)/2, (float)*(table+1)/2);

	
	
	mustMove = *(table-1)+minDis-*(table); 
	printf("mustMove = %.2f\n",(float)mustMove/2 );	
	//offset = (*(table+1)-*(table))/2;
	offset = (amount/2)*minDis;
	if (amount%2==0) offset = offset - minDis/2;	

	
	printf("offset is = %.2f\n",(float)offset/2);
	if (mustMove>0)  // check here....

		if (mustMove > (maxMove - offset)) {

			rest = mustMove - (maxMove - offset);
			maxMove =  maxMove + rest/2; //(maxMove + mustMove )/2;
			*(table+1) = maxMove + *(table+1);
			
		} else *(table+1) = mustMove + *(table+1);
		
		

	/*	rest = maxMove - ((*(table+1)-*table)/2);
//		printf("befiore is %d\n",*(table+1));
		*(table+1) = *(table+1) + min(rest,difference); // thelei min me to difference
//		printf("after is %d\n",*(table+1));
//		printf("the difference is %d\n",difference);
		if (difference - rest > 0 ) { // mporei na mhn xreiaszetai kai na to balw apo panw amesws xwris elegxo
			*(table+1) = *(table+1) + (difference - rest)/2;
			maxMove = maxMove + (difference - rest)/2;
		}
	} */
	printf("finally %.2f and maxMove = %.2f\n", (float)*(table+1)/2,(float)maxMove/2);
	table = table+2;
	printf ("maxMove = %.2f\n",(float)maxMove/2);
}
	printf("%.2f\n",(float)maxMove/2);
}