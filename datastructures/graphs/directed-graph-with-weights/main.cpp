#include "./graph.h"


int main() {
  std::vector<int> V = {0, 1, 2, 3};
  std::vector<std::tuple<int, int>> E = {{0, 3}, {1, 0}, {1, 2}, {2, 3}, {3, 2}};
  Graph graph(V, E);
  printf("graph1\n"); 
  graph.print();

  std::vector<int> V2 = {0, 1};
  std::vector<std::tuple<int, int>> E2 = {{0, 1}};
  Graph graph2(V2, E2);
  printf("graph2\n"); 
  graph2.print();
}
