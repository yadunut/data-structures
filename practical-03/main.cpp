#include "List.h"
#include <iostream>

using namespace std;

int main() {
  List list{};
  list.add("Bobby");
  list.print();
  list.add("Bob");
  list.print();
  list.add("Boy");
  list.print();
  list.add(0, "this");
  list.print();
  list.remove(0);
  list.print();
  list.remove(1);
  list.print();
  cout << list.get(0) << endl;
  cout << list.get(1) << endl;
  cout << list.get(3) << endl;
}
