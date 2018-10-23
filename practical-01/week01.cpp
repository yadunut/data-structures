#include <iostream>
#include <string>
// #define max(x,y) ((x > y)? x : y)
// #define min(x,y) ((x < y)? x : y)

using namespace std;

int main() {
  string model;
  cout << "Please enter your mobile phone model: ";
  cin >> model;

  cout << "Model = " << model << endl;

  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  cout << "Please enter your mobile phone model: ";
  getline(cin, model);
  cout << "Model = " << model << endl;

  int firstvalue, secondvalue;
  int *myptr;

  myptr = &firstvalue;
  *myptr = 10;

  myptr = &secondvalue;
  *myptr = 20;

  cout << "First value is " << firstvalue << endl;
  cout << "Second value is " << secondvalue << endl;
  cout << "ptr addr is " << myptr << endl;
  cout << "ptr value is " << *myptr << endl;

  int v1 = 5, v2 = 15;
  int *p1, *p2;

  p1 = &v1;
  p2 = &v2;

  *p1 = 5;
  *p2 = *p2;
  *p1 = 20;

  cout << "First value is " << v1 << endl;
  cout << "Second value is " << v2 << endl;
  cout << "Addr of First value is " << p1 << endl;
  cout << "Addr of Second value is " << p2 << endl;

  int numArray1[10];
  int numArray2[20];
  int *p;

  p = numArray1;
  p = numArray2;

  // numArray1 = p; This is not allowed as arrays are constant pointers

  int numArray[5];

  p = numArray;
  *p = 10;

  p++;
  *p = 20;

  p = &numArray[2];
  *p = 30;

  p = numArray + 3;
  *p = 40;

  *(p + 1) = 50;

  for (int i = 0; i < 5; i++) {
    cout << numArray[i] << ", ";
  }
  cout << endl;

  return 0;
}
