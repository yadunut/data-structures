#include "Employee.h"
#include <string>
using namespace std;

Employee::Employee(string firstName, string lastName, int salary) {
  this->firstName = firstName;
  this->lastName = lastName;
  this->salary = salary;
}
string Employee::getFirstName() { return firstName; }
void Employee::setFirstName(string firstName) { this->firstName = firstName; }

string Employee::getLastName() { return lastName; }
void Employee::setLastName(string lastName) { this->lastName = lastName; }

int Employee::getSalary() { return salary; }
void Employee::setSalary(int salary) {
  if (salary > 0) {
    this->salary = salary;
  } else {
    this->salary = 0;
  }
}
