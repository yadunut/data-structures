//
// Created by Yadunand Prem on 11/11/18.
//

#include "Queue.h"
#include <iostream>

Queue::Queue() { this->size = 0; }
Queue::~Queue() {
  while (!this->isEmpty()) {
    this->dequeue();
  }
  this->frontNode = nullptr;
  this->backNode = nullptr;
}

bool Queue::enqueue(ItemType item) {
  Node *node = new Node{item, nullptr};
  if (this->isEmpty()) {
    this->backNode = node;
    this->frontNode = node;
    this->size++;
    return true;
  }
  this->size++;
  this->backNode->next = node;
  this->backNode = this->backNode->next;
  return true;
}

bool Queue::dequeue() {
  ItemType tmp;
  dequeue(tmp);
}

bool Queue::dequeue(ItemType &item) {
  if (this->isEmpty())
    return false;

  if (this->size == 1)
    this->backNode = nullptr;

  item = this->frontNode->item;
  Node *tmp = this->frontNode;

  this->frontNode = this->frontNode->next;
  delete tmp;
  this->size--;
  return true;
}

void Queue::getFront(ItemType &item) {
  item = this->frontNode->item;
}

ItemType Queue::getFront() {
  return this->frontNode->item;
}

bool Queue::isEmpty() {
  return this->size == 0;
}

void Queue::displayItems() {
  Node *current = this->frontNode;
  while (current != nullptr) {
    std::cout << current->item << " --> ";
    current = current->next;
  }
  std::cout << "nullptr" << std::endl;
}
