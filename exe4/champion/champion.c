#include <stdio.h>
#include <stdlib.h>

struct node {
	int no;
	struct node * next;

};

void push(struct node ** list,int node) {
	
	struct node * n = malloc(sizeof(struct node));
	n->no = node;
	n->next = *list;
	*list = n;
}

int pop(struct node ** list) {

	int no = (*list)->no;
	struct node * m = *list;
	*list = (*list)->next;
	free(m);
	return no;

}
void bfs(struct node ** table,int node) {
	
	struct node ** list = malloc(sizeof(struct node *));

	struct node * temp;
	push(list,node);
	int n;
	while((*list)!=NULL) {
		n = pop(list);
		printf("%d\n",n);
		temp = table[n];
		while(temp!=NULL) {
			push(list,temp->no);
			temp = temp->next;
		}
	}
	
	

}

int main() {

	struct node ** list = calloc(4,sizeof(struct node *));
	struct node * t = malloc(sizeof(struct node));
	t->no = 1;
	t->next = NULL;

	list[0] = t;
	
	t = malloc(sizeof(struct node));
	t->no = 2;
	t->next = NULL;
	
	list[0]->next = t;

	
	t = malloc(sizeof(struct node));
	t->no = 3;
	t->next = NULL;

	list[1] = t;
	bfs(list,0);

}
