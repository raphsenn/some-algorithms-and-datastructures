#include "./graph.h"

Graph::Graph(std::vector<int> V, std::vector<std::tuple<int, int>> E)
  : vertices(V), edges(E) { check_if_edges_missing(); create_adjacency_list(); }


void Graph::check_if_edges_missing() {
  for (int i = 0; i < edges.size(); i++) {
    std::tuple edge= std::make_tuple(std::get<1>(edges[i]), std::get<0>(edges[i]));
    if (!edge_in_edges(edge)) { 
      edges.emplace_back(edge);
    }
  }
}

bool Graph::edge_in_edges(std::tuple<int, int> edge) {
  if (std::find(edges.begin(), edges.end(), edge) != edges.end()) {
    return true; 
  }
  return false;
}

void Graph::create_adjacency_list() {
  for (int i = 0; i < vertices.size(); i++) {
    adjacency_list[i] = {};
  }
  
  for (int i = 0; i < edges.size(); i++) {
    int from_vertex = std::get<0>(edges[i]);
    int to_vertex = std::get<1>(edges[i]);
    adjacency_list[from_vertex].emplace_back(to_vertex);
    }
  }

void Graph::create_adjacency_matrix() {
  for (int i = 0; i < vertices.size(); i++) {
    for (int j = 0; j < vertices.size(); j++) {
      if (edge_in_edges(std::make_tuple(i, j))) {
        adjacency_matrix[i][j] = 1;
      } else { adjacency_matrix[i][j] = 0; }; 
    }
  }

}


std::vector<int> Graph::get_vertices() { return vertices; }

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
