#include "Trie.h"

Trie::Trie() { this->roots = new std::vector<TrieNode>(); }

int Trie::getCharPos(char c) { return c - 'a'; }

bool Trie::insert(std::string s) { return false; }

bool Trie::search(std::string s) { return false; }

std::string Trie::toString() { return ""; }
