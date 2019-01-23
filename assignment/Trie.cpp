#include "Trie.h"
#include <vector>

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

  result.found = curr->EOW;
  return result;
}

TrieNode *traverseToNode(TrieNode *node, std::string s) {
  if (s.empty()) {
    return node;
  }
  TrieNode *curr = node;
  for (char c : s) {
    int index = c - 'a';
    if (curr->children[index] != nullptr) {
      curr = curr->children[index];
    } else {
      return nullptr;
    }
  }
  return curr;
}

TrieSearchResult _searchWithError(TrieNode *root, std::string s) {
  std::string letters = "abcdefghijklmnopqrstuvwxyz";
  TrieSearchResult result;
  result.found = false;
  result.isAddError = false;
  result.isDelError = false;
  if (root == nullptr) {
    return result;
  }

  for (int i = 0; i < ALPHABET_COUNT; i++) {
    if (root->children[i] != nullptr) {
      std::string sCopy = s;
      sCopy.insert(0, std::string(1, letters[i]));
      TrieNode *curr = traverseToNode(root, sCopy);
      if (curr != nullptr && curr->EOW) {
        result.found = true;
        result.isDelError = true;
        return result;
      }
    }
  }
  TrieNode *curr = traverseToNode(root, s.substr(0, 1));
  result = _searchWithError(curr, s.substr(1));
  return result;
}

TrieSearchResult Trie::searchWithError(std::string s) {
  TrieSearchResult result = _searchWithError(this->root, s);
  if (!result.isDelError) {
    for (int i = 0; i < s.length(); i++) {
      std::string sCopy = s;
      sCopy.erase(i, 1);
      result = search(sCopy);
      if (result.found) {
        result.isAddError = true;
        return result;
      }
    }
    result.found = false;
  }

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

int Trie::getCount() {
  return count;
}

std::vector<std::string> Trie::getWords() {
  return this->root->getWords("");
}
