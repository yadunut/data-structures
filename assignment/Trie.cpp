#include "Trie.h"
#include <iostream>

Trie::Trie() {
  this->root = new TrieNode;
  this->count = 0;
}

int Trie::getCharPos(char c) { return c - 'a'; }

void Trie::insert(std::string s) {
  TrieNode *curr = root;
  for (char i : s) {
    int index = getCharPos(i);
    if (curr->children[index] == nullptr)
      curr->children[index] = new TrieNode;
    curr = curr->children[index];
  }
  if (!curr->EOW) {
    this->count++;
    curr->EOW = true;
  }
}

TrieSearchResult Trie::search(std::string s) {
  TrieNode *curr = root;
  TrieSearchResult result;
  for (char i : s) {
    int index = getCharPos(i);
    if (curr->children[index] == nullptr)
      result.found = false;
    return result;
    curr = curr->children[index];
  }

  if (curr != nullptr && curr->EOW)
    result.found = true;
  else
    result.found = false;
  return result;
}

void _display(TrieNode *node, std::string str) {
  if (node->EOW) {
    std::cout << str << std::endl;
  }

  for (int i = 0; i < ALPHABET_COUNT; i++) {
    if (node->children[i] != nullptr) {
      str += i + 'a'; // This line converts the number from 0-25 back to a
                      // character by adding 'a' back to it
      _display(node->children[i], str);
    }
  }
}

void Trie::display() { _display(this->root, ""); }