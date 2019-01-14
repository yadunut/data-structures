#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

void writeToFile1(string filename);
string readFromFile1(string filename);
void readWriteFile1(string filename, string outfile);

void writeToFile2(string filename);
void readWriteFile2(string filename, string outfile);

void writeFile(string filename, string content);
string readFile(string filename, char delim);

int main() {
  string productFileName = "product1.txt";
  writeToFile1(productFileName);
  cout << readFromFile1(productFileName);
  readWriteFile1(productFileName, "transaction1.txt");
  writeToFile2("product2.txt");
  readWriteFile2("product2.txt", "transaction2.txt");
}

void writeToFile1(string filename) {
  string data = "iPhone_7	10	1088.00\n"
                "Galaxy_S7	10	999.00\n"
                "Xperia_Z	10	899.00\n"
                "Redmi_3S	10	299.00\n";
  writeFile(filename, data);
}

string readFromFile1(string inFilename) {
  string result = "Name\t\t"
                  "Qty\t"
                  "Price\t"
                  "Amount\n";
  result += readFile(inFilename, '\t');
  return result;
}

void readWriteFile1(string filename, string outfile) {
  writeFile(outfile, readFile(filename, '\t'));
}

void writeToFile2(string filename) {
  string data = "iPhone 7;10;1088.00\n"
                "Galaxy S7;10;999.00\n"
                "Xperia Z;10;899.00\n"
                "Redmi 3S;10;299.00\n";
  writeFile(filename, data);
}
void readWriteFile2(string filename, string outfile) {
  writeFile(outfile, readFile(filename, ';'));
}

void writeFile(string filename, string content) {
  ofstream file(filename);
  file << content;
  file.close();
}

string readFile(string filename, char delim) {
  ifstream file(filename);
  stringstream result;
  string line;

  while (getline(file, line, '\n')) {
    stringstream ss(line);
    string cell;

    int counter = 0, qty = 0, price = 0;

    while (getline(ss, cell, delim)) {
      switch (counter) {
      case 0: {
        result << cell << delim;
        break;
      }
      case 1: {
        qty = stoi(cell);
        result << qty << delim;
        break;
      }
      case 2: {
        price = stoi(cell);
        result << price << delim << price * qty << '\n';
        break;
      }
      }
      counter = (counter + 1) % 3;
    }
  }
  return result.str();
}
