/*
 *  2024 Copyright Harry Chou
 */
#include <iostream>
#include <vector>
#include <deque>

using std::cout;
using std::endl;
using std::vector;
using std::deque;

class Solution {
 public:
  vector<int> maxSlidingWindow(const vector<int>& nums, const int& k) {
    vector<int> ret;
    deque<int> dq;

    // creating initial deque
    for (int i = 0; i < k; i++) {
      while (!dq.empty() && nums[i] > dq.back()) {
        dq.pop_back();
      }
      dq.push_back(nums[i]);
    }

    int i = 0, j = k;
    ret.push_back(dq.front());

    while (j < nums.size()) {
      if (dq.front() == nums[i]) dq.pop_front();
      i++;

      while (!dq.empty() && nums[j] > dq.back()) {
        dq.pop_back();
      }
      dq.push_back(nums[j]);
      ret.push_back(dq.front());

      j++;
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

  vector<int> nums, ret;

  // example 1
  nums.clear();
  nums = {1, 3, -1, -3, 5, 3, 6, 7};
  ret = s.maxSlidingWindow(nums, 3);
  print_ret(ret);

  // example 2
  nums.clear();
  nums = {1};
  ret = s.maxSlidingWindow(nums, 1);
  print_ret(ret);

  return 0;
}
