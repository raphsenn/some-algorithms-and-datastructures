#include "./inverted_index.h"

int main() {
  InvertedIndex inverted_index;
  //inverted_index.build_from_file("example.tsv", 0.0, 10000.0);
  
  inverted_index.build_from_file("example.tsv", 0.0, 0.0);
  
  // inverted_index.build_from_file("example.tsv", 0.75, 1.75);
  printf("%s\n", inverted_index.inverted_lists_to_string().c_str());
}
