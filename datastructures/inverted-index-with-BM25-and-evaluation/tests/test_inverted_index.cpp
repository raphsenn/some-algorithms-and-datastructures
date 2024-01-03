#include <gtest/gtest.h>
#include "./inverted_index.h"

/**
 * @brief Unit tests for the InvertedIndex class.
 */

//////////////////////////////////////////////////////////////////////////////
// How to compile the test:
//
// To run the tests, Google Test (gtest) needs to be installed.
//
// Compilation instructions:
// 1. Navigate to the 'inverted-index-with-BM25' folder.
// 2. Execute the following commands in the terminal:

// Compile InvertedIndex implementation file
// g++ -c -std=c++17 src/inverted_index.cpp -Iinclude

// Compile the test file
// g++ -c -std=c++17 tests/test_inverted_index.cpp -Iinclude

// Link object files and Google Test libraries
// g++ -o test -std=c++17 inverted_index.o test_inverted_index.o -lgtest -lgtest_main -lpthread

// Run the compiled test executable
// ./test

//////////////////////////////////////////////////////////////////////////////
// Test: build_from_file
//////////////////////////////////////////////////////////////////////////////

TEST(inverted_index, build_from_file_1) {
  InvertedIndex inverted_index;
  inverted_index.build_from_file("testdata/test_data.tsv", 0.75, 1.75);
  EXPECT_EQ(inverted_index.inverted_lists_to_string(),"{action: [(1, 0.763000)], adventure: [(1, 0.468000), (6, 0.468000)], "
  "comedy: [(4, 0.763000)], drama: [(2, 0.468000), (5, 0.468000)], fantasy: [(6, 0.763000)], fiction: [(3, 0.763000)], film: [(1, 0.763000)], "
  "historical: [(5, 0.763000)], movie: [(1, 0.000000), (2, 0.000000), (3, 0.000000), (4, 0.000000), (5, 0.000000), (6, 0.000000)], "
  "mystery: [(4, 0.763000)], romantic: [(2, 0.763000)], science: [(3, 0.763000)], thriller: [(3, 0.763000)]}");
}

TEST(inverted_index, build_from_file_2) {
  InvertedIndex inverted_index;
  inverted_index.build_from_file("testdata/test_data.tsv", 0.0, 0.0);
  EXPECT_EQ(inverted_index.inverted_lists_to_string(), "{action: [(1, 2.585000)], adventure: [(1, 1.585000), (6, 1.585000)], "
  "comedy: [(4, 2.585000)], drama: [(2, 1.585000), (5, 1.585000)], fantasy: [(6, 2.585000)], fiction: [(3, 2.585000)], film: [(1, 2.585000)], "
  "historical: [(5, 2.585000)], movie: [(1, 0.000000), (2, 0.000000), (3, 0.000000), (4, 0.000000), (5, 0.000000), (6, 0.000000)], "
  "mystery: [(4, 2.585000)], romantic: [(2, 2.585000)], science: [(3, 2.585000)], thriller: [(3, 2.585000)]}");
}

TEST(inverted_index, build_from_file_3) {
  InvertedIndex inverted_index;
  inverted_index.build_from_file("testdata/test_data.tsv", 0.0, 10000.0);
  EXPECT_EQ(inverted_index.inverted_lists_to_string(), "{action: [(1, 2.585000)], adventure: [(1, 1.585000), (6, 1.585000)], "
  "comedy: [(4, 2.585000)], drama: [(2, 1.585000), (5, 1.585000)], fantasy: [(6, 2.585000)], fiction: [(3, 2.585000)], film: [(1, 2.585000)], "
  "historical: [(5, 2.585000)], movie: [(1, 0.000000), (2, 0.000000), (3, 0.000000), (4, 0.000000), (5, 0.000000), (6, 0.000000)], "
  "mystery: [(4, 2.585000)], romantic: [(2, 2.585000)], science: [(3, 2.585000)], thriller: [(3, 2.585000)]}");
}

//////////////////////////////////////////////////////////////////////////////
// Test: build_from_file
//////////////////////////////////////////////////////////////////////////////

TEST(inverted_index, merge_1) {
  InvertedIndex inverted_index;
  std::vector<std::tuple<int, float>> list_1 = {{1, 2.1}, {5, 3.2}};
  std::vector<std::tuple<int, float>> list_2 = {{1, 1.7}, {2, 1.3}, {6, 3.3}};
  std::vector<std::tuple<int, float>> list_result = {{1, 3.8}, {2, 1.3}, {5, 3.2}, {6, 3.3}};
  EXPECT_EQ(inverted_index.merge(list_1, list_2), list_result); 
}

TEST(inverted_index, merge_2) {
  InvertedIndex inverted_index;
  std::vector<std::tuple<int, float>> list_1 = {{3, 1.7}, {5, 3.2}, {7, 4.1}};
  std::vector<std::tuple<int, float>> list_2 = {{1, 2.3}, {5, 1.3}};
  std::vector<std::tuple<int, float>> list_result = {{1, 2.3}, {3, 1.7}, {5, 4.5}, {7, 4.1}};
  EXPECT_EQ(inverted_index.merge(list_1, list_2), list_result); 
}

TEST(inverted_index, merge_3) {
  InvertedIndex inverted_index;
  std::vector<std::tuple<int, float>> list_1 = {};
  std::vector<std::tuple<int, float>> list_2 = {{1, 2.3}, {5, 1.3}};
  std::vector<std::tuple<int, float>> list_result = {{1, 2.3}, {5, 1.3}};
  EXPECT_EQ(inverted_index.merge(list_1, list_2), list_result); 
}

TEST(inverted_index, merge_4) {
  InvertedIndex inverted_index;
  std::vector<std::tuple<int, float>> list_1 = {{1, 2.1}};
  std::vector<std::tuple<int, float>> list_2 = {};
  std::vector<std::tuple<int, float>> list_result = {{1, 2.1}};
  EXPECT_EQ(inverted_index.merge(list_1, list_2), list_result); 
}

TEST(inverted_index, merge_5) {
  InvertedIndex inverted_index;
  std::vector<std::tuple<int, float>> list_1 = {{1, 2.1}, {2, 1.3}, {4, 5.5}};
  std::vector<std::tuple<int, float>> list_2 = {{3, 1.1}};
  std::vector<std::tuple<int, float>> list_result = {{1, 2.1}, {2, 1.3}, {3, 1.1}, {4, 5.5}};
  EXPECT_EQ(inverted_index.merge(list_1, list_2), list_result); 
}

TEST(inverted_index, merge_6) {
  InvertedIndex inverted_index;
  std::vector<std::tuple<int, float>> list_1 = {{1, 2.1}, {2, 1.1}};
  std::vector<std::tuple<int, float>> list_2 = {{1, 1.0}, {2, 1.1}};
  std::vector<std::tuple<int, float>> list_result = {{1, 3.1}, {2, 2.2}};
  EXPECT_EQ(inverted_index.merge(list_1, list_2), list_result); 
}

//////////////////////////////////////////////////////////////////////////////
// Test: process_query
//////////////////////////////////////////////////////////////////////////////

TEST(inverted_index, process_query_1) {
  InvertedIndex inverted_index;
  inverted_index.build_from_file("testdata/test_data.tsv", 0.0, 0.0);
  std::vector<std::string> keywords = {"action", "adventure"}; 
  std::vector<std::tuple<int, float>> list_result = {{1, 2.585 + 1.585}, {6, 1.585}};
  EXPECT_EQ(inverted_index.process_query(keywords), list_result); 
}

TEST(inverted_index, process_query_2) {
  InvertedIndex inverted_index;
  inverted_index.build_from_file("testdata/test_data.tsv", 0.0, 0.0);
  std::vector<std::string> keywords = {"comedy", "drama"};

  std::vector<std::tuple<int, float>> list_result = { {4, 2.585}, {2, 1.585}, {5, 1.585} };
  EXPECT_EQ(inverted_index.process_query(keywords), list_result); 
}

TEST(inverted_index, process_query_3) {
  InvertedIndex inverted_index;
  inverted_index.build_from_file("testdata/test_data.tsv", 0.0, 0.0);
  std::vector<std::string> keywords = {"science"}; 
  std::vector<std::tuple<int, float>> list_result = {{3, 2.585}};
  EXPECT_EQ(inverted_index.process_query(keywords), list_result); 
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS(); 
}
