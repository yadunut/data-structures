#pragma once
#include <iostream>
#include <string>

#define ALPHABET_COUNT 26

// TrieNode defines each node in the trie.
class TrieNode {
public:
  bool EOW; // End of Word
  TrieNode *children[ALPHABET_COUNT];
  // Constructor. Initializes default values
  TrieNode();
  // display prints each word in the TrieNode to std::out
  void display(std::string s);

  // getWords returns a vector of words in the TrieNode
  std::vector<std::string> getWords(std::string s);
};
