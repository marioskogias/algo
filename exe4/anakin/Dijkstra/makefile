Dijkstra.exe: Dijkstra.o FibonacciHeap.o
	g++ Dijkstra.o FibonacciHeap.o -o Dijkstra.exe
	rm Dijkstra.o
	rm FibonacciHeap.o
FibonacciHeap.o: FibonacciHeap.cpp FibonacciHeap.h
	g++ -c FibonacciHeap.cpp
Dijkstra.o: Dijkstra.cpp
	g++ -c Dijkstra.cpp
clean:
	rm -f Dijkstra.exe *.o *~
