#include <gtest/gtest.h>
#include "./graph.h"

//////////////////////////////////////////////////////////////////////////////
// Test: get_vertcies
//////////////////////////////////////////////////////////////////////////////

TEST(graph, get_vertices_1) {
  std::vector<int> vertices = {0, 1};
  std::vector<std::tuple<int, int>> edges = {{0, 1}, {1, 0}};
  Graph graph(vertices, edges);
  ASSERT_EQ(graph.get_vertices(), vertices); 
}


TEST(graph, get_vertices_2) {
  std::vector<int> vertices = {0, 1, 2};
  std::vector<std::tuple<int, int>> edges = {{0, 1}, {0, 2}, {1, 0}, {2, 0}};
  Graph graph(vertices, edges);
  ASSERT_EQ(graph.get_vertices(), vertices);
}

TEST(graph, get_vertices_3) {
  std::vector<int> vertices = {0};
  std::vector<std::tuple<int, int>> edges = {};
  Graph graph(vertices, edges);
  ASSERT_EQ(graph.get_vertices(), vertices);
}

TEST(graph, get_vertices_4) {
  std::vector<int> vertices = {};
  std::vector<std::tuple<int, int>> edges = {};
  Graph graph(vertices, edges);
  ASSERT_EQ(graph.get_vertices(), vertices);
}

//////////////////////////////////////////////////////////////////////////////
// Test: get_edges
//////////////////////////////////////////////////////////////////////////////

TEST(graph, get_edges_1) {
  std::vector<int> vertices = {0, 1};
  std::vector<std::tuple<int, int>> edges = {{0, 1}};
  std::vector<std::tuple<int, int>> expected_edges = {{0, 1}, {1, 0}};
  Graph graph(vertices, edges);
  ASSERT_EQ(graph.get_edges(), expected_edges); 
}

TEST(graph, get_edges_2) {
  std::vector<int> vertices = {0, 1};
  std::vector<std::tuple<int, int>> edges = {{0, 1}, {1, 0}};
  Graph graph(vertices, edges);
  ASSERT_EQ(graph.get_edges(), edges); 
}





int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

