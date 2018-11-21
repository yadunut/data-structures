#include <iostream>

int qn1(int arr[], int pos) {
  if (pos == 1) {
    return arr[0];
  }
  return arr[pos - 1] + qn1(arr, pos - 1);
}

int qn3(int n) {
  if (n == 1) return 1;
  return n + qn3(n - 1);
}

void writeLine(char c, int num) {
  if (num == 0) return;
  std::cout << c;
  writeLine(c, num - 1);
}

void writeBlock(char c, int row, int col) {
  if (row == -1) return;
  writeLine(c, col);
  std::cout << std::endl;
  writeBlock(c, row - 1, col);
}

int f(int n) {
  std::cout << "Function entered with n = " << n << std::endl;
  switch (n) {
    case 0 :
    case 1 :
    case 2 : return n + 1;

    default: return f(n - 2) * f(n - 4);
  }
}

int main() {
  // Question 1
  int arr[] = {1, 2, 3, 4, 5};
  std::cout << "question 1 is " << qn1(arr, 5) << std::endl;


  /* Question 2
   * The function doesn't have a base case and will infinitely recurse until it crashes
   * due to stack overflow or other issues
   */

  // Question 3
  std::cout << "question 3 is " << qn3(10) << std::endl;


  // Question 4a
  std::cout << "Question 4a is ";
  writeLine('*', 3);
  std::cout << std::endl;

  // Question 4b
  std::cout << "Question 4b is ";
  writeBlock('*', 3, 5);
  std::cout << std::endl;


  // Question 5
  std::cout << "The value of f(8) is " << f(8) << std::endl;
  // This function returns 27.
  /* If a odd value is given, the function causes it to go negative and the
   * base case is skipped. E.g f(7)
   * std::cout << "The value of f(7) is " << f(7) << std::endl;
   */

  return 0;

}
