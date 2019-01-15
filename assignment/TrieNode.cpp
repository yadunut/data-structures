//
// Created by Yadunand Prem on 14/1/19.
//

#include "TrieNode.h"

TrieNode::TrieNode() {
  this->EOW = false;
  for (int i = 0; i < ALPHABET_COUNT; i++)
    this->children[i] = nullptr;
}
