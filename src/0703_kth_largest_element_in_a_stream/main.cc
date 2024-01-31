/*
 *  2024 Copyright Harry Chou
 */
#include <iostream>
#include <vector>
#include <deque>
#include <stack>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::deque;
using std::stack;
using std::sort;

class KthLargest {
 public:
  deque<int> dq;
  stack<int> stk;
  int max_k;

  KthLargest(const int& k, const vector<int>& nums) {
    max_k = k;
    for (const auto&n : nums) {
      addToDeque(n);
    }
  }

  void addToDeque(const int& val) {
    if (dq.size() == 0) {
      dq.push_back(val);
    } else if (val > dq.front()) {
      // insert
      while (val < dq.back()) {
        stk.push(dq.back());
        dq.pop_back();
      }
      dq.push_back(val);
      while (!stk.empty()) {
        dq.push_back(stk.top());
        stk.pop();
      }
      // pop front
      if (dq.size() > max_k) dq.pop_front();
    } else if (dq.size() < max_k) {
      dq.push_front(val);
    }
  }

  int add(const int& val) {
    addToDeque(val);
    return dq.front();
  }
};

void print_ret(const int& ret) {
  cout << ret << endl;
}

int main() {
  vector<int> nums = {4, 5, 8, 2};
  KthLargest *kthLargest = new KthLargest(3, nums);

  // example 1
  print_ret(kthLargest->add(3));   // return 4
  print_ret(kthLargest->add(5));   // return 5
  print_ret(kthLargest->add(10));  // return 5
  print_ret(kthLargest->add(9));   // return 8
  print_ret(kthLargest->add(4));   // return 8

  // example 2

  // example 3

  return 0;
}
