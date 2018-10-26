// List.h - - Specification of List ADT
#pragma once
#include "Person.h"
#include <iostream>
using namespace std;

class List {
public:
  List(int cap);
  bool add(Person *item);
  bool remove(int index);
  Person *get(int index);
  bool isEmpty();
  int getLength();
  void print();
  void replace(int index, Person item);

private:
  Person **items; // Stores array of pointers, size of array initialized in
                  // constructor
  int len;        // Length of list
  int cap;        // Capacity of the List
  bool isValid(int index);
};
