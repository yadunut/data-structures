#include "Trie.h"

Trie::Trie() {
  this->root = new TrieNode;
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
  curr->EOW = true;
}

bool Trie::search(std::string s) {
  TrieNode *curr = root;
  for (char i : s) {
    int index = getCharPos(i);
    if (curr->children[index] == nullptr)
      return false;
    curr = curr->children[index];
  }

  return (curr!= nullptr && curr->EOW);
}
