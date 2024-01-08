/*
 *  2024 Copyright Harry Chou
 */
#include <iostream>
#include <vector>
#include <string>
#include <stack>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::stoi;
using std::stack;

class Solution {
 public:
  int evalRPN(const vector<string>& tokens) {
    stack<int> st;
    int v1, v2;

    for (const auto& c : tokens) {
      if (c == "+") {
        v1 = st.top(); st.pop();
        v2 = st.top(); st.pop();
        st.push(v2 + v1);
      } else if (c == "-") {
        v1 = st.top(); st.pop();
        v2 = st.top(); st.pop();
        st.push(v2 - v1);
      } else if (c == "*") {
        v1 = st.top(); st.pop();
        v2 = st.top(); st.pop();
        st.push(v2 * v1);
      } else if (c == "/") {
        v1 = st.top(); st.pop();
        v2 = st.top(); st.pop();
        st.push(v2 / v1);
      } else {
        st.push(stoi(c));
      }
    }

    return st.top();
  }
};

void print_ret(const int& ret) {
  cout << ret << endl;
}

int main() {
  Solution s;

  int ret;
  vector<string> tokens;

  // example 1
  tokens = {"2", "1", "+", "3", "*"};
  ret = s.evalRPN(tokens);
  print_ret(ret);

  // example 2
  tokens = {"4", "13", "5", "/", "+"};
  ret = s.evalRPN(tokens);
  print_ret(ret);

  // example 3
  tokens = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"
           };
  ret = s.evalRPN(tokens);
  print_ret(ret);

  return 0;
}
