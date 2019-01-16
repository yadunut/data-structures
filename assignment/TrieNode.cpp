#include "TrieNode.h"

TrieNode::TrieNode() {
  this->EOW = false;
  for (int i = 0; i < ALPHABET_COUNT; i++)
    this->children[i] = nullptr;
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

void TrieNode::display(std::string starting) {
  std::string str = starting;
  _display(this, str);
}
