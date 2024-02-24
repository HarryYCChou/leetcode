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
  int maxSubArray(const vector<int>& nums) {
    int ret = nums[0];
    int prev = nums[0];
    int next;
    for (int i = 1; i < nums.size(); i++) {
      next = nums[i] + prev;
      next = max(next, nums[i]);
      ret = max(next, ret);
      prev = next;
    }
    return ret;
  }
};

void print_ret(const int& ret) {
  cout << ret << endl;
}

int main() {
  Solution s;

  int ret;
  vector<int> nums;

  // example 1
  nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  ret = s.maxSubArray(nums);
  print_ret(ret);

  // example 2
  nums = {1};
  ret = s.maxSubArray(nums);
  print_ret(ret);

  // example 3
  nums = {5, 4, -1, 7, 8};
  ret = s.maxSubArray(nums);
  print_ret(ret);

  return 0;
}
