//
// Created by Yadunand Prem on 19/11/18.
//
#include <iostream>
using namespace std;

long power(int a, int n);
void printForward(const int array[], int n);
void printBackward(const int array[], int n);
int maxArray(const int array[], int n);

int main() {
  std::cout << power(10, 3) << std::endl;
  int arr[] = {1, 2, 7, 4, 100};
  printForward(arr, 5);
  cout << endl;
  printBackward(arr, 5);
  cout << "Max is " << maxArray(arr, 5) << endl;
}

long power(int a, int n) {
  if (n == 1) return a;
  return a * power(a, n - 1);
}

void printForward(const int array[], int n) {
  if (n != 0) {
    printForward(array, n - 1);
    cout << array[n - 1] << endl;
  }
}

void printBackward(const int array[], int n) {
  if (n != 0) {
    cout << array[n - 1] << endl;
  }
}

// n will store the index of the max value
int maxArray(const int array[], int n) {
  if (n == 1) {
    return array[0];
  }
  int res = maxArray(array, n - 1);
  return array[n-1] > res ? array[n-1] : res;
}
