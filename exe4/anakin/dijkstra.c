#include <stdio.h>
#include "stdlib.h"

struct node {
	int name;
	int distance;
};

int n;

void EmptyQ() {
	n = 0;
	//RETURN a new array	
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
	while ((i/2 != 0) && (k<Q[i/2].distance)){
		swap(Q[i],Q[i/2]);
		i=i/2;
	}
}

void IncreaseKey(struct node * Q,int x,int k){
	
	Q[x].distance = k;

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


struct node * ExtractMin(struct node * Q){
	struct node * p = malloc(sizeof(struct node));
	p->name = Q->name;
	p->distance = Q->distance;
	swap(Q[0],Q[n-1]);	
	n = n-1;
	IncreaseKey(Q, 1, Q[0].distance);
	return p;		
}
	




int main() {


}