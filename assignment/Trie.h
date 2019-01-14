#pragma once

#include "TrieNode.h"
#include <array>
#include <string>

class Trie {
public:
  Trie();

  void insert(std::string s);

  bool search(std::string s);

private:
  TrieNode *roots[26];

  // getPos gets the position of a character in the array
  static int getCharPos(char c);
};
