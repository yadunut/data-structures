#pragma once

#include "TrieNode.h"
#include <string>

class Trie {
public:
  Trie();

  void insert(std::string s);

  bool search(std::string s);

  // getPos gets the position of a character in the array
  static int getCharPos(char c);

private:
  TrieNode *root;

};

/* Design Choice: The inital root node is used to store the 26 chars of the
 * alphabet. Thus, it will have a empty value for char and false for EOL
 *
 *
 */
