#include <gtest/gtest.h>
#include "./graph.h"


TEST(graph, get_verteces_1) {
  std::vector<int> verteces = {0, 1};
  std::vector<std::tuple<int, int>> edges = {{0, 1}, {1, 0}};
  Graph graph(verteces, edges);
  ASSERT_EQ(graph.get_verteces(), verteces); 
}


TEST(graph, get_verteces_2) {
  std::vector<int> verteces = {0, 1, 2};
  std::vector<std::tuple<int, int>> edges = {{0, 1}, {0, 2}, {1, 0}, {2, 0}};
  Graph graph(verteces, edges);
  ASSERT_EQ(graph.get_verteces(), verteces);
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

