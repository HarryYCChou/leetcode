/*
 *  2024 Copyright Harry Chou
 */
#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::max;

class Solution {
 public:
  bool canJump(const vector<int>& nums) {
    int goal = nums.size() - 1;
    int cur_max = 0;
    for (int i = 0; i <= cur_max; i++) {
      if (cur_max >= goal) return true;
      cur_max = max(cur_max, i + nums[i]);
    }
    return false;
  }
};

void print_ret(const int& ret) {
  if (ret) {
    cout << "true" << endl;
  } else {
    cout << "false" << endl;
  }
}

int main() {
  Solution s;

  int ret;
  vector<int> nums;

  // example 1
  nums = {2, 3, 1, 1, 4};
  ret = s.canJump(nums);
  print_ret(ret);

  // example 2
  nums = {3, 2, 1, 0, 4};
  ret = s.canJump(nums);
  print_ret(ret);

  return 0;
}
