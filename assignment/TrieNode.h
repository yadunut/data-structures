#pragma once
#include <vector>

struct TrieNode {
  char item;
  bool EOW; // End of Word
  std::vector<TrieNode> children;
};
