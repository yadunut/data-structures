// List.cpp - Implementation of List ADT using Array
#include "List.h"
#include <iostream>

using namespace std;
List::List(int cap) {
  this->cap = cap;
  this->len = 0;
  items = new ItemType *[cap];
}

bool List::add(ItemType *item) {
  if (len < cap) {
    items[len] = item;
    this->len++;
    return true;
  }
  return false;
}

bool List::remove(int index) {
  if (this->isValid(index)) {
    delete items[index - 1];
    for (int fromPosition = index + 1; fromPosition <= len; fromPosition++)
      items[fromPosition - 2] = items[fromPosition - 1];
    len--; // decrease the size by 1
    return true;
  }
  return false;
}

ItemType *List::get(int index) {
  if (this->isValid(index)) {
    return items[index - 1];
  }
  return nullptr;
}

bool List::isEmpty() { return len == 0; }

int List::getLength() { return len; }

void List::print() {
  for (int i = 0; i < len; i++) {
    cout << "(" << i + 1 << ") " << items[i]->print() << endl;
  }
}

bool List::isValid(int index) { return ((index >= 1) && (index <= len)); }
