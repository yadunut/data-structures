#include <iostream>
#include <fstream>
#include <string>
#include "Trie.h"

using namespace std;

// loadDictionary loads file from the default path of test/
void loadDictionary(string filename, Trie *t);
void displayMenu();

int main() {
  Trie root;
  displayMenu();
  loadDictionary("/home/yadunut/dev/src/github.com/yadunut/data-structures/assignment/data/randomwords100.txt", &root);
  TrieSearchResult res = root.search("inspiration");
  if (res.found) {
    cout << "Found!" << endl;
  } else {
    cout << "Not Found!" << endl;
  }
  root.display();
}

void displayMenu() {
  cout << "[0] Spell check a word" << endl;
  cout << "[1] Spell check a file" << endl;
  cout << "[2] Add word to dictionary" << endl;
  cout << "[3] Save the dictionary" << endl;
  cout << "[4] Display all words" << endl;
  cout << "[5] Display all words starting with letter" << endl;
  cout << endl;
}

void loadDictionary(string filename, Trie *t) {
  ifstream file(filename);
  string line;
  while (getline(file, line)) {
    t->insert(line);
  }
  file.close();
}
