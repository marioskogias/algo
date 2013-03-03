#include <stdio.h>

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
	int i=0;
	while (i<2*n) {
		if (Q[i].name == x) 
			break;
		else
			i++; 
	}
	Q[i].distance = k;
	while ((i/2 != 0) && (k<Q[i/2].distance)){
		swap(Q[i],Q[i/2]);
		i=i/2;
	}
}
	
		




int main() {


}