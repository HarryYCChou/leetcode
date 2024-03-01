/*
 *  2024 Copyright Harry Chou
 */
#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::vector;
using std::string;

class Solution {
 public:
  bool checkValidString(const string& s) {
    int balance = 0;
    char c;
    // star as left
    for (int i = 0; i < s.size(); i++) {
      c = s[i];
      if (c == '(' || c == '*') {
        balance++;
      } else {
        balance--;
        if (balance < 0) return false;
      }
    }

    balance = 0;
    // star as right
    for (int i = s.size() - 1; i >= 0; i--) {
      c = s[i];
      if (c == ')' || c == '*') {
        balance++;
      } else {
        balance--;
        if (balance < 0) return false;
      }
    }

    return true;
  }
};

void print_ret(const bool& ret) {
  if (ret) {
    cout << "true" << endl;
  } else {
    cout << "false" << endl;
  }
}

int main() {
  Solution s;

  string str;
  bool ret;

  // example 1
  str = "()";
  ret = s.checkValidString(str);
  print_ret(ret);

  // example 2
  str = "(*)";
  ret = s.checkValidString(str);
  print_ret(ret);

  // example 3
  str = "(*))";
  ret = s.checkValidString(str);
  print_ret(ret);

  return 0;
}
