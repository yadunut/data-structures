#include "Trie.h"

Trie::Trie() {}

int Trie::getCharPos(char c) { return c - 'a'; }

void Trie::insert(std::string s) {
  int pos = getCharPos(s[0]);
  TrieNode **curr = &roots[pos];
  if (*curr == nullptr) {
    printf("Is null");
    *curr = new TrieNode{s[0], false};
  }
  for (int i = 1; i < s.size(); i++) {
    pos = getCharPos(s[i]);
    curr = &curr[pos];
  }
}
