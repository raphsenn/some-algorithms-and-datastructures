#include "./inverted_index.h"

int main() {
  InvertedIndex inverted_index;
  inverted_index.build_from_file("example.tsv");
  printf("%s\n", inverted_index.inverted_lists_to_string().c_str());
}
