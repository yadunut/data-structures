#pragma once

#include "TrieNode.h"
#include <iostream>
#include <string>

struct TrieSearchResult {
  bool found;
    bool isDelError, isAddError;
  std::string *strings;
};
// Trie classstores the root TrieNode
class Trie {
public:
  // Constructor. Initializes the default values
  Trie();
  // Inserts a string into the trie
  void insert(std::string s);
  // Searches for the given word in the string. Returns a TrieSearchResult with
  // true if found and false if not
  TrieSearchResult search(std::string s);

    TrieSearchResult searchWithError(std::string s);
  // Prints the elements in the trie
  void display();

  // displayStr searches for the words starting with the string
  void displayStr(std::string c);

  // Prints the number of elements in the trie
  int getCount();

  // getWords returns a vector of words in the TrieNode
  std::vector<std::string> getWords();

  // getPos gets the position of a character in the array

private:
  int count;
  TrieNode *root;
};

/* Design Choice: The initial root node is used to store the 26 chars of the
 * alphabet. Thus, it will have a empty value for char and false for EOL
 */
