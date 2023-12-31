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
    
    // Cache title and description of the Document.
    std::vector<std::string> split_line = split(line, '\t'); 
    std::string title = split_line[0];
    std::string description = split_line[1];
    records.push_back(std::make_tuple(title, description));

    line = strip(line);
    std::vector<std::string> words = get_words(line);
     
    for (int i = 0; i < words.size(); i++) {
      auto& current_word = words[i];
      if (inverted_lists.find(current_word) == inverted_lists.end()) {
        inverted_lists[current_word] = {document_id};
      }
      // Check if document_id is in inverted_lists[current_word]
      if (std::find(inverted_lists[current_word].begin(), inverted_lists[current_word].end(), document_id) != inverted_lists[current_word].end()) {
        ; 
      }
      // If not, push it.
      else {
        inverted_lists[current_word].push_back(document_id);
      }
      
    }
  }
  inputFile.close();
  return;
}

std::vector<std::string> InvertedIndex::get_words(std::string query) {
  // Vector of all words from query. 
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

std::string InvertedIndex::strip(std::string str) {
  size_t start = str.find_first_not_of(" \t\n\r");
  size_t end = str.find_last_not_of(" \t\n\r");

  if (start == std::string::npos || end == std::string::npos) {
      // The string is either empty or contains only whitespaces
      return "";
  }

  return str.substr(start, end - start + 1);
}

std::string InvertedIndex::inverted_lists_to_string() {
  std::string il_as_string = "{"; 
  for (auto it = inverted_lists.begin(); it != inverted_lists.end(); ++it) {
    const auto& val = it->second;
    const auto& key = it->first;
    
    il_as_string += key + ": [";

    for (int i = 0; i < val.size(); i++) {
      il_as_string += std::to_string(val[i]);
      
      if (i < val.size() - 1) { 
        il_as_string += ", "; 
      }
    }
    if (std::next(it) != inverted_lists.end()) {
      il_as_string += "], ";
    }
    else {
      il_as_string += "]";
    }
  }
  il_as_string += "}";
  return il_as_string;
}

std::string InvertedIndex::records_to_string() {
  std::string records_as_string = "{";
  
  for (int i = 0; i < records.size(); i++) {
    std::string title = std::get<0>(records[i]);
    std::string description = std::get<1>(records[i]);
    
    records_as_string += "(" + title + ", " + description + ")";
  
    if (i < records.size() - 1) {
      records_as_string += ", ";
    }
  }
  records_as_string += "}";
  return records_as_string;
}

std::vector<std::string> InvertedIndex::split(std::string& line, char delimiter) {
  std::vector<std::string> tokens;
  std::istringstream stream(line);
  std::string token;

  while (std::getline(stream, token, delimiter)) {
      tokens.push_back(token);
  }

  return tokens;
}

std::vector<int> InvertedIndex::intersect(std::vector<int> list_1, std::vector<int> list_2) {
  std::vector<int> matches;
  
  int i = 0; // Pointer to list_1
  int j = 0; // pointer to list_2
  
  while (i < list_1.size() && j < list_2.size()) {
    if (list_1[i] == list_2[j]) {
      matches.push_back(list_1[i]);
    } 
    if (list_1[i] < list_2[j]) {
      i += 1;
    }
    else {
      j += 1;
    }
  }
  return matches;
}

std::vector<int> InvertedIndex::process_query(std::vector<std::string> keywords) {
  if (keywords.empty()) {
    return {};
  } 
  std::vector<int> matches = inverted_lists[keywords[0]];
  for (int i = 1; i < keywords.size(); i++) {
    matches = intersect(matches, inverted_lists[keywords[i]]);    
  }
  return matches;
}
