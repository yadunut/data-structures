
#include "Queue.h"
#include "Stack.h"
#include <iostream>
using namespace std;

bool isPalindrome(string input) {
  Stack s;
  Queue q;
  for (char &c: input) {
    s.push(c);
    q.enqueue(c);
  }
  while (!s.isEmpty()) {
    if (s.getTop() != q.getFront())
      return false;
    s.pop();
    q.dequeue();
  }
  return true;
}
int main() {
//  Stack s;
//  s.push('h');
//  s.push('e');
//  s.push('l');
//  s.push('l');
//  s.push('o');
//  s.displayInOrderOfInsertion();

//  Queue q;
//  q.enqueue('a');
//  q.enqueue('b');
//  cout << q.getFront() << endl;
//  q.displayItems();
//  q.dequeue();
//  q.displayItems();

  while (true) {
    string input;
    cout << "Enter a palindrome: ";
    getline(cin, input);
    if (input == "q") {
      break;
    }
    bool result = isPalindrome(input);
    if (result) {
      cout << "Is palindrome" << endl;
    } else {
      cout << "Is not palindrome" << endl;
    }
  }
  return 0;
}
