

compile:
	g++ -c -std=c++17 graph.cpp
	g++ -c -std=c++17 main.cpp
	g++ -c -std=c++17 test_graph.cpp	
	g++ -o main main.o graph.o
	g++ -o test graph.o test_graph.o -lgtest -lgtest_main -lpthread	


clean:
	rm -f *.o
	rm -f main
