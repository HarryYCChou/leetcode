/*
 *  2024 Copyright Harry Chou
 */
#include <iostream>
#include <string>
#include <stack>

using std::cout;
using std::endl;
using std::string;
using std::stack;

class Solution {
 public:
  bool isValid(const string& s) {
    stack<char> st;

    for (const auto& c : s) {
      if (c == ')') {
        if (st.empty() || st.top() != '(') return false;
        st.pop();
      } else if (c == '}') {
        if (st.empty() || st.top() != '{') return false;
        st.pop();
      } else if (c == ']') {
        if (st.empty() || st.top() != '[') return false;
        st.pop();
      } else {
        st.push(c);
      }
    }

    return st.empty();
  }
};

void print_ret(const bool& ret) {
  if (ret) {
    cout << "true";
  } else {
    cout << "false";
  }
  cout << endl;
}

int main() {
  Solution s;

  bool ret;
  string str;

  // example 1
  str = "([[]])";
  ret = s.isValid(str);
  print_ret(ret);

  // example 2
  str = "()[]{}";
  ret = s.isValid(str);
  print_ret(ret);

  // example 3
  str = "([";
  ret = s.isValid(str);
  print_ret(ret);

  return 0;
}
