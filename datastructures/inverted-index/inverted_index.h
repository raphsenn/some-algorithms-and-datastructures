#include <vector>
#include <map>
#include <string>
#include <tuple>
#include <fstream>
#include <regex>
#include <algorithm>
#include <cstdio>


//////////////////////////////////////////////////////////////////////////////
// Simple Implementation of InvertedIndex Datastructure
//////////////////////////////////////////////////////////////////////////////
class InvertedIndex {
  private:
    std::map<std::string, std::vector<int>> inverted_lists;
    std::vector<std::tuple<std::string, std::string>> records;


  public:
    // Constructor
    InvertedIndex();

    // Build inverted_lists and records form file.
    void build_from_file(std::string file);

    // Get words from every line in file.
    std::vector<std::string> get_words(std::string query);

};


