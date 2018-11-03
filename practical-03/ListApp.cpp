#include "List.h"
#include <iostream>

using namespace std;

int main() {
  List nameList{};
  nameList.add("Annie");
  nameList.add("Jacky");
  nameList.add("Wendy");
  nameList.print();
  nameList.add(2, "Brenda");
  nameList.print();
  nameList.remove(3);
  nameList.print();
  nameList.remove(1);
  nameList.print();
}
