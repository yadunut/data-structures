//
// Created by Yadunand Prem on 11/11/18.
//

#ifndef PRACTICAL_05_QUEUE_H
#define PRACTICAL_05_QUEUE_H
typedef char ItemType;
class Queue {
 private:
  struct Node {
    ItemType item;
    Node *next;
  };
  Node *frontNode, *backNode;
  int size;

 public:
  Queue();
  ~Queue();
  bool enqueue(ItemType item);
  bool dequeue();
  bool dequeue(ItemType &item);
  void getFront(ItemType &item);
  ItemType getFront();
  bool isEmpty();
  void displayItems();
};

#endif //PRACTICAL_05_QUEUE_H
