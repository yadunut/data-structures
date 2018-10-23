#include "Person.h"
#include <stdio.h>
#include <string>

Person::Person(string name, string telNo) : name(name), telNo(telNo) {}

void Person::setName(string name) { this->name = name; }
string Person::getName() { return name; }
void Person::setTelNo(string telNo) { this->telNo = telNo; }
string Person::getTelNo() { return telNo; }
string Person::print() { return name + " " + telNo; }
