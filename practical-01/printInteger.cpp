#include <iostream>
#include <string>

using namespace std;

int main() {
  int input;

  cout << "Enter 5 numbers: ";
  cin >> input;

  for (int i = 10000; i != 0; i /= 10) {
    cout << input / i << " ";
    input = input % i;
  }
  cout << endl;
}
