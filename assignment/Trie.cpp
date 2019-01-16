#include "Trie.h"
#include <iostream>

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
  for (char i : s) {
    int index = i - 'a';
    if (curr->children[index] == nullptr) {
      result.found = false;
      return result;
    }
    curr = curr->children[index];
  }

  result.found = curr != nullptr && curr->EOW;
  return result;
}

void _display(TrieNode *node, std::string &str) {
  if (node->EOW) {
    std::cout << str << std::endl;
  }

  for (int i = 0; i < ALPHABET_COUNT; i++) {
    TrieNode *curr = node->children[i];
    if (curr != nullptr) {
      char next = static_cast<char>(i + 'a');
      str.push_back(next);
      _display(curr, str);
      str.pop_back();
    }
  }
}

void Trie::display() {
  std::string str;
  _display(this->root, str);
}
