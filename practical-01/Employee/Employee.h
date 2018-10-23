#pragma once

#include <string>
using namespace std;

class Employee {
private:
  string firstName;
  string lastName;
  int salary;

public:
  Employee(string firstName, string lastName, int salary);
  string getFirstName();
  void setFirstName(string lastName);
  string getLastName();
  void setLastName(string lastName);
  int getSalary();
  void setSalary(int salary);
};
