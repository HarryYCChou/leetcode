/*
 *  2024 Copyright Harry Chou
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <stack>
#include <climits>

using std::cout;
using std::endl;
using std::vector;
using std::sort;
using std::deque;
using std::stack;

class Solution {
 public:
  deque<int> dq;
  stack<int> stk;
  int n, v1, v2, remain;

  int lastStoneWeight(vector<int>& stones) {
    sort(stones.begin(), stones.end());
    for (const auto& n : stones) {
      stk.push(n);
    }

    // check
    while (true) {
      n = dq.size() + stk.size();
      if (n == 0) return 0;
      if (n == 1) return getMax();
      v1 = getMax();
      v2 = getMax();
      remain = v1 - v2;
      if (remain > 0) {
        insert(remain);
      }
    }
    return 0;
  }

  void insert(int w) {
    while (true) {
      v1 = (dq.empty()) ? INT_MAX : dq.back();
      v2 = (stk.empty()) ? INT_MIN : stk.top();
      if (v1 >= w && w >= v2) {
        dq.push_back(w);
        return;
      } else if (w > v1) {
        stk.push(v1);
        dq.pop_back();
      } else if (w < v2) {
        dq.push_back(v2);
        stk.pop();
      }
    }
  }

  int getMax() {
    int tmp;
    if (!dq.empty()) {
      tmp = dq.front();
      dq.pop_front();
    } else if (!stk.empty()) {
      tmp = stk.top();
      stk.pop();
    } else {
      tmp = -1;
    }
    return tmp;
  }
};

void print_ret(const int& ret) {
  cout << ret << endl;
}

int main() {
  Solution s;

  int ret;
  vector<int> stones;

  // example 1
  stones = {2, 7, 4, 1, 8, 1};
  ret = s.lastStoneWeight(stones);
  print_ret(ret);

  // example 2

  // example 3

  return 0;
}
