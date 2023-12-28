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
#include <cmath>

//////////////////////////////////////////////////////////////////////////////
// Simple Implementation of InvertedIndex Data Structure
//////////////////////////////////////////////////////////////////////////////
class InvertedIndex {
  private:
    // Map to store inverted lists for each unique word.
    std::map<std::string, std::vector<std::tuple<int, float>>> inverted_lists;
    
    // Vector to store document records as tuples (title, description). 
    std::vector<std::tuple<std::string, std::string>> records;

  public:
    // Constructor initializes an empty InvertedIndex. 
    InvertedIndex();

    // Build inverted_lists and records from file.
    void build_from_file(std::string file, float b, float k);

    // Inefficient implementation of the BM25 Algorithm, incorporating parameters N, DL, b, and k.
    void BM25(float N, float DL, float b, float k);

    // Find words from line.
    std::vector<std::string> get_words(std::string query);
  
    // Compute the union of the two given inverted lists whre n is the number of Elements in both lists. 
    std::vector<std::tuple<int, float>> merge(std::vector<std::tuple<int, float>> list_1, std::vector<std::tuple<int, float>> list_2);

    // Processes a keyword query, fetching inverted lists, computing their union, and sorting by BM25 scores in descending order.
    std::vector<std::tuple<int, float>> process_query(std::vector<std::string> keywords);

    // Python like strip method.
    std::string strip(std::string str); 

    // Python like split method.
    std::vector<std::string> split(std::string& line, char delimiter);

    // Converts the inverted_lists to a formatted string.
    std::string inverted_lists_to_string();

    // Converts the records to a formatted string.
    std::string records_to_string();
};
#endif // INVERTED_INDEX_H
