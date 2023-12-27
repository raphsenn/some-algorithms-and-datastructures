#include <gtest/gtest.h>
#include "./inverted_index.h"


TEST(inverted_index, build_from_file_1) {
  InvertedIndex inverted_index;
  inverted_index.build_from_file("example.tsv");
}




int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS(); 
}


