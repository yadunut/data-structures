#pragma once
#include <string>
#include <iostream>

#define ALPHABET_COUNT 26

class TrieNode {
 public:
  bool EOW; // End of Word
  TrieNode *children[ALPHABET_COUNT];

  TrieNode();
  void display(std::string s);

    std::vector<std::string> getWords(std::string s);
};
