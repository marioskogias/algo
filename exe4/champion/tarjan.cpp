#include <iostream> 
#include <iomanip> 
#include <stack> 
#include <algorithm> 

const int maxx = 20; 
static int strong_component = 0; 

void read_input_from_user(bool grid[][maxx], int edges) 
{ 
	int u, v; 
	for(int x = 0; x < edges; ++x) 
	{ 
		std::cout << "Enter u : \t"; 
		std::cin >> u; 
		u--; 
		std::cout << "Enter v : \t"; 
		std::cin >> v; 
		v--; 
		grid[u][v] = true; 
		std::cout << "---------------------\n"; 
	} 
	std::cout << std::endl << std::endl; 
} 
void Tarjan_algorithm(bool grid[][maxx], bool _freeN[], int lower[], 
		std::stack<int> &S, int number[], 
		int vertices, int count, int u) 
{ 
	count++; 
	number[u] = count; 
	lower[u] = number[u]; 
	S.push(u); 
	for(int v = 0; v < vertices; ++v) 
	{ 
		if(_freeN[v] && grid[u][v]) 
		{ 
			if(number[v] != 0) 
			{ 
				lower[u] = std::min(lower[u], number[v]); 
			} 
			else 
			{ 
				Tarjan_algorithm(grid, _freeN, lower, S, number, vertices, count, v); 
				lower[u] = std::min(lower[u], lower[v]); 
			} 
		} 
	} 
	if(number[u] == lower[u]) 
	{ 
		strong_component++; 
		std::cout << "Strong Component of : " << strong_component << "\n"; 
		int iss; 
		do{ 
			iss = S.top(); 
			S.pop(); 
			std::cout << iss + 1 << ','; 
			_freeN[iss] = false; 
		}while(u != iss); 
		std::cout << "\n+++++++++++++++++++++++++\n"; 
	} 
} 

int main() 
{ 
	int edges, vertices; 
	bool grid[maxx][maxx] = {}; 
	bool _freeN[maxx] = {}; 
	int number[maxx] = {}; 
	int lower[maxx] = {}; 
	//Create an empty stack 
	std::stack<int> S; 
	for(int x = 0; x < maxx; ++x) 
	{ 
		_freeN[x] = true; 
	} 
	std::cout << "Please input the number of vertices : \n"; 
	std::cin >> vertices; 
	std::cout << "Please input the number of edges : \n"; 
	std::cin >> edges; 
	read_input_from_user(grid, edges); 

	//Initialize data 
	int count = 0; 
	for(int x = 0; x < vertices; ++x) 
	{ 
		if(number[x] == 0) 
		{ 
			Tarjan_algorithm(grid, _freeN, lower, S, number, vertices, count, x); 
		} 
	} 
	return 0; 
}
