#include <gtest/gtest.h>
#include "./inverted_index.h"


TEST(test_inverted_index, build_from_file) {
  InvertedIndex inverted_index;
  inverted_index.build_from_file("test.tsv");
  EXPECT_EQ(inverted_index.inverted_lists_to_string(), "{a: [1, 2], doc: [1, 2, 3], film: [2], movie: [1, 3]}");
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS(); 
}

