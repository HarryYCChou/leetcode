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
  int lengthOfLIS(const vector<int>& nums) {
    vector<int> dp(nums.size(), 1);
    int ret = 0;
    for (int i = 0; i < nums.size(); i++) {
      for (int j = 0; j < i; j++) {
        if (nums[j] < nums[i]) {
          dp[i] = max(dp[j] + 1, dp[i]);
        }
      }
      ret = max(dp[i], ret);
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
  nums = {10, 9, 2, 5, 3, 7, 101, 18};
  ret = s.lengthOfLIS(nums);
  print_ret(ret);

  // example 2
  nums = {0, 1, 0, 3, 2, 3};
  ret = s.lengthOfLIS(nums);
  print_ret(ret);

  // example 3
  nums = {7, 7, 7, 7, 7, 7, 7};
  ret = s.lengthOfLIS(nums);
  print_ret(ret);

  return 0;
}
