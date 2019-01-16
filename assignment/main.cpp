#include "Trie.h"
#include <fstream>

using namespace std;

// addFileToDictionary loads file from the default path of test/
void addFileToDictionary(string filename, Trie *t);
void displayMenu();
void addWord(Trie *root);
void addFile(Trie *t);

void displayWordStartingWithChar(Trie *t);

int main() {
  Trie root;
  while (true) {
    displayMenu();

    int option;
    cin >> option;
    cout << endl;

    switch (option) {
      case 1:break;
      case 2:break;
      case 3:addWord(&root);
        break;
      case 4:addFile(&root);
        break;
      case 5:break;
      case 6:root.display();
        break;
      case 7:displayWordStartingWithChar(&root);
        break;
      default:return 0;
    }
  }
}

void addFileToDictionary(string filename, Trie *t) {
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

void addFile(Trie *t) {
  string line;
  cout << "Enter filename in data/ : ";
  cin >> line;
  cout << endl;
  addFileToDictionary("../data/" + line, t);
}

void displayMenu() {
  cout << "[0] Quit the program" << endl;
  cout << "[1] Spell check a word" << endl;
  cout << "[2] Spell check a file" << endl;
  cout << "[3] Add word to dictionary" << endl;
  cout << "[4] Add file to dictionary" << endl;
  cout << "[5] Save the dictionary" << endl;
  cout << "[6] Display all words" << endl;
  cout << "[7] Display all words starting with letter" << endl;
  cout << endl;
}

void addWord(Trie *root) {
  string line;
  cout << "Enter word: ";
  cin >> line;
  cout << endl;
  root->insert(line);
}

void displayWordStartingWithChar(Trie *t) {
  string line;
  cout << "Enter starting string: ";
  cin >> line;
  cout << endl;
  t->displayStr(line);
}
