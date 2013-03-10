#include <stdio.h>
#include <stdlib.h>
#define GRAPHSIZE 30010

struct node 
{
    long long int second;
    struct node *next;  /*black pointer*/
};

struct node Deiktes[GRAPHSIZE];
struct node *temp;
struct node *temp2;
long long int n,m,k,l,i,j,nod,winner,top,strong,indexing,v,u,count;
long long int Strongly[GRAPHSIZE];
long long int Stack[GRAPHSIZE];
long long int S[GRAPHSIZE];
long long int indexer[GRAPHSIZE];
long long int lowlink[GRAPHSIZE];

long long int explore(long long int komvos) {
    temp = &Deiktes[komvos];
    temp2 = temp->next;
    if (temp2 != NULL) {
        nod = temp2->second;
        temp->next = temp2->next;
    }
    else {
        nod = -1;
    }
    return nod;
}

long long int pop(void) {
    u = Stack[top];
    top--;
    S[u] = 0;
    return u;
}

void push(long long int v) {
    top++;	
    Stack[top] = v;
    S[v] = 1;
}

void strongconnect(long long int v) {
    long long int w;

    indexer[v] = indexing;
    lowlink[v] = indexing;
    indexing++;
    push(v);
    while ((w = explore(v)) != -1) {
        if (indexer[w] == -1) {
            strongconnect(w);
            if (lowlink[w] < lowlink[v]) 
                lowlink[v] = lowlink[w];
        }
        else if (S[w] == 1) {
            if (indexer[w] < lowlink[v]) 
                lowlink[v] = indexer[w];
        } 
    }

    if (lowlink[v] == indexer[v]) {
        strong++;
        do {
            w = pop();
            Strongly[w] = strong;
        } while (w != v);
    }
}

int main(void) {

    scanf("%lld", &n);
    for (k=1;k<=n;k++) {
        Deiktes[k].next = NULL;
        indexer[k]=-1;
        S[k]=0;
        Strongly[k] = 0;
    }

    for (i = 1; i <= n; ++i) {
        scanf("%lld", &m);

        for (j = 0; j < m; ++j) {
            scanf("%lld", &winner);

            temp=(struct node *)malloc(sizeof(struct node));
            temp->second=i;
            temp->next=Deiktes[winner].next;
            Deiktes[winner].next=temp;  /* pointing to the first node */
        }
    }

    top = 0;
    strong = 0;
    indexing = 0;

    for (i=1;i<=n;i++) {
        if (indexer[i] == -1) {
            strongconnect(i);
        }
    }
		printf("%lld ",strong);
  /*  count = 0;
	printf("for strong = %lld\n",strong);
    for (i=1;i<=n;i++) {
        if (Strongly[i] == strong) {
            count++;
        }
    }
    
    printf("%lld\n", count);
*/
    return 0;
}


