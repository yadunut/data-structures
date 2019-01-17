#include "Trie.h"

Trie::Trie() {
  this->root = new TrieNode;
  this->count = 0;
}

void Trie::insert(std::string s) {
  TrieNode *curr = root;
  for (char i : s) {
    int index = i - 'a';
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
  TrieSearchResult result{};
  for (char c : s) {
    int index = c - 'a';
    if (curr->children[index] == nullptr) {
      result.found = false;
      return result;
    }
    curr = curr->children[index];
  }

  result.found = curr != nullptr && curr->EOW;
  return result;
}

void Trie::display() { this->root->display(""); }

void Trie::displayStr(std::string s) {
  TrieNode *curr = this->root;
  for (char c: s) {
    int index = c - 'a';
    curr = curr->children[index];
  }
  if (curr) {
    curr->display(s);
  }
}
