#include <vector>
#include <map>
#include <string>
#include <tuple>
#include <fstream>
#include <regex>
#include <algorithm>
#include <cstdio>
#include <sstream>

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
    
    // Convert inverted_lists to string.
    std::string inverted_lists_to_string();

    // Convert records to string.
    std::string records_to_string();
    
    // Like strip from python.
    std::string strip(std::string str); 

    // Like split form python.
    std::vector<std::string> split(std::string& line, char delimiter);


};


