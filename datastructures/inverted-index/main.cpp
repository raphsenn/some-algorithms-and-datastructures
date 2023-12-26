#include "./inverted_index.h"

int main() {
  InvertedIndex ii;
  ii.build_from_file("test.tsv");
}

