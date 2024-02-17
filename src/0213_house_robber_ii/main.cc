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
  int rob(const vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return nums[0];
    return (max(money(0, n - 2, nums), money(1, n - 1, nums)));
  }

  int money(int start, int end, const vector<int>& nums) {
    int first = 0;
    int second = 0;
    int third = 0;

    for (int i = start; i <= end; i++) {
      third = max(first + nums[i], second);
      first = second;
      second = third;
    }

    return third;
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
  nums = {2, 3, 2};
  ret = s.rob(nums);
  print_ret(ret);

  // example 2
  nums = {1, 2, 3, 1};
  ret = s.rob(nums);
  print_ret(ret);

  // example 3
  nums = {1, 2, 3};
  ret = s.rob(nums);
  print_ret(ret);

  // example 4
  nums = {2};
  ret = s.rob(nums);
  print_ret(ret);

  return 0;
}
