#include <vector>
#include <map>
#include <any>
#include <tuple>
#include <cstdio>
#include <string>

// Easy implementation of an undirected graph.
// In an undirected graph, edges have no direction, and they
// represent symmetric relationships between nodes.
//
// In one restricted but very common sense of the term,a graph is an ordered pair G = ( V , E ) G=(V,E) comprising:
// V, a set of vertices (also called nodes or points),
// E  a set of edges (also called links or lines), which are unordered pairs of vertices
// (that is, an edge is associated with two distinct vertices).

class Graph {

  private:
    std::vector<std::any> vertices;
    std::vector<std::tuple<std::any, std::any>> edges;
    std::map<std::any, std::vector<std::any>> adjacency_list;

  public:
    // V vector<any> of verteces, E vector<any> of edges.
    Graph(std::vector<std::any> V, std::vector<std::tuple<std::any, std::any>> E);
    
    void create_graph();
    
    std::map<std::any, std::vector<std::any>> get_adjacency_list();

};


