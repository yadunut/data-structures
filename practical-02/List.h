// List.h - - Specification of List ADT
#pragma once
#include "Person.h"
#include <iostream>
using namespace std;

typedef Person ItemType;

class List {
private:
  ItemType **items; // Stores array of pointers, size of array initialized in
  // constructor
  int len; // Length of list
  int cap; // Capacity of the List
  bool isValid(int index);

public:
  // constructor
  List(int cap);

  // add an item to the back of the list (append)
  // pre : len < cap;
  // post: item is added to the back of the list
  //       len of list is increased by 1
  bool add(ItemType *item);

  // remove an item at a specified position in the list
  // pre : 1 <= index <= len
  // post: item is removed the specified position in the list
  //       len of list is decreased by 1
  // return true if remove was successful
  bool remove(int index);

  // get an item at a specified position of the list (retrieve)
  // pre : 1 <= index <= len
  // post: none
  ItemType *get(int index);

  // check if the list is empty
  // pre : none
  // post: none
  // return true if the list is empty; otherwise returns false
  bool isEmpty();

  // check the len of the list
  // pre : none
  // post: none
  // return the number of items in the list
  int getLength();

  void print();

  void replace(int index, ItemType item);
};
