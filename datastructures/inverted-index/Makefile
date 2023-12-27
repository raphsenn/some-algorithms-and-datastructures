

compile: inverted_index.o main.o link


main.o: main.cpp
	g++ -c -std=c++17 main.cpp

inverted_index.o: inverted_index.cpp
	g++ -c -std=c++17 inverted_index.cpp


link:
	g++ -o main main.o inverted_index.o

clean:
	rm -f *.o
	rm -f main
