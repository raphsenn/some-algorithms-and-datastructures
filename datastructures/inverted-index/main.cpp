#include "./inverted_index.h"

int main() {
  InvertedIndex ii;
  ii.build_from_file("test.tsv");
  printf("%s\n", ii.inverted_lists_to_string().c_str());


}

