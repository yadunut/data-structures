#include<iostream>
#include<string>

using namespace std;

int main() {
    int value1 = 200000; // a
    int value2; // b
    int *ptr; // c
    ptr = &value1; // d
    cout << "Value of *ptr: " << *ptr << endl; // e
    *ptr = value2; // f
    cout << "Value of value2: " << value2 << endl; // g. Value2 has a default value of 0;
    cout << "Value of &value1: " << &value1 << endl; // h
    cout << "Value of ptr: " << ptr << endl; // i. Yes, It has the same address as value1;
    ptr = &value2; // j
    *ptr += 2000; // k
    cout << "Value of value1: " << value1 << endl << "Value of value2: " << value2 << endl; // l
    // value1 = 0 since step f sets the value of *ptr(which points to value1) to 0
    // value2 = 2000 since step k increments the value of *ptr(which points to value2) by 2000
}
