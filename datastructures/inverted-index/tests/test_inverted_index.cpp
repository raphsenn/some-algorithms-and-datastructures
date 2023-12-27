#include <gtest/gtest.h>
#include "./inverted_index.h"

//////////////////////////////////////////////////////////////////////////////
// Test: build_from_file
//////////////////////////////////////////////////////////////////////////////

TEST(test_inverted_index, build_from_file) {
  InvertedIndex inverted_index;
  inverted_index.build_from_file("example.tsv");
  EXPECT_EQ(inverted_index.inverted_lists_to_string(), "{a: [1, 2], bad: [2, 4], doc: [1, 2, 3, 4, 5], film: [2, 5], movie: [1, 3, 4], nice: [1, 3, 5], pretty: [3, 4], really: [5]}");
  EXPECT_EQ(inverted_index.records_to_string(), "{(Doc 1, A nice movie.), (Doc 2, A bad film.), (Doc 3, Pretty nice movie.), (Doc 4, Pretty bad movie!), (Doc 5, Really nice film.)}");
}

//////////////////////////////////////////////////////////////////////////////
// Test: intersect
//////////////////////////////////////////////////////////////////////////////

TEST(test_inverted_index, intersect_1) {
  InvertedIndex inverted_index;
  std::vector<int> list_1 = {1, 5, 6}; 
  std::vector<int> list_2 = {2, 4};
  std::vector<int> list_result = {};
  EXPECT_EQ(inverted_index.intersect(list_1, list_2), list_result);
}

TEST(test_inverted_index, intersect_2) {
  InvertedIndex inverted_index;
  std::vector<int> list_1 = {1, 2, 5, 7}; 
  std::vector<int> list_2 = {1, 3, 5, 6, 7, 9};
  std::vector<int> list_result = {1, 5, 7};
  EXPECT_EQ(inverted_index.intersect(list_1, list_2), list_result);
}

TEST(test_inverted_index, intersect_3) {
  InvertedIndex inverted_index;
  std::vector<int> list_1 = {1, 3, 5, 7, 9, 11, 13, 15, 17}; 
  std::vector<int> list_2 = {2, 4, 6, 8, 10, 12, 14, 16, 18};
  std::vector<int> list_result = {};
  EXPECT_EQ(inverted_index.intersect(list_1, list_2), list_result);
}

TEST(test_inverted_index, intersect_4) {
  InvertedIndex inverted_index;
  std::vector<int> list_1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19}; 
  std::vector<int> list_2 = {2, 3, 5, 7, 11, 13, 17, 19};
  std::vector<int> list_result = {2, 3, 5, 7, 11, 13, 17, 19};
  EXPECT_EQ(inverted_index.intersect(list_1, list_2), list_result);
}

//////////////////////////////////////////////////////////////////////////////
// Test: process_query
//////////////////////////////////////////////////////////////////////////////

TEST(test_inverted_index, process_query_1) {
  InvertedIndex inverted_index;
  inverted_index.build_from_file("example.tsv");
  std::vector<std::string> keywords = {};
  std::vector<int> intersection = {};
  EXPECT_EQ(inverted_index.process_query(keywords), intersection);
}

TEST(test_inverted_index, process_query_2) {
  InvertedIndex inverted_index;
  inverted_index.build_from_file("example.tsv");
  std::vector<std::string> keywords = {"doc"};
  std::vector<int> intersection = {1, 2, 3, 4, 5};
  EXPECT_EQ(inverted_index.process_query(keywords), intersection);
}

TEST(test_inverted_index, process_query_3) {
  InvertedIndex inverted_index;
  inverted_index.build_from_file("example.tsv");
  std::vector<std::string> keywords = {"doc", "movie"};
  std::vector<int> intersection = {1, 3, 4};
  EXPECT_EQ(inverted_index.process_query(keywords), intersection);
}

TEST(test_inverted_index, process_query_4) {
  InvertedIndex inverted_index;
  inverted_index.build_from_file("example.tsv");
  std::vector<std::string> keywords = {"bad", "movie"};
  std::vector<int> intersection = {4};
  EXPECT_EQ(inverted_index.process_query(keywords), intersection);
}

TEST(test_inverted_index, process_query_5) {
  InvertedIndex inverted_index;
  inverted_index.build_from_file("example.tsv");
  std::vector<std::string> keywords = {"bad"};
  std::vector<int> intersection = {2, 4};
  EXPECT_EQ(inverted_index.process_query(keywords), intersection);
}

TEST(test_inverted_index, process_query_6) {
  InvertedIndex inverted_index;
  inverted_index.build_from_file("example.tsv");
  std::vector<std::string> keywords = {"doc", "nice"};
  std::vector<int> intersection = {1, 3, 5};
  EXPECT_EQ(inverted_index.process_query(keywords), intersection);
}

TEST(test_inverted_index, process_query_7) {
  InvertedIndex inverted_index;
  inverted_index.build_from_file("example.tsv");
  std::vector<std::string> keywords = {"doc", "nice", "movie"};
  std::vector<int> intersection = {1, 3};
  EXPECT_EQ(inverted_index.process_query(keywords), intersection);
}

TEST(test_inverted_index, process_query_8) {
  InvertedIndex inverted_index;
  inverted_index.build_from_file("example.tsv");
  std::vector<std::string> keywords = {"doc", "nice", "movie", "action"};
  std::vector<int> intersection = {};
  EXPECT_EQ(inverted_index.process_query(keywords), intersection);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS(); 
}
