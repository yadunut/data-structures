#include <iostream>
#include "Trie.h"

int main() {
  std::cout << "Hello, World!" << std::endl;

  Trie t;
  t.insert("hello");
  if (t.search("hello")) {
    printf("Found Hello!\n");
  } else {
    printf("Not found!\n");
  }
}
