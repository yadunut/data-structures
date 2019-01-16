#include "Trie.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

// loadDictionary loads file from the default path of test/
void loadDictionary(string filename, Trie *t);
void displayMenu();

int main() {
  Trie root;
  displayMenu();
  loadDictionary("../data/randomwords100.txt", &root);
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
    //    This is to remove the \r from the string
    if (line[line.length() - 1] == '\r')
      line.erase(line.length() - 1);
    t->insert(line);
  }
  file.close();
}
