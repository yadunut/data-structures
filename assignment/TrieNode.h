#pragma once

struct TrieNode {
  char item;
  bool EOW; // End of Word

  TrieNode *children[26];
};
