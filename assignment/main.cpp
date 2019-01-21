#include "Trie.h"
#include <fstream>
#include <vector>

using namespace std;

// addFileToDictionary loads file into the Trie *t
void addFileToDictionary(string filename, Trie *t);
// displayMenu prints the menu to stdout
void displayMenu();
// addWord asks user for word and adds that to the trie
void addWord(Trie *root);
// addFile asks user for filename in the data/ directory to add to the trie
void addFile(Trie *t);
// spellCheckWord spell checks word
void spellCheckWord(Trie *t);
// spellCheckFile spell checks the file
void spellCheckFile(Trie *t);
// displayWordStartingWithStr prints all the words starting with a given tring
void displayWordStartingWithStr(Trie *t);
// saveDictionary saves dictionary to a file
void saveDictionary(Trie *t);

int main() {
  Trie root;

  while (true) {
    displayMenu();

    int option;
    cin >> option;
    cout << endl;

    switch (option) {
    case 1:
      spellCheckWord(&root);
      break;
    case 2:
      spellCheckFile(&root);
      break;
    case 3:
      addWord(&root);
      break;
    case 4:
      addFile(&root);
      break;
    case 5:
      saveDictionary(&root);
      break;
    case 6:
      root.display();
      break;
    case 7:
      displayWordStartingWithStr(&root);
      break;
    default:
      return 0;
    }
  }
}

void saveDictionary(Trie *t) {
  std::vector<std::string> wordList = t->getWords();
  string filename;
  cout << "Key in filename to save in /data (as .txt): ";
  cin >> filename;
  cout << endl;
  cout << filename;
  ofstream dicFile;
  dicFile.open("../data/" + filename);
  for (string w : wordList) {
    dicFile << w << endl;
  }
  dicFile.close();
  cout << "Saved!" << endl;
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
  cout << "Number of words in dictionary: " << t->getCount() << endl;
  file.close();
}

bool isValidWord(string w, Trie *t) {
  TrieSearchResult searchResult = t->search(w);
  return searchResult.found;
}

void spellCheckFile(Trie *t) {
  string filename, line, result;
  cout << "Enter filename in data/ : ";
  cin >> filename;
  cout << endl;
  ifstream file("../data/" + filename);
  while (getline(file, line)) {
    string status = isValidWord(line, t) ? "Found" : "Not found";
    cout << line << ": " << status << endl;
  }
}
void spellCheckWord(Trie *t) {
  string word;
  cout << "Enter word to spell check : ";
  cin >> word;
  cout << endl;
  if (isValidWord(word, t)) {
    cout << "Word is not spelt correctly!" << endl;
  } else {
    cout << "Word is spelt correctly!" << endl;
  }
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
  cout << "[7] Display all words starting with substring" << endl;
  cout << endl;
}

void addWord(Trie *root) {
  string line;
  cout << "Enter word: ";
  cin >> line;
  cout << endl;
  root->insert(line);
  cout << "Number of words in dictionary: " << root->getCount() << endl;
}

void displayWordStartingWithStr(Trie *t) {
  string line;
  cout << "Enter starting string: ";
  cin >> line;
  cout << endl;
  t->displayStr(line);
}
