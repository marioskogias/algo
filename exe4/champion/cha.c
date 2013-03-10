#include <stdio.h>
#include <stdlib.h>
/*read fast*/
#define BSIZE 1<<15
#ifndef min
        #define min( a, b ) ( ((a) < (b)) ? (a) : (b) )
#endif
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


struct node {
	int no;
	struct node * next;

};

/*stack functions*/
void push(struct node ** list,int node) {
	
	struct node * n = malloc(sizeof(struct node));
	n->no = node;
	n->next = NULL;
	*list = n;
}

int pop(struct node ** list) {

	int no = (*list)->no;
	struct node * m = *list;
	*list = (*list)->next;
	free(m);
	return no;

}

void insert(struct node ** e,int h,int t) {
                struct node * temp1;
                struct node * temp2;
                struct node * temp = malloc(sizeof(struct node));

                temp->next = NULL;
                temp->no = t;
                temp1 = e[h];

                if (temp1 == NULL) {
                        e[h] = temp;
                }
                else {

                        while(temp1 != NULL) {
                                temp2 = temp1;
                                temp1 = temp1->next;
	
	
                        }
                        temp2->next = temp;

                }



}

int indexNo = 0;
int count = 0;
struct node ** stack ;
void tarjan(int v,int * index,int * lowLink,struct node **list,int * strong,int * S) {
	printf("tarjan\n");
	index[v] = indexNo;
	lowLink[v] = indexNo;
	index++;
	push(stack,v);
	S[v] = 1;

	struct node * t;
	t = list[v];
	
	while(t!=NULL) {
		if (index[t->no]==-1) {
			tarjan(t->no,index,lowLink,list,strong,S);
			lowLink[v] = min(lowLink[v],lowLink[t->no]);	
		}
		else 
			if (S[t->no]) {
				lowLink[v] = min(lowLink[v],index[t->no]);

			}
		t=t->next;

	}
	int u;	
	if (lowLink[v] == index[v]) {
		count++;
		do {
			u = pop(stack);
			S[u] = 0;
			strong[u] = count;


		} while( u != v);
	}
}
int main() {

	int nodeNo = readLong();
	struct node ** list = calloc(nodeNo,sizeof(struct node *));

	int i,j,k,node;
	struct node * t;
	for (i=0;i<nodeNo;i++) {
		k = readLong();
		for (j=0;j<k;j++) {
			node = readLong();
			insert(list,i,node-1);
		}

	}
	/*now the real thing*/
	int * index = malloc(nodeNo*sizeof(int));
	int * lowLink = malloc(nodeNo*sizeof(int));
	int * S = calloc(nodeNo,sizeof(int));
	int * strong = calloc(nodeNo,sizeof(int));
	stack =  malloc(sizeof(struct node *));
	*stack = NULL;
	for (i=0;i<nodeNo;i++) 
		*(index+i) = -1;


	for (i=0;i<=nodeNo;i++) {
		if (index[i] == -1) {
			tarjan(i,index,lowLink,list,strong,S);
		}
	}
	
	int count2 = 0;

	for (i=0;i<=nodeNo;i++) {
		if (strong[i] == count) {
			count2++;
		}
	}

	printf("%d\n", count);
}
