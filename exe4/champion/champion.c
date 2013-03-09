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
void enqueue(struct node ** listEnd,struct node ** list,int node) {
	
	struct node * n = malloc(sizeof(struct node));
	n->no = node;
	n->next = NULL;
	if (*listEnd != NULL)
		(*listEnd)->next = n;
	*listEnd = n;
	if (*list==NULL)
		*list = *listEnd;
}

int dequeue(struct node ** list,struct node ** listEnd) {

	int no = (*list)->no;
	struct node * m = *list;
	*list = (*list)->next;
	free(m);
	if (*list = NULL)
		*listEnd == NULL;
	return no;

}

/*the bfs*/
int bfs(struct node ** table,int node,int nodeNo,int * v) {

	struct node ** list = malloc(sizeof(struct node *));
	struct node ** listEnd = malloc(sizeof(struct node *));
	*list = NULL;
	*listEnd = NULL;
	int * visited;
	if (v==NULL) 
		visited = calloc(nodeNo,sizeof(int));
	else 
		visited = v;

	struct node * temp;
	enqueue(listEnd,list,node);
	int n;
	while((*list)!=NULL) {
		//printf("stack in loop1\n");
		n = dequeue(list,listEnd);
	//	printf("just poped %d\n",n);
	//	printf("%d\n",n);
		temp = table[n];
		while(temp!=NULL) {
			if (!visited[temp->no]) {
				enqueue(listEnd,list,temp->no);
				//	printf("stack in loop2\n");
				//printf("just pushed %d\n",temp->no);
				}
				temp = temp->next;
			
		}
		visited[n] = 1;


	}
	int i,info = -1;
	for(i=0;i<nodeNo;i++) 
		if (visited[i]==0){
			info =i;
			break;
		}
			
			
	return info;
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
		//		printf("stack in loop3\n");
	
	
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
	/*now the real thing*/
/*	i = rand() % nodeNo;
	k = bfs(list,i,nodeNo,NULL);
	while(k!=-1) {

	//	printf("stack in loop4\n");
		i = k; 
		k = bfs(list,i,nodeNo,NULL);
	}
	
	int * visited = calloc(nodeNo,sizeof(int));

	bfs(inverseList,i,nodeNo,visited);
	
	int count=0;
	for (i=0;i<nodeNo;i++)
		if (!visited[i])
			count++;
	printf("the result is %d\n",count);
*/
}
