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

int n=0;
int * keys;
int * place;

struct node *  EmptyQ(int count) {
	n = 0;
	struct node * q = calloc(2*count,sizeof(struct node));
	return q;
}



void swap(struct node * q1,struct node * q2) {
	int na = q1->name;
	int dis = q1->distance;
	int p;

	p = place[q1->name];
	place[q1->name] = place[q2->name];
	place[q2->name] = p;

	q1->name = q2->name;
	q1->distance = q2->distance;

	q2->name = na;
	q2->distance = dis;


}

void DecreaseKey(struct node * Q,int x,int k){
	int i = x;
	Q[i].distance = k;
	keys[Q[i].name] = k;
	while ((i/2 != 0) && (k<Q[i/2].distance)){
		swap(Q+i,Q+i/2);
		i=i/2;
	}
}

void IncreaseKey(struct node * Q,int x,int k){
	
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

void Insert(struct node *Q, int x,int k) {
	n = n+1;
	Q[n].name = x;
	Q[n].distance = k;
	keys[x] = k;
	place[x] = n;
	DecreaseKey(Q, x, k);
	printf("insertion\n");
}



struct node * ExtractMin(struct node * Q){
	struct node * p = malloc(sizeof(struct node));
	p->name = Q[1].name;
	p->distance = Q[1].distance;
	swap(Q+1,Q+n);
	//free(Q+n-1);	// mallon tha vgei
	n = n-1;
	IncreaseKey(Q, 1, Q[1].distance);
	return p;		
}
	

void insertEdge(struct edge ** e,int h,int t,int d) {
		struct edge * temp1;
		struct edge * temp2;
		struct edge * temp = malloc(sizeof(struct edge));
		
		temp->next = NULL;
		temp->tail = t;
		temp->length = d;
		temp1 = e[h];
		
		if (temp1 == NULL) {
			printf("is NULL\n");
			e[h] = temp;
		}
		else {
			temp2 = temp1;
			while(temp1 != NULL) {
				temp2 = temp1;
				temp1 = temp1->next;
			}
			temp2->next = temp;	
		}


}



int main() {
	int m,k,l,b,i,nodeNo;
	//scanf("%d %d %d %d %d",&n,&m,&k,&l,&b);
	printf("Give no of nodes and no of edges\n");
	scanf("%d %d",&nodeNo,&m);
//	int * D = malloc(n*sizeof(int));
	keys = malloc((nodeNo+1)*sizeof(int));
	place = malloc((nodeNo+1)*sizeof(int));
	struct node * Q = EmptyQ(nodeNo+1);
	
	Insert(Q, 1, 0);

	for(i=2;i<=nodeNo;i++) {
		Insert(Q,i,20001);	
	}

	for (i=1;i<=n;i++) 
		printf("node %d distance %d\n",Q[i].name, Q[i].distance);
	
	int head,tail,distance;

	struct edge ** edges = calloc(nodeNo,sizeof(struct edge *));
	
	for (i=0;i<m;i++) { // δηιουργία λίστας γειτνίασης
		printf("Give edge head tail length\n");
		scanf("%d %d %d",&head,&tail,&distance);
		head++;
		tail++;
		insertEdge(edges,head,tail,distance);
		insertEdge(edges,tail,head,distance);
		//printf("%d %d %d\n",head,e->tail,e->length);
		
	}	

	printf("created list\n");
	struct edge * temp1;

	printf("nodeNo = %d\n",nodeNo);

		
	int j;
	struct node * p;
	for (i=1;i<=nodeNo;i++) {
		p = ExtractMin(Q);
		printf("extracted %d\n",p->name);
	//	D[p->name] = p->distance;
		temp1 = edges[p->name];
		while (temp1!=NULL) {
			if ((p->distance+temp1->length) < keys[temp1->tail])
				DecreaseKey(Q, place[temp1->tail], p->distance + temp1->length);
			temp1 = temp1->next;
		}

		//free(p);
		for (j=1;j<=nodeNo;j++) 
			printf("node %d distance %d\n",Q[j].name, Q[j].distance);
	}
	printf("done with the loop\n");

	for(i=1;i<=nodeNo;i++)
		printf("%d\n",keys[i]);

}
