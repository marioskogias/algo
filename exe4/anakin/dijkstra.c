#include <stdio.h>
#include "stdlib.h"

struct node {
	int name;
	int distance;
};

struct edge {
	struct edge * next;
	int tail;
	int length;
};

int n;
int * keys;

struct node *  EmptyQ() {
	n = 0;
	struct node * q = malloc(n*sizeof(struct node));
	return q;
}



void swap(struct node q1,struct node q2) {
	int na = q1.name;
	int dis = q1.distance;

	q1.name = q2.name;
	q1.distance = q2.distance;

	q2.name = na;
	q2.distance = dis;

}

void DecreaseKey(struct node * Q,int x,int k){
	int i = x;
	Q[i].distance = k;
	keys[i] = k;
	while ((i/2 != 0) && (k<Q[i/2].distance)){
		swap(Q[i],Q[i/2]);
		i=i/2;
	}
}

void IncreaseKey(struct node * Q,int x,int k){
	
	Q[x].distance = k;
	keys[x] = k;

	while ((2*x)<(2*n)) {
		if (Q[2*x].distance < Q[2*x+1].distance){
			swap(Q[x],Q[2*x]);
			x=2*x;
		} else {
			swap(Q[x],Q[2*x+1]);
			x=2*x+1;
		}
	}
}

void Insert(struct node *Q, int x,int k) {
	n = n+1;
	Q[n].name = x;
	Q[n].distance = k;
	keys[x] = k;
	DecreaseKey(Q, x, k);	
}



struct node * ExtractMin(struct node * Q){
	struct node * p = malloc(sizeof(struct node));
	p->name = Q->name;
	p->distance = Q->distance;
	swap(Q[0],Q[n-1]);
	free(Q+n-1);	// mallon tha vgei
	n = n-1;
	IncreaseKey(Q, 1, Q[0].distance);
	return p;		
}
	




int main() {
	int m,k,l,b,i;
	scanf("%d %d %d %d %d",&n,&m,&k,&l,&b);
	int * D = malloc(n*sizeof(int));
	keys = malloc(n*sizeof(int));
	struct node * Q = EmptyQ();
	
	Insert(Q, 0, 0);

	for(i=1;i<n;i++) {
		Insert(Q,1,20001);	
	}
	
	int head;
	struct edge * e; 
	struct edge * temp1; 
	struct edge * temp2;

	struct edge * edges = malloc(n*sizeof(struct edge *));
	for (i=0;i<m;i++) { // δμιουργία λίστας γειτνίασης
		e = malloc(sizeof(struct edge));
		
		scanf("%d %d %d ",&head,&e->tail,&e->length);
		e->next = NULL;

		temp1 = &edges[head];
		temp2 = temp1;
		while(temp1 != NULL) {
			temp2 = temp1;
			temp1 = temp1->next;
		}
		temp2 = e;
	}	

	
	struct node * p;
	for (i=0;i<n;i++) {
		p = ExtractMin(Q);
		D[p->name] = p->distance;
		temp1 = &edges[p->name];
		while (temp1!=NULL) {
			if ((p->distance+temp1->length) < keys[temp1->tail])
				DecreaseKey(Q, temp1->tail, p->distance + temp1->length);
		}

		free(p);
	}

}