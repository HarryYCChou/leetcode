/*
 *  2024 Copyright Harry Chou
 */
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

class Solution {
 public:
  vector<string> generateParenthesis(const int n) {
    vector<string> ret;
    generate(n, 0, 0, "", ret);
    return ret;
  }

 private:
  void generate(const int& n, int open, int close, string s,
                vector<string>& v) {
    if (n == open && n == close) {
      v.push_back(s);
      return;
    }

    // try to add open parenthesis
    if (open < n) {
      generate(n, open + 1, close, s + "(", v);
    }
    // try to add close parenthesis
    if (close < n && close < open) {
      generate(n, open, close + 1, s + ")", v);
    }
  }
};

void print_ret(const vector<string>& ret) {
  for (const auto s : ret) {
    cout << s << endl;
  }
  cout << endl;
}

int main() {
  Solution s;
  vector<string> ret;

  // example 1
  ret = s.generateParenthesis(3);
  print_ret(ret);

  // example 2
  ret = s.generateParenthesis(1);
  print_ret(ret);

  return 0;
}
