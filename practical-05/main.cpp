
#include "Queue.h"
#include <iostream>
#define QUEUE_POINTER
using namespace std;
int main() {
//  Stack s;
//  s.push('h');
//  s.push('e');
//  s.push('l');
//  s.push('l');
//  s.push('o');
//  s.displayInOrderOfInsertion();

  Queue q;
  q.enqueue('a');
  q.enqueue('b');
  cout << q.getFront() << endl;
  q.displayItems();
  q.dequeue();
  q.displayItems();

  string input;
  cout <<
  getline(cin, input);
  cout << input;
  return 0;
}
