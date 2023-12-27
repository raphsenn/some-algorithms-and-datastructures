#include "inverted_index.h"

InvertedIndex::InvertedIndex() {
  inverted_lists = {};
  records = {};  
}

void InvertedIndex::build_from_file(std::string file, float b, float k) {
  // Open the file for reading.
  std::ifstream inputFile(file);

  // Check if the file is open.
  if (!inputFile.is_open()) {
    printf("Error opening the file.\n");
    return; 
  }
 
  // Document id.
  int document_id = 0; 

  // Document length.
  float DL = 0.0;

  // The number of times a word occurs in a document (term frequency tf)
  std::map<std::string, int> word_count = {};
  
  std::string line;
  while (std::getline(inputFile, line)) {
    document_id += 1;
    
    // Cache title and description of the Document.
    std::vector<std::string> split_line = split(line, '\t'); 
    std::string title = split_line[0];
    std::string description = split_line[1];
    records.push_back(std::make_tuple(title, description));

    // Cache words of the Document.
    line = strip(line);
    std::vector<std::string> words = get_words(line);
    
    for (int i = 0; i < words.size(); i++) {
      auto& current_word = words[i];

      // Count words.
      DL += 1.0;
     
      // Calculate term frequency (tf)
      if (word_count.find(current_word) == word_count.end()) {
        word_count[current_word] = 0;
      }
      word_count[current_word] += 1;
     
      // Check if a current_word is present in inverted_lists using find.
      auto it = inverted_lists.find(current_word);
      if (it != inverted_lists.end()) {
        // Key is found
        
        // Check if document_id is present as the first element of tuple in the vector
        std::vector<std::tuple<int, float>> vec = inverted_lists[current_word]; 
        
        // NEED TO IMPROVE!
        // BAD APPROACH!
        std::tuple<bool, int> found = check_if_docid_in_vec(document_id, current_word); 
        if (std::get<0>(found)) {
          // Update term frequency
          int j = std::get<1>(found);
          inverted_lists[current_word][j] = std::make_tuple(document_id, word_count[current_word]);
        }
        else {
          // Push new tuple
          inverted_lists[current_word].emplace_back(std::make_tuple(document_id, word_count[current_word]));
        }
      }
      else {
        // current_word is not found
        inverted_lists[current_word] = {std::make_tuple(document_id, word_count[current_word])};
      }
    }
    word_count.clear();
  }
  inputFile.close();
  
  // Implementation of BM25 algorithm.
  // BM25 = tf * (k+1) / (k * (1 - b + b * DL/AVDL) + tf) * log2(N/df)
  // N: total number of Documents.
  // AVDL: average document length.
  // tf: term frequency.
  // df: document frequency.
  
  float N = document_id;  
  float AVDL = DL / N;
  float BM25_score;
  for (auto it = inverted_lists.begin(); it != inverted_lists.end(); ++it) {
    std::vector<std::tuple<int, float>>& val = it->second; 
    const auto& key = it->first;
    
    for (int i = 0; i < val.size(); i++) {
      float df = val.size(); 
      float document_id = std::get<0>(val[i]); 
      float tf = std::get<1>(val[i]); 
      
      if (std::isinf(k)) {
        BM25_score = tf * log2(N/df);
      }
      else { 
        BM25_score = (tf * (k+1.0) / (k * (1.0 - b + b * DL/AVDL) + tf)) * log2(N/df);
      } 
      val[i] = std::make_tuple(document_id, BM25_score); 
    } 
  }
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
      il_as_string += "(" + std::to_string(std::get<0>(val[i])) + ", " + std::to_string(std::get<1>(val[i])) + ")";
      
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
  //std::vector<int> matches = inverted_lists[keywords[0]];
  //for (int i = 1; i < keywords.size(); i++) {
  //  matches = intersect(matches, inverted_lists[keywords[i]]);    
  //}
  return {};
}

std::tuple<bool, int> InvertedIndex::check_if_docid_in_vec(int document_id, std::string word) {
  std::vector<std::tuple<int, float>> vec = inverted_lists[word]; 
  for (int i = 0; i < vec.size(); i++) {
    if (std::get<0>(vec[i]) == document_id) {
      return std::make_tuple(true, i);
    }
  }
  return std::make_tuple(false, -1);
}

