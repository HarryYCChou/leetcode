/*
 *  2024 Copyright Harry Chou
 */
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::unordered_map;
using std::max;

class Solution {
 public:
  int rob(const vector<int>& nums) {
    int first = 0;
    int second = 0;
    int third = 0;

    for (int i = 0; i < nums.size(); i++) {
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
  nums = {1, 2, 3, 1};
  ret = s.rob(nums);
  print_ret(ret);

  // example 2
  nums = {2, 7, 9, 3, 1};
  ret = s.rob(nums);
  print_ret(ret);

  // example 3
  nums = {2, 1, 1, 2};
  ret = s.rob(nums);
  print_ret(ret);

  // example 4
  nums = {2, 1};
  ret = s.rob(nums);
  print_ret(ret);

  return 0;
}
