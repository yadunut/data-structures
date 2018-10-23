#pragma once
#include <string>

using namespace std;

class Person {

private:
  string name;
  string telNo;

public:
  Person(string name, string telNo);
  void setName(string name);
  string getName();
  void setTelNo(string telNo);
  string getTelNo();
  string print();
};
