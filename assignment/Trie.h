#pragma once

#include "TrieNode.h"
#include <string>
#include <iostream>

struct TrieSearchResult {
  bool found;
  std::string *strings;
};

class Trie {
 public:
  Trie();

  void insert(std::string s);
  TrieSearchResult search(std::string s);
  void display();

  // displayStr searches for the words starting with the string
  void displayStr(std::string c);

    int getCount();

  // getPos gets the position of a character in the array

 private:
  int count;
  TrieNode *root;
};

/* Design Choice: The initial root node is used to store the 26 chars of the
 * alphabet. Thus, it will have a empty value for char and false for EOL
 *
 *
 */
