#include <gtest/gtest.h>
#include "./inverted_index.h"

//////////////////////////////////////////////////////////////////////////////
// Test: build_from_file
//////////////////////////////////////////////////////////////////////////////

TEST(inverted_index, build_from_file_1) {
  InvertedIndex inverted_index;
  inverted_index.build_from_file("example.tsv", 0.75, 1.75);
  EXPECT_EQ(inverted_index.inverted_lists_to_string(),
    "{action: [(1, 0.763345)], adventure: [(1, 0.468043), (6, 0.468043)], comedy: [(4, 0.763345)], drama: [(2, 0.468043), (5, 0.468043)], "
    "fantasy: [(6, 0.763345)], fiction: [(3, 0.763345)], film: [(1, 0.763345)], historical: [(5, 0.763345)], movie: [(1, 0.000000), (2, 0.000000), "
    "(3, 0.000000), (4, 0.000000), (5, 0.000000), (6, 0.000000)], mystery: [(4, 0.763345)], romantic: [(2, 0.763345)], science: [(3, 0.763345)], "
    "thriller: [(3, 0.763345)]}");
}

TEST(inverted_index, build_from_file_2) {
  InvertedIndex inverted_index;
  inverted_index.build_from_file("example.tsv", 0.0, 0.0);
  EXPECT_EQ(inverted_index.inverted_lists_to_string(), "{action: [(1, 2.584963)], adventure: [(1, 1.584962), (6, 1.584962)], "
  "comedy: [(4, 2.584963)], drama: [(2, 1.584962), (5, 1.584962)], fantasy: [(6, 2.584963)], fiction: [(3, 2.584963)], film: [(1, 2.584963)], "
  "historical: [(5, 2.584963)], movie: [(1, 0.000000), (2, 0.000000), (3, 0.000000), (4, 0.000000), (5, 0.000000), (6, 0.000000)], mystery: "
  "[(4, 2.584963)], romantic: [(2, 2.584963)], science: [(3, 2.584963)], thriller: [(3, 2.584963)]}");
}

TEST(inverted_index, build_from_file_3) {
  InvertedIndex inverted_index;
  inverted_index.build_from_file("example.tsv", 0.0, 10000.0);
  EXPECT_EQ(inverted_index.inverted_lists_to_string(), "{action: [(1, 2.584963)], adventure: [(1, 1.584962), (6, 1.584962)], comedy: [(4, 2.584963)], "
  "drama: [(2, 1.584962), (5, 1.584962)], fantasy: [(6, 2.584963)], fiction: [(3, 2.584963)], film: [(1, 2.584963)], historical: [(5, 2.584963)], "
  "movie: [(1, 0.000000), (2, 0.000000), (3, 0.000000), (4, 0.000000), (5, 0.000000), (6, 0.000000)], mystery: [(4, 2.584963)], "
  "romantic: [(2, 2.584963)], science: [(3, 2.584963)], thriller: [(3, 2.584963)]}");
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


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS(); 
}


