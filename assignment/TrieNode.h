#pragma once

#define ALPHABET_COUNT 26

class TrieNode {
 public:
  bool EOW; // End of Word
  TrieNode *children[ALPHABET_COUNT];

  TrieNode();
};


