#include <iostream>
#include "Stack.h"
#include <string>
#include <sstream>
#include <vector>

using namespace std;

string getInput(string message) {
  string input;
  cout << message << " ";
  getline(cin, input);
  return input;
}

int precedence(char c) {
  switch (c) {
    case '(': return 0;
    case ')': return 0;
    case '*': return 2;
    case '/': return 2;
    case '+': return 1;
    case '-': return 1;
    default: return -1;
  }
}

string infixToPostfix(string input) {
  Stack inputStack;
  Stack operatorStack;
  string postfix;
  for (int i = static_cast<int>(input.length() - 1); i >= 0; i--) {
    inputStack.push(string(1, input[i]));
  }
  while (!inputStack.isEmpty()) {
    char c = inputStack.getTop()[0];
    if (c == ' ' || c == '\t') {
      inputStack.pop();
      continue;
    }
    switch (c) {
      case '+':
      case '-':
      case '*':
      case '/': {
        while (!operatorStack.isEmpty() && precedence(c) <= precedence(operatorStack.getTop()[0])) {
          postfix += operatorStack.getTop();
          postfix += " ";
          operatorStack.pop();
        }
        operatorStack.push(string(1, c));
        inputStack.pop();
        break;
      }
      case '(': {
        operatorStack.push(string(1, c));
        inputStack.pop();
        break;
      }
      case ')': {
        char top = operatorStack.getTop()[0];
        while (top != '(') {
          postfix += top;
          postfix += " ";
          operatorStack.pop();
          top = operatorStack.getTop()[0];
        }
        operatorStack.pop();
        inputStack.pop();
        break;
      }
      default: {
        while (!inputStack.isEmpty()) {
          c = inputStack.getTop()[0];
          if (!isdigit(c)) {
            postfix += " ";
            break;
          }
          postfix += c;
          inputStack.pop();
        }
        break;
      }
    }
  }
  while (!operatorStack.isEmpty()) {
    postfix += " ";
    postfix += operatorStack.getTop();
    operatorStack.pop();
  }
  return postfix;
};

vector<string> split(string postfix) {
  stringstream ss(postfix);
  istream_iterator<string> begin(ss);
  istream_iterator<string> end;
  vector<string> vstrings(begin, end);
  return vstrings;
}

string evaluatePostfix(string input) {
  vector<string> postfix = split(input);
  Stack valueStack;
  string next;
  for (int i = 0; i != postfix.size(); i++) {
    next = postfix[i];
    switch (next[0]) {
      case '+': {
        string operandTwo = valueStack.getTop();
        valueStack.pop();
        string operandOne = valueStack.getTop();
        valueStack.pop();
        int result = atoi(operandOne.c_str()) + atoi(operandTwo.c_str());
        valueStack.push(to_string(result));
        break;
      }
      case '-': {
        string operandTwo = valueStack.getTop();
        valueStack.pop();
        string operandOne = valueStack.getTop();
        valueStack.pop();
        int result = atoi(operandOne.c_str()) - atoi(operandTwo.c_str());
        valueStack.push(to_string(result));
        break;
      }
      case '*': {
        string operandTwo = valueStack.getTop();
        valueStack.pop();
        string operandOne = valueStack.getTop();
        valueStack.pop();
        int result = atoi(operandOne.c_str()) * atoi(operandTwo.c_str());
        valueStack.push(to_string(result));
        break;
      }
      case '/': {
        string operandTwo = valueStack.getTop();
        valueStack.pop();
        string operandOne = valueStack.getTop();
        valueStack.pop();
        int result = atoi(operandOne.c_str()) / atoi(operandTwo.c_str());
        valueStack.push(to_string(result));
        break;
      }
      default: {
        valueStack.push(next);
        break;
      }

    }
  }
  return valueStack.getTop();
}

int main() {
//  Stack s;
//  s.push(3);
//  s.push(4);
//  ItemType top;
//  s.getTop(top);
//  cout << top << endl << endl;
//  s.displayInOrderOfInsertion();
//  cout << endl;
//  s.pop();
//  s.displayInOrderOfInsertion();

  string input, output, result;
  while (true) {
    input = getInput(">");
    if (input == "q")
      break;
    output = infixToPostfix(input);
    cout << output << endl;
    result = evaluatePostfix(output);
    cout << result << endl;

  }
  return 0;
}