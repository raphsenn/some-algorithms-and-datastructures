#include "inverted_index.h"

InvertedIndex::InvertedIndex() {
  inverted_lists = {};
  records = {};  
}

void InvertedIndex::build_from_file(std::string file) {
  // Open the file for reading.
  std::ifstream inputFile(file);

  // Check if the file is open.
  if (!inputFile.is_open()) {
    printf("Error opening the file.\n");
    return; 
  }
  
  std::string line;
  int document_id = 0; 

  while (std::getline(inputFile, line)) {
    document_id += 1;
    
    std::vector<std::string> words = get_words(line);
     

  }
  return;
}

std::vector<std::string> InvertedIndex::get_words(std::string query) {
  std::vector<std::string> matches;

  // All words to lowercase.
  std::transform(query.begin(), query.end(), query.begin(), [](unsigned char c) { return std::tolower(c); });
  
  // Define regular expression pattern.
  std::regex pattern("[A-Za-z]+");

 
  // Create an iterator pointing to the beginning and end of the input string
  std::sregex_iterator iterator(query.begin(), query.end(), pattern);
  std::sregex_iterator end;

  while (iterator != end) {
    matches.push_back(iterator->str());
    ++iterator;
  }
  return matches;
}



