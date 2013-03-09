#include <stdio.h>
#include <stdlib.h>
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


struct node {
	int no;
	struct node * next;

};

/*queue functions*/
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
	if (m == NULL) 
		printf("poped NULL\n");
	free(m);
	return no;

}

/*the bfs*/
int dfs(struct node ** table,int node,int nodeNo) {
	
	struct node ** list = malloc(sizeof(struct node *));
	int * visited = calloc(nodeNo,sizeof(int));
	struct node * temp;
	push(list,node);
	int n;
	while((*list)!=NULL) {
		n = pop(list);
		printf("just poped %d\n",n);
		if (!visited[n]) {
			printf("%d\n",n);
			temp = table[n];
			while(temp!=NULL) {
				push(list,temp->no);
				printf("just pushed %d\n",temp->no);
				temp = temp->next;
			}
			visited[n] = 1;
		}

	}
	int i,count = 0;
	for(i=0;i<nodeNo;i++) 
		if (visited[i]==0) 
			count++;
			
	return count;
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
                //      printf("is NULL\n");
                }
                else {

                        while(temp1 != NULL) {
                                temp2 = temp1;
                                temp1 = temp1->next;
                        }
                        temp2->next = temp;

                }

                //printf("insert %d %d with distance %d\n",h,t,d);


}


int main() {

	int nodeNo = readLong();
	struct node ** list = calloc(nodeNo,sizeof(struct node *));
	struct node ** inverseList = calloc(nodeNo,sizeof(struct node *));

	int i,j,k,node;
	struct node * t;
	for (i=0;i<nodeNo;i++) {
		k = readLong();
		for (j=0;j<k;j++) {
			node = readLong();
			insert(list,i,node-1);
			insert(inverseList,node-1,i);
		}

	}
	
/*	printf("the structure is \n");
	for (i=0;i<nodeNo;i++) {
		t = list[i];
		while(t!=NULL) {
			printf("%d ",t->no);
			t=t->next;
		}
		printf("\n");
	}*/
	printf("the result is %d\n",dfs(list,1,nodeNo));
/*	printf("the structure is \n");
	for (i=0;i<nodeNo;i++) {
		t = list[i];
		while(t!=NULL) {
			printf("%d ",t->no);
			t=t->next;
		}
		printf("\n");
	}
	printf("let's see\n");*/
	printf("the result is %d\n",dfs(list,1,nodeNo));
	/*i = rand() % nodeNo;
	printf("now with i = %d\n",i);	
	while(bfs(list,i,nodeNo)!=0){ 
		i = rand() % nodeNo;
		printf("now with i = %d\n",i);	
	}
	printf("after the first'\n");
	printf("the result is %d\n",bfs(list,0,nodeNo));
*/
}
