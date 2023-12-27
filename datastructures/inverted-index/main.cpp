#include "./inverted_index.h"

int main() {
  InvertedIndex ii;
  ii.build_from_file("example.tsv");
  printf("%s\n", ii.inverted_lists_to_string().c_str());
  printf("%s\n", ii.records_to_string().c_str());


}

