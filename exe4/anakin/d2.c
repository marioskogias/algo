#include <stdio.h>
#include "stdlib.h"

/*read fast*/
#define BSIZE 1<<15

char buffer[BSIZE];
long bpos = 0L, bsize = 0L;

long readLong() 
{
	long d = 0L, x = 0L;
	char c;

	while (1)  {
		if (bpos >= bsize) {
			bpos = 0;
			if (feof(stdin)) return x;
			bsize = fread(buffer, 1, BSIZE, stdin);
		}
		c = buffer[bpos++];
		if (c >= '0' && c <= '9') { x = x*10 + (c-'0'); d = 1; }
		else if (d == 1) return x;
	}
	return -1;
}

/*nodes and edges*/

struct node {
	long int  name;
	long int  distance;
};

struct edge {
	struct edge * next;
	long int  tail;
	long int  length;
};

long int  n=0;
long int  * keys;
long int  * place;

struct node *  EmptyQ(long int  count) {
	n = 0;
	struct node * q = calloc(2*count,sizeof(struct node));
	return q;
}


/*binary heap*/
void swap(struct node * q1,struct node * q2) {
	long int  na = q1->name;
	long int  dis = q1->distance;
	long int  p;

	p = place[q1->name];
	place[q1->name] = place[q2->name];
	place[q2->name] = p;

	q1->name = q2->name;
	q1->distance = q2->distance;

	q2->name = na;
	q2->distance = dis;


}

void DecreaseKey(struct node * Q,long int  x,long int  k){
	long int  i = x;
	Q[i].distance = k;
	keys[Q[i].name] = k;
	while ((i/2 != 0) && (k<Q[i/2].distance)){
		swap(Q+i,Q+i/2);
		i=i/2;
	}
}

void IncreaseKey(struct node * Q,long int  x,long int  k){
	
	Q[x].distance = k;
	keys[Q[x].name] = k;

	while ((2*x)<n) { // while x not leaf
		if (Q[2*x].distance < Q[2*x+1].distance){
			swap(Q+x,Q+2*x);
			x=2*x;
		} else {
			swap(Q+x,Q+2*x+1);
			x=2*x+1;
		}
	}
}

void Insert(struct node *Q, long int  x,long int  k) {
	n = n+1;
	Q[n].name = x;
	Q[n].distance = k;
	keys[x] = k;
	place[x] = n;
	DecreaseKey(Q, x, k);
	//printf("insertion\n");
}



struct node * ExtractMin(struct node * Q){
	struct node * p = malloc(sizeof(struct node));
	p->name = Q[1].name;
	p->distance = Q[1].distance;
	swap(Q+1,Q+n);
	n = n-1;
	IncreaseKey(Q, 1, Q[1].distance);
	return p;		
}
	

void insertEdge(struct edge ** e,long int  h,long int  t,long int  d) {
		
		struct edge * temp = malloc(sizeof(struct edge));
		
		
		temp->tail = t;
		temp->length = d;
		temp->next = e[h];
		e[h] = temp;
		
		


}

/*random quicksort*/

void swapSort(struct node * a, struct node * b) {
	struct node temp;
	
	temp.name = a->name;
	temp.distance = a->distance;
	

	a->name = b->name;
	a->distance = b->distance;
	

	b->name = temp.name;
	b->distance = temp.distance;
	
}


long int  partition(struct node A[], long int  left, long int  right) {  // sel 0 for men sel 1 for women 
 	
 	long int  pivot;

 	pivot = A[left].distance ; 
 	long int  i = left -1;
	long int  j = right + 1; 
	while (1) {
		while (A[++i].distance < pivot) ;
		while (A[--j].distance > pivot) ;
		if (i < j) 
			swapSort(A+i, A+j);
		else return(j); 
	}
 	 		
}

void randomQuickSort(struct node * A, long int  left, long int  right) {
	if (left >= right) return; // At most 1 element
	long int  pivot = (rand() % (right-left)) + left ; // random pivot in range (left,right)
	swapSort(A+left, A+pivot);
	long int  q = partition(A, left, right);
	randomQuickSort(A, left, q);
	randomQuickSort(A, q+1, right); 
}



int  main() {
	long int  m,k,l,b,i,nodeNo; 
	nodeNo = readLong();
	m = readLong();
	k = readLong();
	l = readLong();
	b = readLong();

	/*nodes*/
	keys = malloc((nodeNo+2)*sizeof(long int ));
	place = malloc((nodeNo+2)*sizeof(long int ));
	struct node * Q = EmptyQ(nodeNo+1);
	
	Insert(Q, 1, 0);

	for(i=2;i<=nodeNo+1;i++) {
		Insert(Q,i,20001);	
	}

	
	long int  head,tail,distance;

	/*edges*/
	struct edge ** edges = calloc(nodeNo+2,sizeof(struct edge *));
	
	
	

	for (i=0;i<m;i++) { // δηιουργία λίστας γειτνίασης
		//scanf("%d %d %d",&head,&tail,&distance);
		head = readLong();
		tail = readLong();
		distance = readLong();
		head++;
		tail++;
		insertEdge(edges,head,tail,distance);
		insertEdge(edges,tail,head,distance);

	}	

	

	
	/*route*/

	long int  * route = malloc(k*sizeof(long int ));
	for (i=0;i<k;i++) {
		*(route+i)=readLong();
		*(route+i) = *(route+i) + 1;
	}
		

	
	/*route length without stops*/
	long int  sum=0;
	
	struct edge * t;
	for (i=0;i<k-1;i++) {
	
		t = edges[route[i]];
		while(t->tail!=route[i+1])
			t=t->next;
		sum = sum + t->length;

	
	}

	/*βενζινάδικα*/

	for (i=0;i<b;i++) { // εισαγωγή ακμών με μηδενικό βάρος
		
		tail = readLong();
		insertEdge(edges,1,tail+1,0);
		insertEdge(edges,tail+1,1,0);

	}

	
	
	struct edge * temp1;

	

		
	long int  j;
	struct node * p;
	for (i=1;i<=nodeNo;i++) {
		p = ExtractMin(Q);
		
		temp1 = edges[p->name];
		while (temp1!=NULL) {
			if ((p->distance+temp1->length) < keys[temp1->tail])
				DecreaseKey(Q, place[temp1->tail], p->distance + temp1->length);
			temp1 = temp1->next;
		}
		

		
	}
	

	struct node * D = malloc(k*sizeof(struct node));

	for (i=0;i<k-2;i++){
		D[i].name = Q[place[route[i+1]]].name;
		D[i].distance = Q[place[route[i+1]]].distance;
	}

	randomQuickSort(D,0,k-3);

	

	for (i=0;i<l;i++)
		sum = sum + D[i].distance;

	printf("%ld\n",sum);


	



}
