#include "List.h"
#include <iostream>

using namespace std;

List::List() {
  size = 0;
  firstNode = nullptr;
}
bool List::isValid(int index) { return (index >= 0) && (index <= size); }

bool List::add(ItemType item) { return this->add(this->size, item); }

bool List::add(int index, ItemType item) {
  if (!this->isValid(index))
    return false;

  Node **current = &this->firstNode;
  for (int i = 0; i < index; i++)
    current = &(*current)->next;

  *current = new Node{item, *current};

  this->size++;
  cout << "Added " << item << endl;
  return true;
}

bool List::remove(int index) {
  if (!this->isValid(index))
    return false;

  // Check if im deleting the root node
  if (index == 0) {
    Node *temp = this->firstNode;
    this->firstNode = this->firstNode->next;
    delete temp;
  } else {

    Node *current = this->firstNode;
    for (int i = 0; i < index - 1; i++)
      current = current->next;

    Node *temp = current->next;
    current->next = current->next->next;
    delete temp;
  }

  this->size--;
  return true;
}

ItemType List::get(int index) {
  if (!this->isValid(index)) {
    return ItemType();
  }
  Node *current = this->firstNode;
  for (int i = 0; i < index; i++)
    current = current->next;
  return current->item;
}

bool List::isEmpty() { return this->firstNode == nullptr; }

int getLength() { return this->size; }

void List::print() {
  Node *curr = this->firstNode;
  cout << "Size is " << this->size << endl;
  for (int i = 0; i < size; i++) {
    // cout << curr << "    " << curr->next << endl;
    cout << curr->item << " --> ";
    curr = curr->next;
  }

  cout << "nullptr" << endl;
}
