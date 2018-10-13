#include <iostream>

using namespace std;

class Node {
public:
  Node *next;
  int value;
};

class LinkedList {
public:
  Node *root;
  void push(int value);
  Node *pop();
  void print();
};

void LinkedList::push(int value) {
  Node *node = new Node();
  node->next = this->root;
  node->value = value;
  this->root = node;
}

Node *LinkedList::pop() {
  Node *node = this->root;
  this->root = node->next;
  return node;
}

void LinkedList::print() {
  cout << "LinkedList { ";
  Node *node = this->root;
  while (node != nullptr) {
    cout << node->value << " -> ";
    node = node->next;
  }
  cout << "null }" << endl;
}

LinkedList *init() {
  LinkedList *list = new LinkedList();

  Node *node = new Node();
  node->value = 1;
  list->root = node;

  node = new Node();
  node->value = 4;
  node->next = list->root;
  list->root = node;

  node = new Node();
  node->value = 6;
  node->next = list->root;
  list->root = node;

  node = new Node();
  node->value = 7;
  node->next = list->root;
  list->root = node;

  node = new Node();
  node->value = 9;
  node->next = list->root;
  list->root = node;

  return list;
}

int main() {
  cout << "Creating initial list..." << endl;
  LinkedList *list = init();
  list->print();

  cout << "Pushing 5..." << endl;
  list->push(5);
  list->print();

  cout << "Popping..." << endl;
  cout << "Popped " << list->pop()->value << "!" << endl;
  list->print();

  return 0;
}
