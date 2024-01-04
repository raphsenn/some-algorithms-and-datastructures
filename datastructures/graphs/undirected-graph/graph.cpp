#include "./graph.h"

Graph::Graph(std::vector<int> V, std::vector<std::tuple<int, int>> E)
  : vertices(V), edges(E) { create_graph(); }

void Graph::create_graph() {
  for (int i = 0; i < vertices.size(); i++) {
    adjacency_list[i] = {};
  }
  
  for (int i = 0; i < edges.size(); i++) {
    int from_vertex = std::get<0>(edges[i]);
    int to_vertex = std::get<1>(edges[i]);
    adjacency_list[from_vertex].emplace_back(to_vertex);
    }
  }

std::vector<int> Graph::get_verteces() { return vertices; }

std::vector<std::tuple<int, int>> Graph::get_edges() { return edges; }

void Graph::print() {
  printf("{"); 
  for (auto it = adjacency_list.begin(); it != adjacency_list.end(); ++it) {
    printf("%d: [", it->first);
    for (int j = 0; j < it->second.size(); j++) {
      if (j != it->second.size() - 1) { 
        printf("%d, ", it->second[j]);
      } else { printf("%d", it->second[j]); }
    }
    printf("]");
    if (std::next(it) != adjacency_list.end()) {
      printf(", ");
    }
  }
  printf("}\n");
  return;
}
