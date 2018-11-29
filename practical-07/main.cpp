#include <iostream>
#include <string>
using namespace std;

// search for an item in a sorted array using sequential search (Iterative version)
// returns the index of the item in the array if found, otherwise returns -1
int search(int dataArray[], int arraySize, int target);

// search for an item in a sorted array using binary search (Iterative version)
// returns the index of the item in the array if found, otherwise returns -1
int binarySearch(int dataArray[], int arraySize, int target);

// search for an item in a sorted array using sequential search (Recursive version)
// returns the index of the item in the array if found, otherwise returns -1
int recurSearch(int dataArray[], int arraySize, int start, int target);

// search for an item in a sorted array using binary search (Recursive version)
// returns the index of the item in the array if found, otherwise returns -1
int recurBinarySearch(int dataArray[], int first, int last, int target);

static int comparisons = 0;

int main() {
  int dataArray[1000];
  for (int i = 0; i < 1000; i++) dataArray[i] = (i + 1) * 2;

  string input;
  cout << "Get target: ";
  getline(cin, input);

  int target = stoi(input);

  comparisons = 0;
  int idx1 = recurSearch(dataArray, 1000, 0, target);
  cout << "Sequential Search: " << comparisons << endl;
  if (idx1 == -1) cout << "Not found" << endl;
  else cout << "Found" << endl;

  comparisons = 0;
  int idx2 = recurBinarySearch(dataArray, 0, 1000, target);
  cout << "Binary Search    : " << comparisons << endl;
  if (idx2 == -1) cout << "Not found" << endl;
  else cout << "Found" << endl;

  return 0;
}

int search(int dataArray[], int arraySize, int target) {
  for (int index = 0; index < arraySize; index++) {
    comparisons++;
    if (dataArray[index] == target) return index;
    if (dataArray[index] >= target) return -1;
  }
  return -1;
}
int binarySearch(int dataArray[], int arraySize, int target) {
  int first = 0;
  int last = arraySize - 1;
  while (first <= last) {
    comparisons++;
    int mid = (first + last) / 2;
    if (dataArray[mid] == target) return mid;
    else if (target < dataArray[mid]) last = mid - 1;
    else if (target > dataArray[mid]) first = mid + 1;
  }
  return -1;
}
int recurSearch(int dataArray[], int arraySize, int start, int target) {
  comparisons++;
  if (start == arraySize || dataArray[start] > target)
    return -1;
  if (dataArray[start] == target)
    return start;
  return recurSearch(dataArray, arraySize, start + 1, target);
}
int recurBinarySearch(int dataArray[], int first, int last, int target) {
  int middle = (first + last) / 2;
  if (first > last) return -1;
  comparisons++;
  if (dataArray[middle] == target)
    return middle;
  if (target > dataArray[middle])
    return recurBinarySearch(dataArray, middle + 1, last, target);
  return recurBinarySearch(dataArray, first, middle - 1, target);
}
