#include "./graph.h"


int main() {
  std::vector<int> V = {0, 1, 2, 3};
  std::vector<std::tuple<int, int>> E = {{0, 3}, {1, 0}, {1, 2}, {2, 3}, {3, 5}};
  Graph graph(V, E);
  graph.print();
}
