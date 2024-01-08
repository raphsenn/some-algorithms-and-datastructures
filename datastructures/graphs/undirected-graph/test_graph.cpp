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

TEST(graph, get_edges_3) {
  std::vector<int> vertices = {0};
  std::vector<std::tuple<int, int>> edges = {};
  Graph graph(vertices, edges);
  ASSERT_EQ(graph.get_edges(), edges); 
}

TEST(graph, get_edges_4) {
  std::vector<int> vertices = {0, 1, 2};
  std::vector<std::tuple<int, int>> edges = {{0, 1}, {0, 2}};
  std::vector<std::tuple<int, int>> expected_edges = {{0, 1}, {0, 2}, {1, 0}, {2, 0}};
  Graph graph(vertices, edges);
  ASSERT_EQ(graph.get_edges(), expected_edges); 
}

//////////////////////////////////////////////////////////////////////////////
// Test: out_degree
//////////////////////////////////////////////////////////////////////////////

TEST(graph, out_degree_1) {
  std::vector<int> vertices = {0, 1};
  std::vector<std::tuple<int, int>> edges = {{0, 1}};
  std::vector<std::tuple<int, int>> expected_edges = {{0, 1}};
  Graph graph(vertices, edges);
  ASSERT_EQ(graph.out_degree(0), 1); 
  ASSERT_EQ(graph.out_degree(1), 1); 
}

TEST(graph, out_degree_2) {
  std::vector<int> vertices = {0, 1, 2, 3, 4, 5, 6};
  std::vector<std::tuple<int, int>> edges = {{0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}, {0, 6}};
  Graph graph(vertices, edges);
  ASSERT_EQ(graph.out_degree(0), 6); 
  ASSERT_EQ(graph.out_degree(1), 1); 
  ASSERT_EQ(graph.out_degree(2), 1); 
  ASSERT_EQ(graph.out_degree(3), 1); 
  ASSERT_EQ(graph.out_degree(4), 1); 
  ASSERT_EQ(graph.out_degree(5), 1); 
  ASSERT_EQ(graph.out_degree(6), 1); 
}

TEST(graph, out_degree_3) {
  std::vector<int> vertices = {0, 1, 2, 3, 4, 5, 6};
  std::vector<std::tuple<int, int>> edges = {{1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {6, 0}};
  Graph graph(vertices, edges);
  ASSERT_EQ(graph.out_degree(0), 6); 
  ASSERT_EQ(graph.out_degree(1), 1); 
  ASSERT_EQ(graph.out_degree(2), 1); 
  ASSERT_EQ(graph.out_degree(3), 1); 
  ASSERT_EQ(graph.out_degree(4), 1); 
  ASSERT_EQ(graph.out_degree(5), 1); 
  ASSERT_EQ(graph.out_degree(6), 1); 
}

//////////////////////////////////////////////////////////////////////////////
// Test: in_degree
//////////////////////////////////////////////////////////////////////////////

TEST(graph, in_degree_1) {
  std::vector<int> vertices = {0, 1};
  std::vector<std::tuple<int, int>> edges = {{0, 1}};
  std::vector<std::tuple<int, int>> expected_edges = {{0, 1}};
  Graph graph(vertices, edges);
  ASSERT_EQ(graph.in_degree(0), 1); 
  ASSERT_EQ(graph.in_degree(1), 1); 
}

TEST(graph, get_out_degree_2) {
  std::vector<int> vertices = {0, 1, 2, 3, 4, 5, 6};
  std::vector<std::tuple<int, int>> edges = {{1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {6, 0}};
  Graph graph(vertices, edges);
  ASSERT_EQ(graph.in_degree(0), 6); 
  ASSERT_EQ(graph.in_degree(1), 1); 
  ASSERT_EQ(graph.in_degree(2), 1); 
  ASSERT_EQ(graph.in_degree(3), 1); 
  ASSERT_EQ(graph.in_degree(4), 1); 
  ASSERT_EQ(graph.in_degree(5), 1); 
  ASSERT_EQ(graph.in_degree(6), 1); 
}

//////////////////////////////////////////////////////////////////////////////
// Test: get_adjacency_list_as_string
//////////////////////////////////////////////////////////////////////////////

TEST(graph, get_adjacency_list_as_string_1) {
  std::vector<int> vertices = {0, 1};
  std::vector<std::tuple<int, int>> edges = {{0, 1}};
  Graph graph(vertices, edges);
  
  std::string expected_adjacency_list = "{0: [1], 1: [0]}";
  EXPECT_EQ(graph.get_adjacency_list_as_string(), expected_adjacency_list);
}

TEST(graph, get_adjacency_list_as_string_2) {
  std::vector<int> vertices = {0, 1};
  std::vector<std::tuple<int, int>> edges = {{0, 1}, {1, 0}};
  Graph graph(vertices, edges);
  
  std::string expected_adjacency_list = "{0: [1], 1: [0]}";
  EXPECT_EQ(graph.get_adjacency_list_as_string(), expected_adjacency_list);
}

TEST(graph, get_adjacency_list_as_string_3) {
  std::vector<int> vertices = {0, 1, 2};
  std::vector<std::tuple<int, int>> edges = {{0, 1}, {0, 2}};
  Graph graph(vertices, edges);
  
  std::string expected_adjacency_list = "{0: [1, 2], 1: [0], 2: [0]}";
  EXPECT_EQ(graph.get_adjacency_list_as_string(), expected_adjacency_list);
}

TEST(graph, get_adjacency_list_as_string_4) {
  std::vector<int> vertices = {0, 1, 2, 3};
  std::vector<std::tuple<int, int>> edges = {{0, 1}, {0, 2}, {0, 3}};
  Graph graph(vertices, edges);
  
  std::string expected_adjacency_list = "{0: [1, 2, 3], 1: [0], 2: [0], 3: [0]}";
  EXPECT_EQ(graph.get_adjacency_list_as_string(), expected_adjacency_list);
}

//////////////////////////////////////////////////////////////////////////////
// Test: get_adjacency_list_as_string
//////////////////////////////////////////////////////////////////////////////


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

