#include <vector>
#include <map>
#include <any>
#include <tuple>
#include <cstdio>
#include <string>

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

class Graph {

  private:
    std::vector<std::any> vertices;
    std::vector<std::tuple<std::any, std::any>> edges;
    std::map<std::any, std::vector<std::any>> adjacency_list;
    std::vector<std::vector<int>> adjacency_matrix;

  public:
    // V vector<any> of verteces, E vector<any> of edges.
    Graph(std::vector<std::any> V, std::vector<std::tuple<std::any, std::any>> E);
   
    // Fill the adjacency list.
    void create_graph();

    // Returns the adjacency list.
    std::map<std::any, std::vector<std::any>> get_adjacency_list();
   
    // Returns the adjacency matrix.
    std::vector<std::vector<int>> get_adjacency_matrix();



};
