#include <stdio.h>
#include <stdlib.h>


typedef struct node {
	long long int node;
	struct node *next;
} node ;



int main(int argc , char **argv ) {
	
	long long int k,N,M,s,t,*Paths_before,*Paths_next,i,u,v,j,node_to;
	node **adj_list , *temp_node ;	

	//adj_list[i] contains the nodes that are reachable from i from the next level 

	scanf("%lld%lld%lld%lld%lld",&k,&N,&M,&s,&t);

	N += 1 ;
	k -= 1 ;
	
	adj_list = malloc(sizeof(*adj_list) * N );
	for ( i = 1 ; i < N ; i++) 
		adj_list[i] = NULL ;		

	Paths_before = malloc(sizeof(long long int) * N );
	Paths_next   = malloc(sizeof(long long int) * N );
	
	for(i = 1 ; i<N ; i++) {
		Paths_before[i] = 0;
		Paths_next[i] = 0;
	}
	
	Paths_before[s] = 1;

	for ( i = 0 ; i<M ; i++) {
		scanf("%lld%lld",&u,&v);
		temp_node = malloc(sizeof(node));
		temp_node->node=v ;
		temp_node->next = adj_list[u];
		adj_list[u] = temp_node ;	
	}
	
		
	
	for ( i = 0 ; i < k ; i++) {	
		for ( j = 1 ; j < N ; j++) {
			temp_node = adj_list[j] ;
			while(temp_node != NULL) {
				node_to = temp_node->node;	
				Paths_next[node_to] += Paths_before[j]%(100000007);		
				temp_node = temp_node->next ;
			}
		}
		for( j=1 ; j<N; j++ ) {
			Paths_before[j] = Paths_next[j];	
			Paths_next[j] = 0;
		}
	}
	//Paths_before exei to posa monopatia ftanoun ston kathe komvo tou k epipedou
	for (i=0;i<N;i++)
		printf("%lld\n",Paths_before[i]%(100000007));
	free(Paths_before);
	free(Paths_next);
	exit(0);
}
