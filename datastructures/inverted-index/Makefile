
all: compile test linktest

compile: inverted_index.o main.o link

main.o: main.cpp
	g++ -c -std=c++17 main.cpp

inverted_index.o: inverted_index.cpp
	g++ -c -std=c++17 inverted_index.cpp

test: test_inverted_index.cpp
	g++ -c -std=c++17 test_inverted_index.cpp

link:
	g++ -o main main.o inverted_index.o

linktest:
	g++ -o test inverted_index.o test_inverted_index.o -lgtest -lgtest_main -lpthread

clean:
	rm -f *.o
	rm -f main
	rm -f test
