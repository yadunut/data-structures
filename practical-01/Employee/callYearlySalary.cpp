#include "Employee.h"
#include <iostream>

using namespace std;

int main() {
  Employee bob("Bob", "Bobby", 1000);
  Employee mary("Mary", "Bobby", 8000);

  cout << "Salary of Bob is " << bob.getSalary() << endl;
  cout << "Salary of Mary is " << mary.getSalary() << endl;

  bob.setSalary(bob.getSalary() * 1.1);
  mary.setSalary(bob.getSalary() * 1.1);

  cout << "Salary of Bob is " << bob.getSalary() << endl;
  cout << "Salary of Mary is " << mary.getSalary() << endl;
}
