#include <stdio.h>
#include <stdlib.h>

#ifndef min
	#define min( a, b ) ( ((a) < (b)) ? (a) : (b) )
#endif

void fixOne(int  * table,int no,int place,int minimum,int * maxSofar) { //υπολογισμός άκρων διστήματος
	int step = (no/2)*minimum;
	//if (no%2==0) step = step/2;	

	if (no%2==0) step = step - step/2; 
	printf("step = %d\n",step);
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
printf("from main begin = %d and end = %d\n", *table, *(table+1));
table = table +2;

int difference;
int rest;
for (i=1;i<pointNo;i++) {
	scanf("%d",&position);
	position = position*2; 
	scanf("%d",&amount);
	fixOne(table,amount,position,minDis,&maxMove);
	printf("from main begin = %d and end = %d\n", *table, *(table+1));

	
	
	difference = *(table-1)+minDis-*(table); 	
	if (difference>0) {
		
		

		rest = maxMove - ((*(table+1)-*table)/2);
//		printf("befiore is %d\n",*(table+1));
		*(table+1) = *(table+1) + min(rest,difference); // thelei min me to difference
//		printf("after is %d\n",*(table+1));
//		printf("the difference is %d\n",difference);
		if (difference - rest > 0 ) { // mporei na mhn xreiaszetai kai na to balw apo panw amesws xwris elegxo
			*(table+1) = *(table+1) + (difference - rest)/2;
			maxMove = maxMove + (difference - rest)/2;
		}
	} 
	printf("finally %d\n", *(table+1));
	table = table+2;
//	printf ("%d, maxMove = %d\n",i,maxMove);
}
	printf("%.2f\n",(float)maxMove/2);
}