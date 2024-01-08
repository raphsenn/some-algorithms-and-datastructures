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
#include <algorithm>

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

    // Fill missing edges. 
    void check_if_edges_missing(); 

    // Returns true if edge in edges, else false.
    bool edge_in_edges(std::tuple<int, int> edge);

    // Fill the adjacency list.
    void create_adjacency_list();

    // Fill the adjacency matrix.
    void create_adjacency_matrix();

    // Returns vector of Vertices.
    std::vector<int> get_vertices();
   
    // Returns vector of tuple of edges.
    std::vector<std::tuple<int, int>> get_edges();

    // Returns the in-degree of an vertex.
    int in_degree(int vertex);

    // Returns the out-degree of an vertex.
    int out_degree(int vertex);

    // Returns the adjacency list.
    std::map<int, std::vector<int>> get_adjacency_list();
   
    // Returns the adjacency matrix.
    std::vector<std::vector<int>> get_adjacency_matrix();
    
    // Returns adjacency matrix as string. 
    std::string get_adjacency_list_as_string();
   
    // Returns adjacency matrix as string. 
    std::string get_adjacency_matrix_as_string();

    // Print graph as adjacency list.
    void print();
};
