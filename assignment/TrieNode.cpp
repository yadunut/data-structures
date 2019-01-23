#include "TrieNode.h"
#include <vector>

TrieNode::TrieNode() {
  this->EOW = false;
  for (int i = 0; i < ALPHABET_COUNT; i++)
    this->children[i] = nullptr;
}

void TrieNode::display(std::string starting) {
    std::vector<std::string> words = getWords(starting);
    for (std::string s : words) {
        std::cout << s << std::endl;
    }
}

void _getWords(TrieNode *node, std::string &str, std::vector<std::string> *wordList) {
    if (node->EOW) {
        wordList->push_back(str);
    }

    for (int i = 0; i < ALPHABET_COUNT; i++) {
        TrieNode *curr = node->children[i];
        if (curr != nullptr) {
            char next = static_cast<char>(i + 'a');
            str.push_back(next);
            _getWords(curr, str, wordList);
            str.pop_back();
        }
        }
}

std::vector<std::string> TrieNode::getWords(std::string starting) {
    std::vector<std::string> wordList;
    _getWords(this, starting, &wordList);
    return wordList;
}

