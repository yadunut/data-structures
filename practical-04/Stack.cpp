//
// Created by Yadunand Prem on 6/11/18.
//

#include "Stack.h"
#include <iostream>

Stack::Stack() {
  this->size = 0;
  this->topNode = nullptr;
}

Stack::~Stack() {}

bool Stack::isEmpty() { return this->topNode == nullptr; }

bool Stack::push(ItemType item) {
  this->topNode = new Node{item, this->topNode};
  return true;
}

bool Stack::pop() {
  if (this->isEmpty())
    return false;
  this->topNode = this->topNode->next;
}

bool Stack::pop(ItemType &item) {
  this->getTop(item);
  this->pop();
  return false;
}

void Stack::getTop(ItemType &item) { item = this->topNode->item; }

ItemType Stack::getTop() {
  return this->topNode->item;
}

void Stack::displayInOrder() {
  if (this->isEmpty())
    return;
  ItemType item;
  this->pop(item);
  std::cout << item << " ";
  displayInOrder();
  this->push(item);
}

void Stack::displayInOrderOfInsertion() {
  if (this->isEmpty())
    return;
  ItemType item;
  this->pop(item);
  displayInOrderOfInsertion();
  std::cout << item << std::endl;
  this->push(item);
}
