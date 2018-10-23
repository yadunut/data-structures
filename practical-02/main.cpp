#include "List.h"
#include "Person.h"
#include <iostream>
#include <string>

using namespace std;
void printMenu() {
  cout << "---------------- Main Menu -------------------" << endl;
  cout << "[1] List the phone numbers" << endl;
  cout << "[2] Add a new contact" << endl;
  cout << "[3] Remove a contact" << endl;
  cout << "[4] Search for a phone number" << endl;
  cout << "[0] Exit" << endl;
  cout << "----------------------------------------------" << endl;
}

int inputNumber(string prompt) {
  while (true) {
    cout << prompt;
    int res;
    cin >> res;
    if (cin.fail()) {
      cout << "You have entered an invalid number! Try again!" << endl;
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      continue;
    }
    return res;
  }
}

string inputString(string prompt) {
  while (true) {
    cout << prompt;
    string res;
    cin >> res;
    if (cin.fail()) {
      cout << "You have entered an invalid string! Try again!" << endl;
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      continue;
    }
    return res;
  }
}

int main() {
  List list(100);
  while (true) {
    printMenu();
    int input = inputNumber("Enter your option: ");
    switch (input) {
    case 1: {
      list.print();
      break;
    }
    case 2: {
      string name = inputString("Enter name: ");
      string telNo = inputString("Enter TelNo: ");
      Person *person = new Person(name, telNo);
      list.add(person);
      break;
    }
    case 3: {
      int input = inputNumber("Enter the index: ");
      list.remove(input);
      break;
    }
    case 4: {
      int input = inputNumber("Enter the index: ");
      cout << list.get(input)->print() << endl;
      break;
    }
    case 0:
      return 0;
      break;
    default:
      cout << "You have entered an invalid number. Try again" << endl;
      break;
    }
  }
}
