/*
 *  2024 Copyright Harry Chou
 */
#include <iostream>
#include <stack>

using std::cout;
using std::endl;
using std::stack;

class MinStack {
 public:
  stack<int> min_stack;
  stack<int> st;

  MinStack() {}

  void push(int val) {
    st.push(val);
    if (min_stack.empty() || val <= min_stack.top()) min_stack.push(val);
  }

  void pop() {
    if (!st.empty()) {
      if (st.top() == min_stack.top()) min_stack.pop();
      st.pop();
    }
  }

  int top() {
    return st.top();
  }

  int getMin() {
    return min_stack.top();
  }
};

int main() {
  // example 1
  MinStack minStack;  // = new MinStack();
  minStack.push(-2);
  minStack.push(0);
  minStack.push(-3);
  cout << minStack.getMin() << endl;  // return -3
  minStack.pop();
  cout << minStack.top() << endl;     // return 0
  cout << minStack.getMin() << endl;  // return -2

  return 0;
}
