#pragma once
#include <iostream>
#include <string>
#include <vector>

#define ALPHABET_COUNT 26

// TrieNode defines each node in the trie.
class TrieNode {
public:
  // End of Word
  bool EOW;

  // Stores the array of children
  TrieNode *children[ALPHABET_COUNT];

  // display prints each word in the TrieNode to std::out
  void display(std::string s);
  // Constructor. Initializes default values
  TrieNode();

  // getWords returns a vector of words in the TrieNode
  std::vector<std::string> getWords(std::string s);
};
