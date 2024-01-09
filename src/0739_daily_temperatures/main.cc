/*
 *  2024 Copyright Harry Chou
 */
#include <iostream>
#include <vector>
#include <stack>

using std::cout;
using std::endl;
using std::vector;
using std::stack;

class Solution {
 public:
  vector<int> dailyTemperatures(const vector<int>& temperatures) {
    vector<int> ret(temperatures.size());
    stack<int> wait_index;

    for (int i = 0; i < temperatures.size()-1; i++) {
      if (temperatures[i] < temperatures[i+1]) {
        ret[i] = 1;
        // check wait_tmp
        while (!wait_index.empty()
              && (temperatures[wait_index.top()] < temperatures[i+1])) {
          ret[wait_index.top()] = (i + 1 - wait_index.top());
          wait_index.pop();
        }
      } else {
        wait_index.push(i);
      }
    }

    // last one
    ret[temperatures.size()-1] = 0;

    // pop all unsolved stack
    while (!wait_index.empty()) {
      ret[wait_index.top()] = 0;
      wait_index.pop();
    }

    return ret;
  }
};

void print_ret(const vector<int>& ret) {
  for (const auto& n : ret) {
    cout << n << ", ";
  }
  cout << endl;
}

int main() {
  Solution s;
  vector<int> temp;
  vector<int> ret;

  // example 1
  temp.clear();
  temp = {73, 74, 75, 71, 69, 72, 76, 73};
  ret = s.dailyTemperatures(temp);
  print_ret(ret);

  // example 2
  temp.clear();
  temp = {30, 40, 50, 60};
  ret = s.dailyTemperatures(temp);
  print_ret(ret);

  // example 3
  temp.clear();
  temp = {30, 60, 90};
  ret = s.dailyTemperatures(temp);
  print_ret(ret);

  return 0;
}
