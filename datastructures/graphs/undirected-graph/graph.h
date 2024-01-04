//////////////////////////////////////////////////////////////////////////////
// Easy implementation of an undirected graph.
// ///////////////////////////////////////////////////////////////////////////
//
// In an undirected graph, edges have no direction, and they
// represent symmetric relationships between nodes.
// For example, when A goes to B, so B must go to A.
//
// A graph is an ordered pair G = ( V , E ).
// V is a set of vertices (also called nodes or points),
// and E is a set of edges (also called links or lines), which are unordered
// pairs of vertices.
//
// We are using a adjacency list for the graph representation, but
// a adjacency matrix is also included.
//////////////////////////////////////////////////////////////////////////////
#include <vector>
#include <map>
#include <any>
#include <tuple>
#include <cstdio>
#include <string>

class Graph {
  // Let n be the number of verteces and m the number of edges from
  // the graph.
  private:
    std::vector<int> vertices;
    std::vector<std::tuple<int, int>> edges;
    std::map<int, std::vector<int>> adjacency_list;
    std::vector<std::vector<int>> adjacency_matrix;

  public:
    // V vector<any> of verteces, E vector<any> of edges.
    Graph(std::vector<int> V, std::vector<std::tuple<int, int>> E);
   
    // Fill the adjacency list.
    void create_graph();

    // Returns vector of Verteces.
    std::vector<int> get_verteces();
   
    // Returns vector of tuple of edges.
    std::vector<std::tuple<int, int>> get_edges();

    // Returns the adjacency list.
    std::map<int, std::vector<int>> get_adjacency_list();
   
    // Returns the adjacency matrix.
    std::vector<std::vector<int>> get_adjacency_matrix();
  
    // Print graph as adjacency list.
    void print();
};
