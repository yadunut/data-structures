#pragma once

#include "TrieNode.h"
#include <string>
#include <vector>

class Trie {
public:
  Trie();

  bool insert(char c);
  bool insert(std::string s);

  bool search(std::string s);

  std::string toString();

private:
  std::vector<TrieNode> *roots;

  // getPos gets the position of a character in the array
  static int getCharPos(char c);
};
