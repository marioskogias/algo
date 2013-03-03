// ====================================================================
//
//	A network optimization algorithm using Fibonacci Heap
//
//	Written by: Max Winkler
//
// ====================================================================


#include <stdlib.h>
#include <fstream>
#include <string.h>
#include <vector>
#include "FibonacciHeap.h"

int main(int argc, char *argv[])
{
	printf("K-Shortest Path Algorithm\n\n");
		
	/*
		STEP 0: Initialization
	*/
	long n;

	if(argv[1]== NULL)
	{	
		printf("1 Argument required: shortestpath.exe [graph file name]\n");
		printf("Example: ./Dijkstra.exe scotland_big.dat\n");
		return 0;
	}	

	// Define test vertices
	std::vector<Node*> vertices;
	std::vector<Edge*> edges;

	// Read source file
	printf("Loading %s\n", argv[1]);
	std::ifstream indat(argv[1]);
	char inp[100];

	if(indat)
	{
		indat.getline(inp, 160);
		n = atol(inp);

		for(int j=0; j<n-1 ; j++)
		{
			Node* v = new Node(j, -1);
			vertices.push_back(v);
		}

		printf("Vertices loaded...\n");

		vertices.push_back(new Node(n-1, 0)); 
		vertices[n-1]->state = LABELED;

		// Read edges and initialize
		while(!indat.eof())
		{
			memset(inp, '\0', sizeof(inp));
			indat.getline(inp, 160);

			int k=1;
			while(inp[k] != ' ' && inp[k]!='\0')
				k++;
			
			std::string inpstr = inp;
			int tail = atoi(const_cast<char*>(inpstr.substr(0, k).c_str()));
			int l=k+1;
			while(inp[l] != ' ' && inp[l]!='\0')
				l++;
			int head = atoi(const_cast<char*>(inpstr.substr(k+1, l).c_str()));
			k=l+1;
			
			while(inp[k] != ' ' && inp[k]!='\0')
				k++;

			double length = atof(const_cast<char*>(inpstr.substr(l+1, k).c_str()));

			Edge* edge = new Edge(vertices[tail], vertices[head], length);
			edge->head->addIncomingEdge(edge);
			edge->tail->addOutgoingEdge(edge);
			edges.push_back(edge);
		}	
	}
	else
	{
		printf("Could not open input data...\n");
		return 0;
	}

	printf("Edges loaded...\n");
	printf("Vertices: %d\nEdges: %d\n\n", vertices.size(), edges.size());
	printf("Building shortest path tree...\n");
	/*
		STEP 1: Shortest Path Tree
	*/

	FibonacciHeap* heap = new FibonacciHeap();

	heap->insertVertex(vertices[n-1]);
	
	bool abort = false;
	long j = 0;
	// Scan
	do
	{
		// Delete minimum path
		Node* v = heap->deleteMin();
		
		v->state = SCANNED;
		
		for(int i = 0; i < v->incomingEdges.size(); i++)
		{
			Edge* currentEdge = v->incomingEdges[i];
			Node* headOfCurrentEdge = currentEdge->tail;

			if(headOfCurrentEdge->state != SCANNED)
				{
				if(headOfCurrentEdge->state == UNLABELED)
				{
					// Insert a vertex with infinite key
					headOfCurrentEdge->state = LABELED;
					headOfCurrentEdge->pred = v;
					headOfCurrentEdge->key = v->key + currentEdge->length;
					heap->insertVertex(headOfCurrentEdge);
				}
				else if(headOfCurrentEdge->key > v->key + currentEdge->length )
				{
					// decrease the key of a vertex with finite key
					headOfCurrentEdge->pred = v;
					heap->decreaseKey(v->key + currentEdge->length, headOfCurrentEdge);
				}
			}
		}
	}
	while(!heap->isEmpty());

	// Print out path
	Node* temp = vertices[0];

	if(!temp->pred)
	{
		printf("There exist no s-t paths\n");
		return 0;
	}

	int vertexCount = 0;
	
	printf("Shortest Path found:\n");
	printf("Distance: %f\n", vertices[0]->key);
	
	while(temp)
	{
		printf("%d", temp->data);
		temp = temp->pred;
		if(temp)
			printf(" - ");

		vertexCount++;
	}

	printf("\nVertices passed: %d\n", vertexCount);

	return 0;
}