#ifndef INVERTED_INDEX_H
#define INVERTED_INDEX_H
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
// Simple Implementation of InvertedIndex Data Structure
//////////////////////////////////////////////////////////////////////////////
class InvertedIndex {
  private:
    // Map to store inverted lists for each unique word.
    std::map<std::string, std::vector<int>> inverted_lists;
    
    // Vector to store document records as tuples (title, description). 
    std::vector<std::tuple<std::string, std::string>> records;

  public:
    // Constructor initializes an empty InvertedIndex. 
    InvertedIndex();

    // Build inverted_lists and records from file.
    void build_from_file(std::string file);

    // Find words from line.
    std::vector<std::string> get_words(std::string query);
    
    // Convert inverted_lists to string.
    std::string inverted_lists_to_string();

    // Convert records to string.
    std::string records_to_string();
    
    // Python like strip method.
    std::string strip(std::string str); 

    // Python like split method.
    std::vector<std::string> split(std::string& line, char delimiter);

    // Computes the intersection of the two given inverted lists in O(n),
    // whre n is the number of Elements in both lists. 
    std::vector<int> intersect(std::vector<int> list_1, std::vector<int> list_2);

    // Implement your logic to fetch and compute the intersection of inverted lists here.
    // The result should be a vector of integers representing the document IDs.
    std::vector<int> process_query(std::vector<std::string>);
};
#endif // INVERTED_INDEX_H
