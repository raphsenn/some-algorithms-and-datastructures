#include "./graph.h"

Graph::Graph(std::vector<int> V, std::vector<std::tuple<int, int>> E)
  : vertices(V), edges(E) { create_graph(); }

void Graph::create_graph() {
  for (int i = 0; i < edges.size(); i++) {
  
  }
}

std::vector<int> Graph::get_verteces() { return vertices; }

std::vector<std::tuple<int, int>> Graph::get_edges() { return edges; }


