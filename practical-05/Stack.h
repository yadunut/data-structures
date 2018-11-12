//
// Created by Yadunand Prem on 6/11/18.
//

#ifndef PRACTICAL_04_STACK_H
#define PRACTICAL_04_STACK_H

#include <string>

typedef char ItemType;
class Stack {
 private:
  struct Node {
    ItemType item;
    Node *next;
  };
  Node *topNode;
  int size;

 public:
  Stack();

  ~Stack();

  bool isEmpty();

  bool push(ItemType item);

  bool pop();

  bool pop(ItemType &item);

  void getTop(ItemType &item);

  ItemType getTop();

  void displayInOrder();

  void displayInOrderOfInsertion();
};

#endif // PRACTICAL_04_STACK_H
